#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebView>
#include <QNetworkProxy>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Устанавливаем ручную обработку клика по ссылке
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);


    QWebView *wv = new QWebView();
    QWebPage *page = wv->page();
    QWebSettings *settings = page->settings();

    settings->setAttribute(QWebSettings::JavascriptEnabled, true);
    settings->setAttribute(QWebSettings::PluginsEnabled, true);
    settings->setAttribute(QWebSettings::PrivateBrowsingEnabled , true);

    QNetworkProxy proxy;
    proxy.setType(QNetworkProxy::Socks5Proxy);
    proxy.setHostName("proxy.google.com");
    proxy.setPort(1080);
    proxy.setUser("luis");
    proxy.setPassword("luis23");
    QNetworkProxy::setApplicationProxy(proxy);

    QUrl url = QUrl("http://qt.nokia.com/"); // http://www.google.co.in/
//    wv->load(url);
//    wv->setFocus();
//    wv->show();

    // Подключаем сигнал нажатия "Enter" в поле lineEdit
   // connect(ui->lineEdit, &QLineEdit::returnPressed, this, &MainWindow::slotEnter);
    // Подключиаем сигнала клика по ссылке к обработчику
 //   connect(ui->webVieuhw, &QWebView::linkClicked, this, &MainWindow::slotLinkClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotEnter()
{
    // Загружаем страницу по заданном URL в поле lineEdit
    ui->webView->load(QUrl(ui->lineEdit->text()));
}

void MainWindow::slotLinkClicked(QUrl url)
{
    // При клике по ссылке помещаем адрес в поле lineEdit
    ui->lineEdit->setText(url.toString());
    ui->webView->load(url);     // Загружаем страницу по этой ссылке
}


