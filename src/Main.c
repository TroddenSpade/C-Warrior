#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include "Logic.h"
#include "Main.h"

#define WELCOME "~~~~~~~~~~~~~~~~~~~~~~~~~~~~+*+~~~+*$#$*+~~~+*+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n                           Welcome to C Warrior!\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~+*+~~~+*$#$*+~~~+*+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
#define ENTER_NAME "? Enter a name for your warrior: "
#define ENTER_ID "? Enter your Id: "
#define SELECT_TOWER "? Choose a tower: "
#define CHOOSE_PROFILE "? Choose a profile: "
#define GEN_LEVEL "has been generated. See profile/README.md for instructions."

struct Profile
{
    char name[20];
    int id;
    int level;
    int score;
    char tower[20];
} myProfile;

void readProfile(FILE *fptr);
void createProfile();
void printProfile();
void copyReadMe(int);

int main()
{
    printf("%s", WELCOME);
    DIR *dir = opendir("profile");
    if (dir)
    {
        FILE *fptr;
        fptr = fopen("./profile/.profile", "rb");
        if (fptr == NULL)
        {
            createProfile();
        }
        else
        {
            readProfile(fptr);
        }
        fclose(fptr);
        closedir(dir);
    }
    else
    {
        printf("%s", "corrupted files !\nget files from : https://github.com/troddenspade/C-Warrior");
        return 0;
    }

    return 0;
}

void createProfile()
{
    printf("%s", ENTER_NAME);
    scanf("%s", myProfile.name);
    printf("%s", ENTER_ID);
    scanf("%d", &myProfile.id);
    printf("%s", SELECT_TOWER);
    printf("%s", "'Baby-Steps' has been set as default\n");
    // scanf("%s",myProfile.tower);
    strcpy(myProfile.tower, "baby-steps");
    setData(1, 0);
    generateLevel(1);
}

void readProfile(FILE *fptr)
{
    int choice;
    fread(&myProfile, sizeof(struct Profile), 1, fptr);
    printf("%s\n", CHOOSE_PROFILE);
    printf("%s", "1. ");
    printProfile();
    puts("");
    printf("%s", "2. NewProfile");
    puts("");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        play(myProfile.level - 1);
        break;
    case 2:
        createProfile();
        break;
    default:
        puts("invalid");
    }
}

void printProfile()
{
    printf("%s - ", myProfile.name);
    printf("%d - ", myProfile.id);
    printf("%s - ", myProfile.tower);
    printf("level %d - ", myProfile.level);
    printf("score: %d", myProfile.score);
}

void copyReadMe(int level)
{
    FILE *fptr1, *fptr2;
    char c;
    char loc[80];
    char lvl[2];
    sprintf(lvl, "%d", level);
    strcpy(loc, "./towers/");
    strcat(loc, myProfile.tower);
    strcat(loc, "/rm");
    strcat(loc, lvl);
    fptr1 = fopen(loc, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", loc);
        exit(0);
    }

    fptr2 = fopen("./profile/README.md", "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", "README.md");
        exit(0);
    }

    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    fclose(fptr1);
    fclose(fptr2);
}

void setData(int level, int score)
{
    myProfile.level = level;
    myProfile.score = score;
    FILE *fptr;
    fptr = fopen("./profile/.profile", "wb");
    fwrite(&myProfile, sizeof(struct Profile), 1, fptr);
}

void generateLevel(int level)
{
    copyReadMe(level);
    printf("Level %d %s\n", level, GEN_LEVEL);
}