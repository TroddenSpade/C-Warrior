#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "player.h"
#include "../main.h"
#include "structs.c"

#define SLEEP_TIME 1
#define MAX_RUN_TIME 100
#define Warrior &warrior
#define LVL_HEADER "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LEVEL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define TURN_L "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~ "
#define TURN_R " ~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define WALL 'W'
#define __S_A_C__ call++;

int call = 0;
int isLevelOn = 1;
int timeBonus;
int aceScore;
int score = 0;
struct Object *field[10][20];
int objectStat[100];

#include "methods.c"
#include "../towers/baby-steps/index.c"
#include "../data/Player.c"

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#define HEART L"\u2665"
#define SCORE L"\u2666"
#define UP_LEFT L"\u2554"
#define UP_RIGHT L"\u2557"
#define DOWN_LEFT L"\u255a"
#define DOWN_RIGHT L"\u255d"
#define VER L"\u2550"
#define HOR L"\u2551"
#define __APPLE__ 0
#else
#define HEART "\u2665"
#define SCORE "\u2666"
#define UP_LEFT "\u2554"
#define UP_RIGHT "\u2557"
#define DOWN_LEFT "\u255a"
#define DOWN_RIGHT "\u255d"
#define VER "\u2550"
#define HOR "\u2551"
#define _WIN32 0
#endif

void setupField();
void setupObjects();
void draw();
void show();
void check(int level);
void objectsRun();
void resetCall();
void cleaner();

int play(int level)
{
    initialLevels();
    functions[level]();
    setupObjects();
    setupField();
    puts(LVL_HEADER);

    printf("%s000%s\n", TURN_L, TURN_R);
    draw();
    sleep(SLEEP_TIME);
    int counter = 1;
    while (isLevelOn)
    {
        char turn[80];
        char step[3];
        int stp = counter++;
        snprintf(step, 4, "%03d", stp);
        strcpy(turn, TURN_L);
        strcat(turn, step);
        strcat(turn, TURN_R);
        puts(turn);

        playTurn();
        objectsRun();
        cleaner();
        draw();
        check(level);
        resetCall();
        sleep(SLEEP_TIME);
    }
}

void draw()
{
    if (__APPLE__)
    {
        printf("%s %d\n", HEART, warrior.health);
        printf("%s %d\n", SCORE, score);
        printf("%s", UP_LEFT);
        for (int j = 0; j < levelStruct.width; j++)
        {
            printf("%s", VER);
        }
        printf("%s\n", UP_RIGHT);
        for (int i = 0; i < levelStruct.height; i++)
        {
            printf("%s", HOR);
            for (int j = 0; j < levelStruct.width; j++)
            {
                printf("%c", field[i + 1][j + 1]->character);
            }
            printf("%s\n", HOR);
        }
        printf("%s", DOWN_LEFT);
        for (int j = 0; j < levelStruct.width; j++)
        {
            printf("%s", VER);
        }
        printf("%s\n", DOWN_RIGHT);
    }
    else
    {
        _setmode(_fileno(stdout), 0x00020000);
        wprintf(HEART);
        _setmode(_fileno(stdout), 0x4000);
        printf(" %d\n", warrior.health);

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(SCORE);
        _setmode(_fileno(stdout), 0x4000);
        printf(" %d\n", score);

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(UP_LEFT);
        _setmode(_fileno(stdout), 0x4000);
        for (int j = 0; j < levelStruct.width; j++)
        {
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(VER);
            _setmode(_fileno(stdout), 0x4000);
        }

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(UP_RIGHT);
        _setmode(_fileno(stdout), 0x4000);
        puts("");

        for (int i = 0; i < levelStruct.height; i++)
        {
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(HOR);
            _setmode(_fileno(stdout), 0x4000);
            for (int j = 0; j < levelStruct.width; j++)
            {
                printf("%c", field[i + 1][j + 1]->character);
            }
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(HOR);
            _setmode(_fileno(stdout), 0x4000);
            puts("");
        }

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(DOWN_LEFT);
        _setmode(_fileno(stdout), 0x4000);
        for (int j = 0; j < levelStruct.width; j++)
        {
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(VER);
            _setmode(_fileno(stdout), 0x4000);
        }
        _setmode(_fileno(stdout), 0x00020000);
        wprintf(DOWN_RIGHT);
        _setmode(_fileno(stdout), 0x4000);
        puts("");
    }
}

void setupField()
{

    for (int i = 0; i <= levelStruct.width + 1; i++)
    {
        field[0][i] = &wall;
    }

    for (int i = 1; i <= levelStruct.height; i++)
    {
        field[i][0] = &wall;

        for (int j = 1; j <= levelStruct.width; j++)
        {
            field[i][j] = &space;
        }
        field[i][levelStruct.width + 1] = &wall;
    }

    for (int i = 0; i <= levelStruct.width + 1; i++)
    {
        field[levelStruct.height + 1][i] = &wall;
    }

    field[levelStruct.stairY][levelStruct.stairX] = &stairs;

    for (int i = 0; i < levelStruct.objsLength; i++)
    {
        field[levelStruct.thisLevelsObjs[i]->locY][levelStruct.thisLevelsObjs[i]->locX] = levelStruct.thisLevelsObjs[i];
    }

    warrior.locX = levelStruct.startX;
    warrior.locY = levelStruct.startY;
    field[warrior.locY][warrior.locX] = &warrior;
}

void show()
{
    for (int j = 0; j <= levelStruct.height + 1; j++)
    {
        for (int i = 0; i <= levelStruct.width + 1; i++)
        {
            printf("%s ,", field[j][i]->name);
        }
        puts("");
    }
}

void check(int level)
{
    if (warrior.health == 0)
    {
        isLevelOn = 0;
        printf("Warrior Died!, you failed level %d", level + 1);
    }
    else if (call > 1)
    {
        isLevelOn = 0;
        printf("Only one action can be performed per turn.\n");
    }
    else if (warrior.locX == levelStruct.stairX && warrior.locY == levelStruct.stairY)
    {
        isLevelOn = 0;
        printf("%s", "Well Done! ");
        generateLevel(level + 2, 0);
    }
}

void setupObjects()
{
    for (int i = 0; i < levelStruct.objsLength; i++)
    {
        objectStat[i] = 1;
    }

    warrior.character = '@';
    warrior.health = 20;
    warrior.maxHealth = 20;
    warrior.locX = 1;
    warrior.locY = 1;
    warrior.enemy = 0;
    warrior.face = EAST;
    strcpy(warrior.name, "Warrior");

    wall.character = 'W';
    wall.enemy = 0;
    strcpy(wall.name, "Wall");

    space.character = ' ';
    space.enemy = 0;
    strcpy(space.name, "Space");

    stairs.character = '>';
    stairs.enemy = 0;
    strcpy(stairs.name, "Stairs");
}

void objectsRun()
{
    for (int i = 0; i < levelStruct.objsLength; i++)
    {
        if (levelStruct.thisLevelsObjs[i]->health > 0)
            levelStruct.thisLevelsObjs[i]->run(levelStruct.thisLevelsObjs[i]);
    }
}

void resetCall()
{
    call = 0;
}

void cleaner()
{
    for (int i = 0; i < levelStruct.objsLength; i++)
    {
        if (levelStruct.thisLevelsObjs[i]->health == 0 && objectStat[i] == 1)
        {
            field[levelStruct.thisLevelsObjs[i]->locY][levelStruct.thisLevelsObjs[i]->locX] = &space;
            objectStat[i] = 0;
        }
        if (objectStat[i] == 1 &&
            levelStruct.thisLevelsObjs[i]->enemy == 0 &&
            levelStruct.thisLevelsObjs[i]->bound == 0)
        {
            field[levelStruct.thisLevelsObjs[i]->locY][levelStruct.thisLevelsObjs[i]->locX] = &space;
            objectStat[i] = 0;
        }
    }
}