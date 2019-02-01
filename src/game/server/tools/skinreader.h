#ifndef GAME_SERVER_SKINREADER_H
#define GAME_SERVER_SKINREADER_H

/*
I could totally build a skin reader here that automatically reads all skin jsons and tells the clients how the zombies look
OR
I hardcode them somewhere
*/
#include "engine/external/nlohmann/json.hpp"
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
    void GetSkinName(char* filename, std::string skinname, int part, bool& custom_colors, int& color)
    {
        GetInfo(filename, skinname, std::string(partnames[part]), custom_colors, color);
    }


private:
    void GetInfo(char* filename, std::string skinname, std::string part, bool& custom_colors, int& color)
    {
        nlohmann::json& j = skins[skinname]["skin"];
        if(j.is_object())
        {
            nlohmann::json& k = j[part];
            if(k.is_object())
            {
                std::string custom_colors_str = k.value("custom_colors", "false");
                custom_colors = (custom_colors_str == "true");

                int hue, sat, lgt, alp;
                hue = k.value("hue", 0);
                sat = k.value("sat", 0);
                lgt = part == "marking" ? 0 : k.value("lgt", 0);
                alp = k.value("alp", 255);

                color = (color&0xFF00FFFF) | (hue << 16);
                color = (color&0xFFFF00FF) | (sat << 8);
                color = (color&0xFFFFFF00) | lgt;
                color = (color&0x00FFFFFF) | (alp << 24);

                std::string fname = k["filename"];
                fname.resize(24);
                std::strcpy(filename, fname.c_str());
                return;
            }
        }
        std::string fname("standard");
        fname.resize(24);
        std::strcpy(filename, fname.c_str());
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
            //m_pConsole->Print(IConsole::OUTPUT_LEVEL_DEBUG, "json", "success");
        }
        else
        {
            m_pConsole->Print(IConsole::OUTPUT_LEVEL_DEBUG, "json", filename.c_str());
        }
    }

    std::map<std::string, nlohmann::json> skins;
    IConsole* m_pConsole;
    const char* const partnames[6] = {"body", "marking", "decoration", "hands", "feet", "eyes"};
};

#endif // GAME_SERVER_SKINREADER_H
