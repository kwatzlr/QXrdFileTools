#ifndef QXRDFILE_H
#define QXRDFILE_H

#include <QIODevice>
#include <qglobal.h>

class QXrdFilePrivate;

class QXrdFile : public QIODevice
{
  Q_OBJECT
public:
  explicit QXrdFile();
  explicit QXrdFile(QObject *parent);
  explicit QXrdFile(const QString &path);
  explicit QXrdFile(QObject *parent, const QString &path);
  
  virtual bool atEnd() const;
  
  static bool exists(const QString &fileName);
  bool exists() const;
  
  virtual bool open();
  virtual bool open(QIODevice::OpenMode mode);
  virtual void close();
  
  void setFileName(const QString &path);
  QString fileName() const;
  
  qint64 size() const;
protected:
  //! @cond
  QXrdFile(QXrdFilePrivate &d);
  QXrdFile(QObject *parent, QXrdFilePrivate &d);
  QXrdFile(const QString &path, QXrdFilePrivate &d);
  QXrdFile(QObject *parent, const QString &path, QXrdFilePrivate &d);
  //! @endcond
  
  virtual qint64 readData(char *data, qint64 maxSize);
  virtual qint64 writeData(const char *data, qint64 maxSize);

signals:
  
public slots:
  
private:
  Q_PROPERTY(QString filename READ fileName WRITE setFileName);

  //! @cond
  QXrdFilePrivate *d_ptr;
  Q_DECLARE_PRIVATE(QXrdFile)
  //! @endcond
};

#endif // QXRDFILE_H
