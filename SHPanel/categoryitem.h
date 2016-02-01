#ifndef CATEGORYITEM_H
#define CATEGORYITEM_H

#include <QObject>
#include "containers.h"

class CategoryItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int cid READ cid WRITE setCid NOTIFY cidChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit CategoryItem(BoxCategory bcat, QObject *parent = 0);
    int cid() const;
    QString name() const;

signals:
    void cidChanged(int cid);
    void nameChanged(QString name);

public slots:
    void setCid(int cid);
    void setName(QString name);

private:
    int m_cid;
    QString m_name;
};

#endif // CATEGORYITEM_H
