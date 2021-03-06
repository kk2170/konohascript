//QImageWriter QImageWriter.new();
KMETHOD QImageWriter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImageWriter *ret_v = new KQImageWriter();
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}

/*
//QImageWriter QImageWriter.new(QIODevice device, QByteArray fmt);
KMETHOD QImageWriter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	KQImageWriter *ret_v = new KQImageWriter(device, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
/*
//QImageWriter QImageWriter.new(String fileName, QByteArray fmt);
KMETHOD QImageWriter_new(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	const QString fileName = String_to(const QString, sfp[1]);
	const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[2]);
	KQImageWriter *ret_v = new KQImageWriter(fileName, format);
	knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v, NULL);
	ret_v->setSelf(rptr);
	RETURN_(rptr);
}
*/
//boolean QImageWriter.canWrite();
KMETHOD QImageWriter_canWrite(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		bool ret_v = qp->canWrite();
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//int QImageWriter.getCompression();
KMETHOD QImageWriter_getCompression(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		int ret_v = qp->compression();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//QIODevice QImageWriter.getDevice();
KMETHOD QImageWriter_getDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		QIODevice* ret_v = qp->device();
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, (QIODevice*)ret_v, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//int QImageWriter.error();
KMETHOD QImageWriter_error(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		QImageWriter::ImageWriterError ret_v = qp->error();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//String QImageWriter.errorString();
KMETHOD QImageWriter_errorString(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		QString ret_v = qp->errorString();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//String QImageWriter.getFileName();
KMETHOD QImageWriter_getFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		QString ret_v = qp->fileName();
		const char *ret_c = ret_v.toLocal8Bit().data();
		RETURN_(new_String(ctx, ret_c));
	} else {
		RETURN_(KNH_NULL);
	}
}

//QByteArray QImageWriter.getFormat();
KMETHOD QImageWriter_getFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		QByteArray ret_v = qp->format();
		QByteArray *ret_v_ = new QByteArray(ret_v);
		knh_RawPtr_t *rptr = new_ReturnCppObject(ctx, sfp, ret_v_, NULL);
		RETURN_(rptr);
	} else {
		RETURN_(KNH_NULL);
	}
}

//float QImageWriter.getGamma();
KMETHOD QImageWriter_getGamma(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		float ret_v = qp->gamma();
		RETURNf_(ret_v);
	} else {
		RETURNf_(0.0f);
	}
}

//int QImageWriter.getQuality();
KMETHOD QImageWriter_getQuality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		int ret_v = qp->quality();
		RETURNi_(ret_v);
	} else {
		RETURNi_(0);
	}
}

//void QImageWriter.setCompression(int compression);
KMETHOD QImageWriter_setCompression(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		int compression = Int_to(int, sfp[1]);
		qp->setCompression(compression);
	}
	RETURNvoid_();
}

//void QImageWriter.setDevice(QIODevice device);
KMETHOD QImageWriter_setDevice(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		QIODevice*  device = RawPtr_to(QIODevice*, sfp[1]);
		qp->setDevice(device);
	}
	RETURNvoid_();
}

//void QImageWriter.setFileName(String fileName);
KMETHOD QImageWriter_setFileName(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		const QString fileName = String_to(const QString, sfp[1]);
		qp->setFileName(fileName);
	}
	RETURNvoid_();
}

//void QImageWriter.setFormat(QByteArray fmt);
KMETHOD QImageWriter_setFormat(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		const QByteArray  format = *RawPtr_to(const QByteArray *, sfp[1]);
		qp->setFormat(format);
	}
	RETURNvoid_();
}

//void QImageWriter.setGamma(float gamma);
KMETHOD QImageWriter_setGamma(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		float gamma = Float_to(float, sfp[1]);
		qp->setGamma(gamma);
	}
	RETURNvoid_();
}

//void QImageWriter.setQuality(int quality);
KMETHOD QImageWriter_setQuality(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		int quality = Int_to(int, sfp[1]);
		qp->setQuality(quality);
	}
	RETURNvoid_();
}

//void QImageWriter.setText(String key, String text);
KMETHOD QImageWriter_setText(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		const QString key = String_to(const QString, sfp[1]);
		const QString text = String_to(const QString, sfp[2]);
		qp->setText(key, text);
	}
	RETURNvoid_();
}

//boolean QImageWriter.supportsOption(int option);
KMETHOD QImageWriter_supportsOption(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		QImageIOHandler::ImageOption option = Int_to(QImageIOHandler::ImageOption, sfp[1]);
		bool ret_v = qp->supportsOption(option);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//boolean QImageWriter.write(QImage image);
KMETHOD QImageWriter_write(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *  qp = RawPtr_to(QImageWriter *, sfp[0]);
	if (qp) {
		const QImage  image = *RawPtr_to(const QImage *, sfp[1]);
		bool ret_v = qp->write(image);
		RETURNb_(ret_v);
	} else {
		RETURNb_(false);
	}
}

//Array<QByteArray> QImageWriter.supportedImageFormats();
KMETHOD QImageWriter_supportedImageFormats(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	if (true) {
		QList<QByteArray> ret_v = QImageWriter::supportedImageFormats();
		int list_size = ret_v.size();
		knh_Array_t *a = new_Array0(ctx, list_size);
		knh_class_t cid = knh_getcid(ctx, STEXT("QByteArray"));
		for (int n = 0; n < list_size; n++) {
			QByteArray *ret_v_ = new QByteArray(ret_v[n]);
			knh_RawPtr_t *p = new_RawPtr(ctx, ClassTBL(cid), ret_v_);
			knh_Array_add(ctx, a, (knh_Object_t *)p);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}
	

//Array<String> QImageWriter.parents();
KMETHOD QImageWriter_parents(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	QImageWriter *qp = RawPtr_to(QImageWriter*, sfp[0]);
	if (qp != NULL) {
		int size = 10;
		knh_Array_t *a = new_Array0(ctx, size);
		const knh_ClassTBL_t *ct = sfp[0].p->h.cTBL;
		while(ct->supcid != CLASS_Object) {
			ct = ct->supTBL;
			knh_Array_add(ctx, a, (knh_Object_t *)ct->lname);
		}
		RETURN_(a);
	} else {
		RETURN_(KNH_NULL);
	}
}

DummyQImageWriter::DummyQImageWriter()
{
	CTX lctx = knh_getCurrentContext();
	(void)lctx;
	self = NULL;
	event_map = new map<string, knh_Func_t *>();
	slot_map = new map<string, knh_Func_t *>();
}
DummyQImageWriter::~DummyQImageWriter()
{
	delete event_map;
	delete slot_map;
	event_map = NULL;
	slot_map = NULL;
}

void DummyQImageWriter::setSelf(knh_RawPtr_t *ptr)
{
	DummyQImageWriter::self = ptr;
}

bool DummyQImageWriter::eventDispatcher(QEvent *event)
{
	bool ret = true;
	switch (event->type()) {
	default:
		ret = false;
		break;
	}
	return ret;
}

bool DummyQImageWriter::addEvent(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQImageWriter::event_map->bigin();
	if ((itr = DummyQImageWriter::event_map->find(str)) == DummyQImageWriter::event_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*event_map)[str], callback_func);
		return true;
	}
}

bool DummyQImageWriter::signalConnect(knh_Func_t *callback_func, string str)
{
	std::map<string, knh_Func_t*>::iterator itr;// = DummyQImageWriter::slot_map->bigin();
	if ((itr = DummyQImageWriter::slot_map->find(str)) == DummyQImageWriter::slot_map->end()) {
		bool ret = false;
		return ret;
	} else {
		KNH_INITv((*slot_map)[str], callback_func);
		return true;
	}
}

knh_Object_t** DummyQImageWriter::reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	(void)ctx; (void)p; (void)tail_;
//	fprintf(stderr, "DummyQImageWriter::reftrace p->rawptr=[%p]\n", p->rawptr);


	return tail_;
}

void DummyQImageWriter::connection(QObject *o)
{
	QImageWriter *p = dynamic_cast<QImageWriter*>(o);
	if (p != NULL) {
	}
}

KQImageWriter::KQImageWriter() : QImageWriter()
{
	magic_num = G_MAGIC_NUM;
	self = NULL;
	dummy = new DummyQImageWriter();
}

KQImageWriter::~KQImageWriter()
{
	delete dummy;
	dummy = NULL;
}
KMETHOD QImageWriter_addEvent(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImageWriter *qp = RawPtr_to(KQImageWriter *, sfp[0]);
	const char *event_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->event_map->find(event_name) == qp->event_map->end()) {
//			fprintf(stderr, "WARNING:[QImageWriter]unknown event name [%s]\n", event_name);
//			return;
//		}
		string str = string(event_name);
//		KNH_INITv((*(qp->event_map))[event_name], callback_func);
		if (!qp->dummy->addEvent(callback_func, str)) {
			fprintf(stderr, "WARNING:[QImageWriter]unknown event name [%s]\n", event_name);
			return;
		}
	}
	RETURNvoid_();
}
KMETHOD QImageWriter_signalConnect(CTX ctx, knh_sfp_t *sfp _RIX)
{
	(void)ctx;
	KQImageWriter *qp = RawPtr_to(KQImageWriter *, sfp[0]);
	const char *signal_name = String_to(const char *, sfp[1]);
	knh_Func_t *callback_func = sfp[2].fo;
	if (qp != NULL) {
//		if (qp->slot_map->find(signal_name) == qp->slot_map->end()) {
//			fprintf(stderr, "WARNING:[QImageWriter]unknown signal name [%s]\n", signal_name);
//			return;
//		}
		string str = string(signal_name);
//		KNH_INITv((*(qp->slot_map))[signal_name], callback_func);
		if (!qp->dummy->signalConnect(callback_func, str)) {
			fprintf(stderr, "WARNING:[QImageWriter]unknown signal name [%s]\n", signal_name);
			return;
		}
	}
	RETURNvoid_();
}

static void QImageWriter_free(CTX ctx, knh_RawPtr_t *p)
{
	(void)ctx;
	if (!exec_flag) return;
	if (p->rawptr != NULL) {
		KQImageWriter *qp = (KQImageWriter *)p->rawptr;
		if (qp->magic_num == G_MAGIC_NUM) {
			delete qp;
			p->rawptr = NULL;
		} else {
			delete (QImageWriter*)qp;
			p->rawptr = NULL;
		}
	}
}
static void QImageWriter_reftrace(CTX ctx, knh_RawPtr_t *p FTRARG)
{
	if (p->rawptr != NULL) {
//		KQImageWriter *qp = (KQImageWriter *)p->rawptr;
		KQImageWriter *qp = static_cast<KQImageWriter*>(p->rawptr);
		qp->dummy->reftrace(ctx, p, tail_);
	}
}

static int QImageWriter_compareTo(knh_RawPtr_t *p1, knh_RawPtr_t *p2)
{
	return (p1->rawptr == p2->rawptr ? 0 : 1);
}

void KQImageWriter::setSelf(knh_RawPtr_t *ptr)
{
	self = ptr;
	dummy->setSelf(ptr);
}

static knh_IntData_t QImageWriterConstInt[] = {
	{"DeviceError", QImageWriter::DeviceError},
	{"UnsupportedFormatError", QImageWriter::UnsupportedFormatError},
	{"UnknownError", QImageWriter::UnknownError},
	{NULL, 0}
};

DEFAPI(void) constQImageWriter(CTX ctx, knh_class_t cid, const knh_LoaderAPI_t *kapi) {
	kapi->loadClassIntConst(ctx, cid, QImageWriterConstInt);
}


DEFAPI(void) defQImageWriter(CTX ctx, knh_class_t cid, knh_ClassDef_t *cdef)
{
	(void)ctx; (void) cid;
	cdef->name = "QImageWriter";
	cdef->free = QImageWriter_free;
	cdef->reftrace = QImageWriter_reftrace;
	cdef->compareTo = QImageWriter_compareTo;
}


