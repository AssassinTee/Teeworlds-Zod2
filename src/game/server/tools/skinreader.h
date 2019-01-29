#ifndef GAME_SERVER_SKINREADER_H
#define GAME_SERVER_SKINREADER_H

/*
I could totally build a skin reader here that automatically reads all skin jsons and tells the clients how the zombies look
OR
I hardcode them somewhere
*/
#include "json.hpp"
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <engine/console.h>

class CSkinReader
{
public:
    CSkinReader(IConsole* Console){
        m_pConsole = Console;
        std::vector<std::string> skinlist = {"bluekitty",
            "bluestripe", "brownbear", "cammo", "cammostripes",
            "default", "koala", "limekitty", "pinky",
            "redbopp", "redstripe", "saddo", "toptri", "twinbop",
            "twintri", "warpaint"};
        for(auto it = skinlist.begin(); it != skinlist.end(); ++it)
            ReadSkin(*it);

    };
    ~CSkinReader(){};
    std::string GetSkinName(std::string skinname, int part, bool& custom_colors, int& hue, int& sat, int& lgt, int& alp)
    {
        switch(part)
        {
            case 0: return GetInfo(skinname, std::string("body"), custom_colors, hue, sat, lgt, alp);
            case 1: return GetInfo(skinname, std::string("marking"), custom_colors, hue, sat, lgt, alp);
            //case 2: return GetInfo(skinname, std::string("decoration"), custom_colors, hue, sat, lgt, alp);
            case 3: return GetInfo(skinname, std::string("hands"), custom_colors, hue, sat, lgt, alp);
            case 4: return GetInfo(skinname, std::string("feet"), custom_colors, hue, sat, lgt, alp);
            case 5: return GetInfo(skinname, std::string("eyes"), custom_colors, hue, sat, lgt, alp);
            default: return "standard";
        }
    }


private:
    std::string GetInfo(std::string skinname, std::string part, bool& custom_colors, int& hue, int& sat, int& lgt, int& alp)
    {
        nlohmann::json j = skins[skinname]["skin"];
        if(j.is_object())
        {
            nlohmann::json k = j[part];
            if(k.is_object())
            {
                std::string custom_colors_str = k.value("custom_colors", "false");
                custom_colors = (custom_colors_str == "true");
                hue = k.value("hue", 0);
                sat = k.value("sat", 0);
                lgt = k.value("lgt", 0);
                alp = k.value("alp", 255);
                return k["filename"];
            }
        }
        return "standard";
    }

    void ReadSkin(std::string& skin)
    {
        std::string filename = "data/skins/";
        filename+= skin+".json";
        std::ifstream i(filename);
        if(i.is_open())
        {
            nlohmann::json j;
            i >> j;
            skins[skin] = j;
            m_pConsole->Print(IConsole::OUTPUT_LEVEL_DEBUG, "json", "success");
        }
        else
        {
            m_pConsole->Print(IConsole::OUTPUT_LEVEL_DEBUG, "json", filename.c_str());
        }
    }

    std::map<std::string, nlohmann::json> skins;
    IConsole* m_pConsole;
};

#endif // GAME_SERVER_SKINREADER_H
