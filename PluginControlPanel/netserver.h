#ifndef NETSERVER_H
#define NETSERVER_H

#include <QObject>
#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>
#include "comtranslator.h"

typedef struct{
	int id;
	QString value;
} testComBox;


class NetServer : public QTcpServer
{
	Q_OBJECT

public:
	NetServer(ComTranslator *comtranslator, QObject *parent=0);
public slots:
	void sendMess(QByteArray mess);
private slots:
	void readyRead();
	void readyReadLogin();
	void disconnected();

protected:
	void incomingConnection(int socketfd);

private:
	QSet<QTcpSocket*> clients;
	QMap<QTcpSocket*,int> messSize;
	ComTranslator *translator;

	void sendMessToClient(QTcpSocket *client, QByteArray mess, qint32 len);

signals:
	void newMess(QString mess);

};

extern NetServer * TcpServer;

#endif // NETSERVER_H
