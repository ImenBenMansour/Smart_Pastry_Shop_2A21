#ifndef VIDEO_PLAY_H
#define VIDEO_PLAY_H



#include<QLayout>
#include <QWidget>

namespace Ui {
class Video_Play;
}
class QMediaPlayer;
class QVideoWidget;

class Video_Play : public QWidget
{
    Q_OBJECT

public:
    explicit Video_Play(QWidget *parent = nullptr);
    ~Video_Play();

private slots:
    void on_ouvrir_clicked();

    void on_jouer_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volume_valueChanged(int value);

private:
    Ui::Video_Play *ui;
    QMediaPlayer * mediaPlayer;
    QVideoWidget * videoWidget;

};

#endif // VIDEO_PLAY_H
