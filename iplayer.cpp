#include "iplayer.h"
#include "clib_ma.h"

IPlayer::IPlayer(){
    currSongIndex = -1;
    is_playing = false;
}

int IPlayer::playSong(int index){
    // if index > playList.size(), return -1
    if (index >= static_cast<int>(playList.size())){
        return -1;
    }

    if (currSongIndex != -1){
        stopSong(currSongIndex);
    }

    // loop to search for the song that matches the provided index
    for (ISongData* song : playList){
        // set the current song to the song that matches the provided index
        if (song->getSongIndex() == index){
            engine = get_engine();
            play_song(song->getSongFilePath()->c_str());
            currSongIndex = index;
            is_playing = true;
            break;
        }
    }
    return 0;
}

int IPlayer::stopSong(int index){
    // if index > playList.size(), return -1
    if (currSongIndex == -1 || index  >= static_cast<int>(playList.size())){
        return -1;
    }
    stop_song(reinterpret_cast<ma_engine*>(engine));
    currSongIndex = -1;
    is_playing = false;
    return 0;
}

bool IPlayer::isPLaying(){
    return is_playing;
}

int IPlayer::addSongToList(std::string song_path)
{
    ISongData* new_song_data = new ISongData(playList.size(), song_path);
    playList.push_back(new_song_data);
    return new_song_data->getSongIndex();
}

ISongData* IPlayer::getSongDetails(int index){
    if (index >= static_cast<int>(playList.size())){
        return nullptr;
    }

    std::list<ISongData*>::iterator it = playList.begin();
    std::advance(it, index);

    ISongData* m_Song = *it;
    return m_Song;
}
