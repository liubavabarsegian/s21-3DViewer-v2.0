#include <QApplication>

#include "viewer_view.h""

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  ViewerView w;
  w.show();
  return a.exec();
}
