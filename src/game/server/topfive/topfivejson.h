#ifndef GAME_SERVER_TOPFIVEJSON_H
#define GAME_SERVER_TOPFIVEJSON_H

#include "topfivebase.h"
#include "engine/external/nlohmann/json.hpp"

class CTopFiveJson : public ITopFive
{
    class CGameContext *m_pGameServer;
public:
    CTopFiveJson(CGameContext* pGameServer, int lifes, const std::string& mapname) : ITopFive(lifes, mapname){
        m_pGameServer = pGameServer;
        ReadJsonFile();
    }

    void SaveGameEntry() override;
    std::vector<STopFiveGameEntry> GetTopFive() override;
    STopFiveGameEntry& GetRank(const std::string& name, int& rank) override;
private:
    CGameContext *GameServer() const { return m_pGameServer; }

    void ReadJsonFile();
    void SaveJsonFile();
    std::vector<STopFiveGameEntry> m_Entries;
};

#endif // GAME_SERVER_TOPFIVEJSON_H
