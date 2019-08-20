#define NUMBER_OF_LEVELS 2
#define NUMBER_OF_OBJECTS 1

Level levels[NUMBER_OF_LEVELS];
Object objs[NUMBER_OF_OBJECTS];

/////////////////////////////////// Run Methods ////////////////////////////////////
void sludge_run(Object *obj);
void walk(Object *obj);

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
    levels[0].objsLength = 0;

    levels[1].height = 1;
    levels[1].width = 8;
    levels[1].aceScore = 26;
    levels[1].timeBonus = 20;
    levels[1].startX = 1;
    levels[1].startY = 1;
    levels[1].maxHealth = 20;
    levels[1].stairX = 8;
    levels[1].stairY = 1;
    levels[1].objsLength = 1;
    levels[1].thisLevelsObjs[0] = &objs[0];
}

void objConstructor()
{
    strcpy(objs[0].name, "Sludge");
    objs[0].character = 'S';
    objs[0].health = 12;
    objs[0].locX = 3;
    objs[0].locY = 1;
    objs[0].enemy = 1;
    objs[0].face = WEST;
    objs[0].run = sludge_run;
}

void walk(Object *obj)
{
    if (_isEmpty(*obj))
    {
        _move(obj);
        _log(obj->name, "is walking");
    }
    else
    {
        _log(obj->name, "can't move");
    }
}

void attack(Object *obj)
{
    // const receiver = obj.getSpaceAt(direction).getobj();
    // if (receiver)
    // {
    //     obj.log(`attacks ${direction} and hits $ { receiver }`);
    //     obj.damage(receiver, 5);
    // }
    // else
    // {
    //     obj.log(`attacks ${direction} and hits nothing`);
    // }
}

/////////////////////////////////// Run Methods ////////////////////////////////////

void sludge_run(Object *obj)
{
    if (_isEmpty(*obj))
    {
        _log(obj->name, "attacks and hits nothing!");
    }
    else
    {
        _log(obj->name, "attacks and hits 3");
        _damage(_getObject(*obj), 3);
    }
}