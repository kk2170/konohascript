#ifndef QTEXTDECODER
#define QTEXTDECODER
class DummyQTextDecoder {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQTextDecoder();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQTextDecoder : public QTextDecoder, public DummyQTextDecoder {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQTextDecoder(const QTextCodec* codec);
};

#endif //QTEXTDECODER


