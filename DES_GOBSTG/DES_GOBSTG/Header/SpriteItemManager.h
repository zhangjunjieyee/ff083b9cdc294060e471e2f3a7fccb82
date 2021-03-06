#ifndef _SPRITEITEMMANAGER_H
#define _SPRITEITEMMANAGER_H

#include "MainDependency.h"
#include "DataStruct.h"

class SpriteItemManager
{
public:
	SpriteItemManager();
	~SpriteItemManager();

	static void Init();
	static void Release();
	static hgeSprite * CreateSprite(int index);
	static bool CreateSprite(int index, hgeSprite ** sprite);
	static bool ChangeSprite(int index, hgeSprite * sprite);
	static int GetIndexByName(const char * spritename);
	static hgeSprite * CreateSpriteByName(const char * spritename);
	static bool CreateSpriteByName(const char * spritename, hgeSprite ** sprite);
	static void FreeSprite(hgeSprite ** sprite);
	static spriteData * CastSprite(int index);

	static hgeSprite * CreateNullSprite();
	static bool SetSpriteData(hgeSprite * sprite, HTEXTURE tex, float texx, float texy, float texw, float texh, bool flipx=false, bool flipy=false);
	static bool SetSpriteTextureRect(hgeSprite * sprite, float texx, float texy, float texw, float texh);
	static bool SetSpriteFlip(hgeSprite * sprite, bool flipx=false, bool flipy=false);
	static bool SetSpriteHotSpot(hgeSprite * sprite, float hotx, float hoty);
	static bool SetSprite(int index, hgeSprite * sprite);

	static HTEXTURE GetTexture(int index);
	static float GetTexX(int index);
	static float GetTexY(int index);
	static float GetTexW(int index);
	static float GetTexH(int index);

	static bool ptFace(int index, hgeSprite * sprite, bool enemy = true);
	static bool ptName(int index, hgeSprite * sprite, bool enemy = true);

	static bool LoadTextureSetWhenNeeded(HTEXTURE tex);
	static void RenderSprite(hgeSprite * sprite, float x, float y);
	static void RenderSpriteEx(hgeSprite * sprite, float x, float y, float rot, float hscale=1.0f, float vscale=0.0f);
	static void FontPrintf(hgeFont * font, float x, float y, int align, const char * str);
	static void FontPrintfb(hgeFont * font, float x, float y, float w, float h, int align, const char * str);
	static void EffectSystemRender(hgeEffectSystem * eff);
	static void RenderQuad(hgeQuad * quad);

public:
	static int digituiIndex;

	static int faceIndexEnemy;
	static int nameIndexEnemy;
	static int faceIndexPlayer;
	static int nameIndexPlayer;

	static int yesIndex;
	static int noIndex;
	static int cancelIndex;
	static int confirmIndex;
	static int nullIndex;
};

#endif