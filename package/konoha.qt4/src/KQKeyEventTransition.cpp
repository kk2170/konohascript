//QKeyEventTransition QKeyEventTransition.new(QState sourceState);
KMETHOD QKeyEventTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QState*  sourceState = RawPtr_to(QState*, sfp[1]);
	KQKeyEventTransition *ret_v = new KQKeyEventTransition(sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QKeyEventTransition QKeyEventTransition.new(QObject object, int type, int key, QState sourceState);
KMETHOD QKeyEventTransition_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  object = RawPtr_to(QObject*, sfp[1]);
	QEvent::Type type = Int_to(QEvent::Type, sfp[2]);
	int key = Int_to(int, sfp[3]);
	QState*  sourceState = RawPtr_to(QState*, sfp[4]);
	KQKeyEventTransition *ret_v = new KQKeyEventTransition(object, type, key, sourceState);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//int QKeyEventTransition.getKey();
KMETHOD QKeyEventTransition_getKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEventTransition *  qp = RawPtr_to(QKeyEventTransition *, sfp[0]);
	if (qp) {
		int ret_v = qp->key();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QtKeyboardModifiers QKeyEventTransition.getModifierMask();
KMETHOD QKeyEventTransition_getModifierMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEventTransition *  qp = RawPtr_to(QKeyEventTransition *, sfp[0]);
	if (qp) {
		Qt::KeyboardModifiers ret_v = qp->modifierMask();
		Qt::KeyboardModifiers *ret_v_ = new Qt::KeyboardModifiers(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QKeyEventTransition.setKey(int key);
KMETHOD QKeyEventTransition_setKey(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEventTransition *  qp = RawPtr_to(QKeyEventTransition *, sfp[0]);
	if (qp) {
		int key = Int_to(int, sfp[1]);
		qp->setKey(key);
	}
	RETURNvoid_();
}

//void QKeyEventTransition.setModifierMask(QtKeyboardModifiers modifierMask);
KMETHOD QKeyEventTransition_setModifierMask(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QKeyEventTransition *  qp = RawPtr_to(QKeyEventTransition *, sfp[0]);
	if (qp) {
		initFlag(modifierMask, Qt::KeyboardModifiers, sfp[1]);
		qp->setModifierMask(modifierMask);
	}
	RETURNvoid_();
}


DummyQKeyEventTransition::DummyQKeyEventTransition()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQKeyEventTransition::~DummyQKeyEventTransition()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQKeyEventTransition::setSelf(knh_RawPtr_t *ptr)
{
	DummyQKeyEventTransition::self = ptr;
	DummyQEventTransition::setSelf(ptr);
}

bool DummyQKeyEventTransition::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQEventTransition::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQKeyEventTransition::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQKeyEventTransition::event_map->bigin();
	if ((itr = DummyQKeyEventTransition::event_map->find(str)) == DummyQKeyEventTransition::event_map->end()) {
		bool ret = false;
		ret = DummyQEventTransition::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQKeyEventTransition::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQKeyEventTransition::slot_map->bigin();
	if ((itr = DummyQKeyEventTransition::slot_map->find(str)) == DummyQKeyEventTransition::slot_map->end()) {
		bool ret = false;
		ret = DummyQEventTransition::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQKeyEventTransition::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQKeyEventTransition::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQEventTransition::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQKeyEventTransition::connection(QObject *o)
{
	QKeyEventTransition *p = dynamic_cast<QKeyEventTransition*>(o);
	if (p != NULL) {
	}
	DummyQEventTransition::connection(o);
}

KQKeyEventTransition::KQKeyEventTransition(QState* sourceState) : QKeyEventTransition(sourceState)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQKeyEventTransition();
	dummy->connection((QObject*)this);
}

KQKeyEventTransition::~KQKeyEventTransition()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QKeyEventTransition_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQKeyEventTransition *qp = RawPtr_to(KQKeyEventTransition *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QKeyEventTransition]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QKeyEventTransition]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QKeyEventTransition_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQKeyEventTransition *qp = RawPtr_to(KQKeyEventTransition *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QKeyEventTransition]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QKeyEventTransition]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QKeyEventTransition_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQKeyEventTransition *qp = (KQKeyEventTransition *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QKeyEventTransition*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QKeyEventTransition_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQKeyEventTransition *qp = (KQKeyEventTransition *)p->rawptr;
		KQKeyEventTransition *qp = static_cast<KQKeyEventTransition*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QKeyEventTransition_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQKeyEventTransition::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

bool KQKeyEventTransition::event(QEvent *event)
{
	if (!dummy->eventDispatcher(event)) {
		QKeyEventTransition::event(event);
		return false;
	}
//	QKeyEventTransition::event(event);
	return true;
}



DEFAPI(void) defQKeyEventTransition(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QKeyEventTransition";
	cdef->free = QKeyEventTransition_free;
	cdef->reftrace = QKeyEventTransition_reftrace;
	cdef->compareTo = QKeyEventTransition_compareTo;
}


