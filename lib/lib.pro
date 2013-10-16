TARGET = QXrdFileTools

TEMPLATE = lib

SOURCES += QXrdFile.cpp

HEADERS += QXrdFile.h \
           QXrdFile_p.h

_XROOTD_DIR = $$XROOTD_DIR

isEmpty(_XROOTD_DIR) {
  error("XROOTD_DIR is not set!") 
}
message("XROOTD_DIR = $$_XROOTD_DIR")

macx {
  LIBS += -L$$_XROOTD_DIR/lib -lXrdClient -lXrdUtils
}

INCLUDEPATH += $$_XROOTD_DIR/include/xrootd

VERSION = 0.1.0
