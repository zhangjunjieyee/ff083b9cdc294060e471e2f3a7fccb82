#ifndef _PLAYERBULLET_H
#define _PLAYERBULLET_H

#define PBLOCK_LOST		0xffff
#define PBLOCK_GHOST	0x8000


#define PBFLAG_BEAM				0x0001
#define PBFLAG_CHASE			0x0002
#define PBFLAG_DELAY			0x0004
#define PBFLAG_RANDOMANGLE		0x0008
#define PBFLAG_TURN				0x0010
#define PBFLAG_TURNWHILEDELAY	0x0020
#define PBFLAG_HEADUPWARD		0x0040
#define PBFLAG_ANTISHOOTER		0x0080
#define PBFLAG_PREMASK			0x00ff

#define PBFLAG_OUTTURN			0x0100
#define PBFLAG_ANIMATION		0x0200
#define PBFLAG_REBOUND			0x0400
#define PBFLAG_EXPLODE			0x0800
#define PBFLAG_SCALEUP			0x1000
#define PBFLAG_POSTMASK			0xff00

#define PB_FADEOUTTIME		32

#include "BObject.h"

class PlayerBullet : public BObject
{
public:
	PlayerBullet();
	~PlayerBullet();

	static void Init();
	static void Build(int shootdataID);
	static void Action();
	static void ClearAll();

	void valueSet(WORD ID, BYTE arrange, float xbias, float ybias, float scale, int angle, float speed, float accelspeed, float power, int hitonfactor, WORD flag, BYTE seID);

	void action();

	static void RenderAll();
	void Render();

	void hitOn();
	bool isInRange(float aimx, float aimy, float w, float h=0.0f);

	void Lock();

	void DelayShoot();
	void TurnBullet(float mul=1.0f);

	static bool GetLockAim(BObject ** obj);
	static void Release();

public:
	float	oldspeed;
	float	accelspeed;
	float	xplus;
	float	yplus;

	float	xbias;
	float	ybias;
	float	scale;

	bool	fadeout;
	bool	able;
	float	power;

	int		locktimer;
	int		hitonfactor;
	int		animation;

	WORD	flag;

	BYTE	arrange;

	static hgeSprite * sprite[PLAYERSHOOTTYPEMAX][PLAYERBULLETTYPE];
	static DWORD bcol0, bcol1, bcol2, bcol3;
	static int locked;
	static WORD beams;

	static VectorList<PlayerBullet>pb;
};

#endif