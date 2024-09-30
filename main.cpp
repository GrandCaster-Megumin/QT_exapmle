//#include "design_example_of_widget.h"

#include <QApplication>
#include<QWidget>
#include<QSpinBox>
#include<QSlider>
#include<QHBoxLayout>
#include<QSpacerItem>
#include<QVBoxLayout>
#include<QPushButton>
#include<QcolorDialog>
#include<QTabWidget>
#include<Qlabel>
#include<QPalette>
#include<QFontDialog>
#include<QFileDialog>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("example");
    window->resize(300,300);

    QTabWidget *tabWidget = new QTabWidget;
    QWidget *tab1 = new QWidget;
    QWidget *tab2 = new QWidget;
    QWidget *tab3 = new QWidget;
    QWidget *tab4 = new QWidget;
    tabWidget->addTab(tab1, "隊長");
    tabWidget->addTab(tab2, "組員1");
    tabWidget->addTab(tab3, "組員2");
    tabWidget->addTab(tab4, "組員3");
    //tab1 put label
    QVBoxLayout *tab1Layout = new QVBoxLayout;
    tab1->setLayout(tab1Layout);
    QLabel *tab1label = new QLabel("隊長\n組員1\n組員2\n組員3");
    //hello world預設文字改變成紅色

    QPalette *palette = new QPalette();
    palette->setColor(QPalette::WindowText, Qt::blue);
    QFont font;
    font.setPointSize(12);
    tab1label->setFont(font);
    tab1label->setPalette(*palette);

    tab1Layout->addWidget(tab1label);

    //tab2 put button
    QVBoxLayout *tab2Layout = new QVBoxLayout;
    tab2->setLayout(tab2Layout);
    QPushButton *tab2_button = new QPushButton("color select");
    //按鈕按下讓tab1的label文字改變成QcolorDialog選擇的顏色
    QObject::connect(tab2_button, &QPushButton::clicked, [=](){
        QColor color = QColorDialog::getColor(Qt::black, window);
        if(color.isValid())
        {
            //改變*palette的顏色
            palette->setColor(QPalette::WindowText, color);
            tab1label->setPalette(*palette);
        }
    });
    tab2Layout->addWidget(tab2_button);


    //tab3
    QVBoxLayout *tab3Layout = new QVBoxLayout;
    tab3->setLayout(tab3Layout);
    QPushButton *tab3_button = new QPushButton("Font select");
    //按鈕按下讓tab1的label文字改變成FontDialog選擇的字型
    QObject::connect(tab3_button, &QPushButton::clicked, [=](){
        bool ok;
        QFont font = QFontDialog::getFont(&ok);
        if(ok)
        {
            tab1label->setFont(font);
        }
    });
    tab3Layout->addWidget(tab3_button);

    //tab4仿照tab3
    QVBoxLayout *tab4Layout = new QVBoxLayout;
    tab4->setLayout(tab4Layout);
    QPushButton *tab4_button = new QPushButton("File select");
    //按鈕按下讓tab1的label文字改變成FileDialog選擇的檔案路徑
    QObject::connect(tab4_button, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(window, "Open a file", QDir::homePath());
        if(!path.isEmpty())
        {
            tab1label->setText(path);
        }
    });
    tab4Layout->addWidget(tab4_button);


    //幫我在window放入tabWidget
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tabWidget);
    window->setLayout(mainLayout);
    window->show();
    return app.exec();
}
