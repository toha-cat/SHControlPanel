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

void UiBackend::show()
{
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
	viewer = engine.rootObjects()[0];
}

void UiBackend::selectCat(int cid)
{
	qDebug() << cid;
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
/*
void MyClass::buttonClicked(const QString& in)
{
	qDebug() << in;//Просто выведем информацию строки in в консоль Debug. Просто так.

	//Найдем строки ввода
	QObject* textinput1 = viewer->findChild<QObject*>("textinput1");
	QObject* textinput2 = viewer->findChild<QObject*>("textinput2");
	//Найдем поле вывода
	QObject* memo = viewer->findChild<QObject*>("memo");

	//Считаем информацию со строк ввода через свойство text
	QString str1=(textinput1->property("text")).toString();
	QString str2=(textinput2->property("text")).toString();

	int a = str1.toInt();//Переведем строку в число
	int b = str2.toInt();//Переведем строку в число

	int c = a + b; //Вычисления наши

	QString strResult=QString::number(c);//Переведем результат в строку

	//Ну и наконец выведем в поле вывода нашу информацию
	memo->setProperty("text", str1+" + "+str2+" = "+strResult);
}
*/
