#ifndef COMTRANSLATOR_H
#define COMTRANSLATOR_H

#include <QObject>
#include <QByteArray>
#include <QDataStream>
#include <QList>

#include "containers.h"


class ComTranslator : public QObject
{
	Q_OBJECT
public:
	explicit ComTranslator(QObject *parent = 0);
	friend QDataStream &operator <<(QDataStream &stream,const BoxDev &sC);
	friend QDataStream &operator >>(QDataStream &stream, BoxDev &sC);
	friend QDataStream &operator <<(QDataStream &stream,const BoxRule &sC);
	friend QDataStream &operator >>(QDataStream &stream, BoxRule &sC);
	friend QDataStream &operator <<(QDataStream &stream,const BoxAlert &sC);
	friend QDataStream &operator >>(QDataStream &stream, BoxAlert &sC);


signals:
	void reqReadDev(int id, QString state);
	void reqWriteDev(int id, QString state);
	void reqAddDev(BoxDev dev);
    void reqGetDevList(BoxListDev list);
    void reqGetCatList(BoxListCategory list);
    void reqGetRuleList(BoxListRule list);
	void reqGetRule(BoxRule box);
	void reqAddRule(BoxRule box);
	void alertMess(QString mess);

	void sendMess(QByteArray mess);

public slots:
	void translateMess(QByteArray mess);

	void readDev(int id);
    void writeDev(int id, QString state);
	void addDev(int cid, QString name, QString type, QString param);
	void getDevList(int cid);
	void getRuleList(int cid);
	void getRule(int id);
	void addRule(int cid, QString name, QString text, int state);
};

#endif // COMTRANSLATOR_H
