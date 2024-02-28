QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

include(qtgifimage/src/gifimage/qtgifimage.pri)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qt/main.cc \
    qt/opengl.cc \
    qt/viewer_view.cc \
    models/s21_affine_transform.cc \
    models/s21_matrix_oop.cc \
    models/s21_viewer_parser.cc \
    controllers/s21_viewer_controller.cc \

HEADERS += \
    qt/opengl.h \
    qt/viewer_view.h \
    models/s21_affine_transform.h \
    models/s21_matrix_oop.h \
    models/s21_viewer_parser.h \
    controllers/s21_viewer_controller.h \

FORMS += \
    qt/viewer_view.ui

RESOURCES += \
    imgs/folder.png \
    imgs/folder.svg \
    imgs/camera.png \
    imgs/save.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../objs/test_cat.obj
