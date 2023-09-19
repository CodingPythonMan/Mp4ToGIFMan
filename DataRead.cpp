#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "DataRead.h"

MovePatternInfo gMovePatterns[10];
MonsterInfo gMonsterInfos[10];
StageInfo gStageInfos[10][10];

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

	int offset = 0;
	int nextLine;
	int fileCount = 0;
	char word[100] = "";
	memset(word, 0, 100);
	while (*(movePatternInfo + offset) != '\0')
	{
		if (*(movePatternInfo + offset) == '\n')
		{
			memcpy(word, movePatternInfo, offset);
			fileCount = atoi(word);
			offset ++;
			break;
		}
		offset++;
	}

	nextLine = offset;

	for (int i = 0; i < fileCount; i++)
	{
		for (;;)
		{
			if (*(movePatternInfo + offset) == '\n' || *(movePatternInfo + offset) == '\0')
			{
				char file[100] = "MovePattern/";
				memset(word, 0, 100);
				memcpy(word, movePatternInfo + nextLine, offset - nextLine);
				offset++;
				nextLine = offset;
				strcat_s(file, sizeof(file), word);

				char* movePattern = Data_Read(file);

				int eachOffset = 0;
				int eachNextLine = 0;
				int move = 0;
				while (*(movePattern + eachOffset) != '\0')
				{
					if (*(movePattern + eachOffset) == ' ')
					{
						memset(word, 0, 100);
						memcpy(word, movePattern + eachNextLine, eachOffset - eachNextLine);
						eachNextLine = eachOffset + 1;
						gMovePatterns[i]._dX[move] = atoi(word);
					}

					if (*(movePattern + eachOffset) == '\n')
					{
						memset(word, 0, 100);
						memcpy(word, movePattern + eachNextLine, eachOffset - eachNextLine);
						eachNextLine = eachOffset + 1;
						gMovePatterns[i]._dY[move] = atoi(word);
						move++;
					}
					eachOffset++;
				}
				gMovePatterns[i]._move = move;

				free(movePattern);

				break;
			}
			offset++;
		}
	}

	free(movePatternInfo);
}

void Monster_Read()
{
	char* monsterInfo = Data_Read("Monster/MonsterInfo.data");

	int offset = 0;
	int nextLine;
	int fileCount = 0;
	char word[100] = "";
	memset(word, 0, 100);
	while (*(monsterInfo + offset) != '\0')
	{
		if (*(monsterInfo + offset) == '\n')
		{
			memcpy(word, monsterInfo, offset);
			fileCount = atoi(word);
			offset++;
			break;
		}
		offset++;
	}

	nextLine = offset;

	for (int i = 0; i < fileCount; i++)
	{
		for (;;)
		{
			if (*(monsterInfo + offset) == '\n' || *(monsterInfo + offset) == '\0')
			{
				char file[100] = "Monster/";
				memset(word, 0, 100);
				memcpy(word, monsterInfo + nextLine, offset - nextLine);
				offset++;
				nextLine = offset;
				strcat_s(file, sizeof(file), word);

				char* monster = Data_Read(file);

				int eachOffset = 0;
				int eachNextLine = 0;
				int line = 0;
				while (*(monster + eachOffset) != '\0')
				{
					if (*(monster + eachOffset) == '\n' && line == 0)
					{
						memset(word, 0, 100);
						memcpy(word, monster + eachNextLine, eachOffset - eachNextLine);
						eachNextLine = eachOffset + 1;
						gMonsterInfos[i]._shape = *word;
						line++;
					}
					else if (*(monster + eachOffset) == '\n' && line == 1)
					{
						memset(word, 0, 100);
						memcpy(word, monster + eachNextLine, eachOffset - eachNextLine);
						eachNextLine = eachOffset + 1;
						gMonsterInfos[i]._movePatternPtr = &gMovePatterns[atoi(word) - 1];
						line++;
					}
					else if (*(monster + eachOffset + 1) == '\0')
					{
						eachOffset++;
						memset(word, 0, 100);
						memcpy(word, monster + eachNextLine, eachOffset - eachNextLine);
						gMonsterInfos[i]._hp = atoi(word);
						break;
					}
					eachOffset++;
				}

				free(monster);

				break;
			}
			offset++;
		}
	}

	free(monsterInfo);
}

int Stage_Read()
{
	char* stageInfo = Data_Read("Stage/StageInfo.data");

	int offset = 0;
	int nextLine;
	int fileCount = 0;
	char word[100] = "";
	memset(word, 0, 100);
	while (*(stageInfo + offset) != '\0')
	{
		if (*(stageInfo + offset) == '\n')
		{
			memcpy(word, stageInfo, offset);
			fileCount = atoi(word);
			offset++;
			break;
		}
		offset++;
	}

	nextLine = offset;

	for (int i = 0; i < fileCount; i++)
	{
		for (;;)
		{
			if (*(stageInfo + offset) == '\n' || *(stageInfo + offset) == '\0')
			{
				char file[100] = "Stage/";
				memset(word, 0, 100);
				memcpy(word, stageInfo + nextLine, offset - nextLine);
				offset++;
				nextLine = offset;
				strcat_s(file, sizeof(file), word);

				char* stage = Data_Read(file);

				int eachOffset = 0;
				int eachNextLine = 0;
				int spaceBar = 0;
				int monster = 0;
				while (*(stage + eachOffset) != '\0')
				{
					if (*(stage + eachOffset) == ' ' && spaceBar == 0)
					{
						memset(word, 0, 100);
						memcpy(word, stage + eachNextLine, eachOffset - eachNextLine);
						eachNextLine = eachOffset + 1;
						gStageInfos[i][monster]._monsterInfoPtr = &gMonsterInfos[atoi(word) - 1];
						spaceBar++;
					}else if (*(stage + eachOffset) == ' ' && spaceBar == 1)
					{
						memset(word, 0, 100);
						memcpy(word, stage + eachNextLine, eachOffset - eachNextLine);
						eachNextLine = eachOffset + 1;
						gStageInfos[i][monster]._x = atoi(word);
						spaceBar++;
					}else if ((*(stage + eachOffset) == '\n' || *(stage + eachOffset + 1) == '\0') && spaceBar == 2)
					{
						if (*(stage + eachOffset + 1) == '\0')
						{
							eachOffset++;
							memset(word, 0, 100);
							memcpy(word, stage + eachNextLine, eachOffset - eachNextLine);
							gStageInfos[i][monster]._y = atoi(word);
							break;
						}	
						memset(word, 0, 100);
						memcpy(word, stage + eachNextLine, eachOffset - eachNextLine);
						eachNextLine = eachOffset + 1;
						gStageInfos[i][monster]._y = atoi(word);
						monster++;
						spaceBar = 0;
					}
					eachOffset++;
				}

				free(stage);

				break;
			}
			offset++;
		}
	}

	free(stageInfo);

	return fileCount;
}