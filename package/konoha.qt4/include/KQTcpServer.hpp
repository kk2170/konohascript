#ifndef QTCPSERVER
#define QTCPSERVER
class DummyQTcpServer : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *new_connection_func;
	DummyQTcpServer();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
public slots:
	bool newConnectionSlot();
};

class KQTcpServer : public QTcpServer {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQTcpServer *dummy;
	KQTcpServer(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QTCPSERVER

