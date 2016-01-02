#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <QDataStream>

#define MESS_HEADER_SIZE 4

#define LOGIN_RESULT_SUCESS 0x0F
#define LOGIN_RESULT_ERROR 0x01

class Client : public QObject
{
	Q_OBJECT

public:
	explicit Client(QObject *parent = 0);

public slots:
	void connect(QString host, int port);
	void send(QByteArray mess);
	void login(QString login, QString pass);
	void logout();

signals:
	void newMess(QByteArray mess);
	void closeConnect();
	void loginSucess();
	void loginError();

private slots:
	void readyReadNoLogin();
	void readyRead();
	void connected();
	void disconnected();

private:
	QTcpSocket *socket;
	int messSize = 0;

};

#endif // CLIENT_H
