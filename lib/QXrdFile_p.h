//  W A R N I N G
//  -------------
//
// This file is not part of the QXrdFileTools API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#ifndef QXRDFILE_P_H
#define QXRDFILE_P_H

#include <qglobal.h>
// The following undefs are needed to suppress warnings.
#undef TRUE
#undef FALSE
#include "QXrdFile.h"
#include <XrdClient/XrdClient.hh>

class QXrdFilePrivate {
public:
  QXrdFilePrivate(QXrdFile *q);
  qint64 readData(char *data, qint64 maxSize);
  
  bool open();
  void close();
  
  QString fileName() const { return _fileName; }
  void setFileName(const QString& path);
  
  qint64 size() const;
private:
  QString _fileName;
  
  QXrdFile *q_ptr;
  Q_DECLARE_PUBLIC(QXrdFile)
  XrdClient* _client;

};

#endif // QXRDFILE_P_H
