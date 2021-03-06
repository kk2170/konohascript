//QFocusFrame QFocusFrame.new(QWidget parent);
KMETHOD QFocusFrame_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QWidget*  parent = RawPtr_to(QWidget*, sfp[1]);
	KQFocusFrame *ret_v = new KQFocusFrame(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QFocusFrame.setWidget(QWidget widget);
KMETHOD QFocusFrame_setWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusFrame *  qp = RawPtr_to(QFocusFrame *, sfp[0]);
	if (qp) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setWidget(widget);
	}
	RETURNvoid_();
}

//QWidget QFocusFrame.getWidget();
KMETHOD QFocusFrame_getWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QFocusFrame *  qp = RawPtr_to(QFocusFrame *, sfp[0]);
	if (qp) {
		QWidget* ret_v = qp->widget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQFocusFrame::DummyQFocusFrame()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQFocusFrame::~DummyQFocusFrame()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQFocusFrame::setSelf(knh_RawPtr_t *ptr)
{
	DummyQFocusFrame::self = ptr;
	DummyQWidget::setSelf(ptr);
}

bool DummyQFocusFrame::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQWidget::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQFocusFrame::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFocusFrame::event_map->bigin();
	if ((itr = DummyQFocusFrame::event_map->find(str)) == DummyQFocusFrame::event_map->end()) {
		bool ret = false;
		ret = DummyQWidget::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQFocusFrame::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQFocusFrame::slot_map->bigin();
	if ((itr = DummyQFocusFrame::slot_map->find(str)) == DummyQFocusFrame::slot_map->end()) {
		bool ret = false;
		ret = DummyQWidget::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQFocusFrame::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQFocusFrame::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQWidget::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQFocusFrame::connection(QObject *o)
{
	QFocusFrame *p = dynamic_cast<QFocusFrame*>(o);
	if (p != NULL) {
	}
	DummyQWidget::connection(o);
}

KQFocusFrame::KQFocusFrame(QWidget* parent) : QFocusFrame(parent)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQFocusFrame();
	dummy->connection((QObject*)this);
}

KQFocusFrame::~KQFocusFrame()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QFocusFrame_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFocusFrame *qp = RawPtr_to(KQFocusFrame *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QFocusFrame]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFocusFrame]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QFocusFrame_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQFocusFrame *qp = RawPtr_to(KQFocusFrame *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QFocusFrame]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QFocusFrame]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QFocusFrame_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQFocusFrame *qp = (KQFocusFrame *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QFocusFrame*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QFocusFrame_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQFocusFrame *qp = (KQFocusFrame *)p->rawptr;
		KQFocusFrame *qp = static_cast<KQFocusFrame*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QFocusFrame_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQFocusFrame::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQFocusFrame::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QFocusFrame::event(event);
		return false;
	}
//	QFocusFrame::event(event);
	return true;
}



DEFAPI(void) defQFocusFrame(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QFocusFrame";
	cdef->free = QFocusFrame_free;
	cdef->reftrace = QFocusFrame_reftrace;
	cdef->compareTo = QFocusFrame_compareTo;
}


