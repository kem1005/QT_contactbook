#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString> // 新增：為了使用 QString

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    QString mFilename; // 成員變數：儲存檔案路徑
};

#endif // WIDGET_H
