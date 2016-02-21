#include "comtranslator.h"

//TODO: В запросах, где передается только id отсылать только id, а не всю структуру

inline QDataStream &operator <<(QDataStream &stream,const BoxDev &sC) // сериализуем;
{
	stream << sC.id;
	stream << sC.state;
	stream << sC.name;
	stream << sC.type;
	stream << sC.param;
	stream << sC.cid;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, BoxDev &sC) // десериализуем;
{
	stream >> sC.id;
	stream >> sC.state;
	stream >> sC.name;
	stream >> sC.type;
	stream >> sC.param;
	stream >> sC.cid;
	return stream;
}

inline QDataStream &operator <<(QDataStream &stream,const BoxRule &sC) // сериализуем;
{
	stream << sC.id;
	stream << sC.state;
	stream << sC.name;
	stream << sC.text;
	stream << sC.cid;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, BoxRule &sC) // десериализуем;
{
	stream >> sC.id;
	stream >> sC.state;
	stream >> sC.name;
	stream >> sC.text;
	stream >> sC.cid;
	return stream;
}

inline QDataStream &operator <<(QDataStream &stream,const BoxAlert &sC) // сериализуем;
{
	stream << sC.text;
	return stream;
}

inline QDataStream &operator >>(QDataStream &stream, BoxAlert &sC) // десериализуем;
{
	stream >> sC.text;
	return stream;
}


ComTranslator::ComTranslator(QObject *parent) : QObject(parent)
{

}

void ComTranslator::translateMess(QByteArray mess)
{
	qint8 type;
	QDataStream inStream(mess);
	inStream >> type;
	switch (type) {
		case MESS_TYPE_READ_DEV:{
			BoxDev box;
			inStream >> box;
			emit reqReadDev(box.id, box.state);
			break;
		}
		case MESS_TYPE_WRITE_DEV:{
			BoxDev box;
			inStream >> box;
			emit reqWriteDev(box.id, box.state);
			break;
		}
		case MESS_TYPE_GET_LIST_DEV:{
			LIST_LEN count;
			inStream >> count;
			QList<BoxDev> list;
			for (int i = 0; i < count; ++i) {
				BoxDev box;
				inStream >> box;
				list.append(box);
			}
            emit reqGetDevList(list);
		}
		case MESS_TYPE_ADD_DEV:{
			BoxDev box;
			inStream >> box;
			emit reqAddDev(box);
			break;
		}
		case MESS_TYPE_GET_RULE:{
			BoxRule box;
			inStream >> box;
			emit reqGetRule(box);
			break;
		}
		case MESS_TYPE_ADD_RULE:{
			BoxRule box;
			inStream >> box;
			emit reqAddRule(box);
			break;
		}
		case MESS_TYPE_GET_LIST_RULE:{
			LIST_LEN count;
			inStream >> count;
			QList<BoxRule> list;
			for (int i = 0; i < count; ++i) {
				BoxRule box;
				inStream >> box;
				list.append(box);
			}
            emit reqGetRuleList(list);
		}
		case MESS_TYPE_ALERT:{
			BoxAlert box;
			inStream >> box;
			emit alertMess(box.text);
			break;
		}

		default:
			// error
			break;
	}
}

void ComTranslator::readDev(int id)
{
	BoxDev dev;
	dev.id = id;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_READ_DEV;
	outStream << dev;
	emit sendMess(out);
}

void ComTranslator::writeDev(int id, QString state)
{
	BoxDev dev;
	dev.id = id;
	dev.state = state;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_WRITE_DEV;
	outStream << dev;
	emit sendMess(out);
}

void ComTranslator::addDev(int cid, QString name, QString type, QString param)
{
	BoxDev dev;
	dev.cid = cid;
	dev.name = name;
	dev.type = type;
	dev.param = param;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_ADD_DEV;
	outStream << dev;
	emit sendMess(out);
}

void ComTranslator::getDevList(int cid)
{
	BoxDev dev;
	dev.cid = cid;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_GET_LIST_DEV;
	outStream << dev;
	emit sendMess(out);
}

void ComTranslator::getRuleList(int cid)
{
	BoxRule rule;
	rule.cid = cid;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_GET_LIST_RULE;
	outStream << rule;
	emit sendMess(out);
}

void ComTranslator::getRule(int id)
{
	BoxRule rule;
	rule.id = id;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_READ_DEV;
	outStream << rule;
	emit sendMess(out);
}

void ComTranslator::addRule(int cid, QString name, QString text, int state)
{
	BoxRule rule;
	rule.name = name;
	rule.state = state;
	rule.text = text;
	rule.cid = cid;
	QByteArray out;
	QDataStream outStream(&out, QIODevice::WriteOnly);
	outStream << MESS_TYPE_ADD_RULE;
	outStream << rule;
	emit sendMess(out);
}



