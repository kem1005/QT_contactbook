#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QDebug>
QString mFilename ="C:/Users/user/Desktop/ex/txt/myfile.txt";

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
    Write(mFilename, saveFile);
}

