#include <stdio.h>
#include <unistd.h>
#include "player.h"
#include "../towers/baby-steps/index.c"
#include "../data/player.c"

#define MAX_RUN_TIME 100
#define LVL_HEADER "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ level ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define TURN "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ next turn ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
#define HEART "\u2764"
#define SCORE "\u2666"
#define UP_LEFT "\u2554"
#define UP_RIGHT "\u2557"
#define DOWN_LEFT "\u255a"
#define DOWN_RIGHT "\u255d"
#define VER "\u2550"
#define HOR "\u2551"

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
        sleep(2);
        counter++;
    }
}

void draw(int level)
{
    printf("%c %d\n", HEART, health);
    printf("%c %d\n", SCORE, score);
    printf("%c", UP_LEFT);
    for (int j = 0; j < levels[level].width; j++)
    {
        printf("%c", VER);
    }
    printf("%c\n", UP_RIGHT);
    for (int i = 0; i < levels[level].height; i++)
    {
        printf("%c", HOR);
        for (int j = 0; j < levels[level].width; j++)
        {
            printf("%c", " ");
        }
        printf("%c\n", HOR);
    }
    printf("%c", DOWN_LEFT);
    for (int j = 0; j < levels[level].width; j++)
    {
        printf("%c", VER);
    }
    printf("%c\n", DOWN_RIGHT);
}

void setupField(int level)
{
}

int isValid(int valids[])
{
    return 0;
}