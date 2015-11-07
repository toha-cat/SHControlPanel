#ifndef COMTRANSLATOR_H
#define COMTRANSLATOR_H

#include <QObject>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>
#include "plugincontrolpanel.h"

#define MESS_TYPE_READ_DEV 0x01
#define MESS_TYPE_WRITE_DEV 0x02
#define MESS_TYPE_GET_LIST_DEV 0x03
#define MESS_TYPE_ADD_DEV 0x05
#define MESS_TYPE_GET_LIST_RULE 0x06
#define MESS_TYPE_GET_RULE 0x07
#define MESS_TYPE_ADD_RULE 0x08
#define MESS_TYPE_ALERT 0x09

typedef struct{
	qint8 id;
	qint8 state;
	qint8 key;
} MessBoxDev;

typedef struct{
	qint8 id;
	qint8 state;
	QString name;
	qint8 type;
	QString param;
	qint8 key;
} MessBoxDevFull;

typedef struct{
	qint8 id;
	qint8 state;
	QString name;
	qint8 key;
} MessBoxRule;

typedef struct{
	qint8 id;
	qint8 state;
	QString name;
	QString text;
	qint8 key;
} MessBoxRuleFull;

typedef struct{
	QString text;
} MessBoxAlert;

class ComTranslator : public QObject
{
	Q_OBJECT
public:
	explicit ComTranslator(PluginInterface * plugInterface, QObject *parent = 0);
	int sendMess(QString mess);
	QByteArray executeComReq(QByteArray mess);
	friend QDataStream &operator <<(QDataStream &stream,const MessBoxDev &sC);
	friend QDataStream &operator >>(QDataStream &stream, MessBoxDev &sC);
	friend QDataStream &operator <<(QDataStream &stream,const MessBoxDevFull &sC);
	friend QDataStream &operator >>(QDataStream &stream, MessBoxDevFull &sC);
	friend QDataStream &operator <<(QDataStream &stream,const MessBoxRule &sC);
	friend QDataStream &operator >>(QDataStream &stream, MessBoxRule &sC);
	friend QDataStream &operator <<(QDataStream &stream,const MessBoxRuleFull &sC);
	friend QDataStream &operator >>(QDataStream &stream, MessBoxRuleFull &sC);
	friend QDataStream &operator <<(QDataStream &stream,const MessBoxAlert &sC);
	friend QDataStream &operator >>(QDataStream &stream, MessBoxAlert &sC);
public slots:
	void executeCom(QByteArray mess);
signals:
	void newMess(QByteArray mess);
private:
	PluginInterface * host;

	QByteArray readDev(const QByteArray data);
	QByteArray writeDev(const QByteArray data);
	QByteArray getDevList(const QByteArray data);
	QByteArray addDev(const QByteArray data);
	QByteArray getRuleList(const QByteArray data);
	QByteArray getRule(const QByteArray data);
	QByteArray addRule(const QByteArray data);
};

#endif // COMTRANSLATOR_H
