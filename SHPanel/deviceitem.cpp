#include "deviceitem.h"

DeviceItem::DeviceItem(int id, QString name, QString type, QString state, QObject *parent) : QObject(parent)
{
	this->setId(id);
	this->setName(name);
	this->setType(type);
	this->setState(state);
}

int DeviceItem::id() const
{
	return m_id;
}

QString DeviceItem::getName() const
{
	return m_name;
}

QString DeviceItem::getType() const
{
	return m_type;
}

QString DeviceItem::getState() const
{
	return m_state;
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
	emit sendState(state);
}
