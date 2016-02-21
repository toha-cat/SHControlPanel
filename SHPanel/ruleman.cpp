#include "ruleman.h"

RuleMan::RuleMan(QObject *parent) : QObject(parent)
{

}

const QList<QObject *> RuleMan::getList()
{
    QList<QObject*> list;
    foreach (RuleItem *rule, ruleList) {
        list.append(rule);
    }
    return list;
}

void RuleMan::add(BoxRule brule)
{
    RuleItem * item = new RuleItem(brule, this);
    ruleList.insert(brule.id, item);
    QList<QObject*> list = getList();
    emit listChanged(list);
}

void RuleMan::add(int rid, int state, QString name, QString text)
{
    RuleItem * item = new RuleItem(rid, state, name, text, this);
    ruleList.insert(rid, item);
    QList<QObject*> list = getList();
    emit listChanged(list);
}

void RuleMan::setList(BoxListRule list)
{
    ruleList.clear();
    foreach (BoxRule rule, list) {
        RuleItem * item = new RuleItem(rule, this);
        ruleList.insert(rule.id, item);
    }
    QList<QObject*> l = getList();
    emit listChanged(l);
}

void RuleMan::setRuleState(int id, int stat)
{
    RuleItem * item = ruleList.value(id);
    item->setState(stat);
    qDebug() << "Set rule stat " << id << " S: " << stat;
}
