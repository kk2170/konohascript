#ifndef QINPUTMETHODEVENT
#define QINPUTMETHODEVENT
class DummyQInputMethodEvent : public DummyQEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQInputMethodEvent();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQInputMethodEvent : public QInputMethodEvent {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQInputMethodEvent *dummy;
	KQInputMethodEvent();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QINPUTMETHODEVENT


