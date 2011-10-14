#ifndef QGRAPHICSSCALE
#define QGRAPHICSSCALE
class DummyQGraphicsScale : public DummyQGraphicsTransform {
	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	knh_Func_t *origin_changed_func;
	knh_Func_t *scale_changed_func;
	knh_Func_t *x_scale_changed_func;
	knh_Func_t *y_scale_changed_func;
	knh_Func_t *z_scale_changed_func;
	DummyQGraphicsScale();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
	void connection(QObject *o);
public slots:
	bool originChangedSlot();
	bool scaleChangedSlot();
	bool xScaleChangedSlot();
	bool yScaleChangedSlot();
	bool zScaleChangedSlot();
};

class KQGraphicsScale : public QGraphicsScale {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	DummyQGraphicsScale *dummy;
	KQGraphicsScale(QObject* parent);
	void setSelf(knh_RawPtr_t *ptr);
	bool event(QEvent *event);
};

#endif //QGRAPHICSSCALE


