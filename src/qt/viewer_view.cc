#include "viewer_view.h"

#include "ui_viewer_view.h"

namespace s21 {
ViewerView::ViewerView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ViewerView) {
  ui->setupUi(this);
  setWindowTitle("3D VIEWER");
  connect(ui->circleVerticles, &QRadioButton::clicked, this,
          &ViewerView::circleVerticles);
  connect(ui->squareVerticles, &QRadioButton::clicked, this,
          &ViewerView::squareVerticles);
  connect(ui->noVerticles, &QRadioButton::clicked, this,
          &ViewerView::noVerticles);
  connect(ui->verticlesSlider, &QSlider::sliderMoved, this,
          &ViewerView::resizeVerticles);
  connect(ui->edgesSize, &QSlider::sliderMoved, this, &ViewerView::resizeEdges);
  connect(ui->edgesSolid, &QRadioButton::clicked, this,
          &ViewerView::edgesSolid);
  connect(ui->edgesDashed, &QRadioButton::clicked, this,
          &ViewerView::edgesDashed);
  connect(ui->verticlesColor, &QPushButton::clicked, this,
          &ViewerView::verticlesColor);
  connect(ui->edgesColor, &QPushButton::clicked, this, &ViewerView::edgesColor);
  connect(ui->backgroundColor, &QPushButton::clicked, this,
          &ViewerView::backgroundColor);
  connect(ui->inputFileButton, &QPushButton::clicked, this,
          &ViewerView::inputFile);
  connect(ui->openFileButton, &QPushButton::clicked, this,
          &ViewerView::openFile);
  connect(ui->recordButton, &QPushButton::clicked, this, &ViewerView::record);
  connect(ui->saveButton, &QPushButton::clicked, this, &ViewerView::saveImage);
  connect(ui->scaleInc, &QPushButton::clicked, this,
          [this] { resizeModel(1.1); });
  connect(ui->scaleDec, &QPushButton::clicked, this,
          [this] { resizeModel(0.9); });
  connect(ui->x_dec, &QPushButton::clicked, this,
          [this] { rotateModel(-5, 0, 0); });
  connect(ui->x_inc, &QPushButton::clicked, this,
          [this] { rotateModel(5, 0, 0); });
  connect(ui->y_dec, &QPushButton::clicked, this,
          [this] { rotateModel(0, -5, 0); });
  connect(ui->y_inc, &QPushButton::clicked, this,
          [this] { rotateModel(0, 5, 0); });
  connect(ui->z_dec, &QPushButton::clicked, this,
          [this] { rotateModel(0, 0, -5); });
  connect(ui->z_inc, &QPushButton::clicked, this,
          [this] { rotateModel(0, 0, 5); });
  connect(ui->x_dec_2, &QPushButton::clicked, this,
          [this] { moveModel(-5, 0, 0); });
  connect(ui->x_inc_2, &QPushButton::clicked, this,
          [this] { moveModel(5, 0, 0); });
  connect(ui->y_dec_2, &QPushButton::clicked, this,
          [this] { moveModel(0, -5, 0); });
  connect(ui->y_inc_2, &QPushButton::clicked, this,
          [this] { moveModel(0, 5, 0); });
  connect(ui->z_dec_2, &QPushButton::clicked, this,
          [this] { moveModel(0, 0, -5); });
  connect(ui->z_inc_2, &QPushButton::clicked, this,
          [this] { moveModel(0, 0, 5); });
  connect(ui->centralRadio, &QRadioButton::toggled, this,
          &ViewerView::toCentralProjection);
  connect(ui->parallelRadio, &QRadioButton::toggled, this,
          &ViewerView::toParallelProjection);

  // Загрузка параметров при открытии окна
  QSettings settings("S21", "3DV");
  int verticlesSize = settings.value("verticlesSize", 1).toInt();
  int edgesSize = settings.value("edgesSize", 1).toInt();
  bool dashedEdges = settings.value("dashedEdges", false).toBool();
  QColor verticlesColor =
      settings.value("verticlesColor", QColor(Qt::red)).value<QColor>();
  QColor edgesColor =
      settings.value("edgesColor", QColor(Qt::blue)).value<QColor>();
  QColor backgroundColor =
      settings.value("backgroundColor", QColor(Qt::white)).value<QColor>();
  QString file = settings.value("file", "").toString();
  bool circleVerticles = settings.value("circleVerticles", true).toBool();
  bool squreVerticles = settings.value("squareVerticles", false).toBool();
  bool noVerticles = settings.value("noVerticles", false).toBool();

  // Применение загруженных параметров
  ui->verticlesSlider->setValue(verticlesSize);
  ui->viewerWidget->pointSize = verticlesSize;
  ui->edgesSize->setValue(edgesSize);
  ui->viewerWidget->edgeSize = edgesSize;
  if (dashedEdges) {
    ui->viewerWidget->dashed = true;
    ui->edgesDashed->setChecked(true);
  } else {
    ui->viewerWidget->dashed = false;
    ui->edgesSolid->setChecked(true);
  }
  ui->viewerWidget->noVerticles = noVerticles;
  ui->viewerWidget->verticlesColor = verticlesColor;
  ui->viewerWidget->edgesColor = edgesColor;
  ui->viewerWidget->backgroundColor = backgroundColor;
  ui->viewerWidget->file = file;
  ui->viewerWidget->noVerticles = noVerticles;
  ui->viewerWidget->circleVerticles = circleVerticles;
  ui->viewerWidget->squareVerticles = squreVerticles;
  ui->viewerWidget->repaint();

  if (file.size() > 0) {
    ui->viewerWidget->controller.Parse(file.toStdString());
  }

  if (ui->viewerWidget->file.length() > 0) {
    QFileInfo fi(ui->viewerWidget->file);
    ui->filenameLabel->setText(fi.fileName());
    ui->edgesLabel->setText(
        QString::number(ui->viewerWidget->controller.GetMatrix3DRows()));
    ui->verticlesLabel->setText(
        QString::number(ui->viewerWidget->controller.GetPolygons().size()));
  }
}

ViewerView::~ViewerView() {
  QSettings settings("S21", "3DV");
  settings.setValue("verticlesSize", ui->verticlesSlider->value() / 10);
  settings.setValue("edgesSize", ui->edgesSize->value() / 10);
  settings.setValue("dashedEdges", ui->edgesDashed->isChecked());
  settings.setValue("verticlesColor", ui->viewerWidget->verticlesColor);
  settings.setValue("edgesColor", ui->viewerWidget->edgesColor);
  settings.setValue("backgroundColor", ui->viewerWidget->backgroundColor);
  settings.setValue("file", ui->viewerWidget->file);
  settings.setValue("noVerticles", ui->viewerWidget->noVerticles);
  settings.setValue("circleVarticles", ui->viewerWidget->circleVerticles);
  settings.setValue("squareVerticles", ui->viewerWidget->squareVerticles);
  delete ui;
}

void ViewerView::circleVerticles() {
  ui->viewerWidget->squareVerticles = false;
  ui->viewerWidget->noVerticles = false;
  ui->viewerWidget->circleVerticles = true;
  // сглаживание вершин
  glEnable(GL_POINT_SMOOTH);
  glPointSize(ui->viewerWidget->pointSize);
  ui->viewerWidget->repaint();
}

void ViewerView::squareVerticles() {
  ui->viewerWidget->noVerticles = false;
  ui->viewerWidget->circleVerticles = false;
  ui->viewerWidget->squareVerticles = true;
  glDisable(GL_POINT_SMOOTH);
  glPointSize(ui->viewerWidget->pointSize);
  ui->viewerWidget->repaint();
}

void ViewerView::noVerticles() {
  ui->viewerWidget->noVerticles = true;
  ui->viewerWidget->circleVerticles = false;
  ui->viewerWidget->squareVerticles = false;
  ui->viewerWidget->repaint();
}

void ViewerView::resizeVerticles() {
  ui->viewerWidget->pointSize = ui->verticlesSlider->value() / 10;
  ui->viewerWidget->repaint();
}

void ViewerView::resizeEdges() {
  ui->viewerWidget->edgeSize = ui->edgesSize->value() / 10;
  ui->viewerWidget->repaint();
}

void ViewerView::edgesSolid() {
  ui->viewerWidget->dashed = false;
  ui->viewerWidget->repaint();
}

void ViewerView::edgesDashed() {
  glPushAttrib(GL_ENABLE_BIT);
  ui->viewerWidget->dashed = true;
  ui->viewerWidget->repaint();
  glPopAttrib();
}

void ViewerView::verticlesColor() {
  ui->viewerWidget->verticlesColor = QColorDialog::getColor();
  ui->viewerWidget->repaint();
}

void ViewerView::edgesColor() {
  ui->viewerWidget->edgesColor = QColorDialog::getColor();
  ui->viewerWidget->repaint();
}

void ViewerView::backgroundColor() {
  ui->viewerWidget->backgroundColor = QColorDialog::getColor();
  ui->viewerWidget->repaint();
}

void ViewerView::inputFile() {
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open Image"), "../objs", tr("Image Files (*.obj)"));
  ui->inputFile->setText(fileName);
}

void ViewerView::openFile() {
  ui->viewerWidget->file = ui->inputFile->text();
  if (ui->viewerWidget->file.length() > 0) {
    QFileInfo fi(ui->viewerWidget->file);
    ui->filenameLabel->setText(fi.fileName());
  }

  ui->viewerWidget->controller.Parse(ui->viewerWidget->file.toStdString());
  ui->viewerWidget->repaint();
  if (ui->viewerWidget->file.length() > 0) {
    QFileInfo fi(ui->viewerWidget->file);
    ui->filenameLabel->setText(fi.fileName());
    ui->edgesLabel->setText(
        QString::number(ui->viewerWidget->controller.GetMatrix3DRows()));
    ui->verticlesLabel->setText(
        QString::number(ui->viewerWidget->controller.GetPolygons().size()));
  }
}

void ViewerView::saveImage() {
  QString save = NULL;
  save = QFileDialog::getSaveFileName(this, NULL, NULL,
                                      "JPEG (*.jpeg) ;; BMP (*.bmp)");
  if (!save.isNull()) ui->viewerWidget->grabFramebuffer().save(save, NULL, 100);
}

void ViewerView::record() {
  gif = new QGifImage;
  frame = new QImage;
  timer = new QTimer(this);
  count = 0;
  connect(timer, SIGNAL(timeout()), this, SLOT(save()));
  timer->start(50);
}

void ViewerView::save() {
  count++;
  *frame = ui->viewerWidget->grabFramebuffer();
  gif->addFrame(*frame);
  if (count == 50) {
    timer->stop();
    QString save = NULL;
    save = QFileDialog::getSaveFileName(this, NULL, NULL, "GIF (*.gif)");
    if (!save.isNull()) gif->save(save);
  }
}

void ViewerView::resizeModel(double scale) {
  ui->viewerWidget->controller.resizeModel(
      &ui->viewerWidget->controller.GetParser(), scale, scale, scale);
  ui->viewerWidget->repaint();
}

void ViewerView::rotateModel(double x, double y, double z) {
  ui->viewerWidget->controller.rotateModel(
      &ui->viewerWidget->controller.GetParser(), x, y, z);
  ui->viewerWidget->repaint();
}

void ViewerView::moveModel(double x, double y, double z) {
  ui->viewerWidget->controller.moveModel(
      &ui->viewerWidget->controller.GetParser(), x, y, z);

  ui->viewerWidget->repaint();
}

void ViewerView::toCentralProjection() { ui->viewerWidget->repaint(); }

void ViewerView::toParallelProjection() {
  ui->viewerWidget->controller.rotateModel(
      &ui->viewerWidget->controller.GetParser(), 0, -90, 0);
  ui->viewerWidget->repaint();
}
}  // namespace s21
