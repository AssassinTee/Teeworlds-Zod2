
#ifndef GAME_SERVER_WAVE_H
#define GAME_SERVER_WAVE_H

//#include "player.h"//Zombie types
#include "engine/external/nlohmann/json.hpp"//I read json files!!!
#include "gamecontext.h"
#include <vector>
#include <random>

#define ZOMB_NUM 13

class CWave
{
    class CGameContext *m_pGameServer;
public:
    CWave(class CGameContext *pGameServer);
    ~CWave();
    void ReadFile(std::string filename);
    void Reset();
    void StartWave();
    int GetRandZombie();

    void ClearZombies();

    int GetWave(){return m_Wave;}//read only access

    void OnZombieKill();
    int GetZombAlive(){return m_ZombAlive;}

    void DoZombMessage();
	void DoLifeMessage(int Life);

private:
    CGameContext *GameServer() const { return m_pGameServer; }
    void ReadWave(std::string filename);
    void GetEndlessWave();

    nlohmann::json m_Json;
    const std::string m_JsonZombieNames[13];

    int m_Endless;
    std::vector<int> m_vWave;
    int m_Wave;
    int m_ZombLeft;
    int m_ZombAlive;

    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution;
};
#endif
