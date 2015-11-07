#ifndef PLUGINCONTROLPANEL_H
#define PLUGINCONTROLPANEL_H

#include "plugincontrolpanel_global.h"
#include <QDebug>
#include "netserver.h"
#include "comtranslator.h"

class PluginControlPanel : public SHPlugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "SmartHouse/SHPlugin/1.0")
	Q_INTERFACES(SHPlugin)

public:
	PluginControlPanel(QObject *parent = 0) : SHPlugin(parent) {}
	virtual ~PluginControlPanel(){}

	virtual QString getVersion();
	virtual QString getName();

	virtual bool setControlInterface(PluginInterface * plugInterface);

	virtual int start();
	virtual int stop();

private:
	PluginInterface * plgInterface;
	ComTranslator * translator;
	NetServer * nServ;
};

#endif // PLUGINCONTROLPANEL_H
