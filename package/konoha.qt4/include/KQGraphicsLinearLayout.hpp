#ifndef QGRAPHICSLINEARLAYOUT
#define QGRAPHICSLINEARLAYOUT
class DummyQGraphicsLinearLayout : public DummyQGraphicsLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQGraphicsLinearLayout();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
};

class KQGraphicsLinearLayout : public QGraphicsLinearLayout {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsLinearLayout *dummy;
	KQGraphicsLinearLayout(QGraphicsLayoutItem* parent);
	void setSelf(knh_RawPtr_t *ptr);
};

#endif //QGRAPHICSLINEARLAYOUT


