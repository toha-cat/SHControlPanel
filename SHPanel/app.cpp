#include "app.h"

App::App(QObject *parent) : QObject(parent)
{

}

void App::start()
{
    initComponents();

    ui->createUi();

    configUi();

    ui->show();

    connectComponents();

    loadDemoData();
}

void App::initComponents()
{
    client = new Client(this);

    comTranslator = new ComTranslator(this);

    devMan = new DeviceMan(this);

    catMan = new CategoryMan(this);

    ruleMan = new RuleMan(this);

    ui = new UiBackend(this);
}

void App::configUi()
{
    QList<QObject*> devList = devMan->getList();
    ui->setDeviceModel(devList);

    QList<QObject*> catList = catMan->getList();
    ui->setDeviceCatModel(catList);

    QList<QObject*> ruleList = ruleMan->getList();
    ui->setRulesModel(ruleList);
}

void App::connectComponents()
{
    connect(client, &Client::loginSucess, this, &App::clientConnected);
    connect(client, &Client::closeConnect, this, &App::clientDisconected);

    connect(comTranslator, &ComTranslator::reqGetDevList, devMan, &DeviceMan::setDeviceList);
    connect(comTranslator, &ComTranslator::reqWriteDev, devMan, &DeviceMan::setDeviceState);
    connect(comTranslator, &ComTranslator::reqGetCatList, catMan, &CategoryMan::setCategoryList);
    connect(comTranslator, &ComTranslator::reqGetRuleList, ruleMan, &RuleMan::setList);

    connect(devMan, &DeviceMan::listChanged, ui, &UiBackend::setDeviceModel);

    connect(catMan, &CategoryMan::listChanged, ui, &UiBackend::setDeviceCatModel);

    connect(ruleMan, &RuleMan::listChanged, ui, &UiBackend::setRulesModel);

    connect(ui, &UiBackend::selectCat, devMan, &DeviceMan::selectCat);
    connect(ui, &UiBackend::changeDevice, comTranslator, &ComTranslator::writeDev);
    //connect(ui, &UiBackend::changeRuleState, comTranslator, &ComTranslator::)
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

void App::loadDemoData()
{
    devMan->addDevice(0,"Свет в кухне", "ControlLed", "on", 1);
    devMan->addDevice(1,"Подсветка в кухне", "ControlLed", "off", 1);
    devMan->addDevice(2,"Свет в комнате", "ControlLed", "off", 2);
    devMan->addDevice(3,"Подсветка в комнате", "ControlLed", "on", 2);
    devMan->addDevice(4,"Свет в прихожей", "ControlLed", "off", 3);
    devMan->addDevice(5,"Температура в прихожей", "ControlTemp", "20", 3);

    catMan->addCategory(1, "Кухня");
    catMan->addCategory(2, "Комната");
    catMan->addCategory(3, "Прихожая");

    ruleMan->add(1, 1, "Rule 1", "test RULE TEXT");
    ruleMan->add(2, 1, "Rule 2", "test RULE TEXT");
    ruleMan->add(3, 1, "Rule 3", "test RULE TEXT");

    connect(ui, &UiBackend::changeDevice, devMan, &DeviceMan::setDeviceState);
    connect(ui, &UiBackend::changeRuleState, ruleMan, &RuleMan::setRuleState);
}
