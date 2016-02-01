#include "categoryman.h"

CategoryMan::CategoryMan(QObject *parent) : QObject(parent)
{

}

const QList<CategoryItem *> CategoryMan::getList()
{
    return catList;
}

void CategoryMan::addCategory(BoxCategory cat)
{
    CategoryItem * cat = new CategoryItem(cat, this);
    catList.append(cat);
}

void CategoryMan::setCategoryList(BoxListCategory list)
{
    catList.clear();
    foreach (BoxCategory cat, list) {
        addCategory(cat);
    }
}
