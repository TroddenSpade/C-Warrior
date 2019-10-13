typedef struct Warrior
{
    void (*walk)();
} Warrior;

Warrior *warrior ;

void walk()
{
    __S_A_C__

    Object *obj = &__warrior;

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

void attack()
{
    __S_A_C__

    Object *obj = &__warrior;


    if (_isEmpty(*obj))
    {
        _log(obj->name, "attacks and hits nothing!");
    }
    else
    {
        _log(obj->name, "attacks and hits 5");
        _damage(_getObject(*obj, 1), 5);
    }
}

int isEmpty()
{
    Object *obj = &__warrior;

    return _isEmpty(*obj) ? 1 : 0;
}

int health()
{
    Object *obj = &__warrior;

    return _health(*obj);
}

int maxHealth()
{
    Object *obj = &__warrior;

    return _maxHealth(*obj);
}

void rest()
{
    __S_A_C__
    
    Object *obj = &__warrior;

    _heal(obj, 1 / 10. * obj->maxHealth);
    _log(obj->name, "receives 2 health");
}

void rescue()
{
    __S_A_C__

    Object *obj = &__warrior;

    Object *neighbour = _getObject(*obj, 1);
    if (neighbour != NULL && _isBound(*neighbour))
    {
        _release(neighbour);
        _log(obj->name, "unbinds forward and rescues a Captive");
    }
    else
    {
        _log(obj->name, "unbinds forward and rescues nothing");
    }
}

int isBound(Object *obj)
{
    Object *neighbour = _getObject(*obj, 1);
    if (neighbour != NULL)
    {
        return _isBound(*neighbour);
    }
    return 0;
}

void pivot(Object *obj)
{
    __S_A_C__

    _rotate(obj);
    _log(obj->name, "pivots.");
}

void constructor()
{
    warrior = malloc(sizeof(Warrior));

    warrior->walk = &walk;
}