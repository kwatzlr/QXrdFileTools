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
protected:
  QXrdFile(QXrdFilePrivate &d);
  QXrdFile(QObject *parent, QXrdFilePrivate &d);
  QXrdFile(const QString &path, QXrdFilePrivate &d);
  QXrdFile(QObject *parent, const QString &path, QXrdFilePrivate &d);
  QXrdFilePrivate *d_ptr;
  
signals:
  
public slots:
  
private:
  Q_DECLARE_PRIVATE(QXrdFile)
};

#endif // QXRDFILE_H
