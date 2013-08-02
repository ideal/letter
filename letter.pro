TEMPLATE = app
TARGET   = letter

SOURCES *= \
    src/letter.cpp \
    src/welcomepage.cpp \
    src/firework.cpp \
    src/main.cpp

HEADERS *= \
    src/letter.h \
    src/welcomepage.h \
    src/firework.h

RESOURCES = letter.qrc

MOC_DIR = .build
OBJECTS_DIR = .build
RCC_DIR = .build

win32 {
    RC_FILE = letter.rc
}
