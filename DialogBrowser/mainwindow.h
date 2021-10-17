#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool closePatternSet = false;
    QRegExp closePattern;
    QWebEngineView* webView;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void urlChanged(const QUrl &url);
    void titleChanged(const QString &title);
    void iconChanged(const QIcon &icon);
};
#endif // MAINWINDOW_H
