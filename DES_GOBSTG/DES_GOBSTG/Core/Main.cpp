#include "vld.h"

#include "../Header/Process.h"
#include "../Header/Fontsys.h"

#include "../Header/Main.h"

HGE *hge = NULL;

int gametime = 0;

DWORD strdescIndex = 0;

bool RenderFunc()
{
//	Export::clientSetMatrix(worldx, worldy, worldz);

	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0x00000000);

	Process::mp.render();
	hge->Gfx_EndScene();
	
	return false;
}

bool FrameFunc()
{
	if (hge->Input_GetDIKey(KS_ESCAPE_MP))
		return true;
	if(hge->Input_GetDIKey(KS_CAPTURE_MP, DIKEY_DOWN))
	{
		Process::mp.SnapShot();
	}

	if(Process::mp.frame() == PQUIT)
		return true;

	return false;
}

bool FocusGainFunc()
{
	Fontsys::fontsys.FocusChanged();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);
	
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_FOCUSGAINFUNC, FocusGainFunc);

	Export::clientInitial(true);

	if(hge->System_Initiate())
	{
		gametime = 0;
		Process::mp.state = STATE_INIT;
		hge->System_Start();
	}

	//
	Process::mp.Realease();

//	hge->System_Shutdown();
	hge->Release();
	
	return 0;
}