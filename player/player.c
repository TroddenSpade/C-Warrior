#include <stdio.h>

#include <unistd.h>
#include "player.h"
#include "../towers/baby-steps/index.c"
#include "../data/player.c"

#define MAX_RUN_TIME 100
#define LVL_HEADER "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ level ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define TURN "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ~~~~~~~~~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

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

int timeBonus;
int aceScore;
int stairX;
int stairY;
int health;
int score = 0;
int locX;
int loxY;

void setupField(int level);
void draw(int level);

int run(int level)
{
    constructor();
    health = levels[level].maxHealth;
    int counter = 0;
    puts(LVL_HEADER);
    while (counter < MAX_RUN_TIME)
    {
        puts(TURN);
        draw(level);
        player_turn();
        sleep(1);
        counter++;
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
                printf("%s", " ");
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
                printf("%s", " ");
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
}

int isValid(int valids[])
{
    return 0;
}