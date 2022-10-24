#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget;                      //Cria uma janela
    window->setWindowTitle("Calculadora");

    QLabel *label = new QLabel(" ");

    QPushButton *button1 = new QPushButton("1");
    QPushButton *button2 = new QPushButton("2");
    QPushButton *button3 = new QPushButton("3");
    QPushButton *button4 = new QPushButton("4");
    QPushButton *button5 = new QPushButton("5");
    QPushButton *button6 = new QPushButton("6");
    QPushButton *button7 = new QPushButton("7");
    QPushButton *button8 = new QPushButton("8");
    QPushButton *button9 = new QPushButton("9");
    QPushButton *button0 = new QPushButton("0");
    QPushButton *buttonsoma = new QPushButton("+");
    QPushButton *buttonsub = new QPushButton("-");
    QPushButton *buttonmul = new QPushButton("x");
    QPushButton *buttondiv = new QPushButton("%");
    QPushButton *buttonponto = new QPushButton(".");
    QPushButton *buttonresp = new QPushButton("=");


    QObject::connect(button1, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button2, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button3, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button4, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button5, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button6, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button7, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button8, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button9, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(button0, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(buttonsoma, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(buttonsub, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(buttonmul, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(buttondiv, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(buttonponto, SIGNAL(clicked()),
                        &app, SLOT(quit()));
    QObject::connect(buttonresp, SIGNAL(clicked()),
                        &app, SLOT(quit()));


    QGridLayout *grid = new QGridLayout;              //Organiza os componentes em uma grade
    grid->addWidget(label);
    grid->addWidget(button1,1,0);
    grid->addWidget(button2,1,1);
    grid->addWidget(button3,1,2);
    grid->addWidget(button4,2,0);
    grid->addWidget(button5,2,1);
    grid->addWidget(button6,2,2);
    grid->addWidget(button7,3,0);
    grid->addWidget(button8,3,1);
    grid->addWidget(button9,3,2);
    grid->addWidget(button0,4,0);
    grid->addWidget(buttonsoma,1,3);
    grid->addWidget(buttonsub,2,3);
    grid->addWidget(buttonmul,3,3);
    grid->addWidget(buttondiv,4,3);
    grid->addWidget(buttonponto,4,1);
    grid->addWidget(buttonresp,4,2);
    window->setLayout(grid);

    window->show();

    return app.exec();
}
