#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QDebug>
#include <QApplication>
#include "Game.h"
#include "ConsolePlayer.h"
#include <cstdio>
#include <QCoreApplication>
#include <QScrollArea>
#include <QPainter>
#include <QLabel>
#include <QPalette>
#include <QTextEdit>

#define smallw 10
#define smallh 10
#define generalpixNum 25

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->setGeometry(0,0,1600,1000);
    this->setWindowTitle(QString("Sanguosha Game"));

    ui->tiplabel->move(1025,410);
    ui->tiplabel->close();


    ui->handzonelabel->close();
    ui->handzonelabel->setGeometry(200,515,950,250);
    QPixmap handzonepix(ui->handzonelabel->width(),ui->handzonelabel->height());
    QPainter handzonepainter(&handzonepix);
    handzonepainter.drawPixmap(0,0,handzonepix.width(),handzonepix.height(),QPixmap(":/other/other image/card-container.png"));
    ui->handzonelabel->setPixmap(handzonepix);

    ui->humanlabel->close();
    ui->humanlabel->setGeometry(1150,470,300,300);
    QPixmap humanpix(ui->humanlabel->width(),ui->humanlabel->height());
    QPainter humanpainter(&humanpix);
    humanpainter.drawPixmap(0,0,humanpix.width(),humanpix.height(),QPixmap(":/other/other image/dashboard-avatar.png"));
    ui->humanlabel->setPixmap(humanpix);

    ui->humanequiplabel->close();
    ui->humanequiplabel->setGeometry(0,510,200,280);
    QPixmap humanequippix(ui->humanequiplabel->width(),ui->humanequiplabel->height());
    QPainter humanequippainter(&humanequippix);
    humanequippainter.drawPixmap(0,0,humanequippix.width(),humanequippix.height(),QPixmap(":/other/other image/dashboard-equip.png"));
    ui->humanequiplabel->setPixmap(humanequippix);




    QPixmap backpix(this->width(),this->height());
    QPainter backpainter(&backpix);
    backpainter.drawPixmap(0,0,backpix.width(),backpix.height(),QPixmap(":/image/other image/bg.png"));
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Window,backpix);
    this->setPalette(pal);

    for(int i=0;i<7;i++)
    {
        CGlobal::otherplayerzonelabel[i] = new QLabel(this);
        QPixmap otherplayerpix(":/other/other image/photo-back.png");

        int x,y;

        switch (i) {
        case 0:x=50;y=250;break;
        case 1:x=150;y=40;break;
        case 2:x=325;y=40;break;
        case 3:x=500;y=40;break;
        case 4:x=675;y=40;break;
        case 5:x=850;y=40;break;
        case 6:x=950;y=250;break;

        }

        CGlobal::otherplayerzonelabel[i]->close();
        CGlobal::otherplayerzonelabel[i]->setGeometry(x,y,otherplayerpix.width(),otherplayerpix.height());
        CGlobal::otherplayerzonelabel[i]->setPixmap(otherplayerpix);

    }

    CGlobal::deepgreen = new QPixmap(":/other/other image/5.png");
    CGlobal::green = new QPixmap(":/other/other image/4.png");
    CGlobal::yellow = new QPixmap(":/other/other image/3.png");
    CGlobal::orange = new QPixmap(":/other/other image/2.png");
    CGlobal::red = new QPixmap(":/other/other image/1.png");

    for(int i=0;i<5;i++)
    {
        CGlobal::HumanplayerHP[i] = new QLabel(this);
        CGlobal::HumanplayerHP[i]->setGeometry(1408,730-(4-i)*54,CGlobal::deepgreen->width(),CGlobal::deepgreen->height());
        CGlobal::HumanplayerHP[i]->setPixmap(*CGlobal::deepgreen);
        CGlobal::HumanplayerHP[i]->close();
    }



    QPainter smallpainter;

    CGlobal::smalldeepgreen = new QPixmap(smallw,smallh);
    CGlobal::smallgreen = new QPixmap(smallw,smallh);
    CGlobal::smallyellow = new QPixmap(smallw,smallh);
    CGlobal::smallorange = new QPixmap(smallw,smallh);
    CGlobal::smallred = new QPixmap(smallw,smallh);



    smallpainter.begin(CGlobal::smalldeepgreen);
    smallpainter.drawPixmap(0,0,smallw,smallh,QPixmap(":/other/other image/5.png"));
    smallpainter.end();
    smallpainter.begin(CGlobal::smallgreen);
    smallpainter.drawPixmap(0,0,smallw,smallh,QPixmap(":/other/other image/4.png"));
    smallpainter.end();
    smallpainter.begin(CGlobal::smallyellow);
    smallpainter.drawPixmap(0,0,smallw,smallh,QPixmap(":/other/other image/3.png"));
    smallpainter.end();
    smallpainter.begin(CGlobal::smallorange);
    smallpainter.drawPixmap(0,0,smallw,smallh,QPixmap(":/other/other image/2.png"));
    smallpainter.end();
    smallpainter.begin(CGlobal::smallred);
    smallpainter.drawPixmap(0,0,smallw,smallh,QPixmap(":/other/other image/1.png"));
    smallpainter.end();






   for(int i=0;i<7;i++)
    {
        for(int j=0;j<5;j++)
        {
            CGlobal::otherplayerHP[i][j] = new QLabel(this);
            CGlobal::otherplayerHP[i][j]->setGeometry(CGlobal::otherplayerzonelabel[i]->x()+135,CGlobal::otherplayerzonelabel[i]->y()+40+j*15,smallw,smallh);
            CGlobal::otherplayerHP[i][j]->setPixmap(*CGlobal::smalldeepgreen);
            //CGlobal::otherplayerHP[i][j]->show();
            CGlobal::otherplayerHP[i][j]->close();
        }
    }


   // QPainter painter(ui->logolabel);
    //painter.drawPixmap(0,0,ui->logolabel->width(),ui->logolabel->height(),QPixmap(":/image/LOGO.png"));
    ui->logolabel->setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->logolabel->setPixmap(QPixmap(":/image/LOGO.png"));
    ui->logolabel->setGeometry(500,100,QPixmap(":/image/LOGO.png").width(),QPixmap(":/image/LOGO.png").height());
   /* QLabel mainlabel(this);
    mainlabel.setGeometry(0,0,1600,1000);

    QPainter painter(&mainlabel);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/image/other image/bg.png"));*/

    /*this->setAutoFillBackground(true);
    QPalette backgroundpalette;
    QPixmap backgroundpix(":/image/background.png");
    backgroundpalette.setBrush(QPalette::Window,QBrush(backgroundpix));
    this->setPalette(backgroundpalette);*/
    this->show();

    //ui->viewhistorybutton->setGeometry(900,100,100,100);
    //ui->inputablebutton->setGeometry(900,0,100,100);
    ui->inputbutton->setGeometry(900,300,100,30);
    ui->pushButton->close();



    //this->textedit->verticalScrollBar();
    this->textedit->setGeometry(30,30,300,300);
    //this->textedit->show();
    this->scrollArea->setWidget(this->textedit);
    //this->scrollArea->setGeometry(30,30,300,300);
    this->scrollArea->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->scrollArea->setWindowTitle(QString("Game Message"));

    //this->scrollArea->show();



    this->textedit->setReadOnly(true);



    this->textinput->close();
    ui->inputbutton->close();
    this->textinput->setGeometry(950,250,50,50);

    ui->pushButton_2->setGeometry(580,400,300,100);
    ui->exitbutton->setGeometry(580,500,300,100);
    ui->helpbutton->setGeometry(580,500,300,100);
    ui->helpbutton->close();
    ui->autoplaybutton->setGeometry(-5,500,210,80);
    ui->autoplaybutton->close();
    ui->cancelautobutton->setGeometry(-5,500,210,80);
    ui->cancelautobutton->close();


    ui->rebelwinlabel->setGeometry(170,200,900,300);
    ui->lordwinlabel->setGeometry(170,200,900,300);
    ui->renegadewinlabel->setGeometry(170,200,900,300);
    ui->rebelwinlabel->close();
    ui->renegadewinlabel->close();
    ui->lordwinlabel->close();
    CGlobal::rebelwin = ui->rebelwinlabel;
    CGlobal::lordwin = ui->lordwinlabel;
    CGlobal::renegadewin = ui->renegadewinlabel;

    for(int i=0;i<generalpixNum;i++)
    {
        char filename[50] = ":/general/full/needed/";
        char Num[50] = {0};
        if(i+1>=10)
        {
            Num[0] = '0'+(i+1)/10;
            Num[1] = '0'+(i+1)%10;
        }
        else
            Num[0] = '0' +(i+1);

        char Tail[50] = ".png";

        strcat(filename,Num);
        strcat(filename,Tail);

        CGlobal::generalpix[i] = new QPixmap(filename);




    }

    QPixmap startbuttonpix(ui->pushButton_2->width(),ui->pushButton_2->height());
    QPixmap exitbuttonpix(ui->exitbutton->width(),ui->exitbutton->height());
    QPixmap helpbuttonpix(ui->helpbutton->width(),ui->helpbutton->height());
    QPixmap autoplaybuttonpix(ui->autoplaybutton->width(),ui->autoplaybutton->height());
    QPixmap cancelautobuttonpix(ui->cancelautobutton->width(),ui->cancelautobutton->height());

    QPainter buttonpainter;
    buttonpainter.begin(&startbuttonpix);
    buttonpainter.drawPixmap(0,0,startbuttonpix.width(),startbuttonpix.height(),QPixmap(":/image/button.png"));
    buttonpainter.setPen(QColor(205,160,125));
    buttonpainter.setFont(QFont(QString("行楷-简"),50,5,false));
    buttonpainter.drawText(QRect(50,10,startbuttonpix.width(),startbuttonpix.height()),QString("开始游戏"));
    ui->pushButton_2->setIcon(QIcon(startbuttonpix));
    ui->pushButton_2->setIconSize(ui->pushButton_2->size());
    buttonpainter.end();



    buttonpainter.begin(&exitbuttonpix);
    buttonpainter.drawPixmap(0,0,exitbuttonpix.width(),exitbuttonpix.height(),QPixmap(":/image/button.png"));
    buttonpainter.setPen(QColor(205,160,125));
    buttonpainter.setFont(QFont(QString("行楷-简"),50,5,false));
    buttonpainter.drawText(QRect(50,10,exitbuttonpix.width(),exitbuttonpix.height()),QString("退出游戏"));
    ui->exitbutton->setIcon(QIcon(exitbuttonpix));
    ui->exitbutton->setIconSize(ui->exitbutton->size());
    buttonpainter.end();

    buttonpainter.begin(&helpbuttonpix);
    buttonpainter.drawPixmap(0,0,helpbuttonpix.width(),helpbuttonpix.height(),QPixmap(":/image/button.png"));
    buttonpainter.setPen(QColor(205,160,125));
    buttonpainter.setFont(QFont(QString("行楷-简"),50,5,false));
    buttonpainter.drawText(QRect(50,10,helpbuttonpix.width(),helpbuttonpix.height()),QString("游戏帮助"));
    ui->helpbutton->setIcon(QIcon(helpbuttonpix));
    ui->helpbutton->setIconSize(ui->helpbutton->size());
    buttonpainter.end();

    buttonpainter.begin(&autoplaybuttonpix);
    buttonpainter.drawPixmap(0,0,autoplaybuttonpix.width(),autoplaybuttonpix.height(),QPixmap(":/image/button.png"));
    buttonpainter.setPen(QColor(205,160,125));
    buttonpainter.setFont(QFont(QString("行楷-简"),50,5,false));
    buttonpainter.drawText(QRect(7,3,autoplaybuttonpix.width(),autoplaybuttonpix.height()),QString("托管模式"));
    ui->autoplaybutton->setIcon(QIcon(autoplaybuttonpix));
    ui->autoplaybutton->setIconSize(ui->autoplaybutton->size());
    buttonpainter.end();

    buttonpainter.begin(&cancelautobuttonpix);
    buttonpainter.drawPixmap(0,0,cancelautobuttonpix.width(),cancelautobuttonpix.height(),QPixmap(":/image/button.png"));
    buttonpainter.setPen(QColor(205,160,125));
    buttonpainter.setFont(QFont(QString("行楷-简"),50,5,false));
    buttonpainter.drawText(QRect(7,3,cancelautobuttonpix.width(),cancelautobuttonpix.height()),QString("取消托管"));
    ui->cancelautobutton->setIcon(QIcon(cancelautobuttonpix));
    ui->cancelautobutton->setIconSize(ui->cancelautobutton->size());
    buttonpainter.end();



    QPixmap * othernumberpix[8];
    QPixmap * humannumberpix[8];




     for(int i = 0; i < 8 ; i++ )
     {
         CGlobal::humanplayernumber[i]=new QLabel(this);
         CGlobal::otherplayernumber[i]=new QLabel(this);

         CGlobal::humanplayernumber[i]->setGeometry(400,400+50*i,130,60);
         CGlobal::otherplayernumber[i]->setGeometry(300,300+50*i,100,50);


         char numbertext[20] = "Player ";
         numbertext[7] = '0'+i;
             CGlobal::humanplayernumber[i]->setText(QString(numbertext));
             CGlobal::otherplayernumber[i]->setText(QString(numbertext));

             QPalette pe;
             pe.setColor(QPalette::WindowText,Qt::white);

             CGlobal::humanplayernumber[i]->setPalette(pe);
             CGlobal::humanplayernumber[i]->setStyleSheet("font-size:30px");

             CGlobal::otherplayernumber[i]->setPalette(pe);
             CGlobal::otherplayernumber[i]->setStyleSheet("font-size:15px");

             CGlobal::humanplayernumber[i]->close();
             CGlobal::otherplayernumber[i]->close();

     }

     CGlobal::rolespix[0] = new QPixmap(":/other/roles/lord.png");
     CGlobal::rolespix[1] = new QPixmap(":/other/roles/loyalist.png");
     CGlobal::rolespix[2] = new QPixmap(":/other/roles/rebel.png");
     CGlobal::rolespix[3] = new QPixmap(":/other/roles/renegade.png");




    /* for(int i=0;i<7;i++)
     {

         //QPixmap rolespic(CGlobal::roleslabel[i]->width(),CGlobal::roleslabel[i]->height());
         //QPainter rolespainter(&rolespic);
         //rolespainter.drawPixmap(0,0,CGlobal::roleslabel[i]->width(),CGlobal::roleslabel[i]->height(),*CGlobal::rolespix[i]);
         CGlobal::roleslabel[i]->setPixmap(rolespic);
         CGlobal::roleslabel[i]->close();



     }*/

     CGlobal::roleslabel[7]= new QLabel(this);
     CGlobal::roleslabel[7]->setGeometry(300,300,50,70);

     for(int i=0;i<7;i++)
     {
         CGlobal::cardnum[i] = new QTextEdit(this);
         CGlobal::cardnum[i]->setGeometry(CGlobal::otherplayerzonelabel[i]->x()+133,CGlobal::otherplayerzonelabel[i]->y()+5,15,15);
         CGlobal::cardnum[i]->setReadOnly(true);
         CGlobal::cardnum[i]->close();
     }






    //CGlobal::startbutton = ui->pushButton_2;







}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void Inputres(int & a)
{
    bool ok;
    int value1;
    value1=QInputDialog::getInt(this,tr("输入指令"),tr(""),0,0,1000,1,&ok);
    a=value1;
}*/




void MainWindow::on_pushButton_clicked()
{
    bool ok=1;
    int value1;

    while (ok) {

    ok=0;
    value1=QInputDialog::getInt(this,tr("输入指令"),tr(""),0,0,1000,1,&ok);
    if(ok)
    {
        CGlobal::inputtemp=value1;
        CGlobal::inputbutton_clicked=1;
    }



    }

}


void MainWindow::on_pushButton_2_clicked()
{
    int i;
    int NumOfPlayers;


      bool *ok=new bool;
      int *temp=new int;
        *ok=0;
        *temp=QInputDialog::getInt(0,"请选择玩家数","可选玩家数:4-8名",8,4,8,1,ok);
        /*if(*temp==999)
            exit(0);*/
        if(*ok)
        NumOfPlayers=*temp;
        else
            return;

        free(ok);
        free(temp);

       /* QLabel mainlabel(this);
        mainlabel.setGeometry(0,0,1600,1000);

        QPainter painter(&mainlabel);
        painter.drawPixmap(0,0,mainlabel.width(),mainlabel.height(),QPixmap(":/image/background.png"));

        mainlabel.show();*/
    QPalette pal=this->palette();
    pal.setBrush(QPalette::Window,QPixmap(":/image/background.png"));
    this->setPalette(pal);

    ui->handzonelabel->show();

    ui->humanlabel->show();

    ui->humanequiplabel->show();

    ui->tiplabel->show();

    ui->autoplaybutton->show();



    for(int i=0;i<7;i++)
    {
        CGlobal::otherplayerzonelabel[i]->show();
        CGlobal::cardnum[i]->show();
    }



    ui->logolabel->close();


     CGlobal::ww->scrollArea->move(1200,120);
     CGlobal::ww->scrollArea->show();
     CGlobal::ww->textedit->show();
     CGlobal::ww->textinput->show();
    // ui->inputbutton->show();
     ui->pushButton_2->close();
     ui->exitbutton->setGeometry(1200,0,200,70);
     CGlobal::ww->textinput->move(1350,420);
     //ui->inputbutton->move(1250,400);






    vector<ClientPlayer*> p;
    for(i=0;i<NumOfPlayers;i++)
    {
        char buf[100];
        sprintf(buf,"Player %d",i);
        p.push_back(new ConsolePlayer(buf));
    }
    new Game(p,true,this);
    for(i=0;i<5;i++) delete p[i];

    /*CGlobal::rebelwin->close();
    CGlobal::lordwin->close();
    CGlobal::renegadewin->close();*/



}

CGlobal::CGlobal()
{

}

CGlobal::~CGlobal()
{

}

MainWindow * CGlobal::ww=0;
int CGlobal::inputtemp=1;
bool CGlobal::inputbutton_clicked=0;

void MainWindow::on_inputbutton_clicked()
{
    //CGlobal::inputtemp=CGlobal::ww->textinput->toPlainText().toInt();
    CGlobal::inputbutton_clicked=1;
    //CGlobal::ww->textinput->clear();
}


void MainWindow::on_viewhistorybutton_clicked()
{
    CGlobal::ww->textedit->setFocus();
    CGlobal::ww->textedit->moveCursor(QTextCursor::End);
}

void MainWindow::on_inputablebutton_clicked()
{
    CGlobal::ww->textinput->setFocus();
}

void MainWindow::on_exitbutton_clicked()
{
    QCoreApplication::quit();
    exit(0);
}

/*void MainWindow::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,width(),height(),QPixmap(":/image/other image/bg.png"));
    //this->setGeometry(100,100,900,900);
}*/

int CGlobal::CurrentPlayer = -1;

int CGlobal::HumanPlayer = -1;

QLabel * CGlobal::otherplayerzonelabel[7]={0};

QLabel * CGlobal::HumanplayerHP[5]={0};

QLabel * CGlobal::otherplayerHP[7][5]={0};

QPixmap * CGlobal::deepgreen = 0;
QPixmap * CGlobal::green = 0;
QPixmap * CGlobal::yellow = 0;
QPixmap * CGlobal::orange = 0;
QPixmap * CGlobal::red = 0;



QPixmap * CGlobal::smalldeepgreen = 0;//new QPixmap(smallw,smallh);
QPixmap * CGlobal::smallgreen = 0;//new QPixmap(smallw,smallh);
QPixmap * CGlobal::smallyellow = 0;//new QPixmap(smallw,smallh);
QPixmap * CGlobal::smallorange = 0;//new QPixmap(smallw,smallh);
QPixmap * CGlobal::smallred = 0;//new QPixmap(smallw,smallh);//////////有问题

QLabel * CGlobal::Cur[7] = {0};

QLabel * CGlobal::rebelwin = 0;
QLabel * CGlobal::lordwin = 0;
QLabel * CGlobal::renegadewin = 0;

QPixmap * CGlobal::generalpix[25] = {0};

QLabel * CGlobal::otherplayergeneral[7] = {0};
QLabel *CGlobal::Dead = 0;

//QPushButton * startbutton = 0;

QLabel * CGlobal::Humangeneral = 0;

QLabel * CGlobal::otherplayernumber[8] = {0};

QLabel * CGlobal::humanplayernumber[8] = {0};

QLabel * CGlobal::roleslabel[8]={0};

QPixmap * CGlobal::rolespix[4]={0};

QTextEdit * CGlobal::cardnum[7]={0};

int CGlobal::CurrentTurn = -1;

int CGlobal::AutoOrNot = 0 ;

















void MainWindow::on_pushButton_2_pressed()
{

}




void MainWindow::on_pushButton_2_released()
{


}

void MainWindow::on_autoplaybutton_clicked()
{
    ui->autoplaybutton->close();
    ui->cancelautobutton->show();
    CGlobal::AutoOrNot = 1;
}



void MainWindow::on_cancelautobutton_clicked()
{
    ui->cancelautobutton->close();
    ui->autoplaybutton->show();
    CGlobal::AutoOrNot = 0;
}
