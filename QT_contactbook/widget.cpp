#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

void Write (QString Filename, QString str)
{
    QFile mFile (Filename);
    if(!mFile.open(QFile::WriteOnly | QFile::Text)){
        qDebug() <<"could not open file for write";
        return;
    }
    QTextStream out(&mFile);
    out<<str; //將內容輸出至txt檔
    out.flush(); //刷新mFile
    mFile.close(); //關閉mFile
}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList ColTotle;

    ui->tableWidget->setColumnCount(4); //設定欄位
    ColTotle<<QStringLiteral("學號")<<QStringLiteral("班級")<<QStringLiteral("姓名")<<QStringLiteral("電話");
    ui->tableWidget->setHorizontalHeaderLabels (ColTotle);
    
    // 設置現代化深色主題樣式
    this->setStyleSheet(
        // 主視窗背景 - 深色漸層
        "QWidget#Widget {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "       stop:0 #1a1a2e, stop:0.5 #16213e, stop:1 #0f3460);"
        "   font-family: 'Microsoft YaHei', 'PingFang SC', 'Noto Sans CJK SC', 'SimHei', 'WenQuanYi Zen Hei', sans-serif;"
        "}"
        
        // 標籤樣式 - 淺色文字帶陰影
        "QLabel {"
        "   color: #e8e8e8;"
        "   font-size: 13px;"
        "   font-weight: bold;"
        "   font-family: 'Microsoft YaHei', 'PingFang SC', 'Noto Sans CJK SC', 'SimHei', 'WenQuanYi Zen Hei', sans-serif;"
        "   padding: 2px;"
        "}"
        
        // 輸入框樣式 - 圓角、陰影、漸層背景
        "QLineEdit {"
        "   background-color: rgba(255, 255, 255, 0.1);"
        "   border: 2px solid rgba(100, 181, 246, 0.3);"
        "   border-radius: 10px;"
        "   padding: 8px 12px;"
        "   color: #ffffff;"
        "   font-size: 13px;"
        "   font-family: 'Microsoft YaHei', 'PingFang SC', 'Noto Sans CJK SC', 'SimHei', 'WenQuanYi Zen Hei', sans-serif;"
        "   selection-background-color: #64b5f6;"
        "}"
        "QLineEdit:focus {"
        "   border: 2px solid #64b5f6;"
        "   background-color: rgba(255, 255, 255, 0.15);"
        "}"
        "QLineEdit:hover {"
        "   background-color: rgba(255, 255, 255, 0.12);"
        "   border: 2px solid rgba(100, 181, 246, 0.5);"
        "}"
        
        // 按鈕樣式 - 漸層背景、圓角、懸停效果
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #536dfe, stop:1 #3949ab);"
        "   color: white;"
        "   border: none;"
        "   border-radius: 12px;"
        "   padding: 12px 28px;"
        "   font-size: 14px;"
        "   font-weight: bold;"
        "   font-family: 'Microsoft YaHei', 'PingFang SC', 'Noto Sans CJK SC', 'SimHei', 'WenQuanYi Zen Hei', sans-serif;"
        "   min-width: 100px;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #667eea, stop:1 #4a5dc5);"
        "}"
        "QPushButton:pressed {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #3949ab, stop:1 #283593);"
        "   padding: 13px 28px 11px 28px;"
        "}"
        "QPushButton#pushButton {"  // 新增按鈕 - 綠色
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #66bb6a, stop:1 #43a047);"
        "}"
        "QPushButton#pushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #81c784, stop:1 #4caf50);"
        "}"
        "QPushButton#pushButton_2 {"  // 匯出按鈕 - 橙色
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #ffa726, stop:1 #fb8c00);"
        "}"
        "QPushButton#pushButton_2:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #ffb74d, stop:1 #ff9800);"
        "}"
        "QPushButton#pushButton_3 {"  // 匯入按鈕 - 青色
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #26c6da, stop:1 #00acc1);"
        "}"
        "QPushButton#pushButton_3:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #4dd0e1, stop:1 #00bcd4);"
        "}"
        "QPushButton#pushButton_4 {"  // 結束按鈕 - 紅色
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #ef5350, stop:1 #e53935);"
        "}"
        "QPushButton#pushButton_4:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #ef5350, stop:1 #f44336);"
        "}"
        "QPushButton#pushButton_5 {"  // 刪除按鈕 - 深紅色
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #d32f2f, stop:1 #c62828);"
        "}"
        "QPushButton#pushButton_5:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #e57373, stop:1 #d32f2f);"
        "}"
        "QPushButton#pushButton_6 {"  // 編輯按鈕 - 紫色
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #ab47bc, stop:1 #8e24aa);"
        "}"
        "QPushButton#pushButton_6:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #ba68c8, stop:1 #9c27b0);"
        "}"
        
        // 表格樣式 - 透明背景、交替行顏色、懸停效果
        "QTableWidget {"
        "   background-color: rgba(255, 255, 255, 0.05);"
        "   border: 2px solid rgba(100, 181, 246, 0.3);"
        "   border-radius: 15px;"
        "   gridline-color: rgba(100, 181, 246, 0.2);"
        "   color: #ffffff;"
        "   font-size: 13px;"
        "   font-family: 'Microsoft YaHei', 'PingFang SC', 'Noto Sans CJK SC', 'SimHei', 'WenQuanYi Zen Hei', sans-serif;"
        "   selection-background-color: rgba(100, 181, 246, 0.4);"
        "   selection-color: #ffffff;"
        "}"
        "QTableWidget::item {"
        "   padding: 8px;"
        "   border: none;"
        "}"
        "QTableWidget::item:hover {"
        "   background-color: rgba(100, 181, 246, 0.2);"
        "}"
        "QTableWidget::item:selected {"
        "   background-color: rgba(100, 181, 246, 0.4);"
        "}"
        
        // 表頭樣式 - 漸層背景
        "QHeaderView::section {"
        "   background: qlineargradient(x1:0, y1:0, x2:0, y2:1,"
        "       stop:0 #536dfe, stop:1 #3949ab);"
        "   color: white;"
        "   padding: 10px;"
        "   border: none;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "   font-family: 'Microsoft YaHei', 'PingFang SC', 'Noto Sans CJK SC', 'SimHei', 'WenQuanYi Zen Hei', sans-serif;"
        "}"
        "QHeaderView::section:first {"
        "   border-top-left-radius: 12px;"
        "}"
        "QHeaderView::section:last {"
        "   border-top-right-radius: 12px;"
        "}"
        
        // 滾動條樣式
        "QScrollBar:vertical {"
        "   border: none;"
        "   background: rgba(255, 255, 255, 0.05);"
        "   width: 12px;"
        "   border-radius: 6px;"
        "   margin: 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "   background: rgba(100, 181, 246, 0.5);"
        "   border-radius: 6px;"
        "   min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "   background: rgba(100, 181, 246, 0.7);"
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "   border: none;"
        "   background: none;"
        "   height: 0px;"
        "}"
        "QScrollBar:horizontal {"
        "   border: none;"
        "   background: rgba(255, 255, 255, 0.05);"
        "   height: 12px;"
        "   border-radius: 6px;"
        "   margin: 0px;"
        "}"
        "QScrollBar::handle:horizontal {"
        "   background: rgba(100, 181, 246, 0.5);"
        "   border-radius: 6px;"
        "   min-width: 20px;"
        "}"
        "QScrollBar::handle:horizontal:hover {"
        "   background: rgba(100, 181, 246, 0.7);"
        "}"
        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
        "   border: none;"
        "   background: none;"
        "   width: 0px;"
        "}"
    );
    
    // 設置視窗標題
    this->setWindowTitle(QStringLiteral("📇 聯絡人管理系統"));
    
    // 設置表格屬性以啟用交替行顏色
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet(
        ui->tableWidget->styleSheet() + 
        "QTableWidget {"
        "   alternate-background-color: rgba(100, 181, 246, 0.08);"
        "}"
    );
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QTableWidgetItem *col1,*col2,*col3,*col4;

    col1 =new QTableWidgetItem(QString(ui->lineEdit->text()));
    col2 =new QTableWidgetItem(QString(ui->lineEdit_2->text()));
    col3= new QTableWidgetItem(QString(ui->lineEdit_3->text()));
    col4= new QTableWidgetItem(QString(ui->lineEdit_4->text()));
    int rc = ui->tableWidget->rowCount();
    qDebug() << rc << "\n";
    ui->tableWidget->insertRow(rc);
    ui->tableWidget->setItem(rc,0,col1);
    ui->tableWidget->setItem(rc,1,col2);
    ui->tableWidget->setItem(rc,2,col3);
    ui->tableWidget->setItem(rc,3,col4);

}


void Widget::on_pushButton_2_clicked()
{
    // 使用檔案對話框選擇要儲存的位置
    QString fileName = QFileDialog::getSaveFileName(this,
        QStringLiteral("儲存聯絡人"), 
        "",
        QStringLiteral("文字檔案 (*.txt);;所有檔案 (*.*)"));
    
    if (fileName.isEmpty()) {
        return; // 使用者取消選擇
    }
    
    QString saveFile="";
    int rc, cc;
    rc=ui->tableWidget->rowCount();
    cc=ui->tableWidget->columnCount();
    for(int i=0; i< rc; i++)
    {
        for(int j=0; j<cc;j++)
            saveFile += ui->tableWidget->item(i,j)->text()+",";
        saveFile+="\n";
    }
    Write(fileName, saveFile);
    QMessageBox::information(this, QStringLiteral("成功"), 
        QStringLiteral("檔案匯出成功！"));
}


void Widget::on_pushButton_3_clicked()
{
    // 使用檔案對話框選擇要匯入的txt檔案
    QString fileName = QFileDialog::getOpenFileName(this,
        QStringLiteral("選擇要匯入的檔案"), 
        "",
        QStringLiteral("文字檔案 (*.txt);;所有檔案 (*.*)"));
    
    if (fileName.isEmpty()) {
        return; // 使用者取消選擇
    }
    
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, QStringLiteral("錯誤"), 
            QStringLiteral("無法開啟檔案進行讀取"));
        return;
    }
    
    QTextStream in(&file);
    
    // 清空現有的表格資料
    ui->tableWidget->setRowCount(0);
    
    // 讀取檔案並解析每一行
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');
        
        // 確保有4個欄位 (學號,班級,姓名,電話)
        if (fields.size() >= 4) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);
            
            for (int i = 0; i < 4 && i < fields.size(); i++) {
                QTableWidgetItem *item = new QTableWidgetItem(fields[i].trimmed());
                ui->tableWidget->setItem(row, i, item);
            }
        }
    }
    
    file.close();
    QMessageBox::information(this, QStringLiteral("成功"), 
        QStringLiteral("檔案匯入成功！"));
}


void Widget::on_pushButton_4_clicked()
{
    on_pushButton_2_clicked();
    close();
}


void Widget::on_pushButton_5_clicked()
{
    // 刪除選中的聯絡人
    int currentRow = ui->tableWidget->currentRow();
    
    if (currentRow < 0) {
        QMessageBox::warning(this, QStringLiteral("提示"), 
            QStringLiteral("請先選擇要刪除的聯絡人！"));
        return;
    }
    
    // 確認刪除
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, QStringLiteral("確認刪除"), 
        QStringLiteral("確定要刪除選中的聯絡人嗎？"),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        ui->tableWidget->removeRow(currentRow);
        QMessageBox::information(this, QStringLiteral("成功"), 
            QStringLiteral("聯絡人已刪除！"));
    }
}


void Widget::on_pushButton_6_clicked()
{
    // 編輯選中的聯絡人
    int currentRow = ui->tableWidget->currentRow();
    
    if (currentRow < 0) {
        QMessageBox::warning(this, QStringLiteral("提示"), 
            QStringLiteral("請先選擇要編輯的聯絡人！"));
        return;
    }
    
    // 將選中的聯絡人資料填入輸入框
    QTableWidgetItem *item0 = ui->tableWidget->item(currentRow, 0);
    QTableWidgetItem *item1 = ui->tableWidget->item(currentRow, 1);
    QTableWidgetItem *item2 = ui->tableWidget->item(currentRow, 2);
    QTableWidgetItem *item3 = ui->tableWidget->item(currentRow, 3);
    
    if (item0) ui->lineEdit->setText(item0->text());
    if (item1) ui->lineEdit_2->setText(item1->text());
    if (item2) ui->lineEdit_3->setText(item2->text());
    if (item3) ui->lineEdit_4->setText(item3->text());
    
    // 刪除原來的行
    ui->tableWidget->removeRow(currentRow);
    
    QMessageBox::information(this, QStringLiteral("提示"), 
        QStringLiteral("聯絡人資料已載入到輸入框，修改後請點擊「新增」按鈕儲存！"));
}

