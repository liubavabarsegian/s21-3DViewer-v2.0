#include "viewer_view.h"
#include "ui_viewer_view.h"

ViewerView::ViewerView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ViewerView)
{
    ui->setupUi(this);
}

ViewerView::~ViewerView()
{
    delete ui;
}
