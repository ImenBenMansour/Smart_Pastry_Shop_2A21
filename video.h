#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>

namespace Ui {
class video;
}
class QMediaPlayer;

class video : public QWidget
{
    Q_OBJECT

public:
    explicit video(QWidget *parent = nullptr);
    ~video();

private slots:
    void on_ouvrir_clicked();

    void on_jouer_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volume_valueChanged(int value);

private:
    Ui::video *ui;
    QMediaPlayer * mediaPlayer;
};

#endif // VIDEO_H
