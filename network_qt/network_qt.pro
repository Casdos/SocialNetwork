QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    DisjointSetUnion.cpp \
    Graph.cpp \
    checkwidget.cpp \
    cluster_show.cpp \
    function.cpp \
    lead.cpp \
    main.cpp \
    matrix_output.cpp \
    widget.cpp

HEADERS += \
    DisjointSetUnion.h \
    Graph.h \
    checkwidget.h \
    cluster_show.h \
    constant.h \
    lead.h \
    matrix_output.h \
    widget.h

FORMS += \
    checkwidget.ui \
    cluster_show.ui \
    lead.ui \
    matrix_output.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
