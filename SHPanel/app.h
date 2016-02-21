#ifndef APP_H
#define APP_H

#include <QObject>
#include "client.h"
#include "comtranslator.h"
#include "uibackend.h"
#include "deviceman.h"
#include "categoryman.h"
#include "ruleman.h"

class App : public QObject
{
	Q_OBJECT
public:
	explicit App(QObject *parent = 0);
	void start();

signals:
    void viewLoginForm();

public slots:
	void clientConnected();
	void clientDisconected();

private:
	Client *client;
	ComTranslator *comTranslator;
	UiBackend *ui;
	DeviceMan *devMan;
    CategoryMan *catMan;
    RuleMan * ruleMan;

    void initComponents();
    void configUi();
    void connectComponents();
    void loadDemoData();
};

#endif // APP_H
