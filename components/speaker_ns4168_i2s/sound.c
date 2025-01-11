#include "speaker_ns4168.h"
#include "utils.h"
#include "esp_log.h"

#define TAG "Play sound"
void play_sound_id(int id)
{
    switch (id)
    {
    case ID_SPEED_LIMIT_40:
        read_and_play_mp3_file("/sound/4.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 40");
        break;
    case ID_SPEED_LIMIT_50:
        read_and_play_mp3_file("/sound/5.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 50");
        break;
    case ID_SPEED_LIMIT_60:
        read_and_play_mp3_file("/sound/6.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 60");
        break;
    case ID_SPEED_LIMIT_70:
        read_and_play_mp3_file("/sound/7.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 70");
        break;
    case ID_SPEED_LIMIT_80:
        read_and_play_mp3_file("/sound/8.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 80");
        break;
    case ID_SPEED_LIMIT_90:
        read_and_play_mp3_file("/sound/9.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 90");
        break;
    case ID_SPEED_LIMIT_100:
        read_and_play_mp3_file("/sound/10.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 100");
        break;
    case ID_SPEED_LIMIT_120:
        read_and_play_mp3_file("/sound/11.mp3", 2200);
        ESP_LOGI(TAG, "toc do gioi han 120");
        break;
    case ID_TS_ENTER_URBAN_AREA:
        read_and_play_mp3_file("/sound/12.mp3", 2200);
        ESP_LOGI(TAG, "vao khu dan cu");
        break;
    case ID_TS_EXIT_URBAN_AREA:
        read_and_play_mp3_file("/sound/13.mp3", 2200);
        ESP_LOGI(TAG, "Thoat khu dan cu");
        break;
    case ID_TS_NO_OVER_TAKING_ZONE:
        read_and_play_mp3_file("/sound/14.mp3", 2200);
        ESP_LOGI(TAG, "chuan bi toi doan duong cam vuot");
        break;
    case ID_TS_END_OF_NO_OVER_TAKING_ZONE:
        read_and_play_mp3_file("/sound/15.mp3", 1200);
        ESP_LOGI(TAG, "Ket thuc doan duong cam vuot");
        break;
    case ID_TS_SLOW_DOWN_ZONE:
        read_and_play_mp3_file("/sound/16.mp3", 2200);
        ESP_LOGI(TAG, "Sap toi doan phai giam toc do");
        break;
    case ID_TS_TOLL_STATION:
        read_and_play_mp3_file("/sound/18.mp3", 4200);
        ESP_LOGI(TAG, "Sap toi tram thu phi");
        break;
    case ID_TRAFFIC_CAMERA:
        read_and_play_mp3_file("/sound/32.mp3", 2200);
        ESP_LOGI(TAG, "Phia truoc co manera giao thong");
        break;
    case ID_PENALTY_CAMERA:
        read_and_play_mp3_file("/sound/33.mp3", 2200);
        ESP_LOGI(TAG, "Phia truoc co camera theo doi toc do");
        break;
    case ID_RED_LIGHT_SURVEILLANCE_CAMERA:
        read_and_play_mp3_file("/sound/34.mp3", 2200);
        break;
    case CENSOR_BEEP:
        read_and_play_mp3_file("/sound/censor-beep-01.mp3", 300);
        break;
    case OVER_LMIT_SPEED:
        read_and_play_mp3_file("/sound/Over_limit_speed.mp3", 1500);
        break;

    default:
        ESP_LOGE(TAG, "Invalid ID sign, please check again");
        break;
    }
}