#pragma once

#include <stdint.h>

typedef struct Vector3 { float x, y, z; } Vec3;
typedef struct Vector2 { float x, y; } Vec2;

// Created with ReClass.NET 1.2 by KN4CK3R

class LocalPlayer
{
public:
	char pad_0000[48]; //0x0000
	class PlayerController* pPlayerController; //0x0030
	char pad_0038[56]; //0x0038
	class ViewportClient* pViewportClient; //0x0070
	char pad_0078[8]; //0x0078
}; //Size: 0x0080
static_assert(sizeof(LocalPlayer) == 0x80);

class PlayerController
{
public:
	char pad_0000[552]; //0x0000
	class PlayerState* pPlayerState; //0x0228
	char pad_0230[48]; //0x0230
	class Character* pCharacter; //0x0260
	char pad_0268[32]; //0x0268
	Vec2 viewAngle; //0x0288
	char pad_0290[504]; //0x0290
}; //Size: 0x0488
static_assert(sizeof(PlayerController) == 0x488);

class PlayerState
{
public:
	char pad_0000[136]; //0x0000
}; //Size: 0x0088
static_assert(sizeof(PlayerState) == 0x88);

class Character
{
public:
	char pad_0000[288]; //0x0000
	class Items* pItems; //0x0120
	int32_t numItems; //0x0128
	char pad_012C[348]; //0x012C
	class Movement* pMovement; //0x0288
	char pad_0290[784]; //0x0290
	class CharacterHealth* pCharacterHealth; //0x05A0
	char pad_05A8[1504]; //0x05A8
	float meleeRange; //0x0B88
	float meleeDamage; //0x0B8C
	char pad_0B90[285]; //0x0B90
	int8_t bTeamDamage; //0x0CAD
	char pad_0CAE[3510]; //0x0CAE
	float forwardSpeedMult; //0x1A64
	float backwardSpeedMult; //0x1A68
	float sideSpeedMult; //0x1A6C
	float leanSpeedMult; //0x1A70
	float speedLossLeg; //0x1A74
	float speedLossCarry; //0x1A78
	char pad_1A7C[704]; //0x1A7C
	float runSpeed; //0x1D3C
	float maxAccel; //0x1D40
	float speedAimFocus; //0x1D44
	float speedAim; //0x1D48
	float speedCrouch; //0x1D4C
	float speedSprint; //0x1D50
	float speedSprintMax; //0x1D54
	float speedSprintTime; //0x1D58
	float hitSpeedMult; //0x1D5C
	float slowDownSpeedMult; //0x1D60
	float walkSpeedRampMult; //0x1D64
	float sprintSpeedRampMult; //0x1D68
	float currentRunSpeedPercent; //0x1D6C
	char pad_1D70[4]; //0x1D70
	float maxRunSpeedPercent; //0x1D74
	float maxCrouchRunSpeedPercent; //0x1D78
	float minWalkSpeedPercent; //0x1D7C
	char pad_1D80[20]; //0x1D80
	float walkSpeedMult; //0x1D94
	char pad_1D98[152]; //0x1D98
	float recoilSpeed; //0x1E30
	char pad_1E34[428]; //0x1E34
	float exhaustionLevel; //0x1FE0
	char pad_1FE4[12]; //0x1FE4
	float fearLevel; //0x1FF0
	char pad_1FF4[4]; //0x1FF4
	float fearDissipateRate; //0x1FF8
	float fearSuppressScale; //0x1FFC
	float fearThreshold; //0x2000
	char pad_2004[132]; //0x2004
}; //Size: 0x2088
static_assert(sizeof(Character) == 0x2088);

class Items
{
public:
	class Armor* pArmor; //0x0000
	class Helmet* pHelmet; //0x0008
	class Primary* pPrimary; //0x0010
	class Primary* pSecondary; //0x0018
	class Primary* pTertiary; //0x0020
	char pad_0028[96]; //0x0028
}; //Size: 0x0088
static_assert(sizeof(Items) == 0x88);

class Movement
{
public:
	char pad_0000[176]; //0x0000
	class Position* pPosition; //0x00B0
	char pad_00B8[12]; //0x00B8
	Vec3 velocity; //0x00C4
	char pad_00D0[960]; //0x00D0
}; //Size: 0x0490
static_assert(sizeof(Movement) == 0x490);

class CharacterHealth
{
public:
	char pad_0000[232]; //0x0000
	float health; //0x00E8
	float maxHealth; //0x00EC
	char pad_00F0[152]; //0x00F0
}; //Size: 0x0188
static_assert(sizeof(CharacterHealth) == 0x188);

class Armor
{
public:
	char pad_0000[136]; //0x0000
}; //Size: 0x0088
static_assert(sizeof(Armor) == 0x88);

class Helmet
{
public:
	char pad_0000[136]; //0x0000
}; //Size: 0x0088
static_assert(sizeof(Helmet) == 0x88);

class Primary
{
public:
	char pad_0000[1328]; //0x0000
	float movementSpeedMult; //0x0530
	float quickLeanMult; //0x0534
	float freeLeanMult; //0x0538
	char pad_053C[996]; //0x053C
	float currentAmmoDmg; //0x0920
	char pad_0924[140]; //0x0924
	int32_t projectileCount; //0x09B0
	char pad_09B4[276]; //0x09B4
	int32_t currentFireMode; //0x0AC8
	char pad_0ACC[244]; //0x0ACC
	float gunDmg; //0x0BC0
	char pad_0BC4[20]; //0x0BC4
	float shotDelay; //0x0BD8
	char pad_0BDC[4]; //0x0BDC
	int32_t bulletsFiredUntilAccurate; //0x0BE0
	char pad_0BE4[8]; //0x0BE4
	int32_t bArmorPiercing; //0x0BEC
	char pad_0BF0[172]; //0x0BF0
	float adsRecoilMult; //0x0C9C
	char pad_0CA0[92]; //0x0CA0
	float refireDelay; //0x0CFC
	char pad_0D00[876]; //0x0D00
	int32_t bInfiniteAmmo; //0x106C
	char pad_1070[24]; //0x1070
}; //Size: 0x1088
static_assert(sizeof(Primary) == 0x1088);

class ViewportClient
{
public:
	char pad_0000[120]; //0x0000
	class World* pWorld; //0x0078
	char pad_0080[8]; //0x0080
}; //Size: 0x0088
static_assert(sizeof(ViewportClient) == 0x88);

class World
{
public:
	char pad_0000[48]; //0x0000
	class PersistentLevel* pPersistentLevel; //0x0030
	char pad_0038[80]; //0x0038
}; //Size: 0x0088
static_assert(sizeof(World) == 0x88);

class PersistentLevel
{
public:
	char pad_0000[152]; //0x0000
	class EntityList* pEntityList; //0x0098
	char pad_00A0[40]; //0x00A0
}; //Size: 0x00C8
static_assert(sizeof(PersistentLevel) == 0xC8);

class EntityList
{
public:
	char pad_0000[48]; //0x0000
	class GameMode* pGameMode; //0x0030
	char pad_0038[80]; //0x0038
}; //Size: 0x0088
static_assert(sizeof(EntityList) == 0x88);

class GameMode
{
public:
	char pad_0000[1904]; //0x0000
	class SuspectsAndCivilianManager* pSuspectsAndCivilianManager; //0x0770
	char pad_0778[272]; //0x0778
}; //Size: 0x0888
static_assert(sizeof(GameMode) == 0x888);

class SuspectsAndCivilianManager
{
public:
	char pad_0000[584]; //0x0000
	class Suspect* pSuspects; //0x0248
	int32_t numSuspects; //0x0250
	char pad_0254[20]; //0x0254
}; //Size: 0x0268
static_assert(sizeof(SuspectsAndCivilianManager) == 0x268);

class Suspect
{
public:
	char pad_0000[288]; //0x0000
	class Primary* pSuspectItems; //0x0120
	char pad_0128[352]; //0x0128
	class Movement* pMovement; //0x0288
	char pad_0290[784]; //0x0290
	class CharacterHealth* pCharacterHealth; //0x05A0
	char pad_05A8[609]; //0x05A8
	int8_t bInRagdoll; //0x0809
	char pad_080A[894]; //0x080A
	float meleeRange; //0x0B88
	float meleeDamage; //0x0B8C
	char pad_0B90[96]; //0x0B90
	int8_t bSurrendered; //0x0BF0
	int8_t bSurrenderComplete; //0x0BF1
	char pad_0BF2[182]; //0x0BF2
	int8_t bIsBeingArrested; //0x0CA8
	int8_t bArrestComplete; //0x0CA9
	char pad_0CAA[982]; //0x0CAA
}; //Size: 0x1080
static_assert(sizeof(Suspect) == 0x1080);

class Position
{
public:
	char pad_0000[464]; //0x0000
	Vec3 position; //0x01D0
	char pad_01DC[32]; //0x01DC
}; //Size: 0x01FC
static_assert(sizeof(Position) == 0x1FC);







































//
//// Created with ReClass.NET 1.2 by KN4CK3R
//
//class LocalPlayer
//{
//public:
//	char pad_0000[48]; //0x0000
//	class PlayerController* pPlayerController; //0x0030
//}; //Size: 0x0038
//static_assert(sizeof(LocalPlayer) == 0x38);
//
//class PlayerController
//{
//public:
//	char pad_0000[552]; //0x0000
//	class PlayerState* pPlayerState; //0x0228
//	char pad_0230[48]; //0x0230
//	class Character* pCharacter; //0x0260
//	char pad_0268[1568]; //0x0268
//}; //Size: 0x0888
//static_assert(sizeof(PlayerController) == 0x888);
//
//class PlayerState
//{
//public:
//	char pad_0000[136]; //0x0000
//}; //Size: 0x0088
//static_assert(sizeof(PlayerState) == 0x88);
//
//class Character
//{
//public:
//	char pad_0000[288]; //0x0000
//	class Items* pItems; //0x0120
//	int32_t numItems; //0x0128
//	char pad_012C[348]; //0x012C
//	class Movement* pMovement; //0x0288
//	char pad_0290[180]; //0x0290
//	int32_t jumpCount; //0x0344
//	char pad_0348[600]; //0x0348
//	class CharacterHealth* pCharacterHealth; //0x05A0
//	char pad_05A8[1504]; //0x05A8
//	float meleeRange; //0x0B88
//	float meleeDamage; //0x0B8C
//	char pad_0B90[285]; //0x0B90
//	int8_t bTeamDamage; //0x0CAD
//	char pad_0CAE[3510]; //0x0CAE
//	float forwardSpeedMult; //0x1A64
//	float backwardSpeedMult; //0x1A68
//	float sideSpeedMult; //0x1A6C
//	float leanSpeedMult; //0x1A70
//	float speedLossLeg; //0x1A74
//	float speedLossCarry; //0x1A78
//	char pad_1A7C[704]; //0x1A7C
//	float runSpeed; //0x1D3C
//	float maxAccel; //0x1D40
//	float speedAimFocus; //0x1D44
//	float speedAim; //0x1D48
//	float speedCrouch; //0x1D4C
//	float speedSprint; //0x1D50
//	float speedSprintMax; //0x1D54
//	float speedSprintTime; //0x1D58
//	float hitSpeedMult; //0x1D5C
//	float slowDownSpeedMult; //0x1D60
//	float walkSpeedRampMult; //0x1D64
//	float sprintSpeedRampMult; //0x1D68
//	float currentRunSpeedPercent; //0x1D6C
//	char pad_1D70[4]; //0x1D70
//	float maxRunSpeedPercent; //0x1D74
//	float maxCrouchRunSpeedPercent; //0x1D78
//	float minWalkSpeedPercent; //0x1D7C
//	char pad_1D80[20]; //0x1D80
//	float walkSpeedMult; //0x1D94
//	char pad_1D98[152]; //0x1D98
//	float recoilSpeed; //0x1E30
//	char pad_1E34[428]; //0x1E34
//	float exhaustionLevel; //0x1FE0
//	char pad_1FE4[12]; //0x1FE4
//	float fearLevel; //0x1FF0
//	char pad_1FF4[4]; //0x1FF4
//	float fearDisspateRate; //0x1FF8
//	float fearSuppressScale; //0x1FFC
//	float fearThreshold; //0x2000
//	int32_t NOTEND; //0x2004
//}; //Size: 0x2008
//static_assert(sizeof(Character) == 0x2008);
//
//class Items
//{
//public:
//	class Armor* pArmor; //0x0000
//	class Helmet* pHelmet; //0x0008
//	class Primary* pPrimary; //0x0010
//	class Primary* pSecondary; //0x0018
//	class Primary* pTertiary; //0x0020
//	char pad_0028[96]; //0x0028
//}; //Size: 0x0088
//static_assert(sizeof(Items) == 0x88);
//
//class Armor
//{
//public:
//	char pad_0000[136]; //0x0000
//}; //Size: 0x0088
//static_assert(sizeof(Armor) == 0x88);
//
//class Helmet
//{
//public:
//	char pad_0000[136]; //0x0000
//}; //Size: 0x0088
//static_assert(sizeof(Helmet) == 0x88);
//
//class Primary
//{
//public:
//	char pad_0000[1328]; //0x0000
//	float movementSpeedMult; //0x0530
//	float quickLeanMult; //0x0534
//	float freeLeanMult; //0x0538
//	char pad_053C[996]; //0x053C
//	float currentAmmoDmg; //0x0920
//	char pad_0924[140]; //0x0924
//	int32_t projectileCount; //0x09B0
//	char pad_09B4[276]; //0x09B4
//	int32_t currentFireMode; //0x0AC8
//	char pad_0ACC[244]; //0x0ACC
//	float gunDmg; //0x0BC0
//	char pad_0BC4[20]; //0x0BC4
//	float shotDelay; //0x0BD8
//	char pad_0BDC[4]; //0x0BDC
//	int32_t bulletsFiredUntilAccurate; //0x0BE0
//	char pad_0BE4[8]; //0x0BE4
//	int32_t bArmorPiercing; //0x0BEC
//	char pad_0BF0[172]; //0x0BF0
//	float adsRecoilMult; //0x0C9C
//	char pad_0CA0[92]; //0x0CA0
//	float refireDelay; //0x0CFC
//	char pad_0D00[876]; //0x0D00
//	int32_t bInfiniteAmmo; //0x106C
//}; //Size: 0x1070
//static_assert(sizeof(Primary) == 0x1070);
//
//class Secondary
//{
//public:
//	char pad_0000[136]; //0x0000
//}; //Size: 0x0088
//static_assert(sizeof(Secondary) == 0x88);
//
//class Movement
//{
//public:
//	char pad_0000[1144]; //0x0000
//}; //Size: 0x0478
//static_assert(sizeof(Movement) == 0x478);
//
//class CharacterHealth
//{
//public:
//	char pad_0000[232]; //0x0000
//	float health; //0x00E8
//	float maxHealth; //0x00EC
//	char pad_00F0[152]; //0x00F0
//}; //Size: 0x0188
//static_assert(sizeof(CharacterHealth) == 0x188);
//
//class N00000D2D
//{
//public:
//	char pad_0000[136]; //0x0000
//}; //Size: 0x0088
//static_assert(sizeof(N00000D2D) == 0x88);