#ifndef __SPEAKER_NS4168_H_
#define __SPEAKER_NS4168_H_

void speaker_config(void);
void init_sound_spiffs(void);
void read_and_play_mp3_file(const char *filename);
void play_sound_id(int id);

#endif