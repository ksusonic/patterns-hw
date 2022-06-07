#ifndef TEXTBROWSERWRAPPER_H
#define TEXTBROWSERWRAPPER_H
#include <QTextBrowser>
#include <QSet>

class TextBrowserWrapper : public QTextBrowser
{
    Q_OBJECT

public:
    TextBrowserWrapper() = default;

    void append(const QString& text);

private:
    QString proxyText(const QString& s);
    const QSet<QString> banList = {"miem", "hse", "ivt", "session"};
};

#endif // TEXTBROWSERWRAPPER_H
