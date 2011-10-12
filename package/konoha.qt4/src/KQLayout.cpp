//@Virtual @Override int QLayout.expandingDirections();
KMETHOD QLayout_expandingDirections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientations ret_v = qp->expandingDirections();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual @Override QRect QLayout.getGeometry();
KMETHOD QLayout_getGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->geometry();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QLayout.invalidate();
KMETHOD QLayout_invalidate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		qp->invalidate();
	}
	RETURNvoid_();
}

//@Virtual @Override boolean QLayout.isEmpty();
KMETHOD QLayout_isEmpty(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEmpty();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual @Override QLayout QLayout.layout();
KMETHOD QLayout_layout(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QLayout* ret_v = qp->layout();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayout*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QLayout.maximumSize();
KMETHOD QLayout_maximumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->maximumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override QSize QLayout.minimumSize();
KMETHOD QLayout_minimumSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->minimumSize();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual @Override void QLayout.setGeometry(QRect r);
KMETHOD QLayout_setGeometry(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		const QRect  r = *RawPtr_to(const QRect *, sfp[1]);
		qp->setGeometry(r);
	}
	RETURNvoid_();
}

//
/*
//*/
//boolean QLayout.activate();
KMETHOD QLayout_activate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->activate();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual void QLayout.addItem(QLayoutItem item);
KMETHOD QLayout_addItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QLayoutItem*  item = RawPtr_to(QLayoutItem*, sfp[1]);
		qp->addItem(item);
	}
	RETURNvoid_();
}

//void QLayout.addWidgetOL(QWidget w);
KMETHOD QLayout_addWidgetOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		qp->addWidget(w);
	}
	RETURNvoid_();
}

//QMargins QLayout.contentsMargins();
KMETHOD QLayout_contentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QMargins ret_v = qp->contentsMargins();
		QMargins *ret_v_ = new QMargins(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QRect QLayout.contentsRect();
KMETHOD QLayout_contentsRect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QRect ret_v = qp->contentsRect();
		QRect *ret_v_ = new QRect(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//@Virtual int QLayout.count();
KMETHOD QLayout_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QLayout.getContentsMargins(int left, int top, int right, int bottom);
KMETHOD QLayout_getContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		int* left = Int_to(int*, sfp[1]);
		int* top = Int_to(int*, sfp[2]);
		int* right = Int_to(int*, sfp[3]);
		int* bottom = Int_to(int*, sfp[4]);
		qp->getContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

//@Virtual int QLayout.indexOf(QWidget widget);
KMETHOD QLayout_indexOf(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		int ret_v = qp->indexOf(widget);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QLayout.isEnabled();
KMETHOD QLayout_isEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isEnabled();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//@Virtual QLayoutItem QLayout.itemAt(int index);
KMETHOD QLayout_itemAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->itemAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QLayout.getMenuBar();
KMETHOD QLayout_getMenuBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->menuBar();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QWidget QLayout.parentWidget();
KMETHOD QLayout_parentWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QWidget* ret_v = qp->parentWidget();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QWidget*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLayout.removeItem(QLayoutItem item);
KMETHOD QLayout_removeItem(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QLayoutItem*  item = RawPtr_to(QLayoutItem*, sfp[1]);
		qp->removeItem(item);
	}
	RETURNvoid_();
}

//void QLayout.removeWidget(QWidget widget);
KMETHOD QLayout_removeWidget(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->removeWidget(widget);
	}
	RETURNvoid_();
}

//boolean QLayout.setAlignmentOL(QWidget w, int alignment);
KMETHOD QLayout_setAlignmentOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QWidget*  w = RawPtr_to(QWidget*, sfp[1]);
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[2]);
		bool ret_v = qp->setAlignment(w, alignment);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

/*
//void QLayout.setAlignmentOL(int alignment);
KMETHOD QLayout_setAlignmentOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		qp->setAlignment(alignment);
	}
	RETURNvoid_();
}
*/
/*
//boolean QLayout.setAlignmentOL(QLayout l, int alignment);
KMETHOD QLayout_setAlignmentOL(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QLayout*  l = RawPtr_to(QLayout*, sfp[1]);
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[2]);
		bool ret_v = qp->setAlignment(l, alignment);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}
*/
//void QLayout.setContentsMargins(int left, int top, int right, int bottom);
KMETHOD QLayout_setContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		int left = Int_to(int, sfp[1]);
		int top = Int_to(int, sfp[2]);
		int right = Int_to(int, sfp[3]);
		int bottom = Int_to(int, sfp[4]);
		qp->setContentsMargins(left, top, right, bottom);
	}
	RETURNvoid_();
}

/*
//void QLayout.setContentsMargins(QMargins margins);
KMETHOD QLayout_setContentsMargins(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		const QMargins  margins = *RawPtr_to(const QMargins *, sfp[1]);
		qp->setContentsMargins(margins);
	}
	RETURNvoid_();
}
*/
//void QLayout.setEnabled(boolean enable);
KMETHOD QLayout_setEnabled(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setEnabled(enable);
	}
	RETURNvoid_();
}

//void QLayout.setMenuBar(QWidget widget);
KMETHOD QLayout_setMenuBar(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QWidget*  widget = RawPtr_to(QWidget*, sfp[1]);
		qp->setMenuBar(widget);
	}
	RETURNvoid_();
}

//void QLayout.setSizeConstraint(int arg0);
KMETHOD QLayout_setSizeConstraint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QLayout::SizeConstraint arg0 = Int_to(QLayout::SizeConstraint, sfp[1]);
		qp->setSizeConstraint(arg0);
	}
	RETURNvoid_();
}

//@Virtual void QLayout.setSpacing(int arg0);
KMETHOD QLayout_setSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		int arg0 = Int_to(int, sfp[1]);
		qp->setSpacing(arg0);
	}
	RETURNvoid_();
}

//int QLayout.getSizeConstraint();
KMETHOD QLayout_getSizeConstraint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		QLayout::SizeConstraint ret_v = qp->sizeConstraint();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual int QLayout.getSpacing();
KMETHOD QLayout_getSpacing(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->spacing();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//@Virtual QLayoutItem QLayout.takeAt(int index);
KMETHOD QLayout_takeAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		int index = Int_to(int, sfp[1]);
		QLayoutItem* ret_v = qp->takeAt(index);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QLayoutItem*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//void QLayout.update();
KMETHOD QLayout_update(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		qp->update();
	}
	RETURNvoid_();
}

//QSize QLayout.closestAcceptableSize(QWidget widget, QSize size);
KMETHOD QLayout_closestAcceptableSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QLayout *  qp = RawPtr_to(QLayout *, sfp[0]);
	if (qp != NULL) {
		const QWidget*  widget = RawPtr_to(const QWidget*, sfp[1]);
		const QSize  size = *RawPtr_to(const QSize *, sfp[2]);
		QSize ret_v = qp->closestAcceptableSize(widget, size);
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}


DummyQLayout::DummyQLayout()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQLayout::setSelf(knh_RawPtr_t *ptr)
{
	DummyQLayout::self = ptr;
	DummyQLayoutItem::setSelf(ptr);
	DummyQObject::setSelf(ptr);
}

bool DummyQLayout::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQLayoutItem::eventDispatcher(event);
		if (ret) break;
		ret = DummyQObject::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQLayout::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLayout::event_map->bigin();
	if ((itr = DummyQLayout::event_map->find(str)) == DummyQLayout::event_map->end()) {
		bool ret;
		ret = DummyQLayoutItem::addEvent(callback_func, str);
		if (ret) return true;
		ret = DummyQObject::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQLayout::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQLayout::slot_map->bigin();
	if ((itr = DummyQLayout::event_map->find(str)) == DummyQLayout::slot_map->end()) {
		bool ret;
		ret = DummyQLayoutItem::signalConnect(callback_func, str);
		if (ret) return true;
		ret = DummyQObject::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQLayout::KQLayout(QWidget* parent) : QLayout(parent)
{
	self = NULL;
}

KMETHOD QLayout_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLayout *qp = RawPtr_to(KQLayout *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QLayout]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQLayout::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLayout]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QLayout_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQLayout *qp = RawPtr_to(KQLayout *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QLayout]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQLayout::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QLayout]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QLayout_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQLayout *qp = (KQLayout *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QLayout_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQLayout *qp = (KQLayout *)p->rawptr;
		(void)qp;
	}
}

static int QLayout_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQLayout::event(QEvent *event)
{
	if (!DummyQLayout::eventDispatcher(event)) {
		QLayout::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQLayout(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QLayout";
	cdef->free = QLayout_free;
	cdef->reftrace = QLayout_reftrace;
	cdef->compareTo = QLayout_compareTo;
}

static knh_IntData_t QLayoutConstInt[] = {
	{"SetDefaultConstraint", QLayout::SetDefaultConstraint},
	{"SetFixedSize", QLayout::SetFixedSize},
	{"SetMinimumSize", QLayout::SetMinimumSize},
	{"SetMaximumSize", QLayout::SetMaximumSize},
	{"SetMinAndMaxSize", QLayout::SetMinAndMaxSize},
	{"SetNoConstraint", QLayout::SetNoConstraint},
	{NULL, 0}
};

DEFAPI(void) constQLayout(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QLayoutConstInt);
}

