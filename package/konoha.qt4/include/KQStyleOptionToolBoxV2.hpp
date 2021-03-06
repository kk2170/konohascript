#ifndef QSTYLEOPTIONTOOLBOXV2
#define QSTYLEOPTIONTOOLBOXV2
class DummyQStyleOptionToolBoxV2 : public DummyQStyleOptionToolBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionToolBoxV2();
	virtual ~DummyQStyleOptionToolBoxV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionToolBoxV2 : public QStyleOptionToolBoxV2 {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQStyleOptionToolBoxV2 *dummy;
	KQStyleOptionToolBoxV2();
	~KQStyleOptionToolBoxV2();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONTOOLBOXV2


