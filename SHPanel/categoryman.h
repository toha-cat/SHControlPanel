#ifndef CATEGORYMAN_H
#define CATEGORYMAN_H

#include <QObject>
#include "containers.h"
#include "categoryitem.h"

class CategoryMan : public QObject
{
    Q_OBJECT
public:
    explicit CategoryMan(QObject *parent = 0);
    const QList<QObject *> getList();

signals:
    void listChanged(QList<QObject*> list);

public slots:
    void addCategory(BoxCategory bcat);
    void addCategory(int cid, QString name);
    void setCategoryList(BoxListCategory list);

private:
    QList<QObject*> catList;
};

#endif // CATEGORYMAN_H
