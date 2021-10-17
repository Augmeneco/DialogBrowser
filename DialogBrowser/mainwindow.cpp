#include <QRegExp>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    webView = new QWebEngineView(this);
    connect(webView, &QWebEngineView::urlChanged,
            this,    &MainWindow::urlChanged);
    connect(webView, &QWebEngineView::titleChanged,
            this,    &MainWindow::titleChanged);
    connect(webView, &QWebEngineView::iconChanged,
            this,    &MainWindow::iconChanged);
    setCentralWidget(webView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::urlChanged(const QUrl &url)
{
    if (closePatternSet && (closePattern.indexIn(url.toString()) == 0))
    {
        QTextStream out(stdout);
        out << "PatternURL\n" << url.toString() << "\n/PatternURL";
        this->close();
    }
}

void MainWindow::titleChanged(const QString &title)
{
    this->setWindowTitle(title);
}

void MainWindow::iconChanged(const QIcon &icon)
{
    this->setWindowIcon(icon);
}

