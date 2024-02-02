#ifndef VIEWER_VIEW_H
#define VIEWER_VIEW_H

#include <QMainWindow>

namespace Ui {
class ViewerView;
}

class ViewerView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewerView(QWidget *parent = nullptr);
    ~ViewerView();

private:
    Ui::ViewerView *ui;
};

#endif // VIEWER_VIEW_H
