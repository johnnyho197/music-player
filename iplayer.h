#ifndef IPLAYER_H
#define IPLAYER_H

#include <list>
#include <string>

#include "isong.h"


class IPlayer {
public:
    IPlayer();
    int playSong(int index);
    int stopSong(int index);
    int addSongToList(std::string song_path);
    bool isPLaying();
    ISongData* getSongDetails(int index);
private:
    std::list<ISongData*> playList;
    void* engine;
    int currSongIndex;
    bool is_playing;
};

#endif // IPLAYER_H
