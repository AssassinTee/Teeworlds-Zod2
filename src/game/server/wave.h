
#ifndef GAME_SERVER_WAVE_H
#define GAME_SERVER_WAVE_H

//#include "player.h"//Zombie types
#include "engine/external/nlohmann/json.hpp"//I read json files!!!
#include "gamecontext.h"
#include <vector>

#define ZOMB_NUM 13

class CWave
{
public:
    CWave();
    ~CWave();
    void ReadFile(std::string filename);
    std::vector<int> GetZombNum(int wave);

private:
    void ReadWave(std::string filename);
    std::vector<int> GetEndlessWave();
    nlohmann::json m_Json;
    const std::string m_JsonZombieNames[13];
    int m_Endless;
};
#endif
