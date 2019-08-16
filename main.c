#include "./player/player.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#define WELCOME "~~~~~~~~~~~~~~~~~~~~~~~~~~~~+*+~~~+*$#$*+~~~+*+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n                           Welcome to C Warrior!\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~+*+~~~+*$#$*+~~~+*+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
#define ENTER_NAME "? Enter a name for your warrior: "
#define ENTER_ID "? Enter your Id: "
#define SELECT_TOWER "? Choose a tower: (Use arrow keys)"
#define INIT_PLAYER_FILE "void player_turn()\n{\n    // your code goes here\n}\n"
#define CHOOSE_PROFILE "? Choose a profile: "
#define GEN_LEVEL "Level has been generated. See data/README.md for instructions."

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
void generateLevel();
void copyReadMe(int);
int runLevel();

int main()
{
    printf("%s", WELCOME);
    DIR *dir = opendir("data");
    if (dir)
    {
        FILE *fptr;
        fptr = fopen("./data/.profile", "rb");
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
        printf("%s", "corrupted files !\nget files from : https://github.com/3pic/C-Warrior");
        return 0;
    }
    // int status = runLevel();
    // if(status){
    //     generateLevel();
    // }else{

    // }

    return 0;
}

void createProfile()
{
    printf("%s", ENTER_NAME);
    scanf("%s", myProfile.name);
    printf("%s", ENTER_ID);
    scanf("%d", &myProfile.id);
    printf("%s", SELECT_TOWER);
    // scanf("%s",myProfile.tower);
    strcpy(myProfile.tower, "baby-steps");
    myProfile.level = 1;
    FILE *fptr;
    fptr = fopen("./data/.profile", "wb");
    fwrite(&myProfile, sizeof(struct Profile), 1, fptr);
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
        puts("profile selected");
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
    printf("score: %d", myProfile.level);
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
    strcat(loc, "/");
    strcat(loc, lvl);
    strcat(loc, "/rm");
    fptr1 = fopen(loc, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", "towers");
        exit(0);
    }

    fptr2 = fopen("./data/README.md", "w");
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

void generateLevel(int level)
{
    FILE *playerFile;
    playerFile = fopen("./data/player.c", "r");
    if (playerFile == NULL)
    {
        FILE *newFile;
        newFile = fopen("./data/player.c", "w");
        fprintf(newFile, "%s", INIT_PLAYER_FILE);
        fclose(newFile);
    }
    fclose(playerFile);
}