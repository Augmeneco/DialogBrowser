#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QCommandLineParser parser;
    parser.setApplicationDescription("Kiosk browser with command line control");
    parser.addHelpOption();
    parser.addVersionOption();

    parser.addPositionalArgument("url", QCoreApplication::translate("main", "URL to open."));

    QCommandLineOption closePatternOption(QStringList() << "p" << "pattern",
        QCoreApplication::translate("main", "RegEx pattern of URL."),
        QCoreApplication::translate("main", "pattern"));
    QCommandLineOption widthOption(QStringList() << "w" << "width",
        QCoreApplication::translate("main", "Set width of window."),
        QCoreApplication::translate("main", "width"));
    QCommandLineOption heightOption(QStringList() << "h" << "height",
        QCoreApplication::translate("main", "Set height of window."),
        QCoreApplication::translate("main", "height"));
    parser.addOption(closePatternOption);

    parser.process(a);

    const QStringList args = parser.positionalArguments();

    w.webView->setUrl(parser.positionalArguments()[0]);
    w.closePatternSet = parser.isSet(closePatternOption);
    w.closePattern = QRegExp(parser.value(closePatternOption));
    if (parser.isSet(widthOption))
        w.setFixedWidth(parser.value(widthOption).toInt());
    if (parser.isSet(heightOption))
        w.setFixedHeight(parser.value(heightOption).toInt());

    w.show();
    return a.exec();
}
