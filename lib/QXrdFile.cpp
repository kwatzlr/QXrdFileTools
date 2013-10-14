#include "QXrdFile_p.h"

//////////////// QXrdFile ////////////////
#ifdef Q_WS_MAC
#pragma mark QXrdFile
#pragma mark -
#pragma mark Constructors
#endif

QXrdFile::QXrdFile() :
  QIODevice(), d_ptr(new QXrdFilePrivate(this)) {
}

QXrdFile::QXrdFile(const QString &path) :
  d_ptr(new QXrdFilePrivate(this)) {
}

QXrdFile::QXrdFile(QObject *parent) :
  QIODevice(parent), d_ptr(new QXrdFilePrivate(this)) {
}

QXrdFile::QXrdFile(QObject *parent, const QString &path) :
  QIODevice(parent), d_ptr(new QXrdFilePrivate(this)) {
}

#ifdef Q_WS_MAC
#pragma mark Protected constructors
#endif
QXrdFile::QXrdFile(QXrdFilePrivate &d) :
  d_ptr(&d) {
}

QXrdFile::QXrdFile(const QString &path, QXrdFilePrivate &d) :
  d_ptr(&d) {
}

QXrdFile::QXrdFile(QObject *parent, QXrdFilePrivate &d) :
  QIODevice(parent), d_ptr(&d) {
}

QXrdFile::QXrdFile(QObject *parent, const QString &path, QXrdFilePrivate &d) :
  QIODevice(parent), d_ptr(&d) {
}

//////////////// QXrdFilePrivate ////////////////
#ifdef Q_WS_MAC
#pragma mark - QXrdFilePrivate
#pragma mark -
#pragma mark Constructors
#endif

QXrdFilePrivate::QXrdFilePrivate(QXrdFile* q) : q_ptr(q) { }
