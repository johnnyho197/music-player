#include "isong.h"
#include "taglib/fileref.h"
#include "taglib/tag.h"
#include <iostream>
ISongData::ISongData(int songID, std::string song_path){
    this->mSong_ID = songID;
    this->mSong_path = new std::string(song_path);

    TagLib::FileRef fileRef(this->mSong_path->c_str());
    TagLib::Tag *tag = fileRef.tag();

    this->mSong_title = new std::string(tag->title().toCString(true));
    this->mSong_artist = new std::string(tag->artist().toCString(true));

    TagLib::AudioProperties *properties = fileRef.audioProperties();
    int seconds = properties->length() % 60;
    int minutes = (properties->length() - seconds) / 60;
    this->mSong_duration = new std::string(std::to_string(minutes) + ':' + std::to_string(seconds/10) + std::to_string(seconds%10));
    this->mSong_playType = new std::string(tag->genre().toCString(true));
}

int ISongData::getSongIndex(){
    return mSong_ID;
}

std::string* ISongData::getSongFilePath(){
    return mSong_path;
}

std::string* ISongData::getSongTitle(){
    return mSong_title;
}

std::string* ISongData::getSongArtist(){
    return mSong_artist;
}

std::string* ISongData::getSongDuration(){
    return mSong_duration;
}

std::string* ISongData::getSongPlayType(){
    return mSong_playType;
}
