//@Virtual @Override QRectF QGraphicsBlurEffect.boundingRectFor(QRectF rect);
KMETHOD QGraphicsBlurEffect_boundingRectFor(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp != NULL) {
		const QRectF  rect = *RawPtr_to(const QRectF *, sfp[1]);
		QRectF ret_v = qp->boundingRectFor(rect);
		QRectF *ret_v_ = new QRectF(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QGraphicsBlurEffect QGraphicsBlurEffect.new(QObject parent);
KMETHOD QGraphicsBlurEffect_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QObject*  parent = RawPtr_to(QObject*, sfp[1]);
	KQGraphicsBlurEffect *ret_v = new KQGraphicsBlurEffect(parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//int QGraphicsBlurEffect.getBlurHints();
KMETHOD QGraphicsBlurEffect_getBlurHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHints ret_v = qp->blurHints();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//float QGraphicsBlurEffect.getBlurRadius();
KMETHOD QGraphicsBlurEffect_getBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp != NULL) {
		qreal ret_v = qp->blurRadius();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//void QGraphicsBlurEffect.setBlurHints(int hints);
KMETHOD QGraphicsBlurEffect_setBlurHints(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp != NULL) {
		QGraphicsBlurEffect::BlurHints hints = Int_to(QGraphicsBlurEffect::BlurHints, sfp[1]);
		qp->setBlurHints(hints);
	}
	RETURNvoid_();
}

//void QGraphicsBlurEffect.setBlurRadius(float blurRadius);
KMETHOD QGraphicsBlurEffect_setBlurRadius(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QGraphicsBlurEffect *  qp = RawPtr_to(QGraphicsBlurEffect *, sfp[0]);
	if (qp != NULL) {
		qreal blurRadius = Float_to(qreal, sfp[1]);
		qp->setBlurRadius(blurRadius);
	}
	RETURNvoid_();
}


DummyQGraphicsBlurEffect::DummyQGraphicsBlurEffect()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQGraphicsBlurEffect::setSelf(knh_RawPtr_t *ptr)
{
	DummyQGraphicsBlurEffect::self = ptr;
	DummyQGraphicsEffect::setSelf(ptr);
}

bool DummyQGraphicsBlurEffect::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQGraphicsEffect::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQGraphicsBlurEffect::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsBlurEffect::event_map->bigin();
	if ((itr = DummyQGraphicsBlurEffect::event_map->find(str)) == DummyQGraphicsBlurEffect::event_map->end()) {
		bool ret;
		ret = DummyQGraphicsEffect::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQGraphicsBlurEffect::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQGraphicsBlurEffect::slot_map->bigin();
	if ((itr = DummyQGraphicsBlurEffect::event_map->find(str)) == DummyQGraphicsBlurEffect::slot_map->end()) {
		bool ret;
		ret = DummyQGraphicsEffect::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQGraphicsBlurEffect::KQGraphicsBlurEffect(QObject* parent) : QGraphicsBlurEffect(parent)
{
	self = NULL;
}

KMETHOD QGraphicsBlurEffect_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsBlurEffect *qp = RawPtr_to(KQGraphicsBlurEffect *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQGraphicsBlurEffect::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QGraphicsBlurEffect_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQGraphicsBlurEffect *qp = RawPtr_to(KQGraphicsBlurEffect *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQGraphicsBlurEffect::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QGraphicsBlurEffect]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QGraphicsBlurEffect_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQGraphicsBlurEffect *qp = (KQGraphicsBlurEffect *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QGraphicsBlurEffect_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQGraphicsBlurEffect *qp = (KQGraphicsBlurEffect *)p->rawptr;
		(void)qp;
	}
}

static int QGraphicsBlurEffect_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQGraphicsBlurEffect::event(QEvent *event)
{
	if (!DummyQGraphicsBlurEffect::eventDispatcher(event)) {
		QGraphicsBlurEffect::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQGraphicsBlurEffect(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QGraphicsBlurEffect";
	cdef->free = QGraphicsBlurEffect_free;
	cdef->reftrace = QGraphicsBlurEffect_reftrace;
	cdef->compareTo = QGraphicsBlurEffect_compareTo;
}

static knh_IntData_t QGraphicsBlurEffectConstInt[] = {
	{"PerformanceHint", QGraphicsBlurEffect::PerformanceHint},
	{"QualityHint", QGraphicsBlurEffect::QualityHint},
	{"AnimationHint", QGraphicsBlurEffect::AnimationHint},
	{NULL, 0}
};

DEFAPI(void) constQGraphicsBlurEffect(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QGraphicsBlurEffectConstInt);
}

