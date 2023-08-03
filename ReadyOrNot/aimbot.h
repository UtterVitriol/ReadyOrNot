#pragma once

#include "GameData.h"
#include"Game.h"
#include <cmath>

#define PI 3.14159265358979323846f

class MyAimBot
{
public:
	bool bRun = false;
	void run();
	Vec3 enemy = { 0 };
	Vec3 targetAngle = { 0 };
	Suspect* tEnemy = NULL;

private:
	Vec3 get_first_enemy();
	Vec3 get_closest_enemy();
	Vec2 get_angle();
	/*Vec2 CalcAngle(Vec3 src, Vec3 dst);
	float Get3dDistance(Vec3 to, Vec3 from);*/
};

