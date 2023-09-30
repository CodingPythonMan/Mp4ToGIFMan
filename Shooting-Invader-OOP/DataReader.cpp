#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "DataReader.h"

void DataReader::ReadMovePattern()
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
			sscanf_s(line, "%i %i", &MovePatterns[i]._dX[lineCount], &MovePatterns[i]._dY[lineCount]);
			lineCount++;
		}

		MovePatterns[i]._move = lineCount;

		fclose(eachFile);
	}

	fclose(file);
}

void DataReader::ReadMonster()
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
		MonsterInfos[i]._shape = *line;

		fgets(line, LINE_MAX_SIZE, eachFile);
		MonsterInfos[i]._movePattern = atoi(line);

		fgets(line, LINE_MAX_SIZE, eachFile);
		MonsterInfos[i]._hp = atoi(line);

		fclose(eachFile);
	}

	fclose(file);
}

int DataReader::ReadStage()
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
			sscanf_s(line, "%i %i %i", &monsterPtr, &StageInfos[i][lineCount]._x
				, &StageInfos[i][lineCount]._y);

			StageInfos[i][lineCount]._monsterInfoPtr = &MonsterInfos[monsterPtr - 1];

			lineCount++;
		}

		fclose(eachFile);
	}

	fclose(file);

	return fileCount;
}