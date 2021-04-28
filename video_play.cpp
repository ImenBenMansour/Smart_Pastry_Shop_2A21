#include "video_play.h"
#include "ui_video_play.h"
#include<QMediaPlayer>
#include<QFileDialog>
#include<QVideoWidget>
#include<QLayout>
#include<QVBoxLayout>
#include<QBoxLayout>



Video_Play::Video_Play(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Video_Play)
{
    ui->setupUi(this);
    mediaPlayer = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
   // QVBoxLayout * layout=new QVBoxLayout;
    //layout->addWidget(videoWidget);
    mediaPlayer->setVideoOutput(videoWidget);
   // ui->verticalLayout->inserWidget(0,videoWidget);

   /* auto L=static_cast<QVBoxLayout *>(layout());
    L->insertWidget(0,videoWidget);*/

    connect(mediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){
        ui->avance->setValue(pos);
    });
   connect(mediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){
           ui->avance->setMaximum(dur);
           mediaPlayer->setPosition(dur/2);

   });
}

Video_Play::~Video_Play()
{
    delete ui;
}

void Video_Play::on_ouvrir_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"Ouvrir");
    if(filename.isEmpty())
    {
        return;
    }
    mediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mediaPlayer->setVolume(ui->volume->value());
    on_jouer_clicked();
}

void Video_Play::on_jouer_clicked()
{
    mediaPlayer->play();
}

void Video_Play::on_pause_clicked()
{
    mediaPlayer->pause();
}

void Video_Play::on_stop_clicked()
{
    mediaPlayer->stop();
}

void Video_Play::on_mute_clicked()
{
    if(ui->mute->text()=="Mute")
    {
    mediaPlayer->setMuted(true);
    ui->mute->setText("Unmute");
    }
    else
    {
        mediaPlayer->setMuted(false);
        ui->mute->setText("Mute");
    }
}

void Video_Play::on_volume_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}
