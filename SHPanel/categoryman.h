#ifndef CATEGORYMAN_H
#define CATEGORYMAN_H

#include <QObject>

class CategoryMan : public QObject
{
    Q_OBJECT
public:
    explicit CategoryMan(QObject *parent = 0);

signals:

public slots:
};

#endif // CATEGORYMAN_H