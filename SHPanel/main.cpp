#include "window.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	Window *win = new Window();
	win->show();

	return app.exec();
}

