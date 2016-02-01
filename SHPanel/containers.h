#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <QList>
#include "protocol.h"

typedef struct{
	DEV_ID id;
	QString name;
	QString state;
	QString type;
	QString param;
	CAT_ID cid;
} BoxDev;

typedef struct{
    CAT_ID cid;
    QString name;
} BoxCategory;

typedef struct{
	RULE_ID id;
	qint8 state;
	QString name;
	QString text;
	CAT_ID cid;
} BoxRule;

typedef struct{
	QString text;
} BoxAlert;

typedef QList<BoxDev> BoxListDev;

typedef QList<BoxCategory> BoxListCategory;

typedef QList<BoxRule> BoxListRule;

#endif // CONTAINERS_H
