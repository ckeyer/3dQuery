#include <QtCore>
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g_mainWindow = this;
    qInstallMessageHandler(debugLogger);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFileButton_clicked()
{
    qDebug() << "opened";
    
}

void MainWindow::debugLogger(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type)
    {
    case QtDebugMsg:
        localMsg.prepend("DEBUG: ");
        break;
    case QtInfoMsg:
        localMsg.prepend("INFO: ");
        break;
    case QtWarningMsg:
        localMsg.prepend("WARNING: ");
        break;
    case QtCriticalMsg:
        localMsg.prepend("CRITICAL: ");
        break;
    case QtFatalMsg:
        localMsg.prepend("FATAL: ");
        abort();
    default:
        localMsg.prepend("UNKNOWN: ");
        break;
    }
    char *str = nullptr;
    asprintf(&str, "     (%s:%u, %s)", context.file, context.line, context.function);
    localMsg.append(str);
    g_mainWindow->ui->logBrowser->append(localMsg);
}

MainWindow *g_mainWindow = nullptr;
