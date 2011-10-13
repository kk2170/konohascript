#ifndef QUNDOGROUP
#define QUNDOGROUP
class DummyQUndoGroup : public DummyQObject {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQUndoGroup();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQUndoGroup : public QUndoGroup, public DummyQUndoGroup {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQUndoGroup(QObject* parent);
	bool event(QEvent *event);
};

#endif //QUNDOGROUP

