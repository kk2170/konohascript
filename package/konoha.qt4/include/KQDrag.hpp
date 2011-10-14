#ifndef QDRAG
#define QDRAG
class DummyQDrag : public DummyQObject {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *action_changed_func;
	knh_Func_t *target_changed_func;
	DummyQDrag();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool actionChangedSlot(Qt::DropAction action);
	bool targetChangedSlot(QWidget* new_Target);
};

class KQDrag : public QDrag {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQDrag *dummy;
	KQDrag(QWidget* dragSource);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QDRAG


