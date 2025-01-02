TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Consumer.cpp \
        cashier.cpp \
        cook1.cpp \
        main.cpp \
        setting.cpp \
        waiter.cpp \
        xtsz.cpp

HEADERS += \
    Consumer.h \
    boss.h \
    cashier.h \
    cook1.h \
    function_mima.h \
    setting.h \
    waiter.h \
    xiaopiao.h \
    xtsz.h \
    zhuanzifu.h

DISTFILES += \
    cook__waiter.txt \
    meau.txt \
    table.txt \
    user(admin).txt \
    user.txt \
    waiter__shangp.txt \
    xiaopiao.txt \
    xiaopiaoout.txt
