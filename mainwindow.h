#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebKitWidgets/QWebView>
#include <QUrl>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void slotEnter();       // Слот для обработки нажатия клавиши Enter
    void slotLinkClicked(QUrl url); // Слот для клика по ссылке на странице
};

#endif // MAINWINDOW_H
