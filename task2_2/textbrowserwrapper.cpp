#include "textbrowserwrapper.h"

QString TextBrowserWrapper::proxyText(const QString& s) {
    QString result = s;
    for (auto word = banList.begin(); word != banList.end(); ++word) {
        result.replace(*word, QString{word->size(), '*'});
    }
    return result;
}

void TextBrowserWrapper::append(const QString& text) {
    if (banList.contains(text)) {
        return QTextBrowser::append(proxyText(text));
    }
    return QTextBrowser::append(text);
}
