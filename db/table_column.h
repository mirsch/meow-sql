#ifndef DB_TABLE_COLUMN_H
#define DB_TABLE_COLUMN_H

#include <QString>
#include "data_type/data_type.h"

namespace meow {
namespace db {

enum class ColumnDefaultType {
    None, // H: cdtNothing
    Text,
    TextUpdateTS,
    Null,
    NullUpdateTS,
    CurTS,
    CurTSUpdateTS,
    AutoInc
};

const QString columnDefaultType2String(ColumnDefaultType type);

class TableColumn
{
public:
    TableColumn();

    void setName(const QString & name) { _name = name; }
    QString name() const { return _name; }

    QString dataTypeName() const { // TODO: change
        return _dataType->name; } // rm ?

    void setDataType(const DataTypePtr & type) { _dataType = type; }
    const DataTypePtr & dataType() const { return _dataType; }

    void setLengthSet(const QString & len) { _lengthSet = len; }
    QString lengthSet() const { return _lengthSet; }
    int lengthAsInt() const { return _lengthSet.toInt(); }

    void setIsUnsigned(bool isUnsigned) { _unsigned = isUnsigned; }
    bool isUnsigned() const { return _unsigned; }

    void setIsZeroFill(bool isZeroFill) { _zeroFill = isZeroFill; }
    bool isZeroFill() const { return _zeroFill; }

    void setCharset(const QString & charset) { _charset = charset; }
    QString charset() const { return _charset; }

    void setCollation(const QString & collation) { _collation = collation; }
    QString collation() const { return _collation; }

    void setAllowNull(bool allowNull) { _allowNull = allowNull; }
    bool isAllowNull() const { return _allowNull; }

    void setDefaultType(ColumnDefaultType type) { _defaultType = type; }
    ColumnDefaultType defaultType() const { return _defaultType; }

    void setDefaultText(const QString & text) { _defaultText = text; }
    QString defaultText() const { return _defaultText; }

    void setComment(const QString & comment) { _comment = comment; }
    QString comment() const { return _comment; }

    unsigned id() const { return _id; }
    void setId(unsigned id) { _id = id; }

    bool dataDiffers(const TableColumn * other) const;

    operator QString() const;
private:
    QString _name;
    DataTypePtr _dataType;
    QString _lengthSet;
    bool _unsigned;
    bool _allowNull;
    bool _zeroFill;
    ColumnDefaultType _defaultType;
    QString _defaultText;
    QString _comment;
    QString _charset;
    QString _collation;
    unsigned _id;
};

} // namespace db
} // namespace meow

#endif // DB_TABLE_COLUMN_H
