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


ComTranslator::ComTranslator(QObject *parent) : QObject(parent)
{

}

void ComTranslator::translateMess(QByteArray mess)
{
	int type = (int)mess.at(0);
	QByteArray data = mess.right(mess.length()-1);
	QDataStream inStream(data);
	switch (type) {
		case MESS_TYPE_READ_DEV:{
			MessBoxDev box;
			inStream >> box;
			emit reqReadDev(box.key, box.id, box.state);
			break;
		}
		case MESS_TYPE_WRITE_DEV:{
			MessBoxDev box;
			inStream >> box;
			emit reqWriteDev(box.key, box.id, box.state);
			break;
		}
		case MESS_TYPE_GET_RULE:{
			MessBoxRuleFull box;
			inStream >> box;
			emit reqGetRule(box.key, box.id, box);
			break;
		}
		case MESS_TYPE_ADD_RULE:{
			MessBoxRuleFull box;
			inStream >> box;
			emit reqAddRule(box.key, box.id, box);
			break;
		}
		case MESS_TYPE_ALERT:{
			MessBoxAlert box;
			inStream >> box;
			emit alertMess(box.text);
			break;
		}

		default:
			// error
			break;
	}
}

void ComTranslator::readDev(int key, int id)
{
	MessBoxDev dev;
	dev.id = id;
	dev.key = key;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_READ_DEV;
	outStream << dev;
	emit sendMess(out);
}

void ComTranslator::writeDev(int key, int id, int state)
{
	MessBoxDev dev;
	dev.id = id;
	dev.key = key;
	dev.state = state;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_WRITE_DEV;
	outStream << dev;
	emit sendMess(out);
}

void ComTranslator::getDevList(int key, int cid)
{

}

void ComTranslator::getRuleList(int key, int cid)
{

}

void ComTranslator::getRule(int key, int id)
{
	MessBoxRule rule;
	rule.id = id;
	rule.key = key;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_READ_DEV;
	outStream << rule;
	emit sendMess(out);
}

void ComTranslator::addRule(int key, int cid, QString name, QString text, int state)
{

}



