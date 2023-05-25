#define MINIAUDIO_IMPLEMENTATION

#include "clib_ma.h"

#include "miniaudio.h"


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
static ma_result result;
static ma_engine engine;

void* get_engine(){
    result = ma_engine_init(NULL, &engine);
    if (result != MA_SUCCESS) {
        printf("Failed to initialize audio engine.");
    }
    return (void*) &engine;
}

void play_song(const char* play_file_name)
{
    result = ma_engine_play_sound(&engine, play_file_name, NULL);
    if (result != MA_SUCCESS) {
        printf("Failed to play sound.");
        return;
    }
}

void stop_song(ma_engine* engine)
{
    ma_engine_uninit(engine);
}
#ifdef __cplusplus
}
#endif // __cplusplus
