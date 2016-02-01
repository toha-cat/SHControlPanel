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
    const QList<CategoryItem *> getList();

signals:

public slots:
    void addCategory(BoxCategory cat);
    void setCategoryList(BoxListCategory list);

private:
    QList<DeviceItem*> catList;
};

#endif // CATEGORYMAN_H
