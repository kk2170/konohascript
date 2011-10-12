#ifndef QFORMLAYOUT
#define QFORMLAYOUT
class DummyQFormLayout : public DummyQLayout {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFormLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQFormLayout : public QFormLayout, public DummyQFormLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQFormLayout(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QFORMLAYOUT


