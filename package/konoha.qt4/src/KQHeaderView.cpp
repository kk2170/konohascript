//@Virtual @Override void QHeaderView.reset();
KMETHOD QHeaderView_reset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		qp->reset();
	}
	RETURNvoid_();
}

//@Virtual @Override void QHeaderView.setModel(QAbstractItemModel model);
KMETHOD QHeaderView_setModel(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		QAbstractItemModel*  model = RawPtr_to(QAbstractItemModel*, sfp[1]);
		qp->setModel(model);
	}
	RETURNvoid_();
}

//@Virtual @Override QSize QHeaderView.sizeHint();
KMETHOD QHeaderView_sizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		QSize ret_v = qp->sizeHint();
		QSize *ret_v_ = new QSize(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//QHeaderView QHeaderView.new(int orientation, QWidget parent);
KMETHOD QHeaderView_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
	QWidget*  parent = RawPtr_to(QWidget*, sfp[2]);
	KQHeaderView *ret_v = new KQHeaderView(orientation, parent);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->self = rptr;
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

//boolean QHeaderView.getCascadingSectionResizes();
KMETHOD QHeaderView_getCascadingSectionResizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->cascadingSectionResizes();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QHeaderView.count();
KMETHOD QHeaderView_count(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->count();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.getDefaultAlignment();
KMETHOD QHeaderView_getDefaultAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment ret_v = qp->defaultAlignment();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.getDefaultSectionSize();
KMETHOD QHeaderView_getDefaultSectionSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->defaultSectionSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.hiddenSectionCount();
KMETHOD QHeaderView_hiddenSectionCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->hiddenSectionCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHeaderView.hideSection(int logicalIndex);
KMETHOD QHeaderView_hideSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		qp->hideSection(logicalIndex);
	}
	RETURNvoid_();
}

//boolean QHeaderView.getHighlightSections();
KMETHOD QHeaderView_getHighlightSections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->highlightSections();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QHeaderView.isClickable();
KMETHOD QHeaderView_isClickable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isClickable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QHeaderView.isMovable();
KMETHOD QHeaderView_isMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isMovable();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QHeaderView.isSectionHidden(int logicalIndex);
KMETHOD QHeaderView_isSectionHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		bool ret_v = qp->isSectionHidden(logicalIndex);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QHeaderView.isSortIndicatorShown();
KMETHOD QHeaderView_isSortIndicatorShown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->isSortIndicatorShown();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QHeaderView.length();
KMETHOD QHeaderView_length(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->length();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.logicalIndex(int visualIndex);
KMETHOD QHeaderView_logicalIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int visualIndex = Int_to(int, sfp[1]);
		int ret_v = qp->logicalIndex(visualIndex);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.logicalIndexAt(int position);
KMETHOD QHeaderView_logicalIndexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int position = Int_to(int, sfp[1]);
		int ret_v = qp->logicalIndexAt(position);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

/*
//int QHeaderView.logicalIndexAt(int x, int y);
KMETHOD QHeaderView_logicalIndexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int x = Int_to(int, sfp[1]);
		int y = Int_to(int, sfp[2]);
		int ret_v = qp->logicalIndexAt(x, y);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
/*
//int QHeaderView.logicalIndexAt(QPoint pos);
KMETHOD QHeaderView_logicalIndexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		const QPoint  pos = *RawPtr_to(const QPoint *, sfp[1]);
		int ret_v = qp->logicalIndexAt(pos);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}
*/
//int QHeaderView.getMinimumSectionSize();
KMETHOD QHeaderView_getMinimumSectionSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->minimumSectionSize();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHeaderView.moveSection(int from_, int to_);
KMETHOD QHeaderView_moveSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int from = Int_to(int, sfp[1]);
		int to = Int_to(int, sfp[2]);
		qp->moveSection(from, to);
	}
	RETURNvoid_();
}

//int QHeaderView.offset();
KMETHOD QHeaderView_offset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->offset();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.orientation();
KMETHOD QHeaderView_orientation(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation ret_v = qp->orientation();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.getResizeMode(int logicalIndex);
KMETHOD QHeaderView_getResizeMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		QHeaderView::ResizeMode ret_v = qp->resizeMode(logicalIndex);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHeaderView.resizeSection(int logicalIndex, int size);
KMETHOD QHeaderView_resizeSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		int size = Int_to(int, sfp[2]);
		qp->resizeSection(logicalIndex, size);
	}
	RETURNvoid_();
}

//void QHeaderView.resizeSections(int mode);
KMETHOD QHeaderView_resizeSections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		QHeaderView::ResizeMode mode = Int_to(QHeaderView::ResizeMode, sfp[1]);
		qp->resizeSections(mode);
	}
	RETURNvoid_();
}

//boolean QHeaderView.restoreState(QByteArray state);
KMETHOD QHeaderView_restoreState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		const QByteArray  state = *RawPtr_to(const QByteArray *, sfp[1]);
		bool ret_v = qp->restoreState(state);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//QByteArray QHeaderView.saveState();
KMETHOD QHeaderView_saveState(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		QByteArray ret_v = qp->saveState();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QHeaderView.sectionPosition(int logicalIndex);
KMETHOD QHeaderView_sectionPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		int ret_v = qp->sectionPosition(logicalIndex);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.sectionSize(int logicalIndex);
KMETHOD QHeaderView_sectionSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		int ret_v = qp->sectionSize(logicalIndex);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.sectionSizeHint(int logicalIndex);
KMETHOD QHeaderView_sectionSizeHint(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		int ret_v = qp->sectionSizeHint(logicalIndex);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.sectionViewportPosition(int logicalIndex);
KMETHOD QHeaderView_sectionViewportPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		int ret_v = qp->sectionViewportPosition(logicalIndex);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QHeaderView.sectionsHidden();
KMETHOD QHeaderView_sectionsHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->sectionsHidden();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QHeaderView.sectionsMoved();
KMETHOD QHeaderView_sectionsMoved(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->sectionsMoved();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//void QHeaderView.setCascadingSectionResizes(boolean enable);
KMETHOD QHeaderView_setCascadingSectionResizes(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool enable = Boolean_to(bool, sfp[1]);
		qp->setCascadingSectionResizes(enable);
	}
	RETURNvoid_();
}

//void QHeaderView.setClickable(boolean clickable);
KMETHOD QHeaderView_setClickable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool clickable = Boolean_to(bool, sfp[1]);
		qp->setClickable(clickable);
	}
	RETURNvoid_();
}

//void QHeaderView.setDefaultAlignment(int alignment);
KMETHOD QHeaderView_setDefaultAlignment(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		Qt::Alignment alignment = Int_to(Qt::Alignment, sfp[1]);
		qp->setDefaultAlignment(alignment);
	}
	RETURNvoid_();
}

//void QHeaderView.setDefaultSectionSize(int size);
KMETHOD QHeaderView_setDefaultSectionSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int size = Int_to(int, sfp[1]);
		qp->setDefaultSectionSize(size);
	}
	RETURNvoid_();
}

//void QHeaderView.setHighlightSections(boolean highlight);
KMETHOD QHeaderView_setHighlightSections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool highlight = Boolean_to(bool, sfp[1]);
		qp->setHighlightSections(highlight);
	}
	RETURNvoid_();
}

//void QHeaderView.setMinimumSectionSize(int size);
KMETHOD QHeaderView_setMinimumSectionSize(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int size = Int_to(int, sfp[1]);
		qp->setMinimumSectionSize(size);
	}
	RETURNvoid_();
}

//void QHeaderView.setMovable(boolean movable);
KMETHOD QHeaderView_setMovable(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool movable = Boolean_to(bool, sfp[1]);
		qp->setMovable(movable);
	}
	RETURNvoid_();
}

//void QHeaderView.setResizeMode(int mode);
KMETHOD QHeaderView_setResizeMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		QHeaderView::ResizeMode mode = Int_to(QHeaderView::ResizeMode, sfp[1]);
		qp->setResizeMode(mode);
	}
	RETURNvoid_();
}

/*
//void QHeaderView.setResizeMode(int logicalIndex, int mode);
KMETHOD QHeaderView_setResizeMode(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		QHeaderView::ResizeMode mode = Int_to(QHeaderView::ResizeMode, sfp[2]);
		qp->setResizeMode(logicalIndex, mode);
	}
	RETURNvoid_();
}
*/
//void QHeaderView.setSectionHidden(int logicalIndex, boolean hide);
KMETHOD QHeaderView_setSectionHidden(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		bool hide = Boolean_to(bool, sfp[2]);
		qp->setSectionHidden(logicalIndex, hide);
	}
	RETURNvoid_();
}

//void QHeaderView.setSortIndicator(int logicalIndex, int order);
KMETHOD QHeaderView_setSortIndicator(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		Qt::SortOrder order = Int_to(Qt::SortOrder, sfp[2]);
		qp->setSortIndicator(logicalIndex, order);
	}
	RETURNvoid_();
}

//void QHeaderView.setSortIndicatorShown(boolean show);
KMETHOD QHeaderView_setSortIndicatorShown(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool show = Boolean_to(bool, sfp[1]);
		qp->setSortIndicatorShown(show);
	}
	RETURNvoid_();
}

//void QHeaderView.setStretchLastSection(boolean stretch);
KMETHOD QHeaderView_setStretchLastSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool stretch = Boolean_to(bool, sfp[1]);
		qp->setStretchLastSection(stretch);
	}
	RETURNvoid_();
}

//void QHeaderView.showSection(int logicalIndex);
KMETHOD QHeaderView_showSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		qp->showSection(logicalIndex);
	}
	RETURNvoid_();
}

//int QHeaderView.sortIndicatorOrder();
KMETHOD QHeaderView_sortIndicatorOrder(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		Qt::SortOrder ret_v = qp->sortIndicatorOrder();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.sortIndicatorSection();
KMETHOD QHeaderView_sortIndicatorSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->sortIndicatorSection();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//boolean QHeaderView.getStretchLastSection();
KMETHOD QHeaderView_getStretchLastSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		bool ret_v = qp->stretchLastSection();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QHeaderView.stretchSectionCount();
KMETHOD QHeaderView_stretchSectionCount(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int ret_v = qp->stretchSectionCount();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHeaderView.swapSections(int first, int second);
KMETHOD QHeaderView_swapSections(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int first = Int_to(int, sfp[1]);
		int second = Int_to(int, sfp[2]);
		qp->swapSections(first, second);
	}
	RETURNvoid_();
}

//int QHeaderView.visualIndex(int logicalIndex);
KMETHOD QHeaderView_visualIndex(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int logicalIndex = Int_to(int, sfp[1]);
		int ret_v = qp->visualIndex(logicalIndex);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//int QHeaderView.visualIndexAt(int position);
KMETHOD QHeaderView_visualIndexAt(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int position = Int_to(int, sfp[1]);
		int ret_v = qp->visualIndexAt(position);
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QHeaderView.headerDataChanged(int orientation, int logicalFirst, int logicalLast);
KMETHOD QHeaderView_headerDataChanged(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		Qt::Orientation orientation = Int_to(Qt::Orientation, sfp[1]);
		int logicalFirst = Int_to(int, sfp[2]);
		int logicalLast = Int_to(int, sfp[3]);
		qp->headerDataChanged(orientation, logicalFirst, logicalLast);
	}
	RETURNvoid_();
}

//void QHeaderView.setOffset(int offset);
KMETHOD QHeaderView_setOffset(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int offset = Int_to(int, sfp[1]);
		qp->setOffset(offset);
	}
	RETURNvoid_();
}

//void QHeaderView.setOffsetToLastSection();
KMETHOD QHeaderView_setOffsetToLastSection(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		qp->setOffsetToLastSection();
	}
	RETURNvoid_();
}

//void QHeaderView.setOffsetToSectionPosition(int visualIndex);
KMETHOD QHeaderView_setOffsetToSectionPosition(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QHeaderView *  qp = RawPtr_to(QHeaderView *, sfp[0]);
	if (qp != NULL) {
		int visualIndex = Int_to(int, sfp[1]);
		qp->setOffsetToSectionPosition(visualIndex);
	}
	RETURNvoid_();
}


DummyQHeaderView::DummyQHeaderView()
{
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}

void DummyQHeaderView::setSelf(knh_RawPtr_t *ptr)
{
	DummyQHeaderView::self = ptr;
	DummyQAbstractItemView::setSelf(ptr);
}

bool DummyQHeaderView::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = DummyQAbstractItemView::eventDispatcher(event);
		break;
	}
	return ret;
}

bool DummyQHeaderView::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHeaderView::event_map->bigin();
	if ((itr = DummyQHeaderView::event_map->find(str)) == DummyQHeaderView::event_map->end()) {
		bool ret;
		ret = DummyQAbstractItemView::addEvent(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQHeaderView::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQHeaderView::slot_map->bigin();
	if ((itr = DummyQHeaderView::event_map->find(str)) == DummyQHeaderView::slot_map->end()) {
		bool ret;
		ret = DummyQAbstractItemView::signalConnect(callback_func, str);
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}


KQHeaderView::KQHeaderView(Qt::Orientation orientation, QWidget* parent) : QHeaderView(orientation, parent)
{
	self = NULL;
}

KMETHOD QHeaderView_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHeaderView *qp = RawPtr_to(KQHeaderView *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QHeaderView]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->DummyQHeaderView::addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHeaderView]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}

KMETHOD QHeaderView_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQHeaderView *qp = RawPtr_to(KQHeaderView *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QHeaderView]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->DummyQHeaderView::signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QHeaderView]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QHeaderView_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (p->rawptr != NULL) {
		KQHeaderView *qp = (KQHeaderView *)p->rawptr;
		(void)qp;
		//delete qp;
	}
}
static void QHeaderView_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
	if (p->rawptr != NULL) {
		KQHeaderView *qp = (KQHeaderView *)p->rawptr;
		(void)qp;
	}
}

static int QHeaderView_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

bool KQHeaderView::event(QEvent *event)
{
	if (!DummyQHeaderView::eventDispatcher(event)) {
		QHeaderView::event(event);
		return false;
	}
	return true;
}

DEFAPI(void) defQHeaderView(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QHeaderView";
	cdef->free = QHeaderView_free;
	cdef->reftrace = QHeaderView_reftrace;
	cdef->compareTo = QHeaderView_compareTo;
}

static knh_IntData_t QHeaderViewConstInt[] = {
	{"Interactive", QHeaderView::Interactive},
	{"Fixed", QHeaderView::Fixed},
	{"Stretch", QHeaderView::Stretch},
	{"ResizeToContents", QHeaderView::ResizeToContents},
	{"Custom", QHeaderView::Custom},
	{NULL, 0}
};

DEFAPI(void) constQHeaderView(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QHeaderViewConstInt);
}

