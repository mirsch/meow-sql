#ifndef DB_TABLE_STRUCTURE_PARSER_H
#define DB_TABLE_STRUCTURE_PARSER_H

#include <QList>
#include <QPair>
#include "db/data_type/data_type.h"
#include <QRegularExpression>

namespace meow {
namespace db {

class TableEntity;
class TableColumn;
class TableIndex;
class ForeignKey;
class Connection;

// TODO: make specific for each DBMS
class TableStructureParser
{
public:
    TableStructureParser(Connection * connection);
    ~TableStructureParser();
    void run(TableEntity * table);
private:
    void parseColumns(const QString & createSQL, TableEntity * table) const;
    void parseKeysIndicies(const QString & createSQL, TableEntity * table) const;
    void parseForeignKeys(const QString & createSQL, TableEntity * table) const;
    void parseTableOptions(TableEntity * table);

    QString extractId(QString & str, bool remove = true) const;
    DataTypePtr extractDataTypeByName(QString & columnString) const;
    void prepareTypes();
    QString extractLengthSet(QString & columnString) const;
    bool isStartsFromString(QString & columnString, const QString & needle) const;
    void init(TableEntity * table);
    QString extractCharset(QString & columnString) const;
    QString extractCollate(QString & columnString) const;
    bool detectAllowNull(QString & columnString) const;
    QString parseDefault(QString & columnString, TableColumn * column) const;
    bool checkForOnUpdateCurTs(QString & columnString) const;
    QString matchQuotedStr(QString & columnString) const;
    QString parseComment(QString & columnString, TableColumn * column) const;
    QStringList explodeQuotedList(QString & str) const;

    Connection * _connection;
    std::list<DataTypePtr> _typesSorted;
    bool _wasInit;
    QRegularExpression * _charsetRegexp;
    QRegularExpression * _collateRegexp;
    QRegularExpression * _defaultCurTSRegexp;
    QRegularExpression * _defaultOnUpdCurTSRegexp;
    QRegularExpression * _firstWordRegexp;
    QRegularExpression * _indiciesKeysRegexp;
    QRegularExpression * _foreignKeysRegexp;
    QRegularExpression * _tableOptionsRegexp;
    QChar _quoteChar;
};

} // namespace db
} // namespace meow

#endif // DB_TABLE_STRUCTURE_PARSER_H
