#include "plugincontrolpanel.h"

QString PluginControlPanel::getVersion()
{
	return "1.0";
}

QString PluginControlPanel::getName()
{
	return "Control Panel";
}

bool PluginControlPanel::setControlInterface(PluginInterface *plugInterface)
{
	this->plgInterface = plugInterface;
	return true;
}

int PluginControlPanel::start()
{
	if(plgInterface == NULL){
		qDebug() << "Ошибка запуска плагина " << this->getName() << " v." << this->getVersion();
		qDebug() << "отсутствует интерфейс";
		return -1;
	}

	translator = new ComTranslator(plgInterface);
	nServ = new NetServer(translator);

	connect(nServ, &NetServer::newMess, translator, &ComTranslator::executeCom );
	connect(translator, &ComTranslator::newMess, nServ, &NetServer::sendMess );

	return 0;
}

int PluginControlPanel::stop()
{
	return 0;
}
