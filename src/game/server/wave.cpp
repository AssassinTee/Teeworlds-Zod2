#include "wave.h"
#include <fstream>
#include <string>

CWave::CWave() : m_JsonZombieNames({"Zaby", "Zoomer", "Zooker", "Zamer", "Zunner", "Zaster", "Zotter", "Zenade", "Flombie", "Zinja", "Zele", "Zinvis", "Zeater"})
{
    m_Endless = 0;
}

CWave::~CWave()
{

}

void CWave::ReadFile(std::string filename)
{
    ReadWave(filename);
}

void CWave::ReadWave(std::string filename)
{
    using nlohmann::json;
    std::ifstream i(filename);
    i >> m_Json;
}

std::vector<int> CWave::GetZombNum(int wave)
{
    using nlohmann::json;
    std::string wave_str= std::to_string(wave);
    json waves = m_Json.at("Waves");
    //GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_DEBUG, "debug", aBuf);
    json curwave = waves.at(wave_str);
    if(true)
    {
        json j = curwave;//*it;
        std::vector<int> result;
        for(int i = 0; i < 13; ++i)
        {
            result.push_back(j.value(m_JsonZombieNames[i], 0));
        }
        return result;
    }
    else
        return GetEndlessWave();
}

std::vector<int> CWave::GetEndlessWave()
{
    m_Endless++;
    std::vector<int> result;
    for(int i = 0; i < 13; ++i)
    {
        result.push_back(m_Endless*5);
    }
    return result;
}
