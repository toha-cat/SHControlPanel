#include "categoryitem.h"

CategoryItem::CategoryItem(BoxCategory bcat, QObject *parent) : QObject(parent)
{
    setCid(bcat.cid);
    setName(bcat.name);
}

int CategoryItem::cid() const
{
    return m_cid;
}

QString CategoryItem::name() const
{
    return m_name;
}

void CategoryItem::setCid(int cid)
{
    if (m_cid == cid)
        return;

    m_cid = cid;
    emit cidChanged(cid);
}

void CategoryItem::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}
