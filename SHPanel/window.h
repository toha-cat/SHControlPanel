#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "deviceitem.h"

class Window : public QObject
{
	Q_OBJECT
public:
	explicit Window(QObject *parent = 0);
	void show();
signals:

public slots:

protected:
	QObject *viewer;
	QQmlApplicationEngine engine;
};

#endif // WINDOW_H
