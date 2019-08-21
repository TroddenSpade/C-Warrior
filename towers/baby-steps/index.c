#include "actions.c"
#include "runs.c"

#define NUMBER_OF_LEVELS 4
#define NUMBER_OF_LEVEL_1_OBJECTS 0
#define NUMBER_OF_LEVEL_2_OBJECTS 1
#define NUMBER_OF_LEVEL_3_OBJECTS 4
#define NUMBER_OF_LEVEL_4_OBJECTS 3
#define NUMBER_OF_LEVEL_5_OBJECTS 0

Object lvl_1_objs[NUMBER_OF_LEVEL_1_OBJECTS];
Object lvl_2_objs[NUMBER_OF_LEVEL_2_OBJECTS];
Object lvl_3_objs[NUMBER_OF_LEVEL_3_OBJECTS];
Object lvl_4_objs[NUMBER_OF_LEVEL_4_OBJECTS];

Level levelStruct;
Function functions[NUMBER_OF_LEVELS];

void level1();
void level2();
void level3();
void level4();

void initialLevels()
{
    functions[0] = &level1;
    functions[1] = &level2;
    functions[2] = &level3;
    functions[3] = &level4;
}

void level1()
{
    levelStruct.height = 1;
    levelStruct.width = 8;
    levelStruct.aceScore = 26;
    levelStruct.timeBonus = 20;
    levelStruct.startX = 1;
    levelStruct.startY = 1;
    levelStruct.maxHealth = 20;
    levelStruct.stairX = 8;
    levelStruct.stairY = 1;
    levelStruct.objsLength = NUMBER_OF_LEVEL_1_OBJECTS;
}

void level2()
{
    strcpy(lvl_2_objs[0].name, "Sludge");
    lvl_2_objs[0].character = 'S';
    lvl_2_objs[0].health = 12;
    lvl_2_objs[0].locX = 4;
    lvl_2_objs[0].locY = 1;
    lvl_2_objs[0].enemy = 1;
    lvl_2_objs[0].face = WEST;
    lvl_2_objs[0].run = &sludge_run;

    levelStruct.height = 1;
    levelStruct.width = 8;
    levelStruct.aceScore = 26;
    levelStruct.timeBonus = 20;
    levelStruct.startX = 1;
    levelStruct.startY = 1;
    levelStruct.maxHealth = 20;
    levelStruct.stairX = 8;
    levelStruct.stairY = 1;
    levelStruct.objsLength = NUMBER_OF_LEVEL_2_OBJECTS;
    levelStruct.thisLevelsObjs[0] = &lvl_2_objs[0];
}

void level3()
{
    strcpy(lvl_3_objs[0].name, "Sludge");
    lvl_3_objs[0].character = 'S';
    lvl_3_objs[0].health = 12;
    lvl_3_objs[0].locX = 3;
    lvl_3_objs[0].locY = 1;
    lvl_3_objs[0].enemy = 1;
    lvl_3_objs[0].face = WEST;
    lvl_3_objs[0].run = &sludge_run;

    strcpy(lvl_3_objs[1].name, "Sludge");
    lvl_3_objs[1].character = 'S';
    lvl_3_objs[1].health = 12;
    lvl_3_objs[1].locX = 5;
    lvl_3_objs[1].locY = 1;
    lvl_3_objs[1].enemy = 1;
    lvl_3_objs[1].face = WEST;
    lvl_3_objs[1].run = &sludge_run;

    strcpy(lvl_3_objs[2].name, "Sludge");
    lvl_3_objs[2].character = 'S';
    lvl_3_objs[2].health = 12;
    lvl_3_objs[2].locX = 6;
    lvl_3_objs[2].locY = 1;
    lvl_3_objs[2].enemy = 1;
    lvl_3_objs[2].face = WEST;
    lvl_3_objs[2].run = &sludge_run;

    strcpy(lvl_3_objs[3].name, "Sludge");
    lvl_3_objs[3].character = 'S';
    lvl_3_objs[3].health = 12;
    lvl_3_objs[3].locX = 8;
    lvl_3_objs[3].locY = 1;
    lvl_3_objs[3].enemy = 1;
    lvl_3_objs[3].face = WEST;
    lvl_3_objs[3].run = &sludge_run;

    levelStruct.height = 1;
    levelStruct.width = 9;
    levelStruct.aceScore = 26;
    levelStruct.timeBonus = 20;
    levelStruct.startX = 1;
    levelStruct.startY = 1;
    levelStruct.maxHealth = 20;
    levelStruct.stairX = 9;
    levelStruct.stairY = 1;
    levelStruct.objsLength = NUMBER_OF_LEVEL_3_OBJECTS;
    levelStruct.thisLevelsObjs[0] = &lvl_3_objs[0];
    levelStruct.thisLevelsObjs[1] = &lvl_3_objs[1];
    levelStruct.thisLevelsObjs[2] = &lvl_3_objs[2];
    levelStruct.thisLevelsObjs[3] = &lvl_3_objs[3];
}

void level4()
{
    strcpy(lvl_4_objs[0].name, "Thick Sludge");
    lvl_4_objs[0].character = 'S';
    lvl_4_objs[0].health = 19;
    lvl_4_objs[0].locX = 3;
    lvl_4_objs[0].locY = 1;
    lvl_4_objs[0].enemy = 1;
    lvl_4_objs[0].face = WEST;
    lvl_4_objs[0].run = &sludge_run;

    strcpy(lvl_4_objs[1].name, "Archer");
    lvl_4_objs[1].character = 'a';
    lvl_4_objs[1].health = 7;
    lvl_4_objs[1].locX = 4;
    lvl_4_objs[1].locY = 1;
    lvl_4_objs[1].enemy = 1;
    lvl_4_objs[1].face = WEST;
    lvl_4_objs[1].run = &archer_run;

    strcpy(lvl_4_objs[2].name, "Thick Sludge");
    lvl_4_objs[2].character = 'S';
    lvl_4_objs[2].health = 19;
    lvl_4_objs[2].locX = 6;
    lvl_4_objs[2].locY = 1;
    lvl_4_objs[2].enemy = 1;
    lvl_4_objs[2].face = WEST;
    lvl_4_objs[2].run = &sludge_run;

    levelStruct.height = 1;
    levelStruct.width = 7;
    levelStruct.aceScore = 26;
    levelStruct.timeBonus = 20;
    levelStruct.startX = 1;
    levelStruct.startY = 1;
    levelStruct.maxHealth = 20;
    levelStruct.stairX = 7;
    levelStruct.stairY = 1;
    levelStruct.objsLength = NUMBER_OF_LEVEL_4_OBJECTS;
    levelStruct.thisLevelsObjs[0] = &lvl_4_objs[0];
    levelStruct.thisLevelsObjs[1] = &lvl_4_objs[1];
    levelStruct.thisLevelsObjs[2] = &lvl_4_objs[2];
}