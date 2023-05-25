#ifndef CLIB_MA_H
#define CLIB_MA_H

#include "miniaudio.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void play_song(const char* play_file_name);
void stop_song(ma_engine* engine);
void* get_engine();

#ifdef __cplusplus
}
#endif // cplusplus

#endif // CLIB_MA_H
