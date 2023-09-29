#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "DataRead.h"

#define LINE_MAX_SIZE 200

MovePatternInfo gMovePatterns[10];
MonsterInfo gMonsterInfos[10];
StageInfo gStageInfos[10][10];

void DataRead_MovePattern()
{
	FILE* file = nullptr;
	char line[LINE_MAX_SIZE];

	fopen_s(&file, "MovePattern/MovePatternInfo.data", "r");
	if (file == nullptr)
		return;

	fgets(line, LINE_MAX_SIZE, file);
	int fileCount = atoi(line);

	for (int i = 0; i < fileCount; i++)
	{
		char eachFileName[200] = "MovePattern/";
		fgets(line, LINE_MAX_SIZE, file);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		
		strcat_s(eachFileName, LINE_MAX_SIZE, line);

		FILE* eachFile = nullptr;

		fopen_s(&eachFile, eachFileName, "r");
		if (eachFile == nullptr)
			return;

		int lineCount = 0;
		while (fgets(line, LINE_MAX_SIZE, eachFile))
		{
			sscanf_s(line, "%i %i", &gMovePatterns[i]._dX[lineCount], &gMovePatterns[i]._dY[lineCount]);
			lineCount++;
		}

		gMovePatterns[i]._move = lineCount;

		fclose(eachFile);
	}
	
	fclose(file);
}

void DataRead_Monster()
{
	FILE* file = nullptr;
	char line[LINE_MAX_SIZE];

	fopen_s(&file, "Monster/MonsterInfo.data", "r");
	if (file == nullptr)
		return;

	fgets(line, LINE_MAX_SIZE, file);
	int fileCount = atoi(line);

	for (int i = 0; i < fileCount; i++)
	{
		char eachFileName[200] = "Monster/";
		fgets(line, LINE_MAX_SIZE, file);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		strcat_s(eachFileName, LINE_MAX_SIZE, line);

		FILE* eachFile = nullptr;

		fopen_s(&eachFile, eachFileName, "r");
		if (eachFile == nullptr)
			return;

		fgets(line, LINE_MAX_SIZE, eachFile);
		gMonsterInfos[i]._shape = *line;

		fgets(line, LINE_MAX_SIZE, eachFile);
		gMonsterInfos[i]._movePattern = atoi(line);

		fgets(line, LINE_MAX_SIZE, eachFile);
		gMonsterInfos[i]._hp = atoi(line);

		fclose(eachFile);
	}

	fclose(file);
}

int DataRead_Stage()
{
	FILE* file = nullptr;
	char line[LINE_MAX_SIZE];

	fopen_s(&file, "Stage/StageInfo.data", "r");
	if (file == nullptr)
		return -1;

	fgets(line, LINE_MAX_SIZE, file);
	int fileCount = atoi(line);

	for (int i = 0; i < fileCount; i++)
	{
		char eachFileName[200] = "Stage/";
		fgets(line, LINE_MAX_SIZE, file);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		strcat_s(eachFileName, LINE_MAX_SIZE, line);

		FILE* eachFile = nullptr;

		fopen_s(&eachFile, eachFileName, "r");
		if (eachFile == nullptr)
			return -1;

		int lineCount = 0;
		while (fgets(line, LINE_MAX_SIZE, eachFile))
		{
			int monsterPtr;
			sscanf_s(line, "%i %i %i", &monsterPtr, &gStageInfos[i][lineCount]._x
			, &gStageInfos[i][lineCount]._y);

			gStageInfos[i][lineCount]._monsterInfoPtr = &gMonsterInfos[monsterPtr - 1];

			lineCount++;
		}

		fclose(eachFile);
	}

	fclose(file);

	return fileCount;
}