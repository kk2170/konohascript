#ifndef QFONTINFO
#define QFONTINFO
class DummyQFontInfo {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQFontInfo();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQFontInfo : public QFontInfo {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQFontInfo *dummy;
	KQFontInfo(const QFont font);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QFONTINFO


