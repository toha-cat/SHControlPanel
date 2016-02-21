#include "ruleitem.h"

RuleItem::RuleItem(BoxRule brule, QObject *parent) : QObject(parent)
{
    setRId(brule.id);
    setState(brule.state);
    setName(brule.name);
    setText(brule.text);
}

RuleItem::RuleItem(int rid, int state, QString name, QString text, QObject *parent) : QObject(parent)
{
    setRId(rid);
    setState(state);
    setName(name);
    setText(text);
}

int RuleItem::rId() const
{
    return m_rId;
}

int RuleItem::state() const
{
    return m_state;
}

QString RuleItem::name() const
{
    return m_name;
}

QString RuleItem::text() const
{
    return m_text;
}

void RuleItem::setRId(int rId)
{
    if (m_rId == rId)
        return;

    m_rId = rId;
    emit rIdChanged(rId);
}

void RuleItem::setState(int state)
{
    if (m_state == state)
        return;

    m_state = state;
    emit stateChanged(state);
}

void RuleItem::setName(QString name)
{
    if (m_name == name)
        return;

    m_name = name;
    emit nameChanged(name);
}

void RuleItem::setText(QString text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(text);
}
