#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "DataRead.h"

#define LINE_MAX_SIZE 200

MovePatternInfo gMovePatterns[10];
MonsterInfo gMonsterInfos[10];
StageInfo gStageInfos[10][10];

<<<<<<< HEAD
=======
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
	size_t size = ftell(file);
	fseek(file, 0, SEEK_SET);

	buffer = (char*)malloc(size+1);

	if (buffer == nullptr) 
	{
		printf("There is No Buffer. \n");
		return buffer;
	}

	fread(buffer, 1, size, file);
	buffer[size-3] = '\0';
	fclose(file);

	return buffer;
}

>>>>>>> 98fbef453911eaa370e9a23e7582432c487f967f
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