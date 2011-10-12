#ifndef QCOREAPPLICATION
#define QCOREAPPLICATION
class DummyQCoreApplication : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQCoreApplication();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQCoreApplication : public QCoreApplication, public DummyQCoreApplication {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQCoreApplication(int argc, char** argv);
	bool event(QEvent *event);
};

#endif //QCOREAPPLICATION


