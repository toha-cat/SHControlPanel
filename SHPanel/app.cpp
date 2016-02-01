#include "app.h"

App::App(QObject *parent) : QObject(parent)
{

}

void App::start()
{
	client = new Client(this);
    connect(client, &Client::loginSucess, this, &App::clientConnected);
    connect(client, &Client::closeConnect, this, &App::clientDisconected);

	comTranslator = new ComTranslator(this);

	devMan = new DeviceMan(this);

    //connect(comTranslator, &ComTranslator::sendMess, devMan, &DeviceMan::send);

	ui = new UiBackend(this);
	ui->createUi();

    QList<QObject*> dataList;
    dataList.append(new DeviceItem(0, "Item 1", "ControlLed", "On", 1));
    dataList.append(new DeviceItem(1, "Item 2", "ControlLed", "On", 1));
    dataList.append(new DeviceItem(2, "Item 3", "ControlLed", "On", 2));
    dataList.append(new DeviceItem(3, "Item 4", "ControlLed", "On", 2));
    ui->setDeviceModel(dataList);

    QList<QObject*> catList;
    catList.append(new DeviceItem(0, "Item 1", "ControlLed", "On"));
    catList.append(new DeviceItem(1, "Item 2", "ControlLed", "On"));
    catList.append(new DeviceItem(2, "Item 3", "ControlLed", "On"));
    catList.append(new DeviceItem(3, "Item 4", "ControlLed", "On"));
    ui->setDeviceModel(catList);

	ui->show();
}

void App::clientConnected()
{
    connect(client, &Client::newMess, comTranslator, &ComTranslator::translateMess);
    connect(comTranslator, &ComTranslator::sendMess, client, &Client::send);
}

void App::clientDisconected()
{
    disconnect(client, &Client::newMess, comTranslator, &ComTranslator::translateMess);
    disconnect(comTranslator, &ComTranslator::sendMess, client, &Client::send);
}
