#ifndef QSTYLEOPTIONSLIDER
#define QSTYLEOPTIONSLIDER
class DummyQStyleOptionSlider : public DummyQStyleOptionComplex {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionSlider();
	virtual ~DummyQStyleOptionSlider();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionSlider : public QStyleOptionSlider {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQStyleOptionSlider *dummy;
	KQStyleOptionSlider();
	~KQStyleOptionSlider();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONSLIDER


