#pragma once
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dx9core.h>
#include <math.h>
#include <DbgHelp.h>
#include <Mmsystem.h>
#include <ShellAPI.h>
#include <fstream>
#include <iostream>
#include <iosfwd>
#include <vector>
#include <intrin.h>
#include "MenuClasses.h"
#include "DrawElements.h"
#include "DrawMenu.h"
#include "Tools.h"
#include <string>
#include "Classes.h"
#include "MinHook/include/MinHook.h"
#include <ctime>
#define VK_CAPS 0x14
#ifndef _WIN32_WINNT            
#define _WIN32_WINNT 0x0500     
#endif

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")
#include <random>
#include <sstream>
#include <io.h>
#include <iostream>
#include <future>

#include "protec\VirtualizerSDK.h"
#include < Assert.h >
#include < List >
#include < Map >
#include <process.h>
#include <tlhelp32.h>
#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
using namespace std;

#pragma comment (lib, "d3d9.lib" )
#pragma comment (lib, "d3dx9.lib" )
#pragma comment (lib, "dxguid.lib" )
#pragma comment (lib, "WinMM.Lib")
#pragma warning (disable:4996)
#pragma warning (disable: 4244)
#pragma warning (disable : 4099)
#include < algorithm >
#include <intrin.h>
#pragma intrinsic(_ReturnAddress)

using namespace std;

#define ILINE __forceinline
typedef float f32;
typedef double f64;
typedef unsigned short  uint16;
typedef unsigned __int64 uint64;
typedef unsigned int     uint32;
typedef unsigned char  uint8;
typedef signed __int64 int64;
typedef signed __int32 int32;
typedef signed __int8 int8;

template <typename Counter> class _i_reference_target
{
public:
	_i_reference_target() :
		m_nRefCounter(0)
	{
	}

	virtual ~_i_reference_target()
	{
	}

	virtual void AddRef()
	{
		++m_nRefCounter;
	}

	virtual void Release()
	{
		if (--m_nRefCounter == 0)
		{
			delete this;
		}
		else if (m_nRefCounter < 0)
		{
			assert(0);
		}
	}

	// Warning: use for debugging/statistics purposes only!
	Counter NumRefs()	const
	{
		return m_nRefCounter;
	}
protected:
	Counter m_nRefCounter;
};

typedef _i_reference_target<int> _i_reference_target_t;

typedef unsigned int                uint;
typedef signed char                    int8;
typedef signed short                int16;
typedef signed int                    int32;
typedef signed __int64                int64;
typedef unsigned char                uint8;
typedef unsigned char                BYTE;
typedef unsigned short                uint16;
typedef unsigned int                uint32;
typedef unsigned __int64            uint64;
typedef float                        f32;
typedef double                        f64;
typedef double                        real;


struct DirectX9VTable
{
	DWORD QueryInterface; // 0
	DWORD AddRef; // 1
	DWORD Release; // 2
	DWORD TestCooperativeLevel; // 3
	DWORD GetAvailableTextureMem; // 4
	DWORD EvictManagedResources; // 5
	DWORD GetDirect3D; // 6
	DWORD GetDeviceCaps; // 7
	DWORD GetDisplayMode; // 8
	DWORD GetCreationParameters; // 9
	DWORD SetCursorProperties; // 10
	DWORD SetCursorPosition; // 11
	DWORD ShowCursor; // 12
	DWORD CreateAdditionalSwapChain; // 13
	DWORD GetSwapChain; // 14
	DWORD GetNumberOfSwapChains; // 15
	DWORD Reset; // 16
	DWORD Present; // 17
	DWORD GetBackBuffer; // 18
	DWORD GetRasterStatus; // 19
	DWORD SetDialogBoxMode; // 20
	DWORD SetGammaRamp; // 21
	DWORD GetGammaRamp; // 22
	DWORD CreateTexture; // 23
	DWORD CreateVolumeTexture; // 24
	DWORD CreateCubeTexture; // 25
	DWORD CreateVertexBuffer; // 26
	DWORD CreateIndexBuffer; // 27
	DWORD CreateRenderTarget; // 28
	DWORD CreateDepthStencilSurface; // 29
	DWORD UpdateSurface; // 30
	DWORD UpdateTexture; // 31
	DWORD GetRenderTargetData; // 32
	DWORD GetFrontBufferData; // 33
	DWORD StretchRect; // 34
	DWORD ColorFill; // 35
	DWORD CreateOffscreenPlainSurface; // 36
	DWORD SetRenderTarget; // 37
	DWORD GetRenderTarget; // 38
	DWORD SetDepthStencilSurface; // 39
	DWORD GetDepthStencilSurface; // 40
	DWORD BeginScene; // 41
	DWORD EndScene; // 42
	DWORD Clear; // 43
	DWORD SetTransform; // 44
	DWORD GetTransform; // 45
	DWORD MultiplyTransform; // 46
	DWORD SetViewport; // 47
	DWORD GetViewport; // 48
	DWORD SetMaterial; // 49
	DWORD GetMaterial; // 50
	DWORD SetLight; // 51
	DWORD GetLight; // 52
	DWORD LightEnable; // 53
	DWORD GetLightEnable; // 54
	DWORD SetClipPlane; // 55
	DWORD GetClipPlane; // 56
	DWORD SetRenderState; // 57
	DWORD GetRenderState; // 58
	DWORD CreateStateBlock; // 59
	DWORD BeginStateBlock; // 60
	DWORD EndStateBlock; // 61
	DWORD SetClipStatus; // 62
	DWORD GetClipStatus; // 63
	DWORD GetTexture; // 64
	DWORD SetTexture; // 65
	DWORD GetTextureStageState; // 66
	DWORD SetTextureStageState; // 67
	DWORD GetSamplerState; // 68
	DWORD SetSamplerState; // 69
	DWORD ValidateDevice; // 70
	DWORD SetPaletteEntries; // 71
	DWORD GetPaletteEntries; // 72
	DWORD SetCurrentTexturePalette; // 73
	DWORD GetCurrentTexturePalette; // 74
	DWORD SetScissorRect; // 75
	DWORD GetScissorRect; // 76
	DWORD SetSoftwareVertexProcessing; // 77
	DWORD GetSoftwareVertexProcessing; // 78
	DWORD SetNPatchMode; // 79
	DWORD GetNPatchMode; // 80
	DWORD DrawPrimitive; // 81
	DWORD DrawIndexedPrimitive; // 82
	DWORD DrawPrimitiveUP; // 83
	DWORD DrawIndexedPrimitiveUP; // 84
	DWORD ProcessVertices; // 85
	DWORD CreateVertexDeclaration; // 86
	DWORD SetVertexDeclaration; // 87
	DWORD GetVertexDeclaration; // 88
	DWORD SetFVF; // 89
	DWORD GetFVF; // 90
	DWORD CreateVertexShader; // 91
	DWORD SetVertexShader; // 92
	DWORD GetVertexShader; // 93
	DWORD SetVertexShaderConstantF; // 94
	DWORD GetVertexShaderConstantF; // 95
	DWORD SetVertexShaderConstantI; // 96
	DWORD GetVertexShaderConstantI; // 97
	DWORD SetVertexShaderConstantB; // 98
	DWORD GetVertexShaderConstantB; // 99
	DWORD SetStreamSource; // 100
	DWORD GetStreamSource; // 101
	DWORD SetStreamSourceFreq; // 102
	DWORD GetStreamSourceFreq; // 103
	DWORD SetIndices; // 104
	DWORD GetIndices; // 105
	DWORD CreatePixelShader; // 106
	DWORD SetPixelShader; // 107
	DWORD GetPixelShader; // 108
	DWORD SetPixelShaderConstantF; // 109
	DWORD GetPixelShaderConstantF; // 110
	DWORD SetPixelShaderConstantI; // 111
	DWORD GetPixelShaderConstantI; // 112
	DWORD SetPixelShaderConstantB; // 113
	DWORD GetPixelShaderConstantB; // 114
	DWORD DrawRectPatch; // 115
	DWORD DrawTriPatch; // 116
	DWORD DeletePatch; // 117
	DWORD CreateQuery; // 118
};