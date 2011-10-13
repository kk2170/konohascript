#ifndef QPICTURE
#define QPICTURE
class DummyQPicture : public DummyQPaintDevice {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQPicture();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQPicture : public QPicture, public DummyQPicture {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQPicture(int formatVersion);
};

#endif //QPICTURE

