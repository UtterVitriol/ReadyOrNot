#include "Game.h"

extern MyAimBot g_AimBot;
void MyGame::Start()
{
	// Get module base address.
	m_ModuleBase = (uintptr_t)GetModuleHandle(L"ReadyOrNot-Win64-Shipping.exe");

	// Get FNameTable.
	//m_FNameTable = (m_ModuleBase + m_FNameTableOffset);


	// Player character in game.
	pLocalPlayer = (LocalPlayer*)Hack::FindDMAAddy(m_ModuleBase + m_LocalPlayerFirstOffset, { 0x0 });
	pCharacter = pLocalPlayer->pPlayerController->pCharacter;
}

void MyGame::ValidateCharacter()
{
	// When we move between the base and a mission,
	// our character gets reloaded.
	//pCharacter = (Character*)Hack::FindDMAAddy(m_ModuleBase + m_CharacterFirstOffset, { 0x0, 0x20, 0x0 });
	pCharacter = pLocalPlayer->pPlayerController->pCharacter;

	if (pCharacter != pLast)
	{
		g_AimBot.bRun = false;
		while (pLocalPlayer->pPlayerController->pCharacter == NULL)
		{
		};

		pCharacter = pLocalPlayer->pPlayerController->pCharacter;
		pLast = pCharacter;
		
	}

	return;
}

void MyGame::UpdateValues()
{
	// This is our working function for our DLL.

	ValidateCharacter();

	if (!pCharacter)
	{
		pLast = NULL;
	}

	return;
}

void MyGame::ExitMission()
{
	

}

void SetName(char* toSet, char* str)
{
	memset(toSet, 0, MAX_FNAME_LEN);

	for (int i = 0; i < MAX_FNAME_LEN; i++)
	{
		if (isascii(str[i]) && str[i] > 32)
		{
			toSet[i] = str[i];
		}
		else
		{
			return;
		}
	}
	return;
}

char* MyGame::GetFName(uint32_t index, char* destination)
{
	char* Name = (char*)"Name Not Found";

	uint32_t FNameIndex = index;

	if (FNameIndex < 1)
	{
		return Name;
	}

	uint32_t NumElements = (uint32_t)m_FNameTable + 0xC;
	uint32_t NumChunks = (uint32_t)m_FNameTable + 0x8;
	uint32_t ChunkIndex = FNameIndex >> 16;
	uint32_t NameIndex = (FNameIndex << 16) >> 16;

	if (NameIndex < NumElements && ChunkIndex < NumChunks)
	{
		uintptr_t ChunkPtr = *(uintptr_t*)(m_FNameTable + ((ChunkIndex + 0x2) * 0x8));

		if (ChunkPtr)
		{
			uintptr_t NamePtr = (ChunkPtr + (NameIndex * 2));
			uintptr_t NameEntryIndex = *(uintptr_t*)(NamePtr);
			Name = (char*)(NamePtr + 0x2);
			if (destination)
			{
				SetName(destination, Name);
			}
		}
	}
	return Name;
}

