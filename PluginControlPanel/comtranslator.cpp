#include "comtranslator.h"


inline QDataStream &operator <<(QDataStream &stream,const MessBoxDev &sC) // сериализуем;
{
	stream << sC.id;
	stream << sC.state;
	stream << sC.key;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, MessBoxDev &sC) // десериализуем;
{
	stream >> sC.id;
	stream >> sC.state;
	stream >> sC.key;
	return stream;
}


inline QDataStream &operator <<(QDataStream &stream,const MessBoxDevFull &sC) // сериализуем;
{
	stream << sC.id;
	stream << sC.state;
	stream << sC.name;
	stream << sC.type;
	stream << sC.param;
	stream << sC.key;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, MessBoxDevFull &sC) // десериализуем;
{
	stream >> sC.id;
	stream >> sC.state;
	stream >> sC.name;
	stream >> sC.type;
	stream >> sC.param;
	stream >> sC.key;
	return stream;
}

inline QDataStream &operator <<(QDataStream &stream,const MessBoxRule &sC) // сериализуем;
{
	stream << sC.id;
	stream << sC.state;
	stream << sC.name;
	stream << sC.key;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, MessBoxRule &sC) // десериализуем;
{
	stream >> sC.id;
	stream >> sC.state;
	stream >> sC.name;
	stream >> sC.key;
	return stream;
}


inline QDataStream &operator <<(QDataStream &stream,const MessBoxRuleFull &sC) // сериализуем;
{
	stream << sC.id;
	stream << sC.state;
	stream << sC.name;
	stream << sC.text;
	stream << sC.key;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, MessBoxRuleFull &sC) // десериализуем;
{
	stream >> sC.id;
	stream >> sC.state;
	stream >> sC.name;
	stream >> sC.text;
	stream >> sC.key;
	return stream;
}

inline QDataStream &operator <<(QDataStream &stream,const MessBoxAlert &sC) // сериализуем;
{
	stream << sC.text;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, MessBoxAlert &sC) // десериализуем;
{
	stream >> sC.text;
	return stream;
}


ComTranslator::ComTranslator(PluginInterface *plugInterface, QObject *parent) : QObject(parent)
{
	host = plugInterface;
}


int ComTranslator::sendMess(QString mess)
{
	MessBoxAlert messBox;
	messBox.text = mess;
	QByteArray out;
	QDataStream outStream(out, QIODevice::WriteOnly);
	outStream << messBox;
	out.append((char)MESS_TYPE_ALERT);
	emit newMess(out);
	return 0;
}

QByteArray ComTranslator::executeComReq(QByteArray mess)
{
	int type = (int)mess.at(i);
	QByteArray data = mess.right(mess.length()-1);
	QByteArray out;
	switch (type) {
	case MESS_TYPE_READ_DEV:
		out = this->readDev(data);
		break;
	case MESS_TYPE_WRITE_DEV:
		out = this->readDev(data);
		break;
	case MESS_TYPE_GET_LIST_DEV:
		out = this->getDevList(data);
		break;
	case MESS_TYPE_GET_LIST_RULE:
		out = this->getRuleList(data);
		break;
	default:
		// error
		break;
	}
	out.append((char)type);
	return out;
}

QByteArray ComTranslator::readDev(const QByteArray data)
{
	QDataStream inStream(mess, QIODevice::ReadOnly);
	MessBoxDev dev;
	inStream >> dev;
	dev.state = host->getStatDrive(dev.id);
	QByteArray out;
	QDataStream outStream(out, QIODevice::WriteOnly);
	outStream << dev;
	return out;
}

QByteArray ComTranslator::writeDev(const QByteArray data)
{
	QDataStream inStream(mess, QIODevice::ReadOnly);
	MessBoxDev dev;
	inStream >> dev;
	host->setStatDrive(dev.id, dev.state);
	dev.state = host->getStatDrive(dev.id);
	QByteArray out;
	QDataStream outStream(out, QIODevice::WriteOnly);
	outStream << dev;
	return out;
}

QByteArray ComTranslator::getDevList(const QByteArray data)
{

}

void ComTranslator::executeCom(QByteArray mess)
{
	int type = (int)mess.at(i);
	QByteArray data = mess.right(mess.length()-1);
	QByteArray out;
	switch (type) {
	case MESS_TYPE_READ_DEV:
		out = this->readDev(data);
		break;
	case MESS_TYPE_WRITE_DEV:
		out = this->readDev(data);
		break;
	case MESS_TYPE_GET_LIST_DEV:
		out = this->getDevList(data);
		break;
	case MESS_TYPE_GET_LIST_RULE:
		out = this->getRuleList(data);
		break;
	default:
		// error
		break;
	}
}
