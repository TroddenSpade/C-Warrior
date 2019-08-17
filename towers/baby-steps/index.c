#define NUMBER_OF_LEVELS 2
#define NUMBER_OF_UNITS 2

struct Level levels[NUMBER_OF_LEVELS];
struct Unit units[NUMBER_OF_UNITS];

void levelConstructor()
{
    levels[0].height = 1;
    levels[0].width = 8;
    levels[0].aceScore = 26;
    levels[0].timeBonus = 20;
    levels[0].startX = 1;
    levels[0].startY = 1;
    levels[0].maxHealth = 20;
    levels[0].stairX = 8;
    levels[0].stairY = 1;
    levels[0].unitsLength = 1;
    levels[0].thisLevelsUnits[0] = units[0];
}

void unitConstructor()
{
    units[0].character = '@';
    units[0].health = 20;
    units[0].locX = 1;
    units[0].locY = 1;
    units[0].enemy = 0;
    strcpy(units[0].name, "Warrior");
}

void walk(struct Unit *unit)
{
    if (isEmpty())
    {
        move(unit);

        cLog(unit, "is moving");
    }
    else
    {
        cLog(unit, "cant move");
    }
}