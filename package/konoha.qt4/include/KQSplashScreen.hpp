#ifndef QSPLASHSCREEN
#define QSPLASHSCREEN
class DummyQSplashScreen : public DummyQWidget {
public:
	knh_RawPtr_t *self;
	std::map<std::string, knh_Func_t *> *event_map;
	std::map<std::string, knh_Func_t *> *slot_map;
	DummyQSplashScreen();
	void setSelf(knh_RawPtr_t *ptr);
	bool eventDispatcher(QEvent *event);
	bool addEvent(knh_Func_t *callback_func, std::string str);
	bool signalConnect(knh_Func_t *callback_func, std::string str);
};

class KQSplashScreen : public QSplashScreen, public DummyQSplashScreen {
//	Q_OBJECT;
public:
	knh_RawPtr_t *self;
	KQSplashScreen(const QPixmap pixmap, Qt::WindowFlags f);
	bool event(QEvent *event);
};

#endif //QSPLASHSCREEN


