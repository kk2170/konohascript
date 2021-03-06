//@Virtual @Override QtOrientations QSpacerItem.expandingDirections();
KMETHOD QSpacerItem_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		Qt::Orientations ret_v = qp->expandingDirections();
		Qt::Orientations *ret_v_ = new Qt::Orientations(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QRect QSpacerItem.getGeometry();
KMETHOD QSpacerItem_getGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override boolean QSpacerItem.isEmpty();
KMETHOD QSpacerItem_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QSize QSpacerItem.maximumSize();
KMETHOD QSpacerItem_maximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QSpacerItem.minimumSize();
KMETHOD QSpacerItem_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QSpacerItem.setGeometry(QRect r);
KMETHOD QSpacerItem_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(r);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QSpacerItem.sizeHint();
KMETHOD QSpacerItem_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSpacerItem QSpacerItem.spacerItem();
KMETHOD QSpacerItem_spacerItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		QSpacerItem* ret_v = qp->spacerItem();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QSpacerItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QSpacerItem QSpacerItem.new(int w, int h, int hPolicy, int vPolicy);
KMETHOD QSpacerItem_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	int w = Int_to(int, sfp[1]);
	int h = Int_to(int, sfp[2]);
	QSizePolicy::Policy hPolicy = Int_to(QSizePolicy::Policy, sfp[3]);
	QSizePolicy::Policy vPolicy = Int_to(QSizePolicy::Policy, sfp[4]);
	KQSpacerItem *ret_v = new KQSpacerItem(w, h, hPolicy, vPolicy);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//void QSpacerItem.changeSize(int w, int h, int hPolicy, int vPolicy);
KMETHOD QSpacerItem_changeSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QSpacerItem *  qp = RawPtr_to(QSpacerItem *, sfp[0]);
	if (qp) {
		int w = Int_to(int, sfp[1]);
		int h = Int_to(int, sfp[2]);
		QSizePolicy::Policy hPolicy = Int_to(QSizePolicy::Policy, sfp[3]);
		QSizePolicy::Policy vPolicy = Int_to(QSizePolicy::Policy, sfp[4]);
		qp->changeSize(w, h, hPolicy, vPolicy);
	}
	RETURNvoid_();
}


DummyQSpacerItem::DummyQSpacerItem()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQSpacerItem::~DummyQSpacerItem()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQSpacerItem::setSelf(knh_RawPtr_t *ptr)
{
	DummyQSpacerItem::self = ptr;
	DummyQLayoutItem::setSelf(ptr);
}

bool DummyQSpacerItem::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQLayoutItem::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQSpacerItem::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSpacerItem::event_map->bigin();
	if ((itr = DummyQSpacerItem::event_map->find(str)) == DummyQSpacerItem::event_map->end()) {
		bool ret = false;
		ret = DummyQLayoutItem::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQSpacerItem::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQSpacerItem::slot_map->bigin();
	if ((itr = DummyQSpacerItem::slot_map->find(str)) == DummyQSpacerItem::slot_map->end()) {
		bool ret = false;
		ret = DummyQLayoutItem::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQSpacerItem::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQSpacerItem::reftrace p->rawptr=[%p]\n", p->rawptr);

	tail_ = DummyQLayoutItem::reftrace(ctx, p, tail_);

	return tail_;
}

void DummyQSpacerItem::connection(QObject *o)
{
	QSpacerItem *p = dynamic_cast<QSpacerItem*>(o);
	if (p != NULL) {
	}
	DummyQLayoutItem::connection(o);
}

KQSpacerItem::KQSpacerItem(int w, int h, QSizePolicy::Policy hPolicy, QSizePolicy::Policy vPolicy) : QSpacerItem(w, h, hPolicy, vPolicy)
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQSpacerItem();
}

KQSpacerItem::~KQSpacerItem()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QSpacerItem_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSpacerItem *qp = RawPtr_to(KQSpacerItem *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QSpacerItem]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSpacerItem]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QSpacerItem_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQSpacerItem *qp = RawPtr_to(KQSpacerItem *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QSpacerItem]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QSpacerItem]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QSpacerItem_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQSpacerItem *qp = (KQSpacerItem *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QSpacerItem*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QSpacerItem_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQSpacerItem *qp = (KQSpacerItem *)p->rawptr;
		KQSpacerItem *qp = static_cast<KQSpacerItem*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QSpacerItem_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQSpacerItem::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}



DEFAPI(void) defQSpacerItem(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QSpacerItem";
	cdef->free = QSpacerItem_free;
	cdef->reftrace = QSpacerItem_reftrace;
	cdef->compareTo = QSpacerItem_compareTo;
}


