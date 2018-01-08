#ifndef MODELS_TABLE_INFO_FORM_H
#define MODELS_TABLE_INFO_FORM_H

#include <QObject>
#include <QString>

namespace meow {

namespace db {
    class TableEntity;
}

namespace models {
namespace forms {

class TableIndexesModel;
class TableForeignKeysModel;

class TableInfoForm : public QObject
{
    Q_OBJECT
public:
    explicit TableInfoForm(QObject *parent = nullptr);
    ~TableInfoForm();

    void setTable(meow::db::TableEntity * table);
    meow::db::TableEntity * editableTable() const { return _table; }

    const QString tableName() const;
    void setTableName(const QString & name);

    const QString tableComment() const;

    const QString autoInc() const;
    const QString avgRowLen() const;
    const QString maxRows() const;
    const QString collation() const;
    const QString engine() const;
    const QString rowFormat() const;
    bool isCheckSum() const;

    TableIndexesModel * indexesModel();
    TableForeignKeysModel * foreignKeysModel();

    void save();

private:

    meow::db::TableEntity * _table; // copy of source table to edit
    meow::db::TableEntity * _sourceTable;
    TableIndexesModel * _indexesModel;
    TableForeignKeysModel * _fKeysModel;
};

} // namespace forms
} // namespace models
} // namespace meow

#endif // MODELS_TABLE_INFO_FORM_H
