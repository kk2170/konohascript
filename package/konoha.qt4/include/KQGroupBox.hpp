#ifndef QGROUPBOX
#define QGROUPBOX
class DummyQGroupBox : public DummyQWidget {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *clicked_func;
	knh_Func_t *toggled_func;
	DummyQGroupBox();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool clickedSlot(bool checked);
	bool toggledSlot(bool on);
};

class KQGroupBox : public QGroupBox {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGroupBox *dummy;
	KQGroupBox(QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGROUPBOX


