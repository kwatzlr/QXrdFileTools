TARGET = QXrdFileTools

TEMPLATE = lib

_XROOTD_DIR = $$XROOTD_DIR

isEmpty(_XROOTD_DIR) {
  error("XROOTD_DIR is not set!") 
}
message("XROOTD_DIR = $$_XROOTD_DIR")

macx {
  LIBS += -L$$_XROOTD_DIR/lib -lXrdClient
}

INCLUDEPATH += $$_XROOTD_DIR/include/xrootd
