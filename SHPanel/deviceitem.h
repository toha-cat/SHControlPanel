#ifndef DEVICEITEM_H
#define DEVICEITEM_H

#include <QObject>
#include <QString>
#include "containers.h"

class DeviceItem : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(int cid READ cid WRITE setCid NOTIFY cidChanged)

public:
    explicit DeviceItem(int id, QString name, QString type, QString state, int cid = 0, QObject *parent = 0);
    DeviceItem(BoxDev dev, QObject *parent = 0);
	int id() const;
    QString name() const;
    QString type() const;
    QString state() const;
    int cid() const;

signals:
	void idChanged(int id);
	void nameChanged(QString name);
	void typeChanged(QString type);
	void stateChanged(QString state);
	void sendState(int id, QString state);
    void cidChanged(int cid);

public slots:
	void setId(int id);
	void setName(QString name);
	void setType(QString type);
	void setState(QString state);
	void changeState(QString state);
    void setCid(int cid);

private:
	int m_id;
	QString m_name;
	QString m_type;
    QString m_state;
    int m_cid;
};

#endif // DEVICEITEM_H
