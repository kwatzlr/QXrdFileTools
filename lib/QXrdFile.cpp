#include "QXrdFile_p.h"

//////////////// QXrdFile ////////////////
#ifdef Q_WS_MAC
#pragma mark QXrdFile
#pragma mark -
#pragma mark Constructors
#endif

/**
 * Constructs a new file object.
 */
QXrdFile::QXrdFile() :
  QIODevice(), d_ptr(new QXrdFilePrivate(this)) {
}

/**
 * Constructs a new file object to represent the file with the given path.
 */
QXrdFile::QXrdFile(const QString &path) :
  d_ptr(new QXrdFilePrivate(this)) {
  this->setFileName(path);
}

/**
 * Constructs a new file object with the given parent.
 */
QXrdFile::QXrdFile(QObject *parent) :
  QIODevice(parent), d_ptr(new QXrdFilePrivate(this)) {
}

/**
 * Constructs a new file object with the given parent to represent 
 * the file with the specified path.
 */
QXrdFile::QXrdFile(QObject *parent, const QString &path) :
  QIODevice(parent), d_ptr(new QXrdFilePrivate(this)) {
  this->setFileName(path);
}

#ifdef Q_WS_MAC
#pragma mark Protected constructors
#endif
QXrdFile::QXrdFile(QXrdFilePrivate &d) :
  d_ptr(&d) {
}

QXrdFile::QXrdFile(const QString &path, QXrdFilePrivate &d) :
  d_ptr(&d) {
  this->setFileName(path);
}

QXrdFile::QXrdFile(QObject *parent, QXrdFilePrivate &d) :
  QIODevice(parent), d_ptr(&d) {
}

QXrdFile::QXrdFile(QObject *parent, const QString &path, QXrdFilePrivate &d) :
  QIODevice(parent), d_ptr(&d) {
  this->setFileName(path);
}

/**
 * Reimplemented from QIODevice::readData().
 */
qint64 QXrdFile::readData(char *data, qint64 maxSize) {
  Q_D(QXrdFile);
  return d->readData(data, maxSize);
}

/**
 * Reimplemented from QIODevice::writeData().
 *
 * Dummy implementation, always returns false.
 */
qint64 QXrdFile::writeData(const char *data, qint64 maxSize) {
  Q_UNUSED(maxSize);
  Q_UNUSED(data);
  return -1;
}

/**
 * Reimplemented from QIODevice::open().
 * 
 * Opens the file previously setusing OpenMode mode, returning true if successful; 
 * otherwise false.
 * 
 * Currently only QIODevice::ReadOnly is supported.
 */
bool QXrdFile::open(QIODevice::OpenMode mode) {
  if (mode == QIODevice::ReadOnly)
    return this->open();
  return false;
}

/**
 * Opens the file previously set using OpenMode QIODevice::ReadOnly, returning true 
 * if successful; otherwise false;
 */
bool QXrdFile::open() {
  Q_D(QXrdFile);
  return d->open();
}

/**
 * Returns the name set by setFileName() or to the QXrdFile constructors.
 * 
 * \sa setFileName()
 */
QString QXrdFile::fileName() const {
  Q_D(const QXrdFile);
  return d->fileName();
}

/**
 * Sets the name of the file. The name must be a full xrootd URL (including protocol, 
 * host and path.
 * 
 * If this function is called when a file is already opened, this file is closed and
 * the new file is open.
 *
 * \sa fileName()
 */
void QXrdFile::setFileName(const QString& path) {
  Q_D(QXrdFile);
  d->setFileName(path);
}
/**
 * Reimplemented from QIODevice::size().
 * 
 * Returns the size of the file.
 */
qint64 QXrdFile::size() const {
  Q_D(const QXrdFile);
  return d->size();
}

/**
 * Reimplemented from QIODevice::atEnd().
 * 
 * Returns true if the end of the file has been reached; otherwise returns false.
 */
bool QXrdFile::atEnd() const {
  if (!this->isOpen())
    return true;
  if (this->pos()<this->size()-1)
    return false;
  return true;
}

/** 
 * Reimplemented from QIODevice::close().
 *
 * Closes the file.
 *
 * \sa QIODevice::close()
 */
void QXrdFile::close() {
  Q_D(QXrdFile);
  d->close();
  QIODevice::close();
}


//////////////// QXrdFilePrivate ////////////////
#ifdef Q_WS_MAC
#pragma mark - QXrdFilePrivate
#pragma mark -
#pragma mark Constructors
#endif

QXrdFilePrivate::QXrdFilePrivate(QXrdFile* q) : q_ptr(q), _client(0) { }

bool QXrdFilePrivate::open() {
  Q_Q(QXrdFile);
  bool openWorked = false;
  _client = new XrdClient(qPrintable(_fileName));
  openWorked = _client->Open(0,0);
  if (openWorked) {
    q->setOpenMode(QIODevice::ReadOnly);
  } else {
    q->setOpenMode(QIODevice::NotOpen);
  }
  q->seek(0);
  return openWorked;
}

qint64 QXrdFilePrivate::readData(char *data, qint64 maxSize) {
  Q_Q(const QXrdFile);
  if (!q->isOpen())
    return -1;
  return _client->Read(data, q->pos(), maxSize);
}

void QXrdFilePrivate::setFileName(const QString& path) {
  this->close();
  this->_fileName = path;
  this->open();
}

qint64 QXrdFilePrivate::size() const {
  Q_Q(const QXrdFile);
  if (!q->isOpen())
    return -1;
  XrdClientStatInfo info;
  _client->Stat(&info, true);
  return info.size;
}

void QXrdFilePrivate::close() {
  if (_client) {
    _client->Close();
    delete _client;
    _client = 0;
  }
}