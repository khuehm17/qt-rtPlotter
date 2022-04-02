QT += widgets serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
requires(qtConfig(combobox))

TARGET = terminal
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    plotdialog.cpp \
    settingsdialog.cpp \
    console.cpp \
    qcustomplot.cpp

HEADERS += \
    mainwindow.h \
    plotdialog.h \
    settingsdialog.h \
    console.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui \
    plotdialog.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target
