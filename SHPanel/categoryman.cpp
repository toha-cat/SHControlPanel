#include "categoryman.h"

CategoryMan::CategoryMan(QObject *parent) : QObject(parent)
{

}

const QList<QObject *> CategoryMan::getList()
{
    return catList;
}

void CategoryMan::addCategory(BoxCategory bcat)
{
    CategoryItem * cat = new CategoryItem(bcat, this);
    catList.append(cat);
}

void CategoryMan::setCategoryList(BoxListCategory list)
{
    catList.clear();
    foreach (BoxCategory cat, list) {
        addCategory(cat);
    }
}
