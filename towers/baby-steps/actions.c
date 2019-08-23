void walk(Object *obj)
{
    __S_A_C__

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
    __S_A_C__

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

int isEmpty(Object *obj)
{
    return _isEmpty(*obj) ? 1 : 0;
}

int health(Object *obj)
{
    return _health(*obj);
}

int maxHealth(Object *obj)
{
    return _maxHealth(*obj);
}

void rest(Object *obj)
{
    __S_A_C__

    _heal(obj, 1 / 10. * obj->maxHealth);
    _log(obj->name, "receives 2 health");
}

void rescue(Object *obj)
{
    __S_A_C__

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