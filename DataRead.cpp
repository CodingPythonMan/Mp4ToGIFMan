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
		char eachMovePattern[200] = "MovePattern/";
		fgets(line, LINE_MAX_SIZE, file);
		line[strlen(line) - 1] = '\0';
		
		strcat_s(eachMovePattern, LINE_MAX_SIZE, line);

		FILE* eachFile = nullptr;

		fopen_s(&eachFile, eachMovePattern, "r");
		if (eachFile == nullptr)
			return;

		int lineCount = 0;
		while (fgets(line, LINE_MAX_SIZE, eachFile))
		{
			sscanf_s(line, "%i %i", &gMovePatterns[i]._dX[lineCount], &gMovePatterns[i]._dY[lineCount]);
			lineCount++;
		}

		fclose(eachFile);
	}
	
	fclose(file);
}

void DataRead_Monster()
{
	
}

int DataRead_Stage()
{
	return -1;
}