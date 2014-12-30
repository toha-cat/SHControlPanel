#include "plugincontrolpanel.h"

QString PluginControlPanel::getVersion() const
{
	return "1.0";
}

QString PluginControlPanel::getName() const
{
	return "Control Panel";
}

bool PluginControlPanel::setControlInterface(PluginInterface *plugInterface)
{
	return true;
}

int PluginControlPanel::start()
{
	qDebug() << "Я запустился))";
	return 0;
}

int PluginControlPanel::stop()
{
	return 0;
}
