#include "Includes.h"

LPDIRECT3DDEVICE9 pD3D9;    //D3D9 Device pD3D9
ID3DXFont*  pFont;          //D3D9 Device pFont
ID3DXFont*  pNFont;         //D3D9 Device pFont
ID3DXFont*  pWFont;			//D3D9 Device pFont
LPD3DXLINE  pLine;          //D3D9 Device pLine


#define LText (DT_LEFT|DT_NOCLIP)

class Menu
{
public:
	int x, y;
	int fx, fy;
	float FOVChoice;
	int HeadChoice;
	IDirect3DTexture9 *Primitive;
	void DirectEngine(LPDIRECT3DDEVICE9 pD3D9);
	void Text(int x, int y, LPSTR text, DWORD color, DWORD ST);
	void NewText(int x, int y, LPSTR text, DWORD color, DWORD ST);
	void DrawBox(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9);
	void DrawBorder(int x, int y, int w, int h, int s, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9);
	void Font(CHAR* FontName, DWORD Stile, LPDIRECT3DDEVICE9 pD3D9);
	void NFont(CHAR* FontName, DWORD Stile, LPDIRECT3DDEVICE9 pD3D9);
	void WFont(CHAR* FontName, DWORD Stile, LPDIRECT3DDEVICE9 pD3D9);
	void MyFolder(LPSTR fText, bool &Var, LPDIRECT3DDEVICE9 pD3D9);
	void DrawFolderMenu(int x, int y, LPSTR Text1, LPSTR Text2, LPDIRECT3DDEVICE9 pD3D9);
	void MyButtons(LPSTR fText, bool &Var, LPDIRECT3DDEVICE9 pD3D9);
	bool DrawMessage(LPD3DXFONT font, unsigned int x, unsigned int y, int alpha, unsigned char r, unsigned char g, unsigned char b, LPCSTR Message);
	void DrawLine(float x, float y, float x2, float y2, float width, DWORD color);
	void DrawHealthBar(INT x, INT y, FLOAT health, INT w, INT h, INT s, D3DCOLOR color, D3DCOLOR frame, LPDIRECT3DDEVICE9 pD3D9);
	void Engine_Scroll(int &studio, char **typ, int max, LPSTR text, IDirect3DDevice9* pD3D9);
}M;

void MEMwrite(void *adr, void *ptr, int size)
{
	DWORD OldProtection;
	VirtualProtect(adr, size, PAGE_EXECUTE_READWRITE, &OldProtection);
	memcpy(adr, ptr, size);
	VirtualProtect(adr, size, OldProtection, &OldProtection);
}

struct MyVar
{
public:
	bool Create, Show;
	bool SelfMenu, AimbotMenu, ESPMenu,TeleportMenu, MiscMenu;
	int FOV;
	int headscroll;

	struct FuncVar//tout les boutons
	{
	public:
		bool AimbotBouton, Shutter, Damage, noSound, Telekill, Kasper, NoReculBouton, WH, AutoshootButton, Knife, PVEKick, NoFlash, AutoClimbButton, SlideButton, CrouchFast, NoClaymore,
			Sprint, Ammo, Notification, NameESP, DistanceESP, HealthBar, Skeleton, BoxESP, Silhouettes, Lines, ExplosiESP, Preset, SilentAim, DBoxESP, Shit;
	}Bouton;

}MV;

static struct _Keys
{
	bool        bPressed;
	DWORD       dwStartTime;
}kPressingKeys[256];

struct SelfBools
{
public:
	bool Shutter = false;
	bool Accuracy = false;
	bool minimap = false;
	bool pickup = false;
	bool Damage = false;
	bool Kasper = false;
	bool Telekill = false;
	bool Knife = false;
	bool PveKick = false;
	bool noSound = false;
	bool flash = false;
	bool WH = false;
	bool aimbot = false;
	bool autoshoot = false;
	bool recul = false;
	bool Climb = false;
	bool Slide = false;
	bool NoClaymore = false;
	bool Sprint = false;
	bool shit = false;
	bool Ammo = false;
	bool Notification = false;
	bool NameESP = false;
	bool DistanceESP = false;
	bool HealthBar = false;
	bool Skeleton = false;
	bool BoxESP = false;
	bool DBoxESP = false;
	bool Silhouettes = false;
	bool Lines = false;
	bool ExplosiESP = false;
	bool Preset = false;
	bool SilentAim = false;
}SelfBools;