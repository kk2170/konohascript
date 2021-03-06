//QPointF QTapGesture.getPosition();
KMETHOD QTapGesture_getPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTapGesture *  qp = RawPtr_to(QTapGesture *, sfp[0]);
	if (qp) {
		QPointF ret_v = qp->position();
		QPointF *ret_v_ = new QPointF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QTapGesture.setPosition(QPointF pos);
KMETHOD QTapGesture_setPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QTapGesture *  qp = RawPtr_to(QTapGesture *, sfp[0]);
	if (qp) {
		const QPointF  pos = *RawPtr_to(const QPointF *, sfp[1]);
		qp->setPosition(pos);
	}
	RETURNvoid_();
}


DummyQTapGesture::DummyQTapGesture()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTapGesture::~DummyQTapGesture()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTapGesture::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTapGesture::self = ptr;
	DummyQGesture::setSelf(ptr);
}

bool DummyQTapGesture::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGesture::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTapGesture::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTapGesture::event_map->bigin();
	if ((itr = DummyQTapGesture::event_map->find(str)) == DummyQTapGesture::event_map->end()) {
		bool ret = false;
		ret = DummyQGesture::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTapGesture::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTapGesture::slot_map->bigin();
	if ((itr = DummyQTapGesture::slot_map->find(str)) == DummyQTapGesture::slot_map->end()) {
		bool ret = false;
		ret = DummyQGesture::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTapGesture::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTapGesture::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQGesture::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTapGesture::connection(QObject *o)
{
	QTapGesture *p = dynamic_cast<QTapGesture*>(o);
	if (p != NULL) {
	}
	DummyQGesture::connection(o);
}

KQTapGesture::~KQTapGesture()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTapGesture_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTapGesture *qp = RawPtr_to(KQTapGesture *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTapGesture]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTapGesture]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTapGesture_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTapGesture *qp = RawPtr_to(KQTapGesture *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTapGesture]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTapGesture]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTapGesture_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTapGesture *qp = (KQTapGesture *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QTapGesture*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QTapGesture_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTapGesture *qp = (KQTapGesture *)p->rawptr;
		KQTapGesture *qp = static_cast<KQTapGesture*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTapGesture_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTapGesture::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTapGesture::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTapGesture::event(event);
		return false;
	}
//	QTapGesture::event(event);
	return true;
}



DEFAPI(void) defQTapGesture(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTapGesture";
	cdef->free = QTapGesture_free;
	cdef->reftrace = QTapGesture_reftrace;
	cdef->compareTo = QTapGesture_compareTo;
}


