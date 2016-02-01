#ifndef DEVICELISST_H
#define DEVICELISST_H

#include <QObject>
#include <QList>
#include <QMap>
#include <QString>
#include "deviceitem.h"
#include "containers.h"

class DeviceMan : public QObject
{
	Q_OBJECT
public:
    explicit DeviceMan(QObject *QMLObject = 0);
    const QList<QObject *> getList();

signals:

public slots:
    void addDevice(int id, QString name, QString type, QString state, int cid);
    void setDeviceList(BoxListDev list);
    void selectCat(int cid);

private:
    int currentCat = 0;
    QList<QObject*> deviceList;
	QMap<int, DeviceItem*> deviceMap;

    void updateList();
};

#endif // DEVICELISST_H
