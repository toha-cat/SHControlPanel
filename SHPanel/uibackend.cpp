#include "uibackend.h"

UiBackend::UiBackend(QObject *parent) : QObject(parent)
{

}

void UiBackend::createUi()
{
	rootContext = engine.rootContext();
	rootContext->setContextProperty("backend", this);
    regMetrics();
}

void UiBackend::setDeviceModel(QList<QObject*> list)
{
    rootContext->setContextProperty("deviceModel", QVariant::fromValue(list));
}

void UiBackend::setDeviceCatModel(QList<QObject *> list)
{
    rootContext->setContextProperty("catDeviceModel", QVariant::fromValue(list));
}

void UiBackend::setRulesModel(QList<QObject *> list)
{
    rootContext->setContextProperty("rulesModel", QVariant::fromValue(list));
}

void UiBackend::showLoginForm()
{
    //QVariant returnedValue;
    //QVariant msg = "Hello from C++";
    QMetaObject::invokeMethod(viewer, "showLoginForm");
    /*
    QMetaObject::invokeMethod(object, "myQmlFunction",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, msg));
    */
}

void UiBackend::show()
{
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
	viewer = engine.rootObjects()[0];
}

void UiBackend::regMetrics()
{
#ifdef Q_OS_ANDROID
    //  BUG with dpi on some androids: https://bugreports.qt-project.org/browse/QTBUG-35701
    //  Workaround:
    QAndroidJniObject qtActivity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");
    QAndroidJniObject resources = qtActivity.callObjectMethod("getResources", "()Landroid/content/res/Resources;");
    QAndroidJniObject displayMetrics = resources.callObjectMethod("getDisplayMetrics", "()Landroid/util/DisplayMetrics;");
    int density = displayMetrics.getField<int>("densityDpi");
#else
    QScreen *screen = qApp->primaryScreen();
    float density = screen->physicalDotsPerInch();
#endif

	rootContext->setContextProperty("mm",density / 25.4);
	rootContext->setContextProperty("pt", 1);

	double scale = density < 180 ? 1 :
				   density < 270 ? 1.5 :
				   density < 360 ? 2 : 3;
	engine.rootContext()->setContextProperty("dp", scale);
}
