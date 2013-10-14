#include "QXrdFile_p.h"

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

QXrdFilePrivate::QXrdFilePrivate(QXrdFile* q) : q_ptr(q) { }
