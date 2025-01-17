#ifndef DB_ENTITY_LIST_FOR_DATABASE_H
#define DB_ENTITY_LIST_FOR_DATABASE_H

#include <QList>

namespace meow {
namespace db {

class Entity;

// Intent: list of entities for a database
// TODO: rm?
class EntityListForDataBase
{
public:
    EntityListForDataBase();
    ~EntityListForDataBase();
    QList<Entity *> * list() { return &_entities; }
private:
    QList<Entity *> _entities;
};

} // namespace db
} // namespace meow

#endif // DB_ENTITY_LIST_FOR_DATABASE_H
