#ifndef ISONG_H
#define ISONG_H

#include <string>

class ISongData {
private:
    int mSong_ID;
    std::string* mSong_path;
    std::string* mSong_title;
    std::string* mSong_artist;
    std::string* mSong_duration;
    std::string* mSong_playType;
public:
    ISongData(int songID, std::string song_path);
    int getSongIndex();
    std::string* getSongTitle();
    std::string* getSongFilePath();
    std::string* getSongArtist();
    std::string* getSongDuration();
    std::string* getSongPlayType();
};

#endif
