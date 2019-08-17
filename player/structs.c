struct Unit
{
    int health;
    int maxHealth;
    char name[10];
    char character;
    int reward;
    int enemy;
    int bound;
    int locX;
    int locY;
};

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
    int unitsLength;
    struct Unit thisLevelsUnits[];
};