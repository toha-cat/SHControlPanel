#ifndef DEVICEITEM_H
#define DEVICEITEM_H

#include <QObject>

class DeviceItem : public QObject
{
	Q_OBJECT

	Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
	Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
	Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
	Q_PROPERTY(QString state READ getState WRITE setState NOTIFY stateChanged)

public:
	explicit DeviceItem(int id, QString name, QString type, QString state, QObject *parent = 0);
	int id() const;
	QString getName() const;
	QString getType() const;
	QString getState() const;

signals:
	void idChanged(int id);
	void nameChanged(QString name);
	void typeChanged(QString type);
	void stateChanged(QString state);
	void sendState(QString state);

public slots:
	void setId(int id);
	void setName(QString name);
	void setType(QString type);
	void setState(QString state);
	void changeState(QString state);

private:
	int m_id;
	QString m_name;
	QString m_type;
	QString m_state;
};

#endif // DEVICEITEM_H
