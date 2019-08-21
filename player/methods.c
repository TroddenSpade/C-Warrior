// void getLocation();
// int isStairs();
// int isWall();
// int isobj();
// getobj();
// void release(obj);
// void unbind();
// void rotate();
// void print(char log[]);

void _move(Object *obj)
{
    field[obj->locY][obj->locX] = &space;
    switch (obj->face)
    {
    case EAST:
        obj->locX++;
        break;
    case WEST:
        obj->locX--;
        break;
    default:
        break;
    }
    field[obj->locY][obj->locX] = obj;
}

int _isAlive(Object obj)
{
    if (obj.health > 0)
        return 1;
    return 0;
}

void _log(char name[], char mssg[])
{
    printf("%s %s\n", name, mssg);
}

int _isEmpty(Object obj)
{
    switch (obj.face)
    {
    case EAST:
        if (field[obj.locY][obj.locX + 1]->character == ' ' || field[obj.locY][obj.locX + 1]->character == '>')
            return 1;
        else
            return 0;
    case WEST:
        if (field[obj.locY][obj.locX - 1]->character == ' ' || field[obj.locY][obj.locX - 1]->character == '>')
            return 1;
        else
            return 0;
    default:
        return 0;
    }
}

Object *_getObject(Object obj, int distance)
{
    if (obj.locX - distance < 0)
        return NULL;

    switch (obj.face)
    {
    case EAST:
        if (field[obj.locY][obj.locX + distance]->character == ' ' ||
            field[obj.locY][obj.locX + distance]->character == '>' ||
            field[obj.locY][obj.locX + distance]->character == 'W')
            return NULL;
        else
            return field[obj.locY][obj.locX + distance];
    case WEST:
        if (field[obj.locY][obj.locX - distance]->character == ' ' ||
            field[obj.locY][obj.locX - distance]->character == '>' ||
            field[obj.locY][obj.locX - distance]->character == 'W')
            return NULL;
        else
            return field[obj.locY][obj.locX - distance];
    default:
        return NULL;
    }
}

void _damage(Object *obj, int damage)
{
    obj->health = obj->health - damage >= 0 ? obj->health - damage : 0;
}

void _heal(Object *obj, int amount)
{
    obj->health = obj->health + amount <= obj->maxHealth ? obj->health + amount : obj->maxHealth;
    _log(obj->name, "rests");
}

int _health(Object obj)
{
    return obj.health;
}

int _maxHealth(Object obj)
{
    return obj.maxHealth;
}