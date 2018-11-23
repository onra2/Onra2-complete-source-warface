#pragma once
#include "Maths.h"
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <map>
#pragma region sheh
#define IGameFramework_Address 0x1B29194 //Failed to create the GameFramework Interface!
#define SSystemGlobalEnvironment__GlobalAdr 0x18F32F0 //ai_compatabilityMode
#define SSystemGlobalEnvironment__pIPhysicalWorld 0x44 //RayWorldIntersection(Game)
#define SSystemGlobalEnvironment__pIRenderer 0x30 //Draw2dLine
#define SSystemGlobalEnvironment__pIGame 0x70 //IsPlayer
#define SSystemGlobalEnvironment__GetI3DEngine 0x88 //Dof_Active
#define SSystemGlobalEnvironment__GetITimer 0x2C //GetFrameTime (this + 96 at the top)
#define SSystemGlobalEnvironment__GetIEntitySystem 0x78 //GetEntities
//ssglobal + 120 ientitysystem
/////////POSITION/////////////////////
#define IGF__GetClientActor 0x238 / 4 //sp_difficulty (2 lines above)
#define IEntitySystem_GetEntityIt 0x50 / 4 //GetEntitiesByClass (second SSGE)
#define IEntitySystem_GetEntityByName 0x30 / 4 //GetEntityByName(a2 = ...)
#define IEntityIt_Next 0x18 / 4 //GameObjectSystem (i = ...)
#define IEntity___SetPos 0x54 / 4 //SetWorldPos
#define IEntity__SetLocalPos 0x6C / 4 //SetLocalPos
#define IEntity__SetSlotLocalTM 0x130 / 4 //SetSlotPos
#define IEntity__GetWorldBBox 0x64 / 4 //GetWorldBoundsCenter (v3 + ..., before the __asm stuff)
#define IEntity__SetName 0x2C / 4 //SetName
#define IEntity__SetScale 0x7C / 4 //SetVecScale
#define IEntity___GetCharacter 0x148 / 4 //RgtArm01 (v4, the first one tout au dessu)
#define ISkeletonPose__GetAbsJointByID 0x1C / 4 //RgtArm01 (v7, the third one)
#define ISkeletonPose__GetJointNameByID 0xC0 / 4 //
#define V_GetISkeletonPose 0x14 / 4 //RgtArm01 (v6, the second one)
#define V_GetProxy 0xEC / 4 //CreateRenderProxy (the first one with !)
#define ISystem__GetCamera 0x1B4 / 4 //GetViewCameraPos
#define ITimer_GetFrameTime 0x1C / 4 //mat_water (SSGE at the top 2 lines above the sub call)
#define V_SetPostEffectParamI 0x23C / 4 //Dof_Active
#define IEntityRenderProxy__SetHUDSilhouettesParams 0xB0 / 4 //HudSilhouettes_Type (v10 + ...)
#define IActor__GetPlayer 0x8F8 //SetViewRotation (first one)
///////////////////////////////
#define V_Shutter 0x8A
#define V_SetRecoilMult 752 //-
#define V_OffRecoil 756 //-
#define V_SetRecoil 748 //-
#define V_CameraSway 4
//////////OFFSET//////////////////
#define V_GetIWeapon 0x14
///////////////////////////////
#define V_GetCurrentClass 0x328
#define V_StartFire 0x2C / 4 //CScriptBind_Weapon::AutoShoot (first)
#define V_StopFire 0x30 / 4 //CScriptBind_Weapon::AutoShoot (second)
#define Off_PickupDistance 0x1CD //i_pickupDistance
///////////////////////////////
#define IGameRules__GetTeam 0x1B0 / 4 //GetTeam (if v3)
#define IGameRules__SetTeam 0x1A8 / 4 //SetTeam (if v4)
#define IGameRules__GetIBombSystem 0x234 //SetIBombSystem
#define IGameRules__AttackersTeam 0x224 //getAttackersTeam
#define IGameRules__DefendersTeam 0x168
#define V_GetCurrentGameRules 0x618 //
#define V_ProjectScreen 0x178 / 4 //ProjectToScreen
#define IPW_RWI 0x88 / 4 //RayWorldIntersection
///////////////////////////////
#define jsp 0xA4D1

template< typename cData >
cData vFun_Call(PVOID BaseClass, DWORD vOFFSET)
{
	PDWORD* vPointer = (PDWORD*)BaseClass;
	PDWORD vFunction = *vPointer;
	DWORD dwAddress = vFunction[vOFFSET];
	return (cData)(dwAddress);
}
#pragma endregion
class SSystemGlobalEnvironment;
class I3DEngine;
class IGame;
class IActorSystem;
class ICVar;
class IRenderer;
class IEntitySystem;
class IEntity;
class IEntityClassRegistry;
class IPhysicalWorld;
class ITimer;
class ISystem;
class IPhysicalEntity;
struct HitInfo;
class SSystemGlobalEnvironment
{
public:
	char pad_0x0000[0x30]; //0x0000
	IRenderer* pRenderer; //0x0030 
	char pad_0x0034[0x10]; //0x0034
	IPhysicalWorld* pPhysicalWorld; //0x0044
	char pad_0x0048[0x28]; //0x0048
	IGame* pIGame; //0x0070 
	char pad_0x0074[0x4]; //0x0074
	IEntitySystem* pEntitySystem; //0x0078 
	char pad_0x007C[0xC]; //0x007C
	I3DEngine* p3DEngine; //0x0088 
	char pad_0x008C[0x34]; //0x008C
};

class I3DEngine
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual void Function86(); //
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual void Function91(); //
	virtual void Function92(); //
	virtual void Function93(); //
	virtual void Function94(); //
	virtual void Function95(); //
	virtual void Function96(); //
	virtual void Function97(); //
	virtual void Function98(); //
	virtual void Function99(); //
	virtual void Function100(); //
	virtual void Function101(); //
	virtual void Function102(); //
	virtual void Function103(); //
	virtual void Function104(); //
	virtual void Function105(); //
	virtual void Function106(); //
	virtual void Function107(); //
	virtual void Function108(); //
	virtual void Function109(); //
	virtual void Function110(); //
	virtual void Function111(); //
	virtual void Function112(); //
	virtual void Function113(); //
	virtual void Function114(); //
	virtual void Function115(); //
	virtual void Function116(); //
	virtual void Function117(); //
	virtual void Function118(); //
	virtual void Function119(); //
	virtual void Function120(); //
	virtual void Function121(); //
	virtual void Function122(); //
	virtual void Function123(); //
	virtual void Function124(); //
	virtual void Function125(); //
	virtual void Function126(); //
	virtual void Function127(); //
	virtual void Function128(); //
	virtual void Function129(); //
	virtual void Function130(); //
	virtual void Function131(); //
	virtual void Function132(); //
	virtual void Function133(); //
	virtual void Function134(); //
	virtual void Function135(); //
	virtual void Function136(); //
	virtual void Function137(); //
	virtual void Function138(); //
	virtual void Function139(); //
	virtual void Function140(); //
	virtual void Function141(); //
	virtual void Function142(); //
	virtual void SetPostEffectParam(const char *pParam, float fValue, bool bForceValue = false); //virtual void Function143(); //
}; //Size=0x0004

struct CPlayer
{
	char unknown0[164]; //
	Quat m_viewQuat; //0x00A4
	Quat m_viewQuatFinal; //0x00B4
	Quat m_BaseQuat; //0x00C4
	bool m_timeDemo; //0x00D4
	bool m_ignoreRecoil; //0x00D5
	char unknown1[2]; //0x00D6
	Vec3 m_viewAngleOffset; //0x00D8

	Quat GetViewRotation() { return m_viewQuatFinal; }

	void SetViewRotation(Quat &rotation) {
		m_BaseQuat = rotation;
		m_viewQuat = rotation;
		m_viewQuatFinal = rotation;
	}
};

enum EStance {
	STANCE_NULL = -1,
	STANCE_STAND = 0,
	STANCE_CROUCH,
	STANCE_PRONE,
	STANCE_RELAXED,
	STANCE_STEALTH,
	STANCE_LOW_COVER,
	STANCE_ALERTED,
	STANCE_HIGH_COVER,
	STANCE_SWIM,
	STANCE_ZEROG,
	STANCE_LAST
};

struct SStanceState {
	Vec3 pos;///0-8
	Vec3 entityDirection;//c-14
	Vec3 animationBodyDirection;//18-20
	Vec3 upDirection;//24-2C
	Vec3 weaponPosition;//30-38
	Vec3 aimDirection;//3C-44
	Vec3 fireDirection;//48-50
	Vec3 eyePosition;//54-5C
	Vec3 eyeDirection;//60-68
	float lean;//6C
	float peekOver;//70
	AABB m_StanceSize;//74-88
	AABB m_ColliderSize;//8C-94,98-A0
};

struct SMovementState : public SStanceState {
	DWORD Unk;//Vec3 fireTarget;//A4
	EStance stance;//A8
	Vec3 animationEyeDirection;//AC-B4
	Vec3 movementDirection, lastMovementDirection;//B8-C0,C4-CC
	float desiredSpeed;//D0
	float minSpeed;
	float normalSpeed;
	float maxSpeed;
	float slopeAngle;
	bool atMoveTarget;
	bool isAlive;
	bool isAiming;
	bool isFiring;
	bool isVisible;
	bool isMoving;
};

class CMovementRequest {};

class IMovementController {
public:
	virtual virtual ~IMovementController() {}; //0x0 
	virtual bool RequestMovement(CMovementRequest& request) = 0;
	virtual void GetMovementState(SMovementState &state) = 0;
	virtual bool GetStanceState( /*const SStanceStateQuery& query, SStanceState& state*/) = 0;
};

template <typename T>
T cClassValue(VOID *Base, INT index) { return (*(T**)Base)[index / 4]; }

class IWeaponExtraOne
{
public:
	void Damage(__int32 iValue) { *(__int32*)((DWORD)this + 0x8) = iValue; }
	void SetRecoil(int Status)
	{
		if (Status == 0) { *(INT*)((DWORD)this + 0x2F0) = *(INT*)((DWORD)this + V_OffRecoil); }
		if (Status == 1) { *(INT*)((DWORD)this + 0x2F0) = *(INT*)((DWORD)this + V_SetRecoil); }
	}
};

class IWeaponExtraTwo
{
public:
	void SetCameraSway(float fValue)
	{
		*(float*)((DWORD)this) = fValue;
		*(float*)((DWORD)this + V_CameraSway) = fValue;
	}
};

class IWeaponExtraThree
{
public:
	void SetAmmoCount(__int32 iValue) { *(__int32*)((DWORD)this + 0x4) = iValue; }
	__int32 GetAmmoCount() { return *(__int32*)((DWORD)this + 0x4); }
};

class IWeaponSpecific
{
public:
	auto m_pWeaponExtraOne() { return *(IWeaponExtraOne**)((DWORD)this + 0x24); }
	auto m_pWeaponExtraTwo() { return *(IWeaponExtraTwo**)((DWORD)this + 0x30); }
	auto m_pWeaponExtraThree() { return *(IWeaponExtraThree**)((DWORD)this + 0x34); }

	VOID Shutter(INT8 iValue) { *(INT8*)((DWORD)this + V_Shutter) = iValue; }
	VOID SetRecoilMult(INT8 iValue) { *(INT8*)((DWORD)this + V_SetRecoilMult) = iValue; }
};

class IFireMode
{
public:
	bool IsFiring()
	{
		using oIsFiring = bool(__thiscall*)(PVOID);
		return cClassValue<oIsFiring>(this, 144)(this);
	}
};

class IWeapon
{
public:
	void StartFire()
	{
		using oStartFire = void(__thiscall*)(PVOID);
		return cClassValue<oStartFire>(this, 44)(this);
	}

	void StopFire()
	{
		using oStopFire = void(__thiscall*)(PVOID);
		return cClassValue<oStopFire>(this, 48)(this);
	}

	IFireMode* GetFireMode(int FireModeId)
	{
		using oGetFireMode = IFireMode * (__thiscall*)(PVOID, int);
		return cClassValue<oGetFireMode>(this, 116)(this, FireModeId);
	}

	auto m_pWeaponSpecific() { return *(IWeaponSpecific**)((DWORD)this + 0x4); }
};

class IItem
{
public:
	IWeapon * GetIWeapon() { return((IWeapon*)this + 0x14); }
	VOID SetFiringPos(Vec3 vPos) { *(Vec3*)((DWORD)*(DWORD*)((DWORD)GetIWeapon() + 0xC) + 0x10) = vPos; }
	Vec3 GetFiringPos() { return *(Vec3*)((DWORD)*(DWORD*)((DWORD)GetIWeapon() + 0xC) + 0x10); }
};

class IActor
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual bool IsDead(); //0x0060  activeplayer
	virtual void Function25(); //0x64
	virtual void Function26(); //0x68
	virtual int GetHealth(); //
	virtual void SetHealth(int Health);//Function28(); //0x70
	virtual void Function29(); //0x74
	virtual void SetMaxHealth(float fMaxHealth); //
	virtual int GetMaxHealth(); //
	virtual int GetArmor(); //
	virtual int GetMaxArmor(); //
	virtual void Function34(); //0x88
	virtual void Function35(); //0x8C
	virtual void Function36(); //0x90
	virtual void Function37(); //0x94
	virtual void Function38(); //0x98
	virtual void Function39(); //0x9C
	virtual void Function40(); //0xA0
	virtual void Function41(); //0xA4
	virtual void Function42(); //0xA8
	virtual void Function43(); //0xAC
	virtual void Function44(); //0xB0
	virtual EntityId GetGrabbedEntityId(); //0xB4  //CGameRules::CullEntitiesInExplosion
	virtual void Function46(); //0xB8
	virtual void Function47(); //0xBC
	virtual void SetCurrentItem(EntityId itemid); //0xE0
	virtual void Function49(); //0xC4
	virtual void Function50(); //0xC8
	virtual void SetViewRotation(const Quat& pRotation); //
	virtual Quat GetViewRotation(); //
	virtual void Function53(); //0xD4
	virtual void Function54(); //0xD8
	virtual void Function55(); //0xDC
	virtual IItem* GetCurrentItem(bool includeVehicle = false) const = 0; //0xE0
	virtual void Function57(); //0xE4
	virtual void Function58();  //virtual IInventory *GetInventory();//virtual void Function58(); //E8
	virtual void Function59();//EC
	virtual IMovementController *GetMovementController(); //"ASCII bodyfall -- inside func CPlayer::Landed virtual void Function60(); //F0  
	virtual IEntity *LinkToVehicle(EntityId vehicleId) = 0;
	virtual IEntity* GetLinkedEntity() const = 0;
	virtual int GetSpectatorMode() const = 0;
	virtual void SetSleepTimer(float timer) = 0;
	virtual void *GetReplacementMaterial() = 0;//IMaterial
	virtual bool IsThirdPerson() const = 0;//108
	virtual void ToggleThirdPerson() = 0;//10C
	virtual bool IsPlayer();//
	virtual bool IsClient();//
	virtual void Function70();//
	virtual void Function71();//
	virtual char *GetActorClassName();
	virtual void Function73(); //virtual ActorClass GetActorClass() const = 0;
	virtual const char* GetEntityClassName() const = 0;

	int getEntityId() { return *(int*)((DWORD)this + 0x10); };
	//8 192 44
	int getSelectedWeaponType() { return (int)*(DWORD*)((DWORD)this + 0xAE8); }
	//Primary: 1818650994
	//Secondary: 1953720688
	//Knife: 1718185579
	//Grenade: 1852142183
	//Claymore: 30574
	//Medikit: 1801741677
	//Ammo Box: 1869442401
	//Armor Kit: 1634755954
	//Defi: 26212
	int GetCurrentClass() { return (int)*(DWORD*)((DWORD)this + V_GetCurrentClass); }
	
	IEntity* getIEntity() { return (IEntity*)*(DWORD*)((DWORD)this + 0x08); };
	CPlayer *GetPlayer() { return (CPlayer*)*(DWORD*)((DWORD)this + 0x8F8); };

	auto IsTriggerID()
	{
		auto u = *(int*)((DWORD)this + 0xC);
		u = *(int*)((DWORD)u + 0x40);
		u = *(int*)((DWORD)u + 0x18);
		return (int)*(DWORD*)((DWORD)u + 0x110);
	}

	void SetExtraClimbHeight(float fValue) {
		*(float*)((DWORD)this + 0xC18) = fValue;
	}

	void slideDistanceMult(float pValue) {
		*(float*)((DWORD)this + 0xC0C) = pValue;
	}

	void claymore_detector_radius(float eValue) {
		*(float*)((DWORD)this + 0xAB8) = eValue;
	}

	void minStaminaToStartHaste(float gValue) {
		*(float*)((DWORD)this + 0xC10) = gValue;
	}
};

struct IGame
{
public:
	ICVar * GetICvar()
	{
		return (ICVar*)*(DWORD*)((DWORD)this + 0xA0);//GetICVar
	}

	//static IGame* GetIGame() {
	//	return *(IGame**)0x1B26B04;  // atimeout ds:d___   upper ssge   or  Libs/UI/HUDHitIndicatorHor.tif  between ssge and aLibsUiHudhitin ds:d
	//}
};

class ICVar
{
public:
	void SetIPelletsDisp(float iValue)//accuracy
	{
		*(float*)((DWORD)this + 0x120) = iValue;//i_pelletsDisp
	}
	void CrosshairSpreadTuning(int iValue) {
		*(int*)((DWORD)this + 0x544) = iValue;//g_crosshairSpreadTuning_Enable
	}
	void ACPatternScan(int OFF) {
		*(int*)((DWORD)this + 0xA10) = OFF;
	}
	void ACMemScan(int OFF) {
		*(int*)((DWORD)this + 0xA08) = OFF;
	}
	void ACMemLog(int OFF) {
		*(int*)((DWORD)this + 0xA0C) = OFF;
	}
	void SetUnlimAmmo(int iAmmo)
	{
		*(int*)((DWORD)this + 0x128) = iAmmo;
	}
	void silencer_shoot_spotting(int xValue)
	{
		*(int*)((DWORD)this + 0xB70) = xValue;
	}
	void SetPickupDist(float fValue)
	{
		*(float*)((DWORD)this + 0x734) = fValue;
	}
	void g_kickvote_pve_max_checkpoints(int num)
	{
		*(int*)((DWORD)this + 0x44C) = num;
	}
	void g_enable_ingame_kickvote_in_zombiemission(int fValue)
	{
		*(int*)((DWORD)this + 0x448) = fValue;
	}
	void i_soundeffects(int fValue)
	{
		*(int*)((DWORD)this + 0x00D8) = fValue;
	}
	void g_enableIdleCheck(int fValue)
	{
		*(int*)((DWORD)this + 0x160) = fValue;
	}
};

enum FlagStates
{
	Flag_Unknown = 0,
	Flag_PickedUp,
	Flag_Dropped,
	Flag_Captured,
};

enum BombStates
{
	Bomb_Unknown = 0,
	Bomb_Initial,
	Bomb_Dropped,
	Bomb_PickedUp,
	Bomb_Planted,
	Bomb_Exploded,
	Bomb_Defusing //6
};

enum BombPlantSites
{
	Site_Unknown = 0,
	Site_A,
	Site_B
};

class ICaptureSystem
{
public:
	EntityId CaseCarrierId; //0x0000 
	char _0x0004[4];
	__int32 CurrentCaseState; //0x0008 

};//Size=0x000C

class IBombSystem
{
public:
	char _0x0000[8];
	__int32 CurrentBombState; //0x008
	__int32 CurrentPlantSite; //0x0012
	EntityId BombCarrierId; //0x0016
};//Size=0x0014

class ICoreSystem
{
public:
	char _0x0000[64];
};//Size=0x0040

class IStormSystem
{
public:
	__int32 CurrentCoreId; //0x0000
	__int32 TotalCores; //0x0004
	__int32 CaptureProgress; //0x0008
	__int32 CoresCaptured; //0x000C

};//Size=0x0010

enum GameModes
{
	Mode_Unknown = 0,
	Mode_TeamDeathmatch,
	Mode_Capture,
	Mode_CoopSurvival,
	Mode_PlantTheBomb,
	Mode_Storm,
	Mode_FreeForAll,
	Mode_Destruction,
	Mode_Domination
};

struct IGameRoom
{
	char unknown0[1372]; //
	__int32 GameType; //1372

	static IGameRoom* GetGameRoom() {
		return *(IGameRoom**)0x1B8F034;
	}
};

struct ray_hit {
	float dist;
	IPhysicalEntity *pCollider;
	int ipart;
	int partid;
	short surface_idx;
	short idmatOrg;	// original material index, not mapped with material mapping
	int foreignIdx;
	int iNode; // BV tree node that had the intersection; can be used for "warm start" next time
	Vec3 pt;
	Vec3 n;	// surface normal
	int bTerrain;	// global terrain hit
	int iPrim; // hit triangle index
	ray_hit *next; // reserved for internal use, do not change
};

struct IGameRules
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual int GetChannelId(IActor* playerId); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void SendTextMessage(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual bool IsTimeLimited() const;//
	virtual float GetRemainingGameTime() const;//
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void ResetGameTime(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void ResetRoundTime(); //
	virtual float GetRemainingRoundTime() const; //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void AwardPlayer(int scoringEvent, int entityId);
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual IActor *SpawnPlayer(int channelId, const char *name, const char *className, const Vec3 &pos, const Ang3 &angles);
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void RevivePlayer(IActor *pActor, const Vec3 &pos, const Ang3 &angles, int teamId, bool clearInventory = true);
	virtual void RenamePlayer(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void KillPlayer(IActor* pActor, const bool inDropItem, const bool inDoRagdoll, const HitInfo &inHitInfo);
	virtual void Function82(); //
	virtual void GetPlayerCount(); //
	virtual void GetSpectatorCount(); //
	virtual void Function85(); //
	virtual void Function86(); //
	virtual void IsPlayerInGame(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual void Function91(); //
	virtual void Function92(); //
	virtual void Function93(); //
	virtual void Function94(); //
	virtual void Function95(); //
	virtual void CreateTeam(const char* name); //
	virtual void GetTeamName(); //
	virtual void GetTeamCount(); //
	virtual void GetTeamPlayerCount(); //18C
	virtual int GetTeamId(const char* teamname); //
	virtual void GetTeamPlayer(); //
	virtual void GetTeamChannelCount(); //
	virtual void Function103(); //
	virtual void Function104(); //
	virtual void Function105(); //
	virtual void SetTeam(int teamId, int entityId); //
	virtual void Function107(); //
	virtual int GetTeam(int entityId); //0x01B0
	virtual void GetChannelTeam();//
	virtual void Function110(); //
	virtual void Function111(); //
	virtual void Function112(); //
	virtual void Function113(); //
	virtual void Function114(); //
	virtual void Function115(); //
	virtual void Function116(); //
	virtual void Function117(); //
	virtual void Function118(); //
	virtual int AddSpawnLocation(int entityId); //
	virtual void Function120(); //
	virtual void Function121(); //
	virtual void GetSpawnLocation(int playerId, int teamId, bool ignoreTeam, bool includeNeutral); //
	virtual int AddSpawnGroup(int groupId); //
	virtual void AddSpawnLocationToSpawnGroup(int groupId, int location); //
	virtual void Function125(); //
	virtual void Function126(); //
	virtual void Function127(); //
	virtual void Function128(); //
	virtual void Function129(); //
	virtual void Function130(); //
	virtual void SetTeamDefaultSpawnGroup(int teamId, int groupId); //
	virtual int GetTeamDefaultSpawnGroup(int teamId); //
	virtual void Function133(); //
	virtual void Function134(); //
	virtual void Function135(); //
	virtual void Function136(); //
	virtual void Function137(); //
	virtual void GetTeamInstantSpawnGroup(int teamId); //
	virtual void SetTeamInstantSpawnGroup(int teamId, int groupId); //
	virtual void Function140(); //
	virtual void Function141(); //
	virtual void Function142(); //
	virtual void Function143(); //
	virtual void Function144(); //
	virtual void Function145(); //
	virtual void Function146(); //
	virtual void Function147(); //
	virtual void Function148(); //
	virtual void Function149(); //
	virtual void EndGame(int reason, int winningteamId); //
	virtual void Function151(); //
	virtual void Function152(); //
	virtual void Function153(); //
	virtual void Function154(); //
	virtual void GameOver(int Winnerteam); //

	__int32 AttackersTeamId() { return *(__int32*)((DWORD)this + IGameRules__DefendersTeam - 4); }
	__int32 DefendersTeamId() { return *(__int32*)((DWORD)this + IGameRules__DefendersTeam); }

	ICaptureSystem *pCaptureSystem() { return (ICaptureSystem*)*(DWORD*)((DWORD)this + IGameRules__GetIBombSystem - 4); };
	IBombSystem *pBombSystem() { return (IBombSystem*)*(DWORD*)((DWORD)this + IGameRules__GetIBombSystem); };
	ICoreSystem *pCoresSystem() { return (ICoreSystem*)*(DWORD*)((DWORD)this + IGameRules__GetIBombSystem + 4); };
	IStormSystem *pStormSystem() { return (IStormSystem*)*(DWORD*)((DWORD)this + IGameRules__GetIBombSystem + 8); };
};

struct IGameFramework
{
public:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual IActorSystem* GetIActorSystem();
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual void Function86(); //
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual void Function91(); //
	virtual void Function92(); //
	virtual void Function93(); //
	virtual void Function94(); //
	virtual void Function95(); //
	virtual void Function96(); //
	virtual void Function97(); //
	virtual void Function98(); //
	virtual void Function99(); //
	virtual void Function100(); //
	virtual void Function101(); //
	virtual void Function102(); //
	virtual void Function103(); //
	virtual void Function104(); //
	virtual void Function105(); //
	virtual void Function106(); //
	virtual void Function107(); //
	virtual void Function108(); //
	virtual void Function109(); //
	virtual void Function110(); //
	virtual void Function111(); //
	virtual void Function112(); //
	virtual void Function113(); //
	virtual void Function114(); //
	virtual void Function115(); //
	virtual void Function116(); //
	virtual void Function117(); //
	virtual void Function118(); //
	virtual void Function119(); //
	virtual void Function120(); //
	virtual void Function121(); //
	virtual void Function122(); //
	virtual void Function123(); //
	virtual void Function124(); //
	virtual void Function125(); //
	virtual void Function126(); //
	virtual void Function127(); //
	virtual void Function128(); //
	virtual void Function129(); //
	virtual void Function130(); //
	virtual void Function131(); //
	virtual void Function132(); //
	virtual void Function133(); //
	virtual void Function134(); //
	virtual void Function135(); //
	virtual void Function136(); //
	virtual void Function137(); //
	virtual void Function138(); //
	virtual void Function139(); //
	virtual void Function140(); //
	virtual void Function141(); //
	virtual bool GetClientActor(IActor **pAct); //0x23c

	static IGameFramework* GetGameFramework() {//The highlited dword_... is the IGameFramework address.
		return *(IGameFramework**)IGameFramework_Address; //search Failed to create the GameFramework Interface!
	}

	IGameRules* GetIGameRules() { return *(IGameRules**)((DWORD)this + V_GetCurrentGameRules); }
};

struct IActorIterator
{
public:
	virtual void Function0(); //
	virtual IActor* Next(); //
	virtual void IncreaseIndex(); //
	virtual int Count(); //

};//Size=0x0004

struct IActorSystem
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void CreateActorIterator(IActorIterator** ActorIterator);
	virtual void Function12(); //
	virtual int GetCount(); //0x0034
	virtual IActor* GetActorByChannelId(int ChannelId); //0x0038
	virtual IActor* GetActor(int entityId); //0x003C
};

struct IRenderer
{
	struct w2s_info
	{
		float Posx;
		float Posy;
		float Posz;
		float *Scrnx;
		float *Scrny;
		float *Scrnz;
	};
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual int GetWidth(); //
	virtual int GetHeight(); //
	virtual void Function86(); //
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual void Function91(); //
	virtual void Function92(); //
	virtual void Function93(); //
	virtual bool ProjectToScreen(w2s_info *info); //0x0178
	virtual void Function95(); //
	virtual void Function96(); //
	virtual void GetModelViewMatrix(float *mat) = 0;
	virtual void GetProjectionMatrix(float *mat) = 0;
};

struct IEntityIt
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5();
	virtual IEntity* Next(); //
};

struct IEntitySystem
{
	virtual void Function0(); //
	virtual IEntityClassRegistry* GetClassRegistry() = 0;// 
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void GetEntity(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual IEntityIt* GetEntityIterator();
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual IEntity* FindEntityByName(const char* EntityName); //0x00D0
};

struct IEntityClass
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual const char* GetName() const = 0;//0x3C 
};

struct IEntityProxy;

enum EEntityProxy
{
	ENTITY_PROXY_RENDER,
	ENTITY_PROXY_PHYSICS,
	ENTITY_PROXY_SCRIPT,
	ENTITY_PROXY_SOUND,
	ENTITY_PROXY_AI,
	ENTITY_PROXY_AREA,
	ENTITY_PROXY_BOIDS,
	ENTITY_PROXY_BOID_OBJECT,
	ENTITY_PROXY_CAMERA,
	ENTITY_PROXY_FLOWGRAPH,
	ENTITY_PROXY_SUBSTITUTION,
	ENTITY_PROXY_TRIGGER,
	ENTITY_PROXY_ROPE,
	ENTITY_PROXY_ENTITYNODE,

	ENTITY_PROXY_USER,

	// Always the last entry of the enum.	
	ENTITY_PROXY_LAST
};

enum ESilhouettesParams {
	eAllMap = 524312,
	eLimitDistance = 524296
};

struct IRenderNode
{
	// Rendering flags.
	void SetRndFlags(unsigned int dwFlags) { m_dwRndFlags = dwFlags; }
	void SetRndFlags(unsigned int dwFlags, bool bEnable) { if (bEnable) SetRndFlags(m_dwRndFlags | dwFlags); else SetRndFlags(m_dwRndFlags&(~dwFlags)); }
	unsigned int GetRndFlags() const { return m_dwRndFlags; }

	char unknown0[16]; //0x0000
	int m_dwRndFlags; //0x0010  
};

struct IEntityRenderProxy
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void SetHUDSilhouettesParams(float a, float r, float g, float b);
	void SetRndFlags(int Flag) { *(int*)((DWORD)this + 0x14) = Flag; }
};

struct IEntityClassRegistry
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual IEntityClass* FindClass(const char *sClassName) const = 0;//0x20
};

class CCamera
{
public:
	const Matrix34& GetMatrix() { return m_Matrix; };
	Vec3 GetViewdir() { return m_Matrix.GetColumn1(); };
	Vec3 GetPosition() { return m_Matrix.GetTranslation(); }
private:
	char unknown0[200]; //
	Matrix34 m_Matrix; //0x00C8
};

struct ISkeletonPose
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual QuatT& GetBoneByID(int nJointID);//GetAbsJointByID rghtarm01
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual int GetJointNameByID(int ID); //0x00A8
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
};

struct ICharacterInstance
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual ISkeletonPose* GetISkeletonPose(); //0x14 //virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
};

struct IEntity
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual int GetFlags(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10();// virtual const Matrix34& GetWorldTM();; //virtual void Function10(); //
	virtual void SetName(const char* NewName); //
	virtual const char* GetName() const; //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15();//
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual const Matrix34& GetWorldTM(); //
	virtual void Function24(); //
	virtual void GetWorldBounds(AABB &bbox) = 0;
	virtual void Function26(); //
	virtual void SetLocalPos(const Vec3 &vPos, int nWhyFlags = 0);;  //virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void SetScale(const Vec3 &vScale, int nWhyFlags = 0) = 0;
	virtual const Matrix34& GetSlotLocalTM(int nSlot, bool bRelativeToParent) const;; //0x0080
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void SetPos(const Vec3 &vPos, int nWhyFlags = 0);; //0x00A0
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual int LoadCharacter(int nSlot, const char *sFilename, int nLoadFlags = 0);; //0x00DC
	virtual EntityId GetId() const;; //0x00E0
	virtual void Function57(); //
	virtual void Function58(); //
	virtual IEntityProxy* GetProxy(EEntityProxy proxy) const;; //virtual void Function59(); //
	virtual void Function60();//
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void FreeAllSlots(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); ////;; //0x0114
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74();//
	virtual void SetFlags(int iFlags);; //0x012C
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual ICharacterInstance* GetCharacter(int nSlot);//0x148
	int GetID() { return *(int*)((DWORD)this + 0x14); }

	Vec3 GetWorldPos() {
		Matrix34 m = this->GetWorldTM();
		return m.GetTranslation();
	}

	char _0x0004[16];
	DWORD EntityID; //0x0014 
	char _0x0018[24];
	Matrix34 EntityWorldTM; //0x0030
	char _0x0070[8];
	Quat EntityAngle; //0x0078 
	char _0x0088[48];
	//	DWORD NamePtr; //0x00B8 
};

enum phentity_flags {
	// PE_PARTICLE-specific flags
	particle_single_contact = 0x01, // full stop after first contact
	particle_constant_orientation = 0x02, // forces constant orientation
	particle_no_roll = 0x04, // 'sliding' mode; entity's 'normal' vector axis will be alinged with the ground normal
	particle_no_path_alignment = 0x08, // unless set, entity's y axis will be aligned along the movement trajectory
	particle_no_spin = 0x10, // disables spinning while flying
	particle_no_self_collisions = 0x100, // disables collisions with other particles
	particle_no_impulse = 0x200, // particle will not add hit impulse (expecting that some other system will) 

								 // PE_LIVING-specific flags
								 lef_push_objects = 0x01, lef_push_players = 0x02,	// push objects and players during contacts
								 lef_snap_velocities = 0x04,	// quantizes velocities after each step (was ised in MP for precise deterministic sync)
								 lef_loosen_stuck_checks = 0x08, // don't do additional intersection checks after each step (recommended for NPCs to improve performance)
								 lef_report_sliding_contacts = 0x10,	// unless set, 'grazing' contacts are not reported 

																		// PE_ROPE-specific flags
																		rope_findiff_attached_vel = 0x01, // approximate velocity of the parent object as v = (pos1-pos0)/time_interval
																		rope_no_solver = 0x02, // no velocity solver; will rely on stiffness (if set) and positional length enforcement
																		rope_ignore_attachments = 0x4, // no collisions with objects the rope is attached to
																		rope_target_vtx_rel0 = 0x08, rope_target_vtx_rel1 = 0x10, // whether target vertices are set in the parent entity's frame
																		rope_subdivide_segs = 0x100, // turns on 'dynamic subdivision' mode (only in this mode contacts in a strained state are handled correctly)
																		rope_no_tears = 0x200, // rope will not tear when it reaches its force limit, but stretch
																		rope_collides = 0x200000, // rope will collide with objects other than the terrain
																		rope_collides_with_terrain = 0x400000, // rope will collide with the terrain
																		rope_collides_with_attachment = 0x80, // rope will collide with the objects it's attached to even if the other collision flags are not set
																		rope_no_stiffness_when_colliding = 0x10000000, // rope will use stiffness 0 if it has contacts

																								// PE_SOFT-specific flags
																								se_skip_longest_edges = 0x01,	// the longest edge in each triangle with not participate in the solver
																													   se_rigid_core = 0x02, // soft body will have an additional rigid body core

																																			 // PE_RIGID-specific flags (note that PE_ARTICULATED and PE_WHEELEDVEHICLE are derived from it)
																																			 ref_use_simple_solver = 0x01,	// use penalty-based solver (obsolete)
																																			 ref_no_splashes = 0x04, // will not generate EventPhysCollisions when contacting water
																																			 ref_checksum_received = 0x04, ref_checksum_outofsync = 0x08, // obsolete
																																			 ref_small_and_fast = 0x100, // entity will trace rays against alive characters; set internally unless overriden

																																										 // PE_ARTICULATED-specific flags
																																										 aef_recorded_physics = 0x02, // specifies a an entity that contains pre-baked physics simulation

																																																	  // PE_WHEELEDVEHICLE-specific flags
																																																	  wwef_fake_inner_wheels = 0x08, // exclude wheels between the first and the last one from the solver
																																																									 // (only wheels with non-0 suspension are considered)

																																																									 // general flags
																																																									 pef_parts_traceable = 0x10,	// each entity part will be registered separately in the entity grid
																																																									 pef_disabled = 0x20, // entity will not be simulated
																																																									 pef_never_break = 0x40, // entity will not break or deform other objects
																																																									 pef_deforming = 0x80, // entity undergoes a dynamic breaking/deforming
																																																									 pef_pushable_by_players = 0x200, // entity can be pushed by playerd	
																																																									 pef_traceable = 0x400, particle_traceable = 0x400, rope_traceable = 0x400, // entity is registered in the entity grid
																																																									 pef_update = 0x800, // only entities with this flag are updated if ent_flagged_only is used in TimeStep()
																																																									 pef_monitor_state_changes = 0x1000, // generate immediate events for simulation class changed (typically rigid bodies falling asleep)
																																																									 pef_monitor_collisions = 0x2000, // generate immediate events for collisions
																																																									 pef_monitor_env_changes = 0x4000,	// generate immediate events when something breaks nearby
																																																									 pef_never_affect_triggers = 0x8000,	// don't generate events when moving through triggers
																																																									 pef_invisible = 0x10000, // will apply certain optimizations for invisible entities
																																																									 pef_ignore_ocean = 0x20000, // entity will ignore global water area
																																																									 pef_fixed_damping = 0x40000,	// entity will force its damping onto the entire group
																																																									 pef_monitor_poststep = 0x80000, // entity will generate immediate post step events
																																																									 pef_always_notify_on_deletion = 0x100000,	// when deleted, entity will awake objects around it even if it's not referenced (has refcount 0)
																																																									 pef_override_impulse_scale = 0x200000, // entity will ignore breakImpulseScale in PhysVars
																																																									 pef_players_can_break = 0x400000, // playes can break the entiy by bumping into it
																																																									 pef_cannot_squash_players = 0x10000000,	// entity will never trigger 'squashed' state when colliding with players
																																																									 pef_ignore_areas = 0x800000, // entity will ignore phys areas (gravity and water)
																																																									 pef_log_state_changes = 0x1000000, // entity will log simulation class change events
																																																									 pef_log_collisions = 0x2000000, // entity will log collision events
																																																									 pef_log_env_changes = 0x4000000, // entity will log EventPhysEnvChange when something breaks nearby
																																																									 pef_log_poststep = 0x8000000, // entity will log EventPhysPostStep events
};

enum entity_query_flags { // see GetEntitiesInBox and RayWorldIntersection
	ent_static = 1, ent_sleeping_rigid = 2, ent_rigid = 4, ent_living = 8, ent_independent = 16, ent_deleted = 128, ent_terrain = 0x100,
	ent_all = ent_static | ent_sleeping_rigid | ent_rigid | ent_living | ent_independent | ent_terrain,
	ent_flagged_only = pef_update, ent_skip_flagged = pef_update * 2, // "flagged" meas has pef_update set
	ent_areas = 32, ent_triggers = 64,
	ent_ignore_noncolliding = 0x10000,
	ent_sort_by_mass = 0x20000, // sort by mass in ascending order
	ent_allocate_list = 0x40000, // if not set, the function will return an internal pointer
	ent_addref_results = 0x100000, // will call AddRef on each entity in the list (expecting the caller call Release)
	ent_water = 0x200, // can only be used in RayWorldIntersection
	ent_no_ondemand_activation = 0x80000, // can only be used in RayWorldIntersection
	ent_delayed_deformations = 0x80000 // queues procedural breakage requests; can only be used in SimulateExplosion
};

enum draw_helper_flags { pe_helper_collisions = 1, pe_helper_geometry = 2, pe_helper_bbox = 4, pe_helper_lattice = 8 };
enum surface_flags { sf_pierceable_mask = 0x0F, sf_max_pierceable = 0x0F, sf_important = 0x200, sf_manually_breakable = 0x400, sf_matbreakable_bit = 16 };

enum rwi_flags { // see RayWorldIntersection
	rwi_ignore_terrain_holes = 0x20, rwi_ignore_noncolliding = 0x40, rwi_ignore_back_faces = 0x80, rwi_ignore_solid_back_faces = 0x100,
	rwi_pierceability_mask = 0x0F, rwi_pierceability0 = 0, rwi_stop_at_pierceable = 0x0F,
	rwi_separate_important_hits = sf_important,	// among pierceble hits, materials with sf_important will have priority
	rwi_colltype_bit = 16, // used to manually specify collision geometry types (default is geom_colltype_ray)
	rwi_colltype_any = 0x400, // if several colltype flag are specified, switches between requiring all or any of them in a geometry
	rwi_queue = 0x800, // queues the RWI request, when done it'll generate EventPhysRWIResult
	rwi_force_pierceable_noncoll = 0x1000, // non-colliding geometries will be treated as pierceable regardless of the actual material
	rwi_debug_trace = 0x2000, // marks the rwi to be a debug rwi (used for spu debugging, only valid in non-release builds)
	rwi_update_last_hit = 0x4000, // update phitLast with the current hit results (should be set if the last hit should be reused for a "warm" start)
	rwi_any_hit = 0x8000 // returns the first found hit for meshes, not necessarily the closets
};
#define MAX_PHYS_THREADS 4
#define RWI_NAME_TAG "RayWorldIntersection(Game)"

struct IEntityProxy;

class IEntityLink;

struct ray_hit_cached {	// used in conjunction with rwi_reuse_last_hit
	ray_hit_cached() { pCollider = 0; ipart = 0; }
	ray_hit_cached(const ray_hit &hit) { pCollider = hit.pCollider; ipart = hit.ipart; iNode = hit.iNode; }
	ray_hit_cached &operator=(const ray_hit &hit) { pCollider = hit.pCollider; ipart = hit.ipart; iNode = hit.iNode; return *this; }

	IPhysicalEntity *pCollider;
	int ipart;
	int iNode;
};

#define MAX_PHYS_THREADS 4
#define RWI_NAME_TAG "RayWorldIntersection(Game)"

enum eRWIFlags
{
	eAmmoFlags = 0x31F,
	eAmmoWallShot = 0x7E
};

class SRWIParams
{
public:
	void *pForeignData; //0x0000 
	__int32 iForeignData; //0x0004 
	char pad_0x0008[0x4]; //0x0008
	Vec3 org; //0x000C 
	Vec3 dir; //0x0018 
	__int32 objTypes; //0x0024 
	unsigned int flags; //0x0028 
	ray_hit *hits; //0x002C 
	__int32 nMaxHits; //0x0030 
	ray_hit_cached *phitLast; //0x0034 
	__int32 nSkipEnts; //0x0038 
	IPhysicalEntity **pSkipEnts; //0x003C 
}; //Size=0x0040

struct pe_explosion
{
	Vec3 epicenter;
	Vec3 epicenterImp;
	float rmin, rmax, r;
	float impulsivePressureAtR;
	int nOccRes;
	int nGrow;
	float rminOcc;
	float holeSize;
	Vec3 explDir;
	int iholeType;
	bool forceDeformEntities;
	IPhysicalEntity **pAffectedEnts;
	float *pAffectedEntsExposure;
	int nAffectedEnts;
};

struct IPhysicalWorld
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function12(); //
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void SimulateExplosion(pe_explosion *pexpl, IPhysicalEntity **pSkipEnts = 0, int nSkipEnts = 0, int iTypes = ent_rigid | ent_sleeping_rigid | ent_living | ent_independent, int iCaller = 4) = 0;
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual void Function86(); //
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual void Function91(); //
	virtual void Function92(); //
	
	INT RayWorldIntersection(const Vec3& org, const Vec3& dir, int objtypes, unsigned int flags, ray_hit *hits, int nMaxHits = 1, IPhysicalEntity **pSkipEnts = 0, int nSkipEnts = 0, void *pForeignData = 0, int iForeignData = 0, const char *pNameTag = "RayWorldIntersection(Game)", ray_hit_cached *phitLast = 0, int iCaller = 4)
	{
		return vFun_Call<int(__thiscall*)(PVOID, const Vec3&, const Vec3&, int, unsigned int, ray_hit*, int, IPhysicalEntity **, int, void *, int, const char *, ray_hit_cached *, int)>(this, 94)(this, org, dir, objtypes, flags, hits, nMaxHits, pSkipEnts, nSkipEnts, pForeignData, iForeignData, pNameTag, phitLast, iCaller);
	}
};

struct ITimer
{
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual float GetFrameTime(int Timer = 0); //0x002C
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
};

enum Bones
{
	Bone_Pelvis = 1,
	Bone_Locomotion,
	Bone_Spine,
	Bone_L_Thigh,
	Bone_R_Thigh,
	Bone_Groin_Back,
	Bone_Groin_Front,
	Bone_Spine1,
	Bone_Spine2,
	Bone_Spine3,
	Bone_Wep_Law,
	Bone_Neck,
	Bone_Head,
	Bone_L_Clavicle,
	Bone_R_Clavicle,
	Bone_L_Eye,
	Bone_R_Eye,
	Bone_Camera,
	Bone_L_Eye_01,
	Bone_R_Eye_01,
	Bone_HNeck,
	Bone_Camera_01,
	Bone_HNeck_End,
	Bone_L_UpperArm,
	Bone_L_Forearm,
	Bone_L_Hand,
	Bone_L_ForeTwist,
	Bone_L_Finger0,
	Bone_L_Finger1,
	Bone_L_Finger2,
	Bone_L_Finger3,
	Bone_L_Finger4,
	Bone_Wep_Alt,
	Bone_L_Hand_Push,
	Bone_L_Finger01,
	Bone_L_Finger02,
	Bone_L_Finger11,
	Bone_L_Finger12,
	Bone_L_Finger21,
	Bone_L_Finger22,
	Bone_L_Finger31,
	Bone_L_Finger32,
	Bone_L_Finger41,
	Bone_L_Finger42,
	Bone_L_ForeTwist_1,
	Bone_L_ForeTwist_2,
	Bone_R_UpperArm,
	Bone_R_Forearm,
	Bone_R_Hand,
	Bone_R_ForeTwist,
	Bone_R_Finger0,
	Bone_R_Finger1,
	Bone_R_Finger2,
	Bone_R_Finger3,
	Bone_R_Finger4,
	Bone_WepBone,
	Bone_R_Hand_Push,
	Bone_R_Finger01,
	Bone_R_Finger02,
	Bone_R_Finger11,
	Bone_R_Finger12,
	Bone_R_Finger21,
	Bone_R_Finger22,
	Bone_R_Finger31,
	Bone_R_Finger32,
	Bone_R_Finger41,
	Bone_R_Finger42,
	Bone_R_ForeTwist_1,
	Bone_R_ForeTwist_2,
	Bone_L_Calf,
	Bone_L_Foot,
	Bone_L_Toe0,
	Bone_L_Heel,
	Bone_L_Heel01,
	Bone_L_Toe0Nub,
	Bone_L_Toe0Nub01,
	Bone_R_Calf,
	Bone_R_Foot,
	Bone_R_Toe0,
	Bone_R_Heel,
	Bone_R_Heel01,
	Bone_R_Toe0Nub,
	Bone_R_Toe0Nub01,
	Bone_Groin_Back_End,
	Bone_Groin_Front_End,
	Bone_Locator_Collider
};

enum PlayerClasses
{
	Class_Rifleman = 0,
	Class_Sniper = 2,
	Class_Medic = 3,
	Class_Engineer = 4
};

enum Stance
{
	None = -1,
	Stand = 0,
	Crouch,
	Prone,
	Relaxed,
	Stealth,
	Cover_Low,
	Cover_High,
	Swim
};