TEMPLATE = app
TARGET   = letter

SOURCES *= \
    src/letter.cpp \
    src/welcomepage.cpp \
    src/main.cpp

HEADERS *= \
    src/letter.h \
    src/welcomepage.h

RESOURCES = letter.qrc

MOC_DIR = .build
OBJECTS_DIR = .build
RCC_DIR = .build

win32 {
    RC_FILE = letter.rc
}
