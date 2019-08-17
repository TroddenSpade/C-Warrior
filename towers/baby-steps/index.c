#define NUMBER_OF_LEVELS 2

struct Level
{
    int timeBonus;
    int aceScore;
    int width;
    int height;
    int stairX;
    int stairY;
    int maxHealth;
    int startX;
    int startY;
} levels[NUMBER_OF_LEVELS];

void constructor()
{
    levels[0].height = 1;
    levels[0].width = 8;
    levels[0].aceScore = 26;
    levels[0].timeBonus = 20;
    levels[0].stairX = 7;
    levels[0].stairY = 0;
    levels[0].maxHealth = 20;
    levels[0].stairX = 0;
    levels[0].stairY = 0;

    levels[1].height = 1;
    levels[1].width = 1;
    levels[1].aceScore = 1;
    levels[1].timeBonus = 1;
    levels[1].stairX = 1;
    levels[1].stairY = 1;
    levels[1].maxHealth = 1;
    levels[1].stairX = 0;
    levels[1].stairY = 0;
    puts("set");
}
