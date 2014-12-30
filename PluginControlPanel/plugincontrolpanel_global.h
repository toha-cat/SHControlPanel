#ifndef PLUGINCONTROLPANEL_GLOBAL_H
#define PLUGINCONTROLPANEL_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QObject>
#include <QtPlugin>

class DriveBox
{
public:
	DriveBox();
	int id;
	QString name;
	int type;
	int stat;
};

class PluginInterface
{
public:
	PluginInterface();
	bool sendMess(QString mess);
	bool setStatDrive(int driveId, int stat);
	int getStatDrive(int driveId);
	QList<DriveBox> * getListDrives(int type);
};

class SHPlugin : public QObject
{
	Q_OBJECT
public:
	SHPlugin(QObject *parent = 0) : QObject(parent) {}
	virtual ~SHPlugin() = 0;

	virtual QString getVersion() = 0;
	virtual QString getName() = 0;

	virtual bool setControlInterface(PluginInterface * plugInterface){return true;}

	virtual int start() = 0;
	virtual int stop() = 0;
};

Q_DECLARE_INTERFACE(SHPlugin, "SmartHouse/SHPlugin/1.0")

#endif // PLUGINCONTROLPANEL_GLOBAL_H
