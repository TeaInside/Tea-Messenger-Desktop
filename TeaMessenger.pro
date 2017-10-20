SOURCES = src/TeaMessenger.cpp\
          src/screens/IntroWelcome.cpp

HEADERS = src/TeaMessenger.h\
          src/screens/IntroWelcome.h

CONFIG += qt warn_on release

QT +=  widgets\
       gui

RESOURCES = src/Resource.qrc

RC_ICONS = resources/icons/app.ico
