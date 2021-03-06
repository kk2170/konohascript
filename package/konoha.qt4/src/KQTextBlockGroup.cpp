
DummyQTextBlockGroup::DummyQTextBlockGroup()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQTextBlockGroup::~DummyQTextBlockGroup()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQTextBlockGroup::setSelf(knh_RawPtr_t *ptr)
{
	DummyQTextBlockGroup::self = ptr;
	DummyQTextObject::setSelf(ptr);
}

bool DummyQTextBlockGroup::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQTextObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQTextBlockGroup::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockGroup::event_map->bigin();
	if ((itr = DummyQTextBlockGroup::event_map->find(str)) == DummyQTextBlockGroup::event_map->end()) {
		bool ret = false;
		ret = DummyQTextObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQTextBlockGroup::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQTextBlockGroup::slot_map->bigin();
	if ((itr = DummyQTextBlockGroup::slot_map->find(str)) == DummyQTextBlockGroup::slot_map->end()) {
		bool ret = false;
		ret = DummyQTextObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQTextBlockGroup::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQTextBlockGroup::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQTextObject::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQTextBlockGroup::connection(QObject *o)
{
	QTextBlockGroup *p = dynamic_cast<QTextBlockGroup*>(o);
	if (p != NULL) {
	}
	DummyQTextObject::connection(o);
}

KQTextBlockGroup::~KQTextBlockGroup()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QTextBlockGroup_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockGroup *qp = RawPtr_to(KQTextBlockGroup *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QTextBlockGroup_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQTextBlockGroup *qp = RawPtr_to(KQTextBlockGroup *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QTextBlockGroup]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QTextBlockGroup_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQTextBlockGroup *qp = (KQTextBlockGroup *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
//			delete (QTextBlockGroup*)qp;
//			p->rawptr = NULL;
		}
	}
}
static void QTextBlockGroup_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQTextBlockGroup *qp = (KQTextBlockGroup *)p->rawptr;
		KQTextBlockGroup *qp = static_cast<KQTextBlockGroup*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QTextBlockGroup_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQTextBlockGroup::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQTextBlockGroup::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QTextBlockGroup::event(event);
		return false;
	}
//	QTextBlockGroup::event(event);
	return true;
}



DEFAPI(void) defQTextBlockGroup(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QTextBlockGroup";
	cdef->free = QTextBlockGroup_free;
	cdef->reftrace = QTextBlockGroup_reftrace;
	cdef->compareTo = QTextBlockGroup_compareTo;
}


