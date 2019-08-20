enum Face
{
    EAST,
    WEST
};

typedef struct Object
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
    void (*run)(struct Object *);
    enum Face face;
} Object;

Object warrior, wall, space, stairs;

typedef struct Level
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
    int objsLength;
    Object *thisLevelsObjs[];
} Level;