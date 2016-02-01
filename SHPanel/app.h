#ifndef APP_H
#define APP_H

#include <QObject>
#include "client.h"
#include "comtranslator.h"
#include "uibackend.h"
#include "deviceman.h"

class App : public QObject
{
	Q_OBJECT
public:
	explicit App(QObject *parent = 0);
	void start();

signals:

public slots:
	void clientConnected();
	void clientDisconected();

private:
	Client *client;
	ComTranslator *comTranslator;
	UiBackend *ui;
	DeviceMan *devMan;
};

#endif // APP_H
