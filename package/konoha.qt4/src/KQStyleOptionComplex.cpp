//QStyleOptionComplex QStyleOptionComplex.new(int version, int type);
KMETHOD QStyleOptionComplex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int version = Int_to(int, sfp[1]);
	int type = Int_to(int, sfp[2]);
	KQStyleOptionComplex *ret_v = new KQStyleOptionComplex(version, type);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionComplex QStyleOptionComplex.new(QStyleOptionComplex other);
KMETHOD QStyleOptionComplex_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionComplex  other = *RawPtr_to(const QStyleOptionComplex *, sfp[1]);
	KQStyleOptionComplex *ret_v = new KQStyleOptionComplex(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionComplex::DummyQStyleOptionComplex()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQStyleOptionComplex::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionComplex::self = ptr;
	DummyQStyleOption::setSelf(ptr);
}

bool DummyQStyleOptionComplex::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOption::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionComplex::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionComplex::event_map->bigin();
	if ((itr = DummyQStyleOptionComplex::event_map->find(str)) == DummyQStyleOptionComplex::event_map->end()) {
		bool ret;
		ret = DummyQStyleOption::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionComplex::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionComplex::slot_map->bigin();
	if ((itr = DummyQStyleOptionComplex::event_map->find(str)) == DummyQStyleOptionComplex::slot_map->end()) {
		bool ret;
		ret = DummyQStyleOption::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQStyleOptionComplex::KQStyleOptionComplex(int version, int type) : QStyleOptionComplex(version, type)
{
	self = NULL;
}

KMETHOD QStyleOptionComplex_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComplex *qp = RawPtr_to(KQStyleOptionComplex *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionComplex]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQStyleOptionComplex::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionComplex]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QStyleOptionComplex_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionComplex *qp = RawPtr_to(KQStyleOptionComplex *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionComplex]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQStyleOptionComplex::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionComplex]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionComplex_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQStyleOptionComplex *qp = (KQStyleOptionComplex *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QStyleOptionComplex_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQStyleOptionComplex *qp = (KQStyleOptionComplex *)p->rawptr;
		(void)qp;
	}
}

static int QStyleOptionComplex_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

DEFAPI(void) defQStyleOptionComplex(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionComplex";
	cdef->free = QStyleOptionComplex_free;
	cdef->reftrace = QStyleOptionComplex_reftrace;
	cdef->compareTo = QStyleOptionComplex_compareTo;
}

static knh_IntData_t QStyleOptionComplexConstInt[] = {
	{"Type", QStyleOptionComplex::Type},
	{"Version", QStyleOptionComplex::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionComplex(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionComplexConstInt);
}

