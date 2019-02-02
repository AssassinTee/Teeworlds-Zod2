#ifndef GAME_SERVER_GAMEMODES_ZOD_H
#define GAME_SERVER_GAMEMODES_ZOD_H
#include <game/server/gamecontroller.h>

class CGameControllerZOD : public IGameController
{
public:
	//vec2 *m_pTeleporter;

	CGameControllerZOD(class CGameContext *pGameServer);

	//void InitTeleporter();
	//virtual void Snap(int SnappingClient);
	//virtual void Tick();
	virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);
};

#endif
