#ifndef UIBACKEND_H
#define UIBACKEND_H

#include <QObject>
#include <QDebug>
#include <QScreen>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "deviceitem.h"

class UiBackend : public QObject
{
	Q_OBJECT
public:
	explicit UiBackend(QObject *parent = 0);
	void createUi();
    void setDeviceModel(QList<QObject *> list);
    void setDeviceCatModel(QList<QObject *> list);
    void show();
signals:

public slots:
	void selectCat(int cid);

protected:
	void regMetrics();

	QObject *viewer;
	QQmlApplicationEngine engine;
	QQmlContext *rootContext;
};

#endif // UIBACKEND_H
