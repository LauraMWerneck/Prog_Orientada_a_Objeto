#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QtWidgets>

void set_flag(char op, QLineEdit *display);
void verifica_ponto(QLineEdit *display);
void check_left_zero(QLineEdit *display);
void mostra_resultado(char op, QLineEdit *display);
void limpa_valores(QLineEdit *display);

volatile char operacao;
volatile int num = 0;
float valores[100];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Cria uma janela
    QWidget *window = new QWidget;
    window->setWindowTitle("Calculadora");

    // Botões da calculadora
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
    QPushButton *buttonclear = new QPushButton("C");

    //Organiza os componentes em uma grade
    QGridLayout *grid = new QGridLayout;
    QLineEdit *display = new QLineEdit("");
    display->setAlignment(Qt::AlignRight);
    display->setReadOnly(true);
    grid->addWidget(display, 0, 0, 1, 6);
    grid->addWidget(button1, 2, 0);
    grid->addWidget(button2, 2, 1);
    grid->addWidget(button3, 2, 2);
    grid->addWidget(button4, 3, 0);
    grid->addWidget(button5, 3, 1);
    grid->addWidget(button6, 3, 2);
    grid->addWidget(button7, 4, 0);
    grid->addWidget(button8, 4, 1);
    grid->addWidget(button9, 4, 2);
    grid->addWidget(button0, 5, 0);
    grid->addWidget(buttonsoma, 2, 3);
    grid->addWidget(buttonsub, 3, 3);
    grid->addWidget(buttonmul, 5, 3);
    grid->addWidget(buttondiv, 4, 3);
    grid->addWidget(buttonponto, 5, 1);
    grid->addWidget(buttonresp, 5, 2);
    grid->addWidget(buttonclear, 1, 0);
    window->setLayout(grid);

    // O que cada botão faz
    QObject::connect(button1, &QPushButton::clicked, [=] {
        display->setText(display->text() + "1");
    });
    QObject::connect(button2, &QPushButton::clicked, [=] {
        display->setText(display->text() + "2");
    });
    QObject::connect(button3, &QPushButton::clicked, [=] {
        display->setText(display->text() + "3");
    });
    QObject::connect(button4, &QPushButton::clicked, [=] {
        display->setText(display->text() + "4");
    });
    QObject::connect(button5, &QPushButton::clicked, [=] {
        display->setText(display->text() + "5");
    });
    QObject::connect(button6, &QPushButton::clicked, [=] {
        display->setText(display->text() + "6");
    });
    QObject::connect(button7, &QPushButton::clicked, [=] {
        display->setText(display->text() + "7");
    });
    QObject::connect(button8, &QPushButton::clicked, [=] {
        display->setText(display->text() + "8");
    });
    QObject::connect(button9, &QPushButton::clicked, [=] {
        display->setText(display->text() + "9");
    });
    QObject::connect(button0, &QPushButton::clicked, [=] {
        check_left_zero(display);
    });
    QObject::connect(buttonsoma, &QPushButton::clicked, [=] {
        set_flag('+', display);
    });
    QObject::connect(buttonsub, &QPushButton::clicked, [=] {
        set_flag('-', display);
    });
    QObject::connect(buttonmul, &QPushButton::clicked, [=] {
        set_flag('*', display);
    });
    QObject::connect(buttondiv, &QPushButton::clicked, [=] {
        set_flag('/', display);
    });
    QObject::connect(buttonponto, &QPushButton::clicked, [=] {
       verifica_ponto(display);
    });
    QObject::connect(buttonresp, &QPushButton::clicked, [=] {
        mostra_resultado(operacao, display);
    });
    QObject::connect(buttonclear, &QPushButton::clicked, [=] {
       limpa_valores(display);
    });

    window->show();
    return a.exec();
}

void set_flag(char op, QLineEdit *display)
{
    valores[num] = display->text().toFloat();
    display->setText("");
    operacao = op;
    num++;
}


void verifica_ponto(QLineEdit *display)
{
    if (display->text().contains(".")) return;
    display->setText(display->text() + ".");
}

void check_left_zero(QLineEdit *display)
{
    if (display->text() == "") return;
    display->setText(display->text() + "0");
}

void mostra_resultado(char op, QLineEdit *display)
{
    float result;
    switch (operacao) {
    case '+':
        result = valores[0] + display->text().toFloat();
        display->setText(QString::number(result));
        break;
    case '-':
        result = valores[0] - display->text().toFloat();
        display->setText(QString::number(result));
        break;
    case '*':
        result = valores[0] * display->text().toFloat();
        display->setText(QString::number(result));
        break;
    case '/':
        result = valores[0] / display->text().toFloat();
        display->setText(QString::number(result));
        break;
    default:
        break;
    }
    num = 0;
}

void limpa_valores(QLineEdit *display)
{
    valores[0] = 0;
    display->setText("");
}
