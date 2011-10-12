#ifndef QCOLORDIALOG
#define QCOLORDIALOG
class DummyQColorDialog : public DummyQDialog {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQColorDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQColorDialog : public QColorDialog, public DummyQColorDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQColorDialog(QWidget* parent);
	bool event(QEvent *event);
};

#endif //QCOLORDIALOG


