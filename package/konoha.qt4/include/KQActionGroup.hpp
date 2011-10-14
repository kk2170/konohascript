#ifndef QACTIONGROUP
#define QACTIONGROUP
class DummyQActionGroup : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *hovered_func;
	knh_Func_t *triggered_func;
	DummyQActionGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool hoveredSlot(QAction* action);
	bool triggeredSlot(QAction* action);
};

class KQActionGroup : public QActionGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQActionGroup *dummy;
	KQActionGroup(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QACTIONGROUP


