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
#include "QXrdFile.h"
class QXrdFilePrivate {
public:
  QXrdFilePrivate(QXrdFile *q) : q_ptr(q) { }
private:
  QXrdFile *q_ptr;
  Q_DECLARE_PUBLIC(QXrdFile)

};

#endif // QXRDFILE_P_H
