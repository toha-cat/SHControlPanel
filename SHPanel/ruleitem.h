#ifndef RULEITEM_H
#define RULEITEM_H

#include <QObject>
#include "containers.h"

class RuleItem : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int rId READ rId WRITE setRId NOTIFY rIdChanged)
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    explicit RuleItem(BoxRule brule, QObject *parent = 0);
    explicit RuleItem(int rid, int state, QString name, QString text, QObject *parent = 0);
    int rId() const;
    int state() const;
    QString name() const;
    QString text() const;

signals:
    void rIdChanged(int rId);
    void stateChanged(int state);
    void nameChanged(QString name);
    void textChanged(QString text);

public slots:
    void setRId(int rId);
    void setState(int state);
    void setName(QString name);
    void setText(QString text);

private:
    int m_rId;
    int m_state;
    QString m_name;
    QString m_text;
};

#endif // RULEITEM_H
