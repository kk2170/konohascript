//QStyleOptionToolBar QStyleOptionToolBar.new();
KMETHOD QStyleOptionToolBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBar *ret_v = new KQStyleOptionToolBar();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionToolBar QStyleOptionToolBar.new(QStyleOptionToolBar other);
KMETHOD QStyleOptionToolBar_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionToolBar  other = *RawPtr_to(const QStyleOptionToolBar *, sfp[1]);
	KQStyleOptionToolBar *ret_v = new KQStyleOptionToolBar(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionToolBar::DummyQStyleOptionToolBar()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionToolBar::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionToolBar::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionToolBar::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionToolBar::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBar::event_map->bigin();
	if ((itr = DummyQStyleOptionToolBar::event_map->find(str)) == DummyQStyleOptionToolBar::event_map->end()) {
		bool ret;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionToolBar::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionToolBar::slot_map->bigin();
	if ((itr = DummyQStyleOptionToolBar::event_map->find(str)) == DummyQStyleOptionToolBar::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionToolBar::KQStyleOptionToolBar() : QStyleOptionToolBar()
{
	self = NULL;
}

KMETHOD QStyleOptionToolBar_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBar *qp = RawPtr_to(KQStyleOptionToolBar *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionToolBar::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionToolBar_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionToolBar *qp = RawPtr_to(KQStyleOptionToolBar *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionToolBar::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionToolBar]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionToolBar_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionToolBar *qp = (KQStyleOptionToolBar *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionToolBar_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionToolBar *qp = (KQStyleOptionToolBar *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionToolBar_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionToolBar(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionToolBar";
	cdef->free = QStyleOptionToolBar_free;
	cdef->reftrace = QStyleOptionToolBar_reftrace;
	cdef->compareTo = QStyleOptionToolBar_compareTo;
}

static knh_IntData_t QStyleOptionToolBarConstInt[] = {
	{"Type", QStyleOptionToolBar::Type},
	{"Version", QStyleOptionToolBar::Version},
	{"None", QStyleOptionToolBar::None},
	{"Movable", QStyleOptionToolBar::Movable},
	{"Beginning", QStyleOptionToolBar::Beginning},
	{"Middle", QStyleOptionToolBar::Middle},
	{"End", QStyleOptionToolBar::End},
	{"OnlyOne", QStyleOptionToolBar::OnlyOne},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionToolBar(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionToolBarConstInt);
}

