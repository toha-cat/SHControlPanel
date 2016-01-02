#ifndef DEVICELISST_H
#define DEVICELISST_H

#include <QObject>
#include <QList>

class DeviceLisst : public QObject
{
	Q_OBJECT
public:
	DeviceLisst(QObject *QMLObject = 0);

signals:

public slots:

private:
	QList<QObject*> dataList;
};

#endif // DEVICELISST_H
