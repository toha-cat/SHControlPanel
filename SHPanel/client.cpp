#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readyReadNoLogin()));
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(connected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void Client::connect(QString host, int port)
{
	socket->connectToHost(host, port);
}

void Client::send(QByteArray mess)
{
	qint32 len = mess.length();
	if(len > 0)
	{
		QByteArray baLen;
		QDataStream dsLen(&baLen, QIODevice::WriteOnly);
		dsLen << len;
		socket->write(baLen, MESS_HEADER_SIZE);
		socket->write(mess.data(), len);
	}
}

void Client::login(QString login, QString pass)
{
	QByteArray mess;
	QDataStream dsMess(&mess, QIODevice::WriteOnly);
	//TODO: нужно добавить какой то уникальный идентификатор на каждое подключение
	// при этом идентификатор должен распознаватся на сервере, после расшифровки
	// для исключения перехвата и последующей отправки сообщения 3-ми лицами
	dsMess << login;
	dsMess << pass;
	send(mess);
}

void Client::logout()
{
	//TODO: реализовать logout
}


void Client::readyReadNoLogin()
{
	qint64 countByte = socket->bytesAvailable();
	if(countByte==0LL)
	{
		emit closeConnect();
		return;
	}
	if(messSize == 0 && countByte >= MESS_HEADER_SIZE){
		QByteArray baLen = socket->read(MESS_HEADER_SIZE);
		QDataStream dsLen(&baLen, QIODevice::ReadOnly);
		dsLen >> messSize;
		countByte -= 4;
	}
	if(messSize > 0 && countByte >= messSize){
		QByteArray mess = socket->read(messSize);
		messSize = 0;
		QDataStream dsMess(&mess, QIODevice::ReadOnly);
		qint32 result;
		dsMess >> result;
		if(result == LOGIN_RESULT_SUCESS){
			QObject::disconnect(socket, SIGNAL(readyRead()), this, SLOT(readyReadNoLogin()));
			QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
			emit loginSucess();
		}
		if(result == LOGIN_RESULT_ERROR){
			emit loginError();
		}
	}
}

void Client::readyRead()
{
	qint64 countByte = socket->bytesAvailable();
	if(countByte==0LL)
	{
		emit closeConnect();
		return;
	}
	if(messSize == 0 && countByte >= MESS_HEADER_SIZE){
		QByteArray baLen = socket->read(MESS_HEADER_SIZE);
		QDataStream dsLen(&baLen, QIODevice::ReadOnly);
		dsLen >> messSize;
		countByte -= 4;
	}
	if(messSize > 0 && countByte >= messSize){
		QByteArray mess = socket->read(messSize);
		messSize = 0;
		emit newMess(mess);
	}
}

// При удачном конекте к серверу вызывается эта функция
void Client::connected()
{
	socket->write(QString("/me: \n").toUtf8());
}

// При разрыве связи с сервером вызывается эта функция
void Client::disconnected()
{

}
