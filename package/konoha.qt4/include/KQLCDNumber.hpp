#ifndef QLCDNUMBER
#define QLCDNUMBER
class DummyQLCDNumber : public DummyQFrame {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQLCDNumber();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQLCDNumber : public QLCDNumber, public DummyQLCDNumber {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQLCDNumber(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QLCDNUMBER

