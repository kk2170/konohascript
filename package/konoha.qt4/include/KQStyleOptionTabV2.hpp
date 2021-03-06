#ifndef QSTYLEOPTIONTABV2
#define QSTYLEOPTIONTABV2
class DummyQStyleOptionTabV2 : public DummyQStyleOptionTab {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQStyleOptionTabV2();
	virtual ~DummyQStyleOptionTabV2();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	knh_Object_t** reftrace(CTX ctx, knh_RawPtr_t *p FTRARG);
	void connection(QObject *o);
};

class KQStyleOptionTabV2 : public QStyleOptionTabV2 {
//	Q_OBJECT;
public:
	int magic_num;
	knh_RawPtr_t *self;
	DummyQStyleOptionTabV2 *dummy;
	KQStyleOptionTabV2();
	~KQStyleOptionTabV2();
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QSTYLEOPTIONTABV2


