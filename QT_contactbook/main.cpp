#include "widget.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // 設置 UTF-8 編碼以正確顯示中文字符
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    
    Widget w;
    w.show();
    return a.exec();
}
