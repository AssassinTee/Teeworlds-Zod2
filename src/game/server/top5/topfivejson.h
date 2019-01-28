#ifndef GAME_SERVER_TOPFIVEJSON_H
#define GAME_SERVER_TOPFIVEJSON_H

#include "topfivebase.h"
#include "../tools/json.hpp"

class CTopFiveJson : public ITopFive
{
public:
    CTopFiveJson(int lifes, std::string mapname) : ITopFive(lifes, mapname){
        ReadJsonFile();
    }

    void SaveGameEntry() override;
    std::vector<STopFiveGameEntry> GetTopFive() override;
private:
    void ReadJsonFile();
    void SaveJsonFile();
    std::vector<STopFiveGameEntry> m_Entries;
};

#endif // GAME_SERVER_TOPFIVEJSON_H
