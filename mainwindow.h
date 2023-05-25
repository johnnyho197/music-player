#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iplayer.h"
#include "SongTaskThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_add_song_button_clicked();

    void on_play_button_clicked();

    void on_next_song_button_clicked();

    void on_prev_song_button_clicked();

    void set_song_details();

    void play_set_current_song(int current_index);
private:
    Ui::MainWindow *ui;
    IPlayer m_iplayer;
    size_t m_current_index =-1;
    ISongData* m_current_song;
    SongTaskThread *pSongThread;
};

#endif // MAINWINDOW_H
