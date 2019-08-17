#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_RUN_TIME 100
#define LVL_HEADER "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ level ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define TURN_L "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~ "
#define TURN_R " ~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define WARRIOR &units[0]
#define WALL 'W'

int timeBonus;
int aceScore;
int stairX;
int stairY;
int health;
int score = 0;
char field[10][20];

#include "player.h"
#include "structs.c"
#include "space.c"
#include "unit.c"
#include "../towers/baby-steps/index.c"
#include "../data/player.c"

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
#define _O_TEXT 0
#endif

void setupField(int level);
void draw(int level);
void show(int level);
int run(int level)
{
    unitConstructor();
    levelConstructor();
    health = levels[level].maxHealth;
    int counter = 0;
    setupField(level);
    puts(LVL_HEADER);
    while (counter < MAX_RUN_TIME)
    {
        char turn[80];
        char step[3];
        int stp = counter++;
        snprintf(step, 4, "%03d", stp);
        strcpy(turn, TURN_L);
        strcat(turn, step);
        strcat(turn, TURN_R);
        puts(turn);

        draw(level);
        player_turn();

        sleep(2);
    }
}

void draw(int level)
{
    if (__APPLE__)
    {
        printf("%s %d\n", HEART, health);
        printf("%s %d\n", SCORE, score);
        printf("%s", UP_LEFT);
        for (int j = 0; j < levels[level].width; j++)
        {
            printf("%s", VER);
        }
        printf("%s\n", UP_RIGHT);
        for (int i = 0; i < levels[level].height; i++)
        {
            printf("%s", HOR);
            for (int j = 0; j < levels[level].width; j++)
            {
                printf("%c", field[i + 1][j + 1]);
            }
            printf("%s\n", HOR);
        }
        printf("%s", DOWN_LEFT);
        for (int j = 0; j < levels[level].width; j++)
        {
            printf("%s", VER);
        }
        printf("%s\n", DOWN_RIGHT);
    }
    else
    {
        _setmode(_fileno(stdout), 0x00020000);
        wprintf(HEART);
        _setmode(_fileno(stdout), _O_TEXT);
        printf(" %d\n", health);

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(SCORE);
        _setmode(_fileno(stdout), _O_TEXT);
        printf(" %d\n", score);

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(UP_LEFT);
        _setmode(_fileno(stdout), _O_TEXT);
        for (int j = 0; j < levels[level].width; j++)
        {
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(VER);
            _setmode(_fileno(stdout), _O_TEXT);
        }

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(UP_RIGHT);
        _setmode(_fileno(stdout), _O_TEXT);
        puts("");

        for (int i = 0; i < levels[level].height; i++)
        {
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(HOR);
            _setmode(_fileno(stdout), _O_TEXT);
            for (int j = 0; j < levels[level].width; j++)
            {
                printf("%c", field[i + 1][j + 1]);
            }
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(HOR);
            _setmode(_fileno(stdout), _O_TEXT);
            puts("");
        }

        _setmode(_fileno(stdout), 0x00020000);
        wprintf(DOWN_LEFT);
        _setmode(_fileno(stdout), _O_TEXT);
        for (int j = 0; j < levels[level].width; j++)
        {
            _setmode(_fileno(stdout), 0x00020000);
            wprintf(VER);
            _setmode(_fileno(stdout), _O_TEXT);
        }
        _setmode(_fileno(stdout), 0x00020000);
        wprintf(DOWN_RIGHT);
        _setmode(_fileno(stdout), _O_TEXT);
        puts("");
    }
}

void setupField(int level)
{

    for (int i = 0; i <= levels[level].width + 1; i++)
    {
        field[0][i] = WALL;
    }

    for (int i = 1; i <= levels[level].height; i++)
    {
        field[i][0] = WALL;
        for (int j = 1; j <= levels[level].width; j++)
        {
            field[i][j] = ' ';
        }
        field[i][levels[level].width + 1] = WALL;
    }

    for (int i = 0; i <= levels[level].width + 1; i++)
    {
        field[levels[level].height + 1][i] = WALL;
    }

    for (int i = 0; i < levels[level].unitsLength; i++)
    {
        field[levels[level].thisLevelsUnits[i].locY][levels[level].thisLevelsUnits[i].locX] = levels[level].thisLevelsUnits[i].character;
    }
}

void show(int level)
{
    for (int j = 0; j <= levels[level].height + 1; j++)
    {
        for (int i = 0; i <= levels[level].width + 1; i++)
        {
            printf("%c", field[j][i]);
        }
        puts("");
    }
}