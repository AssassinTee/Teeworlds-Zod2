#ifndef GAME_SERVER_TOPFIVEBASE_H
#define GAME_SERVER_TOPFIVEBASE_H

#define TOP_FIVE_PLAYER_NUM_ENTRY 4

#include <vector>
#include <string>

struct STopFivePlayerEntry
{
    std::string name;
    int kills;
};

struct STopFiveGameEntry
{
    std::string mapname;
    int lifes;
    int wave;
    int kills;
    int entry_num;
    STopFivePlayerEntry player_entry[TOP_FIVE_PLAYER_NUM_ENTRY];
};

class ITopFive
{
public:
    ITopFive(int lifes, const std::string& mapname){
        Reset(lifes, mapname);
    }

    void Reset(int lifes, const std::string& mapname)
    {
        m_GameEntry.mapname = mapname;
        m_GameEntry.lifes = lifes;
        m_GameEntry.kills = 0;
        m_GameEntry.wave = 0;
        m_GameEntry.entry_num = 0;
        for(int i = 0; i < TOP_FIVE_PLAYER_NUM_ENTRY; ++i)
        {
            ResetPlayer(i);
        }
    }

    void IncreaseKills()
    {
        m_GameEntry.kills++;
    }

    void SetWave(int wave)
    {
        m_GameEntry.wave = wave;
    }

    void SetPlayerName(int index, const std::string& name)
    {
        m_GameEntry.player_entry[index].name = name;
    }

    void ResetPlayer(int index)
    {
        m_GameEntry.player_entry[index].name = "";
        m_GameEntry.player_entry[index].kills = 0;
    }

    void IncreasePlayerKill(int index)
    {
        m_GameEntry.player_entry[index].kills++;
    }

    virtual void SaveGameEntry() = 0;
    virtual std::vector<STopFiveGameEntry> GetTopFive() = 0;
    virtual STopFiveGameEntry& GetRank(const std::string& name, int& rank) = 0;

    STopFiveGameEntry& GetGameEntry() {return m_GameEntry;}

protected:
    STopFiveGameEntry m_GameEntry;
};

#endif // GAME_SERVER_TOPFIVEBASE_H
