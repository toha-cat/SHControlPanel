#ifndef UIBACKEND_H
#define UIBACKEND_H

#include <QObject>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "deviceitem.h"

#ifdef Q_OS_ANDROID
#include <QAndroidJniObject>
#endif

class UiBackend : public QObject
{
	Q_OBJECT
public:
	explicit UiBackend(QObject *parent = 0);
	void createUi();
    void show();

signals:
    void selectCat(int cid);
    void changeDevice(int id, QString stat);
    void changeRuleState(int id, int stat);

public slots:
    void setDeviceModel(QList<QObject *> list);
    void setDeviceCatModel(QList<QObject *> list);
    void setRulesModel(QList<QObject *> list);
    void showLoginForm();

protected:
    void regMetrics();

	QObject *viewer;
	QQmlApplicationEngine engine;
	QQmlContext *rootContext;
};

#endif // UIBACKEND_H
