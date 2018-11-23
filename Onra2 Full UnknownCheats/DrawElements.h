void Menu::Font(CHAR* FontName,  DWORD Stile, LPDIRECT3DDEVICE9 pD3D9)
{
	D3DXCreateFont(pD3D9, 15, 0, Stile, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, FontName, &pFont);
}

void Menu::NFont(CHAR* FontName,  DWORD Stile, LPDIRECT3DDEVICE9 pD3D9)
{
	D3DXCreateFont(pD3D9, 15, 0, Stile, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, FontName , &pNFont);
}

void Menu::WFont(CHAR* FontName, DWORD Stile, LPDIRECT3DDEVICE9 pD3D9)
{
	D3DXCreateFont(pD3D9, 20, 0, Stile, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_MODERN, FontName, &pWFont);
}

struct D3DTLVERTEX
{
	float x, y, z, rhw;
	DWORD color;
};

void  Menu::Text(int x, int y, LPSTR text,DWORD color, DWORD ST)
{
	RECT rect, rect2;
	SetRect(&rect, x, y, x, y);
	SetRect(&rect2, x - 0.1, y + 0.2, x - 0.1, y + 0.);
	pFont->DrawTextA(NULL, text, -1, &rect2, ST, 0x00000000);
	pFont->DrawTextA(NULL, text, -1, &rect, ST, color);
}

void  Menu::NewText(int x, int y, LPSTR text, DWORD color, DWORD ST)
{
	RECT rect, rect2;
	SetRect(&rect, x, y, x, y);
	SetRect(&rect2, x - 0.1, y + 0.2, x - 0.1, y + 0.);
	pNFont->DrawTextA(NULL, text, -1, &rect2, ST, 0x00000000);
	pNFont->DrawTextA(NULL, text, -1, &rect, ST, color);
}

void  Menu::DrawBox(int x, int y, int w, int h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	struct Vertex
	{
		float x, y, z, ht;
		DWORD Color;
	}
	V[4] = { { x, y + h, 0.0f, 0.0f, Color }, { x, y, 0.0f, 0.0f, Color }, { x + w, y + h, 0.0f, 0.0f, Color }, { x + w, y, 0.0f, 0.0f, Color } };
	pD3D9->SetTexture(0, NULL);
	pD3D9->SetPixelShader(0);
	pD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	pD3D9->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3D9->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3D9->SetRenderState(D3DRS_ZENABLE, FALSE);
	pD3D9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, V, sizeof(Vertex));
	return;
}

void Menu::DrawBorder(int x, int y, int w, int h, int s, D3DCOLOR Color, LPDIRECT3DDEVICE9 pD3D9)
{
	DrawBox(x - s, y, s, h, Color, pD3D9);
	DrawBox(x - s, y + h, w + s * 2, s, Color, pD3D9);
	DrawBox(x - s, y - s, w + s * 2, s, Color, pD3D9);
	DrawBox(x + w, y, s, h + s, Color, pD3D9);
}

void Menu::DrawLine(float x, float y, float x2, float y2, float width, DWORD color)
{
	D3DXVECTOR2 vLine[2];
	pLine->SetWidth(width);
	pLine->SetAntialias(false);
	pLine->SetGLLines(true);
	vLine[0].x = x;
	vLine[0].y = y;
	vLine[1].x = x2;
	vLine[1].y = y2;
	pLine->Begin();
	pLine->Draw(vLine, 2, color);
	pLine->End();

	return;
}

void Line(float x, float y, float x2, float y2, float width, DWORD color)
{
	D3DXVECTOR2 vLine[2];
	pLine->SetWidth(width);
	pLine->SetAntialias(false);
	pLine->SetGLLines(true);
	vLine[0].x = x;
	vLine[0].y = y;
	vLine[1].x = x2;
	vLine[1].y = y2;
	pLine->Begin();
	pLine->Draw(vLine, 2, color);
	pLine->End();

	return;
}

void Menu::DrawHealthBar(INT x, INT y, FLOAT health, INT w, INT h, INT s, D3DCOLOR color, D3DCOLOR frame, LPDIRECT3DDEVICE9 pD3D9)
{
	DrawBorder(x, y, w, h, s, frame, pD3D9);
	UINT hw = (UINT)(((w - 2)*health) / 100);
	DrawBox(x + 1, y + 1, hw, h - 1, color, pD3D9);
}

/*==============================================================*/

BOOL  IsInBox(int x, int y, int w, int h)
{
	POINT MousePosition;
	GetCursorPos(&MousePosition);
	ScreenToClient(GetForegroundWindow(), &MousePosition);
	return(MousePosition.x >= x && MousePosition.x <= x + w && MousePosition.y >= y && MousePosition.y <= y + h);
}

void DrawGradient(int x, int y, int w, int h, DWORD one, DWORD two, LPDIRECT3DDEVICE9 pD3D9)
{
	struct D3DVERTEX
	{
		float x, y, z, rhw;
		DWORD color;
	};

	D3DVERTEX   vertices[4] =
	{
		{ x, y, w, h, one },
		{ x, y, w, h, one },
		{ x, y, w, h, one },
		{ x, y, w, h, one }
	};

	vertices[0].x = x;
	vertices[0].y = y;
	vertices[0].rhw = 1.0f;
	vertices[0].color = one;

	vertices[1].x = x + w;
	vertices[1].y = y;
	vertices[1].rhw = 1.0f;
	vertices[1].color = one;

	vertices[2].x = x;
	vertices[2].y = y + h;
	vertices[2].rhw = 1.0f;
	vertices[2].color = two;

	vertices[3].x = x + w;
	vertices[3].y = y + h;
	vertices[3].rhw = 1.0f;
	vertices[3].color = two;


	pD3D9->SetTexture(0, NULL);
	pD3D9->SetPixelShader(0);
	pD3D9->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	pD3D9->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	pD3D9->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	pD3D9->SetRenderState(D3DRS_ZENABLE, FALSE);
	pD3D9->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	pD3D9->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, vertices, sizeof(D3DVERTEX));


}

BOOL  State_Key(int Key, DWORD dwTimeOut)
{
	if (HIWORD(GetKeyState(Key)))
	{
		if (!kPressingKeys[Key].bPressed || (kPressingKeys[Key].dwStartTime && (kPressingKeys[Key].dwStartTime + dwTimeOut) <= GetTickCount()))
		{
			kPressingKeys[Key].bPressed = TRUE;
			if (dwTimeOut > NULL)
				kPressingKeys[Key].dwStartTime = GetTickCount();
			return TRUE;
		}
	}
	else
		kPressingKeys[Key].bPressed = FALSE;
	return FALSE;
}

void Menu::DrawFolderMenu(int x, int y,LPSTR Title,LPSTR Title2, LPDIRECT3DDEVICE9 pD3D9)
{
	DrawBox(x, y, 220, 20, D3DCOLOR_ARGB(255, 219, 96, 8), pD3D9);
	Text(x + 70, y + 2, Title, D3DCOLOR_ARGB(255, 255, 255, 255), LText);
}

LPSTR On;
void Menu::MyFolder(LPSTR fText,bool &Var,LPDIRECT3DDEVICE9 pD3D9)
{
	int px=x,py=M.y+25;
	
	D3DCOLOR BOXCOL = D3DCOLOR_ARGB(255, 219, 96, 8),
	TextColor = D3DCOLOR_ARGB(255, 255, 255, 255);

	if (IsInBox(px, py, 220, 20))
	{
		BOXCOL = D3DCOLOR_ARGB(255, 255, 255, 255),
		TextColor = D3DCOLOR_ARGB(255, 0, 0, 0);
		px = x - 2;
		if (State_Key(VK_LBUTTON, 300))//les menus
		{
			MV.SelfMenu = MV.AimbotMenu = MV.MiscMenu = MV.ESPMenu = 0;
			Var = !Var;
		}
	}

	if (Var==true)
		{

		BOXCOL = D3DCOLOR_ARGB(255, 255, 255, 255),
		TextColor = D3DCOLOR_ARGB(255, 0, 0, 0);
		px = x - 2;
			On = "Close";
		}
	else On = "";


	M.y = y + 23;
	
	DrawBox(px,py, 220, 20, BOXCOL, pD3D9);
	Text(px + 30, py+1, fText,TextColor,LText);
	Text(px + 145, py + 1, On, TextColor, LText);
}

void Menu::MyButtons(LPSTR fText, bool &Var, LPDIRECT3DDEVICE9 pD3D9)
{
	int px = fx, py = fy + 25;

	D3DCOLOR BOXCOL = D3DCOLOR_ARGB(255, 219, 96, 8),
		TextColor = D3DCOLOR_ARGB(255, 255, 255, 255);

	if (IsInBox(px, py, 220, 20))
	{
		BOXCOL = D3DCOLOR_ARGB(255, 255, 255, 255),
			TextColor = D3DCOLOR_ARGB(255, 0, 0, 0);
		px = fx - 2;
		if (State_Key(VK_LBUTTON, 300))
		{
			Var = !Var;
		}

	}

	if (Var == true)
	{
		BOXCOL = D3DCOLOR_ARGB(255, 24, 145, 000),
		TextColor = D3DCOLOR_ARGB(255, 0, 0, 0);
		px = fx - 2;
		On = "ON";
	}
	else On = "";


	M.fy = fy + 23;

	DrawBox(px, py, 220, 20, BOXCOL, pD3D9);
	Text(px + 30, py + 1, fText, TextColor, LText);
	Text(px + 180, py + 1, On, TextColor, LText);
}

void Menu::Engine_Scroll(int  &studio, char **typ, int max, LPSTR text, IDirect3DDevice9* pD3D9)
{
	int px = fx, py = fy + 25;

	if (IsInBox(px + 210, py + 2, 9, 15) && (State_Key(VK_LBUTTON, 1000)))
	{
		if (studio >= 0 && studio<max)
		{
			studio++;
		}
	}

	if (IsInBox(px + 165, py + 2, 9, 15) && (State_Key(VK_LBUTTON, 1000)))
	{
		if (studio != 0)
		{
			studio--;
		}
	}

	M.fy = fy + 23;

	DrawBorder(px, py, 220, 20, 1, D3DCOLOR_ARGB(255, 219, 96, 8), pD3D9);//orange
	DrawBox(px, py, 219, 19, D3DCOLOR_ARGB(150, 000, 000, 000), pD3D9);//black transpa
	Text(px + 30, py + 1, text, D3DCOLOR_ARGB(255, 000, 255, 000), LText);
	Text(px + 165, py + 2, "«", D3DCOLOR_ARGB(255, 255, 255, 255), LText);
	Text(px + 178, py + 2, typ[studio], D3DCOLOR_ARGB(255, 000, 255, 000), LText);
	Text(px + 210, py + 2, "»", D3DCOLOR_ARGB(255, 255, 255, 255), LText);//238
}

bool Menu::DrawMessage(LPD3DXFONT font, unsigned int x, unsigned int y, int alpha, unsigned char r, unsigned char g, unsigned char b, LPCSTR Message)
{	// Create a colour for the text
	D3DCOLOR fontColor = D3DCOLOR_ARGB(alpha, r, g, b);
	RECT rct; //Font
	rct.left = x;
	rct.right = 1680;
	rct.top = y;
	rct.bottom = rct.top + 200;
	font->DrawTextA(NULL, Message, -1, &rct, 0, fontColor);
	return true;
}
