#include "deviceitem.h"

DeviceItem::DeviceItem(int id, QString name, QString type, QString state, int cid, QObject *parent) : QObject(parent)
{
	this->setId(id);
	this->setName(name);
	this->setType(type);
    this->setState(state);
    this->setCid(cid);
}

DeviceItem::DeviceItem(BoxDev dev, QObject *parent) : QObject(parent)
{
    this->setId(dev.id);
    this->setName(dev.name);
    this->setType(dev.type);
    this->setState(dev.state);
}

int DeviceItem::id() const
{
	return m_id;
}

QString DeviceItem::name() const
{
	return m_name;
}

QString DeviceItem::type() const
{
	return m_type;
}

QString DeviceItem::state() const
{
	return m_state;
}

int DeviceItem::cid() const
{
    return m_cid;
}

void DeviceItem::setId(int id)
{
    if (m_id == id)
        return;

    m_id = id;
	emit idChanged(id);
}

void DeviceItem::setName(QString name)
{
	if (m_name == name)
		return;

	m_name = name;
	emit nameChanged(name);
}

void DeviceItem::setType(QString type)
{
	if (m_type == type)
		return;

	m_type = type;
	emit typeChanged(type);
}

void DeviceItem::setState(QString state)
{
	if (m_state == state)
		return;

	m_state = state;
	emit stateChanged(state);
}

void DeviceItem::changeState(QString state)
{
	emit sendState(this->m_id, state);
}

void DeviceItem::setCid(int cid)
{
    if (m_cid == cid)
        return;

    m_cid = cid;
    emit cidChanged(cid);
}
