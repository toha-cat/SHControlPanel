#include "netserver.h"

#include <QTcpSocket>
#include <QRegExp>

#define MESS_HEADER_SIZE 4

NetServer * TcpServer;

NetServer::NetServer(ComTranslator *comtranslator, QObject *parent) : QTcpServer(parent)
{
	this->translator = comtranslator;
}

void NetServer::sendMess(QByteArray mess)
{
	qint32 len = mess.length();
	foreach(QTcpSocket *client, clients){
		sendMessToClient(QTcpSocket *client, mess, len)
	}
}

void NetServer::incomingConnection(int socketfd)
{
	QTcpSocket *client = new QTcpSocket(this);
	client->setSocketDescriptor(socketfd);
	clients.insert(client);
	messSize[client] << 0;

	qDebug() << "New client from:" << client->peerAddress().toString();

	connect(client, &QTcpSocket::readyRead, this, &NetServer::readyRead);
	connect(client, &QTcpSocket::disconnected, this, &NetServer::disconnected);
}

void NetServer::sendMessToClient(QTcpSocket *client, QByteArray mess, qint32 len)
{
	client->write(len, MESS_HEADER_SIZE);
	client->write(mess.data(), len);
}

void NetServer::readyReadLogin()
{
	QTcpSocket *client = (QTcpSocket*)sender();
	int expected = messSize[client];
	qint64 countByte = client->bytesAvailable();
	if(expected == 0){
		if(countByte < MESS_HEADER_SIZE){
			return;
		}
		messSize[client] = (int)client->read(MESS_HEADER_SIZE);
	}
	else{
		if(countByte < expected){
			return;
		}

		QByteArray mess = client->read(expected);
		// login
		connect(client, &QTcpSocket::readyRead, this, &NetServer::readyRead);
		disconnect(client, &QTcpSocket::readyRead, this, &NetServer::readyReadLogin);
	}

}

void NetServer::readyRead()
{
	QTcpSocket *client = (QTcpSocket*)sender();
	int expected = messSize[client];
	qint64 countByte = client->bytesAvailable();
	if(countByte==0LL)
	{
		//сокет был закрыт на удаленной стороне
		return;
	}
	if(expected == 0){
		if(countByte < MESS_HEADER_SIZE){
			return;
		}
		messSize[client] = (int)client->read(MESS_HEADER_SIZE);
	}
	else{
		if(countByte < expected){
			return;
		}

		QByteArray mess = client->read(expected);
		emit valueChanged(value);
		QByteArray req = translator->executeComReq(mess);
		sendMessToClient(client, req, req.length());
	}
}

void NetServer::disconnected()
{
	QTcpSocket *client = (QTcpSocket*)sender();
	qDebug() << "Client disconnected:" << client->peerAddress().toString();

	clients.remove(client);
	messSize.remove(client);

}

