#ifndef PLUGINCONTROLPANEL_H
#define PLUGINCONTROLPANEL_H

#include "plugincontrolpanel_global.h"
#include <QDebug>

class PluginControlPanel : public SHPlugin
{
	Q_OBJECT
	Q_INTERFACES(SHPlugin)
	Q_PLUGIN_METADATA(IID "SmartHouse/SHPlugin/1.0" FILE "myplugin.json")
public:
	PluginControlPanel(QObject *parent = 0) : SHPlugin(parent) {}
	~PluginControlPanel(){}

	virtual QString getVersion() const;
	virtual QString getName() const;

	virtual bool setControlInterface(PluginInterface * plugInterface);

	virtual int start();
	virtual int stop();
};

#endif // PLUGINCONTROLPANEL_H
