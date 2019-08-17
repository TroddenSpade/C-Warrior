// void heal(int amount);
// void takeDamage(int amount);
// void damage(receiver, amount);
// void release(unit);
// void unbind();
// void rotate();
// void print(char log[]);

void move(struct Unit *unit)
{
    field[unit->locY][unit->locX] = ' ';
    unit->locX++;
    field[unit->locY][unit->locX] = unit->character;
}

int isAlive(struct Unit unit)
{
    if (unit.health > 0)
        return 1;
    return 0;
}

void cLog(struct Unit *unit, char mssg[])
{
    char log[20];
    strcpy(log, unit->name);
    strcat(log, mssg);
    puts(log);
}