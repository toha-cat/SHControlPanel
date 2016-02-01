#ifndef PROTOCOL_H
#define PROTOCOL_H

#define MESS_TYPE_READ_DEV 0x01
#define MESS_TYPE_WRITE_DEV 0x02
#define MESS_TYPE_GET_LIST_DEV 0x03
#define MESS_TYPE_ADD_DEV 0x05
#define MESS_TYPE_GET_LIST_RULE 0x06
#define MESS_TYPE_GET_RULE 0x07
#define MESS_TYPE_ADD_RULE 0x08
#define MESS_TYPE_ALERT 0x09

typedef qint32 DEV_ID;
typedef qint32 LIST_LEN;
typedef qint32 RULE_ID;
typedef qint32 CAT_ID;

#endif // PROTOCOL_H
