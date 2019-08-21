void sludge_run(Object *obj)
{
    Object *neighbour = _getObject(*obj, 1);
    if (neighbour != NULL && neighbour->enemy != obj->enemy)
    {
        _log(obj->name, "attacks and hits 3");
        _damage(neighbour, 3);
    }
}

void archer_run(Object *obj)
{
    Object *neighbour = _getObject(*obj, 1);
    Object *neighbour2 = _getObject(*obj, 2);
    Object *neighbour3 = _getObject(*obj, 3);
    if (neighbour != NULL && neighbour->enemy != obj->enemy)
    {
        _log(obj->name, "attacks and hits 3");
        _damage(neighbour, 3);
    }
    else if (neighbour == NULL &&
             neighbour2 != NULL &&
             neighbour2->enemy != obj->enemy)
    {
        _log(obj->name, "attacks and hits 3");
        _damage(neighbour2, 3);
    }
    else if (neighbour == NULL &&
             neighbour2 == NULL &&
             neighbour3 != NULL &&
             neighbour3->enemy != obj->enemy)
    {
        _log(obj->name, "attacks and hits 3");
        _damage(neighbour3, 3);
    }
}

void wizard_run(Object *obj)
{
    // const threatDirection = RELATIVE_DIRECTIONS.find(direction = > {
    //     const spaceWithUnit = archer
    //                               .look(direction)
    //                               .find(space = > space.isUnit());
    //     return (
    //         spaceWithUnit &&
    //         spaceWithUnit.getUnit().isEnemy() &&
    //         !spaceWithUnit.getUnit().isBound());
    // });
    // if (threatDirection)
    // {
    //     archer.shoot(threatDirection);
    // }
}