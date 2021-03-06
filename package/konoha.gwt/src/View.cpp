#include <gwt.hpp>

#ifdef __cplusplus
extern "C" {
#endif

KMETHOD View_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	GamScene *s = RawPtr_to(GamScene *, sfp[1]);
	QGraphicsView *v = new QGraphicsView(s);
	knh_RawPtr_t *p = new_ReturnCppObject(ctx, sfp, v, NULL);
	RETURN_(p);
}

KMETHOD View_setBackgroundOpacity(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	int alpha = Int_to(int, sfp[1]);
	if (alpha < 256) {
		size_t s_max = sizeof("QGraphicsView { background-color: rgba(0, 0, 0, ___); }");
		char style[s_max];
		sprintf(style, "QGraphicsView { background-color: rgba(0, 0, 0, %d); }", alpha);
		v->setStyleSheet(style);
	}
	RETURNvoid_();
}

KMETHOD View_setViewportUpdateMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	QGraphicsView::ViewportUpdateMode mode = Int_to(QGraphicsView::ViewportUpdateMode, sfp[1]);
	v->setViewportUpdateMode(mode);
	RETURNvoid_();
}

KMETHOD View_setRenderHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	QPainter::RenderHint hint = Int_to(QPainter::RenderHint, sfp[1]);
	v->setRenderHint(hint);
	RETURNvoid_();
}

KMETHOD View_rotate(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	qreal angle = Float_to(qreal, sfp[1]);
	v->rotate(angle);
	RETURNvoid_();
}

KMETHOD View_setTransform(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	//v->setTransformationAnchor(QGraphicsView::NoAnchor);
	v->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
	QTransform *trans = RawPtr_to(QTransform *, sfp[1]);
	v->setTransform(*trans);
	RETURNvoid_();
}

KMETHOD View_show(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	v->show();
	RETURNvoid_();
}

KMETHOD View_setShadow(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	QGraphicsDropShadowEffect *e = RawPtr_to(QGraphicsDropShadowEffect *, sfp[1]);
	v->setGraphicsEffect(e);
	RETURNvoid_();
}

KMETHOD View_setMouseTracking(CTX ctx, knh_sfp_t *sfp _RIX)
{
	NO_WARNING();
	QGraphicsView *v = RawPtr_to(QGraphicsView *, sfp[0]);
	bool b = Boolean_to(bool, sfp[1]);
	v->setMouseTracking(b);
	RETURNvoid_();
}

static void View_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL && O_cTBL(p)->total < 4) {
#ifdef DEBUG_MODE
		fprintf(stderr, "View:free\n");
#endif
		QGraphicsView *view = (QGraphicsView *)p->rawptr;
		delete view;
	}
}

static void View_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx;
	(void)p;
	(void)tail_;
	if (p->rawptr != NULL) {
#ifdef DEBUG_MODE
		fprintf(stderr, "View:reftrace\n");
#endif
	}
}

DEFAPI(void) defView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	NO_WARNING2();
	cdef->name = "View";
	cdef->free = View_free;
	cdef->reftrace = View_reftrace;
}

static knh_IntData_t ViewConstInt[] = {
	{"FullViewportUpdate", QGraphicsView::FullViewportUpdate},
	{NULL, 0}
};

DEFAPI(void) constView(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi)
{
	kapi->loadClassIntConst(ctx, cid, ViewConstInt);
}

#ifdef __cplusplus
}
#endif
