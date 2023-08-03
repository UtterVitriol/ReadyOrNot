#include "aimbot.h"

extern MyGame g_Game;

//Vec2 MyAimBot::CalcAngle(Vec3 src, Vec3 dst)
//{
//	Vec2 angle;
//	angle.x = -atan2f(dst.x - src.x, dst.y - src.y) / PI * 180.0f;
//	angle.y = -asinf((dst.z - src.z) / Get3dDistance(src, dst)) * (180.0f / PI);
//
//	return angle;
//}
//
//float MyAimBot::Get3dDistance(Vec3 to, Vec3 from)
//{
//	return
//		(sqrtf(
//			((to.x - from.x) * (to.x - from.x)) +
//			((to.y - from.y) * (to.y - from.y)) +
//			((to.z - from.z) * (to.z - from.z))
//		));
//}


Vec3 Subtract(Vec3 src, Vec3 dst)
{
	Vec3 diff;
	diff.x = src.x - dst.x;
	diff.y = src.y - dst.y;
	diff.z = src.z - dst.z;
	return diff;
}

float Magnitude(Vec3 vec)
{
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float Distance(Vec3 src, Vec3 dst)
{
	Vec3 diff = Subtract(src, dst);
	return Magnitude(diff);
}

Vec2 CalcAngle(Vec3 src, Vec3 dst)
{
	Vec2 angle;
	angle.y = -atan2f(dst.x - src.x, dst.y - src.y) / PI * 180.0f + 180.0f;
	angle.x = asinf((dst.z - src.z) / Distance(src, dst)) * 180.0f / PI;
	//angle.z = 0.0f;

	angle.y -= 90;

	return angle;
}

Vec3 MyAimBot::get_first_enemy()
{
	Suspect* pSuspects = g_Game.pLocalPlayer->pViewportClient->pWorld->pPersistentLevel->pEntityList->pGameMode->pSuspectsAndCivilianManager->pSuspects;
	int numSuspects = g_Game.pLocalPlayer->pViewportClient->pWorld->pPersistentLevel->pEntityList->pGameMode->pSuspectsAndCivilianManager->numSuspects;

	Suspect* target = NULL;

	for (int i = 0; i < numSuspects; i++)
	{
		target = &pSuspects[i];

		if (target->pCharacterHealth->health > 0)
		{
			break;
		}

	}

	if (!target)
	{
		return { 0,0,0 };
	}

	return target->pMovement->pPosition->position;
}

Vec3 MyAimBot::get_closest_enemy()
{
	Suspect** pSuspects = (Suspect**)g_Game.pLocalPlayer->pViewportClient->pWorld->pPersistentLevel->pEntityList->pGameMode->pSuspectsAndCivilianManager->pSuspects;
	int numSuspects = g_Game.pLocalPlayer->pViewportClient->pWorld->pPersistentLevel->pEntityList->pGameMode->pSuspectsAndCivilianManager->numSuspects;
	Vec3 myPos = g_Game.pCharacter->pMovement->pPosition->position;

	Suspect* temp = NULL;
	Suspect* target = NULL;

	float distance = 10000000;
	float last = 0;


	for (int i = 0; i < numSuspects; i++)
	{
		temp = pSuspects[i];

		if (temp->pCharacterHealth->health > 0)
		{
			if ((last = Distance(temp->pMovement->pPosition->position, myPos)) < distance)
			{
				distance = last;
				target = temp;
			}
		}
	}

	if (!target)
	{
		return { 0,0,0 };
	}

	tEnemy = target;

	return target->pMovement->pPosition->position;
}


Vec2 MyAimBot::get_angle()
{
	Vec3 myPos = g_Game.pCharacter->pMovement->pPosition->position;
	myPos.z += 64;
	Vec3 target = get_closest_enemy();
	target.z += 64;
	Vec2 angle = { 0 };

	if (target.x == 0 && target.y == 0 && target.z == 0)
	{
		return { 0, 0 };
	}

	enemy = target;

	angle = CalcAngle(myPos, target);
	targetAngle.x = angle.x;
	targetAngle.y = angle.y;
	g_Game.pLocalPlayer->pPlayerController->viewAngle.x = angle.x;
	g_Game.pLocalPlayer->pPlayerController->viewAngle.y = angle.y;

	return angle;
}

void MyAimBot::run()
{
	Vec2 angle = { 0 };

	angle = get_angle();

	if (angle.x == 0 && angle.y == 0)
	{
		return;
	}

	

	/*g_Game.pLocalPlayer->pPlayerController->viewAngle.x = angle.x;
	g_Game.pLocalPlayer->pPlayerController->viewAngle.y = angle.y;*/


}