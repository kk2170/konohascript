//QActionEvent QActionEvent.new(int type, QAction action, QAction before);
KMETHOD QActionEvent_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int type = Int_to(int, sfp[1]);
	QAction*  action = RawPtr_to(QAction*, sfp[2]);
	QAction*  before = RawPtr_to(QAction*, sfp[3]);
	KQActionEvent *ret_v = new KQActionEvent(type, action, before);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//QAction QActionEvent.action();
KMETHOD QActionEvent_action(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionEvent *  qp = RawPtr_to(QActionEvent *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->action();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QAction QActionEvent.before();
KMETHOD QActionEvent_before(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QActionEvent *  qp = RawPtr_to(QActionEvent *, sfp[0]);
	if (qp != NULL) {
		QAction* ret_v = qp->before();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QAction*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQActionEvent::DummyQActionEvent()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQActionEvent::setSelf(knh_RawPtr_t *ptr)
{
	DummyQActionEvent::self = ptr;
	DummyQEvent::setSelf(ptr);
}

bool DummyQActionEvent::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEvent::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQActionEvent::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQActionEvent::event_map->bigin();
	if ((itr = DummyQActionEvent::event_map->find(str)) == DummyQActionEvent::event_map->end()) {
		bool ret;
		ret = DummyQEvent::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQActionEvent::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQActionEvent::slot_map->bigin();
	if ((itr = DummyQActionEvent::event_map->find(str)) == DummyQActionEvent::slot_map->end()) {
		bool ret;
		ret = DummyQEvent::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQActionEvent::KQActionEvent(int type, QAction* action, QAction* before) : QActionEvent(type, action, before)
{
	self = NULL;
}

KMETHOD QActionEvent_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQActionEvent *qp = RawPtr_to(KQActionEvent *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QActionEvent]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQActionEvent::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QActionEvent]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QActionEvent_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQActionEvent *qp = RawPtr_to(KQActionEvent *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QActionEvent]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQActionEvent::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QActionEvent]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QActionEvent_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQActionEvent *qp = (KQActionEvent *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QActionEvent_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQActionEvent *qp = (KQActionEvent *)p->rawptr;
		(void)qp;
	}
}

static int QActionEvent_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQActionEvent(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QActionEvent";
	cdef->free = QActionEvent_free;
	cdef->reftrace = QActionEvent_reftrace;
	cdef->compareTo = QActionEvent_compareTo;
}

