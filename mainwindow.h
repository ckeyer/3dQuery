#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:    
    static void debugLogger(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private slots:
    void on_openFileButton_clicked();

private:
    Ui::MainWindow *ui;
};

extern MainWindow *g_mainWindow;

#endif // MAINWINDOW_H
