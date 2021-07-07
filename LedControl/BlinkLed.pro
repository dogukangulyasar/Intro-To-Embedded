QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Sources/Pincontroller.cpp \
        Sources/Pinmodel.cpp \
        Sources/Pinoperation.cpp \
        Sources/Pinview.cpp \
        Sources/main.cpp

RESOURCES += Resources/qml.qrc \
    Resources/Images.qrc

LIBS += -L/usr/local/include -lwiringPi

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /home/pi/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Headers/Pincontroller.h \
    Headers/Pinmodel.h \
    Headers/Pinoperation.h \
    Headers/Pinview.h
