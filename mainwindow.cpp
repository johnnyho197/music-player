#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <iostream>

const std::string PLAY = "▶️";
const std::string PAUSE = "⏸️";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_song_button_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Select Music File"), "/home", tr("Music Files (*.mp3 *.mp4 *.wav)"));
        // The above line will open a dialog window to allow the user to choose an mp3 or mp4 file.

    if (fileName != "") {
        std::string file_path = fileName.toStdString();
        m_iplayer.addSongToList(file_path);
        ui->song_list->addItem(file_path.substr(file_path.find_last_of("/\\") + 1).c_str());
    }
}

void MainWindow::on_play_button_clicked()
{
    if (ui->song_list->currentRow() == -1){
        return;
    }
    if (!m_iplayer.isPLaying()){
        ui->play_button->setText(QString::fromStdString(PAUSE));
        ui->now_playing->setText("Now Playing...");
        m_current_index = ui->song_list->currentRow();
        play_set_current_song(m_current_index);

    } else {
        ui->play_button->setText(QString::fromStdString(PLAY));
        ui->now_playing->setText("Stopped Playing...");
        m_iplayer.stopSong(m_current_index);
    }
}

void MainWindow::set_song_details(){
    ui->song_title->setText(QString::fromStdString(*m_current_song->getSongTitle()));
    ui->song_artist->setText(QString::fromStdString(*m_current_song->getSongArtist()));
    ui->song_duration->setText(QString::fromStdString(*m_current_song->getSongDuration()));
    ui->song_play_type->setText(QString::fromStdString(*m_current_song->getSongPlayType()));
}

void MainWindow::play_set_current_song(int current_index){
    m_current_song = m_iplayer.getSongDetails(current_index);
    m_iplayer.playSong(current_index);

    set_song_details();
}

void MainWindow::on_next_song_button_clicked()
{
    if (!m_iplayer.isPLaying()){
        return;
    }
    if (m_current_index +1 == ui->song_list->count()){
        m_current_index = 0;
    } else {
        m_current_index +=1;
    }
    play_set_current_song(m_current_index);
}


void MainWindow::on_prev_song_button_clicked()
{
    if (!m_iplayer.isPLaying()){
        return;
    }
    if (m_current_index == 0){
        m_current_index = ui->song_list->count() -1;
    } else {
        m_current_index -=1;
    }
    play_set_current_song(m_current_index);
}


