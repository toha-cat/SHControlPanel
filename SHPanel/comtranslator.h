#ifndef COMTRANSLATOR_H
#define COMTRANSLATOR_H

#include <QObject>
#include <QByteArray>
#include <QDataStream>
#include <QList>

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
	explicit ComTranslator(QObject *parent = 0);
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


signals:
	void reqReadDev(int key, int id, int state);
	void reqWriteDev(int key, int id, int state);
	void reqGetDevList(int key, int cid, QList<MessBoxDevFull> list);
	void reqGetRuleList(int key, int cid, QList<MessBoxRule> list);
	void reqGetRule(int key, int id, MessBoxRuleFull box);
	void reqAddRule(int key, int id, MessBoxRuleFull box);
	void alertMess(QString mess);

public slots:
	void translateMess(QByteArray mess);

	void readDev(int key, int id);
	void writeDev(int key, int id, int state);
	void getDevList(int key, int cid);
	void getRuleList(int key, int cid);
	void getRule(int key, int id);
	void addRule(int key, int cid, QString name, QString text, int state);
};

#endif // COMTRANSLATOR_H
