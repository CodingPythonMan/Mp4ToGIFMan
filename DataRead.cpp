#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "DataRead.h"

MovePatternInfo* gMovePatterns[10];
MonsterInfo* gMonsterInfos[10];

char* Data_Read(const char* data)
{
	char* buffer = nullptr;
	FILE* file = nullptr;
	fopen_s(&file, data, "r");

	if (file == nullptr) // warning C6387 : 파일 없음 예외 처리를 해 주어야 한다.
	{
		printf("There is No File. \n");
		return buffer;
	}

	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);

	buffer = (char*)malloc(size);

	if (buffer == nullptr)
	{
		printf("There is No Buffer. \n");
		return buffer;
	}

	fread(buffer, 1, size, file);
	fclose(file);

	return buffer;
}

void MovePattern_Read()
{
	char* movePatternInfo = Data_Read("MovePattern/MovePatternInfo.data");
	char* movePattern;

	int pos = 0;
	int fileCount = 0;
	char word[100] = "";
	memset(word, 0, 100);
	while (*(movePatternInfo + pos) != '\0')
	{
		if (*(movePatternInfo + pos) == '\n')
		{
			memcpy(word, movePatternInfo, pos);
			fileCount = atoi(word);
			movePatternInfo += pos + 1;
			break;
		}
		pos++;
	}

	for (int i = 0; i < fileCount; i++)
	{
		for (;;)
		{
			if (*(movePatternInfo + pos) == '\n')
			{
				char file[100] = "MovePattern/";
				memset(word, 0, 100);
				memcpy(word, movePatternInfo, pos);
				strcat_s(file, sizeof(file), word);

				movePattern = Data_Read(file);

				int movePos = 0;
				int move = 1;
				MovePatternInfo movePatternStruct;
				gMovePatterns[i] = &movePatternStruct;
				while (*(movePattern + movePos) != '\0')
				{
					if (*(movePattern + movePos) == ' ')
					{
						memset(word, 0, 100);
						memcpy(word, movePattern, movePos);
						movePattern += movePos + 1;
						movePos = 0;
						gMovePatterns[i]->_dX[move] = atoi(word);
					}

					if (*(movePattern + movePos) == '\n')
					{
						memset(word, 0, 100);
						memcpy(word, movePattern, movePos);
						movePattern += movePos + 1;
						movePos = 0;
						gMovePatterns[i]->_dY[move] = atoi(word);
						move++;
					}
					movePos++;
				}
				gMovePatterns[i]->_move = move;

				break;
			}
			pos++;
		}
	}
}

void Monster_Read()
{
	char* monsterInfo = Data_Read("Monster/MonsterInfo.data");
	char* monster;

	int pos = 0;
	int fileCount = 0;
	char word[100] = "";
	memset(word, 0, 100);
	while (*(monsterInfo + pos) != '\0')
	{
		if (*(monsterInfo + pos) == '\n')
		{
			memcpy(word, monsterInfo, pos);
			fileCount = atoi(word);
			monsterInfo += pos + 1;
			break;
		}
		pos++;
	}

	for (int i = 0; i < fileCount; i++)
	{
		for (;;)
		{
			if (*(monsterInfo + pos) == '\n')
			{
				char file[100] = "Monster/";
				memset(word, 0, 100);
				memcpy(word, monsterInfo, pos);
				strcat_s(file, sizeof(file), word);

				monster = Data_Read(file);

				int monsterPos = 0;
				MonsterInfo monsterStruct;
				gMonsterInfos[i] = &monsterStruct;

				int line = 0;
				while (*(monster + monsterPos) != '\0')
				{
					if (*(monster + monsterPos) == '\n' && line == 0)
					{
						memset(word, 0, 100);
						memcpy(word, monster, monsterPos);
						monster += monsterPos + 1;
						monsterPos = 0;
						gMonsterInfos[i]->_shape = *word;
						line++;
					}

					if (*(monster + monsterPos) == '\n' && line == 1)
					{
						memset(word, 0, 100);
						memcpy(word, monster, monsterPos);
						monster += monsterPos + 1;
						monsterPos = 0;
						int index = atoi(word);
						gMonsterInfos[i]->_movePatternPtr = gMovePatterns[index];
						line++;
					}

					if (*(monster + monsterPos) == '\n' && line == 2)
					{
						memset(word, 0, 100);
						memcpy(word, monster, monsterPos);
						monster += monsterPos + 1;
						monsterPos = 0;
						gMonsterInfos[i]->_hp = atoi(word);
						line++;
						break;
					}
					monsterPos++;
				}

				break;
			}
			pos++;
		}
	}
}