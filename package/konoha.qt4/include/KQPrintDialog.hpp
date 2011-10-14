#ifndef QPRINTDIALOG
#define QPRINTDIALOG
class DummyQPrintDialog : public DummyQAbstractPrintDialog {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *accepted_func;
	DummyQPrintDialog();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool acceptedSlot(QPrinter* printer);
};

class KQPrintDialog : public QPrintDialog {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQPrintDialog *dummy;
	KQPrintDialog(QPrinter* printer, QWidget* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QPRINTDIALOG


