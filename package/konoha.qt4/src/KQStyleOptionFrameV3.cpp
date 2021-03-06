//QStyleOptionFrameV3 QStyleOptionFrameV3.new();
KMETHOD QStyleOptionFrameV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrameV3 *ret_v = new KQStyleOptionFrameV3();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QStyleOptionFrameV3 QStyleOptionFrameV3.new(QStyleOptionFrameV3 other);
KMETHOD QStyleOptionFrameV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionFrameV3  other = *RawPtr_to(const QStyleOptionFrameV3 *, sfp[1]);
	KQStyleOptionFrameV3 *ret_v = new KQStyleOptionFrameV3(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QStyleOptionFrameV3 QStyleOptionFrameV3.new(QStyleOptionFrame other);
KMETHOD QStyleOptionFrameV3_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QStyleOptionFrame  other = *RawPtr_to(const QStyleOptionFrame *, sfp[1]);
	KQStyleOptionFrameV3 *ret_v = new KQStyleOptionFrameV3(other);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/

DummyQStyleOptionFrameV3::DummyQStyleOptionFrameV3()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQStyleOptionFrameV3::~DummyQStyleOptionFrameV3()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQStyleOptionFrameV3::setSelf(knh_RawPtr_t *ptr)
{
	DummyQStyleOptionFrameV3::self = ptr;
	DummyQStyleOptionFrameV2::setSelf(ptr);
}

bool DummyQStyleOptionFrameV3::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQStyleOptionFrameV2::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQStyleOptionFrameV3::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFrameV3::event_map->bigin();
	if ((itr = DummyQStyleOptionFrameV3::event_map->find(str)) == DummyQStyleOptionFrameV3::event_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionFrameV2::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQStyleOptionFrameV3::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQStyleOptionFrameV3::slot_map->bigin();
	if ((itr = DummyQStyleOptionFrameV3::slot_map->find(str)) == DummyQStyleOptionFrameV3::slot_map->end()) {
		bool ret = false;
		ret = DummyQStyleOptionFrameV2::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQStyleOptionFrameV3::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQStyleOptionFrameV3::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQStyleOptionFrameV2::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQStyleOptionFrameV3::connection(QObject *o)
{
	QStyleOptionFrameV3 *p = dynamic_cast<QStyleOptionFrameV3*>(o);
	if (p != NULL) {
	}
	DummyQStyleOptionFrameV2::connection(o);
}

KQStyleOptionFrameV3::KQStyleOptionFrameV3() : QStyleOptionFrameV3()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQStyleOptionFrameV3();
}

KQStyleOptionFrameV3::~KQStyleOptionFrameV3()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QStyleOptionFrameV3_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrameV3 *qp = RawPtr_to(KQStyleOptionFrameV3 *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFrameV3]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFrameV3]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QStyleOptionFrameV3_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQStyleOptionFrameV3 *qp = RawPtr_to(KQStyleOptionFrameV3 *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QStyleOptionFrameV3]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QStyleOptionFrameV3]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QStyleOptionFrameV3_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQStyleOptionFrameV3 *qp = (KQStyleOptionFrameV3 *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QStyleOptionFrameV3*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QStyleOptionFrameV3_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQStyleOptionFrameV3 *qp = (KQStyleOptionFrameV3 *)p->rawptr;
		KQStyleOptionFrameV3 *qp = static_cast<KQStyleOptionFrameV3*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QStyleOptionFrameV3_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQStyleOptionFrameV3::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QStyleOptionFrameV3ConstInt[] = {
	{"Version", QStyleOptionFrameV3::Version},
	{NULL, 0}
};

DEFAPI(void) constQStyleOptionFrameV3(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QStyleOptionFrameV3ConstInt);
}


DEFAPI(void) defQStyleOptionFrameV3(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QStyleOptionFrameV3";
	cdef->free = QStyleOptionFrameV3_free;
	cdef->reftrace = QStyleOptionFrameV3_reftrace;
	cdef->compareTo = QStyleOptionFrameV3_compareTo;
}


