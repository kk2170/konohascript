//@Virtual @Override QSize QProgressBar.minimumSizeHint();
KMETHOD QProgressBar_minimumSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QProgressBar.sizeHint();
KMETHOD QProgressBar_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QProgressBar QProgressBar.new(QWidget parent);
KMETHOD QProgressBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQProgressBar *ret_v = new KQProgressBar(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QtAlignment QProgressBar.getAlignment();
KMETHOD QProgressBar_getAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		Qt::Alignment ret_v = qp->alignment();
		Qt::Alignment *ret_v_ = new Qt::Alignment(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QProgressBar.getFormat();
KMETHOD QProgressBar_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		QString ret_v = qp->format();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//boolean QProgressBar.getInvertedAppearance();
KMETHOD QProgressBar_getInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		bool ret_v = qp->invertedAppearance();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//boolean QProgressBar.getInvertedAppearance();
KMETHOD QProgressBar_getInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		bool ret_v = qp->invertedAppearance();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//boolean QProgressBar.isTextVisible();
KMETHOD QProgressBar_isTextVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isTextVisible();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QProgressBar.getMaximum();
KMETHOD QProgressBar_getMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		int ret_v = qp->maximum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProgressBar.getMinimum();
KMETHOD QProgressBar_getMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		int ret_v = qp->minimum();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QProgressBar.getOrientation();
KMETHOD QProgressBar_getOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QProgressBar.setAlignment(QtAlignment alignment);
KMETHOD QProgressBar_setAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		initFlag(alignment, Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}

//void QProgressBar.setFormat(String fmt);
KMETHOD QProgressBar_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		const QString format = String_to(const QString, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//void QProgressBar.setInvertedAppearance(boolean invert);
KMETHOD QProgressBar_setInvertedAppearance(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		bool invert = Boolean_to(bool, sfp[1]);
		qp->setInvertedAppearance(invert);
	}
	RETURNvoid_();
}

//void QProgressBar.setTextDirection(int textDirection);
KMETHOD QProgressBar_setTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		QProgressBar::Direction textDirection = Int_to(QProgressBar::Direction, sfp[1]);
		qp->setTextDirection(textDirection);
	}
	RETURNvoid_();
}

//void QProgressBar.setTextVisible(boolean visible);
KMETHOD QProgressBar_setTextVisible(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		bool visible = Boolean_to(bool, sfp[1]);
		qp->setTextVisible(visible);
	}
	RETURNvoid_();
}

//@Virtual String QProgressBar.text();
KMETHOD QProgressBar_text(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		QString ret_v = qp->text();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QProgressBar.getTextDirection();
KMETHOD QProgressBar_getTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		QProgressBar::Direction ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QProgressBar.getTextDirection();
KMETHOD QProgressBar_getTextDirection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		QProgressBar::Direction ret_v = qp->textDirection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QProgressBar.getValue();
KMETHOD QProgressBar_getValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		int ret_v = qp->value();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QProgressBar.reset();
KMETHOD QProgressBar_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		qp->reset();
	}
	RETURNvoid_();
}

//void QProgressBar.setMaximum(int maximum);
KMETHOD QProgressBar_setMaximum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		int maximum = Int_to(int, sfp[1]);
		qp->setMaximum(maximum);
	}
	RETURNvoid_();
}

//void QProgressBar.setMinimum(int minimum);
KMETHOD QProgressBar_setMinimum(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		int minimum = Int_to(int, sfp[1]);
		qp->setMinimum(minimum);
	}
	RETURNvoid_();
}

//void QProgressBar.setOrientation(int arg0);
KMETHOD QProgressBar_setOrientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		Qt::Orientation arg0 = Int_to(Qt::Orientation, sfp[1]);
		qp->setOrientation(arg0);
	}
	RETURNvoid_();
}

//void QProgressBar.setRange(int minimum, int maximum);
KMETHOD QProgressBar_setRange(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		int minimum = Int_to(int, sfp[1]);
		int maximum = Int_to(int, sfp[2]);
		qp->setRange(minimum, maximum);
	}
	RETURNvoid_();
}

//void QProgressBar.setValue(int value);
KMETHOD QProgressBar_setValue(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QProgressBar *  qp = RawPtr_to(QProgressBar *, sfp[0]);
	if (qp) {
		int value = Int_to(int, sfp[1]);
		qp->setValue(value);
	}
	RETURNvoid_();
}


DummyQProgressBar::DummyQProgressBar()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	value_changed_func = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
	slot_map->insert(map<string, knh_Func_t *>::value_type("value-changed", NULL));
}
DummyQProgressBar::~DummyQProgressBar()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQProgressBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQProgressBar::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQProgressBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQProgressBar::valueChangedSlot(int value)
{
	if (value_changed_func != NULL) {
		CTX lctx = knh_getCurrentContext();
		knh_sfp_t *lsfp = lctx->esp;
		KNH_SETv(lctx, lsfp[K_CALLDELTA+1].o, UPCAST(self));
		lsfp[K_CALLDELTA+2].ivalue = value;
		knh_Func_invoke(lctx, value_changed_func, lsfp, 2);
		return true;
	}
	return false;
}

bool DummyQProgressBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProgressBar::event_map->bigin();
	if ((itr = DummyQProgressBar::event_map->find(str)) == DummyQProgressBar::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQProgressBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQProgressBar::slot_map->bigin();
	if ((itr = DummyQProgressBar::slot_map->find(str)) == DummyQProgressBar::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		value_changed_func = (*slot_map)["value-changed"];
		return true;
	}
}

knh_Object_t** DummyQProgressBar::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
//	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQProgressBar::reftrace p->rawptr=[%p]\n", p->rawptr);

	int list_size = 2;
	KNH_ENSUREREF(ctx, list_size);

	KNH_ADDNNREF(ctx, value_changed_func);

	KNH_SIZEREF(ctx);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQProgressBar::connection(QObject *o)
{
	QProgressBar *p = dynamic_cast<QProgressBar*>(o);
	if (p != NULL) {
		connect(p, SIGNAL(valueChanged(int)), this, SLOT(valueChangedSlot(int)));
	}
	DummyQWidget::connection(o);
}

KQProgressBar::KQProgressBar(QWidget* parent) : QProgressBar(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQProgressBar();
	dummy->connection((QObject*)this);
}

KQProgressBar::~KQProgressBar()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QProgressBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProgressBar *qp = RawPtr_to(KQProgressBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QProgressBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProgressBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QProgressBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQProgressBar *qp = RawPtr_to(KQProgressBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QProgressBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QProgressBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QProgressBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQProgressBar *qp = (KQProgressBar *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QProgressBar*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QProgressBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQProgressBar *qp = (KQProgressBar *)p->rawptr;
		KQProgressBar *qp = static_cast<KQProgressBar*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QProgressBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQProgressBar::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQProgressBar::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QProgressBar::event(event);
		return false;
	}
//	QProgressBar::event(event);
	return true;
}

static knh_IntData_t QProgressBarConstInt[] = {
	{"TopToBottom", QProgressBar::TopToBottom},
	{"BottomToTop", QProgressBar::BottomToTop},
	{NULL, 0}
};

DEFAPI(void) constQProgressBar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QProgressBarConstInt);
}


DEFAPI(void) defQProgressBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QProgressBar";
	cdef->free = QProgressBar_free;
	cdef->reftrace = QProgressBar_reftrace;
	cdef->compareTo = QProgressBar_compareTo;
}


