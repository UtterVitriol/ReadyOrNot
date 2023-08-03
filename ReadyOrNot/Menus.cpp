#include "Menus.h"
#include <string>



extern MyGame g_Game;
extern MyAimBot g_AimBot;

void MyMenu()
{
	const float MAX_SCALE = 3.0F;
	const float MIN_SCALE = 0.3F;

	ImGuiIO& io = ImGui::GetIO();
	ImGuiWindowFlags window_flags = 0;

	static float window_scale = 1.5f;

	static bool bShowAppLog = false;
	static bool bShowPlayerMenu = false;
	static bool bShowAimBotMenu = false;

	if (!ImGui::Begin("Tingle's Internal Trainer", (bool*)0, ImGuiWindowFlags_MenuBar))
	{
		ImGui::End();
		return;
	}

	ImGui::PushItemWidth(ImGui::GetFontSize() * -12);

	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("Menu"))
		{
			ImGui::MenuItem("Log", NULL, &bShowAppLog);
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::Text("Press END to Eject :)");
	//ImGui::SeparatorText("Disclaimer");
	//ImGui::TextWrapped("Making more than 1,000 voxel changes might crash the game. E.G. You set your autocannon fire rate to 100 and shoot for a while.");
	ImGui::Separator();

	if (ImGui::CollapsingHeader("Set Values"))
	{
		if (ImGui::BeginTable("split", 4))
		{
			ImGui::TableNextColumn();  ImGui::Checkbox("Player", &bShowPlayerMenu);
			ImGui::TableNextColumn();  ImGui::Checkbox("Aimbot", &bShowAimBotMenu);

			ImGui::EndTable();

		}

	}

	if (ImGui::CollapsingHeader("Settings")) {
		ImGui::DragFloat("global scale", &io.FontGlobalScale, 0.005f, MIN_SCALE, MAX_SCALE, "%.2f", ImGuiSliderFlags_AlwaysClamp); // Scale everything
	}

	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);

	ImGui::End();


	if (bShowPlayerMenu)
	{
		PlayerMenu();
	}

	if (bShowAimBotMenu)
	{
		AimBotMenu();
	}

	if (bShowAppLog)
	{
		LogMenu();
	}

}

/// <summary>
/// Shows the debug log
/// </summary>
static void LogMenu()
{
	ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
	g_Game.log.Draw("Debug Log");
}


/// <summary>
/// Shows Player
/// </summary>
void PlayerMenu()
{
	ImGui::Begin("Player");

	ImGuiInputTextFlags_;
	ImGui::SeparatorText("Primary");
	ImGui::InputInt("Fire Mode##primary", &g_Game.pCharacter->pItems->pPrimary->currentFireMode);
	ImGui::InputFloat("Show Delay##primary", &g_Game.pCharacter->pItems->pPrimary->shotDelay, 1, 100, "%.3f");
	ImGui::InputFloat("Refire Delay##primary", &g_Game.pCharacter->pItems->pPrimary->refireDelay, 1, 100, "%.3f");
	ImGui::InputFloat("ADS Recoil Mult##primary", &g_Game.pCharacter->pItems->pPrimary->adsRecoilMult, 1, 100, "%.3f");
	ImGui::Checkbox("Infinite Ammo##primary", (bool*)(&g_Game.pCharacter->pItems->pPrimary->bInfiniteAmmo));

	ImGui::SeparatorText("Secondary");
	ImGui::InputInt("Fire Mode##secondary", &g_Game.pCharacter->pItems->pSecondary->currentFireMode);
	ImGui::InputFloat("Show Delay##secondary", &g_Game.pCharacter->pItems->pSecondary->shotDelay, 1, 100, "%.3f");
	ImGui::InputFloat("Refire Delay##secondary", &g_Game.pCharacter->pItems->pSecondary->refireDelay, 1, 100, "%.3f");
	ImGui::InputFloat("ADS Recoil Mult##secondary", &g_Game.pCharacter->pItems->pSecondary->adsRecoilMult, 1, 100, "%.3f");
	ImGui::Checkbox("Infinite Ammo##secondary", (bool*)(&g_Game.pCharacter->pItems->pSecondary->bInfiniteAmmo));

	ImGui::SeparatorText("Tertiary");
	ImGui::InputInt("Fire Mode##tertiary", &g_Game.pCharacter->pItems->pTertiary->currentFireMode);
	ImGui::InputFloat("Show Delay##tertiary", &g_Game.pCharacter->pItems->pTertiary->shotDelay, 1, 100, "%.3f");
	ImGui::InputFloat("Refire Delay##tertiary", &g_Game.pCharacter->pItems->pTertiary->refireDelay, 1, 100, "%.3f");
	ImGui::InputFloat("ADS Recoil Mult##tertiary", &g_Game.pCharacter->pItems->pTertiary->adsRecoilMult, 1, 100, "%.3f");
	ImGui::Checkbox("Infinite Ammo##tertiary", (bool*)(&g_Game.pCharacter->pItems->pTertiary->bInfiniteAmmo));

	ImGui::SeparatorText("Melee");
	ImGui::InputFloat("Melee Damage", &g_Game.pCharacter->meleeDamage, 1, 100, "%.3f");
	ImGui::InputFloat("Melee Range", &g_Game.pCharacter->meleeRange, 1, 100, "%.3f");

	ImGui::SeparatorText("Health");
	ImGui::InputFloat("Health", &g_Game.pCharacter->pCharacterHealth->health, 1, 100, "%.3f");
	ImGui::InputFloat("Max Health", &g_Game.pCharacter->pCharacterHealth->maxHealth, 1, 100, "%.3f");

	ImGui::SeparatorText("Speeed");
	ImGui::InputFloat("Run Speed", &g_Game.pCharacter->runSpeed, 1, 100, "%.3f");
	ImGui::InputFloat("Acceleration", &g_Game.pCharacter->maxAccel, 1, 100, "%.3f");

	ImGui::End();
}

void AimBotMenu()
{
	static Vec3 toTeleport = { 0 };
	ImGui::Begin("AimBot");
	ImGui::InputFloat3("Your Position", (float*)&g_Game.pCharacter->pMovement->pPosition->position, "%.03f");
	ImGui::InputFloat3("Target Position", (float*)&g_AimBot.enemy, "%.03f");
	ImGui::InputFloat3("Target Angle", (float*)&g_AimBot.targetAngle, "%.03f");
	DMSGP(g_AimBot.tEnemy);
	ImGui::Checkbox("Enable", &g_AimBot.bRun);

	ImGui::SeparatorText("Teleport");
	ImGui::InputFloat3("Position", (float*)&toTeleport, "%.03f");
	if (ImGui::Button("Tele"))
	{
		g_Game.pCharacter->pMovement->pPosition->position = toTeleport;
	}
	
	ImGui::End();

}



