#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject
{
	Q_OBJECT
public:
	explicit Client(QObject *parent = 0);
	void connect(QString host, int port);
	void send(QString mess);
private slots:
	void readyRead();
	void connected();
	void disconnected();
private:
	QTcpSocket *socket;
signals:

public slots:
};

#endif // CLIENT_H
