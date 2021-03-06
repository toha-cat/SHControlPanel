#include "deviceman.h"

DeviceMan::DeviceMan(QObject *QMLObject) : QObject(QMLObject)
{

}

const QList<QObject *> DeviceMan::getList()
{
    return deviceList;
}

void DeviceMan::addDevice(int id, QString name, QString type, QString state, int cid = 0)
{
    DeviceItem *dev = new DeviceItem(id, name, type, state, cid, this);
    deviceMap.insert(id, dev);
    if(!currentCat || cid == currentCat){
        deviceList.append(dev);
        emit listChanged(deviceList);
    }
}

void DeviceMan::setDeviceList(BoxListDev list)
{
    deviceMap.clear();
    foreach (BoxDev bdev, list) {
        DeviceItem *dev = new DeviceItem(bdev, this);
        deviceMap.insert(bdev.id, dev);
    }
    updateList();
}

void DeviceMan::selectCat(int cid)
{
    currentCat = cid;
    updateList();
}

void DeviceMan::setDeviceState(int id, QString stat)
{
    DeviceItem *dev = deviceMap.value(id);
    dev->setState(stat);
}

void DeviceMan::updateList()
{
    deviceList.clear();
    foreach (DeviceItem *dev, deviceMap) {
        if(!currentCat || dev->cid() == currentCat){
            deviceList.append(dev);
        }
    }
    emit listChanged(deviceList);
}


