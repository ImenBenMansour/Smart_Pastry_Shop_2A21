
#include<QMediaPlayer>
#include<QFileDialog>
#include "video.h"
#include "ui_video.h"

video::video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::video)
{
    ui->setupUi(this);
    mediaPlayer = new QMediaPlayer(this);
    connect(mediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){
        ui->avance->setValue(pos);
    });
   connect(mediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){
           ui->avance->setMaximum(dur);
   });
}

video::~video()
{
    delete ui;
}

void video::on_ouvrir_clicked()
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

void video::on_jouer_clicked()
{
    mediaPlayer->play();
}

void video::on_pause_clicked()
{
    mediaPlayer->pause();
}

void video::on_stop_clicked()
{
    mediaPlayer->stop();
}

void video::on_mute_clicked()
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

void video::on_volume_valueChanged(int value)
{
    mediaPlayer->setVolume(value);
}
