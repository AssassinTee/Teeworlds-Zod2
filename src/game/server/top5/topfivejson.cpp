#include "topfivejson.h"
#include <fstream>

bool sortfunction(STopFiveGameEntry i,STopFiveGameEntry j)
{
    if(i.wave == j.wave)
    {
        if(i.kills == j.kills)
        {
            return i.entry_num < j.entry_num;
        }
        else
            return i.kills > j.kills;
    }
    else
        return i.wave > j.wave;
}

void CTopFiveJson::SaveGameEntry()
{
    SaveJsonFile();//2 hours debugging to find out, that this line is missing <.<
}

std::vector<STopFiveGameEntry> CTopFiveJson::GetTopFive()
{
    std::vector<STopFiveGameEntry> res;
    for(auto it = m_Entries.begin(); it != m_Entries.end(); ++it)
    {
        if(it->lifes == m_GameEntry.lifes)
        {
            res.push_back(*it);
        }
        if(res.size() == 5)
            break;
    }
    return res;
    //return m_Entries;
}

STopFiveGameEntry& CTopFiveJson::GetRank(std::string name, int& rank)
{
    for(size_t j = 0; j < m_Entries.size(); ++j)
    {
        if(m_Entries[j].lifes == m_GameEntry.lifes) {
            for(int i = 0; i < TOP_FIVE_PLAYER_NUM_ENTRY; ++i)
            {
                if(m_Entries[j].player_entry[i].name == name)
                {
                    rank = j;
                    return m_Entries[j];
                }
            }
        }
    }
    rank = -1;
    return m_GameEntry;
}

void CTopFiveJson::ReadJsonFile()
{
    std::string filename = "top5/";
    filename += m_GameEntry.mapname+".json";
    std::ifstream i(filename, std::ifstream::in);
    if(i.is_open())
    {
        nlohmann::json input;
        i >> input;
        for (nlohmann::json::iterator it = input.begin(); it != input.end(); ++it)
        {
            STopFiveGameEntry entry;
            entry.mapname = (*it)["mapname"];
            entry.entry_num = (*it)["entry_num"];
            entry.kills = (*it)["kills"];
            entry.lifes = (*it)["lifes"];
            entry.wave = (*it)["wave"];
            nlohmann::json player_entries = (*it)["player_entry"];
            for (int i = 0; i < TOP_FIVE_PLAYER_NUM_ENTRY; ++i)
            {
                nlohmann::json::iterator player_entry = player_entries.begin()+i;
                entry.player_entry[i].kills = (*player_entry)["kills"];
                entry.player_entry[i].name = (*player_entry)["name"];
            }
            m_Entries.push_back(entry);
        }
    }
    else
    {
        //SaveJsonFile();
    }
}

void CTopFiveJson::SaveJsonFile()
{
    std::string filename = "top5/";
    filename += m_GameEntry.mapname+".json";
    std::ofstream of(filename, std::ofstream::out);
    m_GameEntry.entry_num = m_Entries.size();
    m_Entries.push_back(m_GameEntry);
    std::sort(m_Entries.begin(), m_Entries.end(), sortfunction);
    nlohmann::json output;
    for(auto it = m_Entries.begin(); it != m_Entries.end(); ++it)
    {
        nlohmann::json game_entry, player_entries;
        game_entry["mapname"] = it->mapname;
        game_entry["wave"] = it->wave;
        game_entry["kills"] = it->kills;
        game_entry["lifes"] = it->lifes;
        game_entry["entry_num"] = it->entry_num;
        for(int i = 0; i < TOP_FIVE_PLAYER_NUM_ENTRY; ++i)
        {
            nlohmann::json player_entry;
            player_entry["kills"] = it->player_entry[i].kills;
            player_entry["name"] = it->player_entry[i].name;
            //game_entry.push_back(player_entry);
            //of << player_entry;
            player_entries.push_back(player_entry);
        }
        game_entry["player_entry"] = player_entries;
        output.push_back(game_entry);
    }

    of << output;
}
