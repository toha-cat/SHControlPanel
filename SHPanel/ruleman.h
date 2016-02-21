#ifndef RULEMAN_H
#define RULEMAN_H

#include <QObject>
#include <QMap>
#include <QDebug>
#include "ruleitem.h"

class RuleMan : public QObject
{
    Q_OBJECT
public:
    explicit RuleMan(QObject *parent = 0);
    const QList<QObject *> getList();

signals:
    void listChanged(QList<QObject*> list);

public slots:
    void add(BoxRule brule);
    void add(int rid, int state, QString name, QString text);
    void setList(BoxListRule list);
    void setRuleState(int id, int stat);

private:
    QMap<int, RuleItem*> ruleList;
};

#endif // RULEMAN_H
