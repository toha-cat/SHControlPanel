#include "window.h"

Window::Window(QObject *parent) : QObject(parent)
{

}

void Window::show()
{
	QQmlContext *ctxt = engine.rootContext();

	ctxt->setContextProperty("window", this);

	QList<QObject*> dataList;

	dataList.append(new DeviceItem(1, "Item 1", "ControlLed", "On"));
	dataList.append(new DeviceItem(2, "Item 2", "ControlLed", "On"));
	dataList.append(new DeviceItem(3, "Item 3", "ControlLed", "On"));
	dataList.append(new DeviceItem(4, "Item 4", "ControlLed", "On"));

	ctxt->setContextProperty("dataModel", QVariant::fromValue(dataList));

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	viewer = engine.rootObjects()[0];
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
