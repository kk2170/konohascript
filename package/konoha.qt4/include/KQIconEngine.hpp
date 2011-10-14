#ifndef QICONENGINE
#define QICONENGINE
class DummyQIconEngine {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQIconEngine();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQIconEngine : public QIconEngine {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQIconEngine *dummy;
	KQIconEngine();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QICONENGINE


