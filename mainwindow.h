#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QMouseEvent>
#include <QScrollArea>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTextEdit * textedit = new QTextEdit(this);
    QTextEdit * textinput = new QTextEdit(this);

    QScrollArea * scrollArea = new QScrollArea;

private:
    //void paintEvent(QPaintEvent*);
            ;








private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_inputbutton_clicked();

    void on_viewhistorybutton_clicked();

    void on_inputablebutton_clicked();

    void on_exitbutton_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_autoplaybutton_clicked();

    void on_cancelautobutton_clicked();

private:
    Ui::MainWindow *ui;
};

class CGlobal
{
public:
    CGlobal();
    ~CGlobal();

public:
    static MainWindow * ww;
    static int inputtemp ;
    static bool inputbutton_clicked ;

    static void QOUT(std::string a) {
        QString qs = QString::fromStdString(a);
        CGlobal::ww->textedit->insertPlainText(qs);
        CGlobal::ww->textedit->moveCursor(QTextCursor::End);


    }

    static int CurrentPlayer ;
    static int HumanPlayer ;

    static QLabel * otherplayerzonelabel[7];

    static QLabel * HumanplayerHP[5];

    static QLabel * otherplayerHP[7][5];

    static QPixmap * deepgreen;
    static QPixmap * green;
    static QPixmap * yellow;
    static QPixmap * orange;
    static QPixmap * red;

    static QPixmap * smalldeepgreen;
    static QPixmap * smallgreen;
    static QPixmap * smallyellow;
    static QPixmap * smallorange;
    static QPixmap * smallred;

    static QLabel *Cur[7];

    static QLabel * rebelwin;
    static QLabel * lordwin;
    static QLabel * renegadewin;

 //   static QPushButton * startbutton;

    static QPixmap * generalpix[25];

    static QLabel * otherplayergeneral[7];

    static QLabel *Dead;

    static QLabel * Humangeneral ;

    static QLabel * otherplayernumber [8] ;

    static QLabel * humanplayernumber [8] ;

    static QLabel * roleslabel[8];

    static QPixmap * rolespix[4];

    static QTextEdit * cardnum[7];

    static int CurrentTurn;

    static int AutoOrNot;








};







#endif // MAINWINDOW_H
