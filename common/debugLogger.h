#ifndef CKDEBUGLOGGER_H
#define CKDEBUGLOGGER_H

#include <QFile>
#include <QtCore>

void debugLogger(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif // CKDEBUGLOGGER_H
