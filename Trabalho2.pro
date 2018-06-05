TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
    file.c \
    tree.c \
    closedHash.c \
    list.c

HEADERS += \
    list.h \
    closedHash.h \
    tree.h \
    file.h
