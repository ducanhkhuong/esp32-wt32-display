
#ifndef GUI_EVENT_DEF_H_
#define GUI_EVENT_DEF_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MSG_PAGE_HOME           0
#define MSG_PAGE_REMOTE         1
#define MSG_PAGE_SETTINGS       2
#define MSG_PAGE_OTA            3

// Used for WiFI status update
#define MSG_WIFI_PROV_MODE      50
#define MSG_WIFI_CONNECTED      51
#define MSG_WIFI_DISCONNECTED   52

// Updates during OTA
#define MSG_OTA_STATUS          55
#define MSG_OTA_INITIATE        56

#define MSG_SDCARD_STATUS       57
#define MSG_BATTERY_STATUS      58

#define MSG_DEVICE_INFO         60

#define MSG_TIME_CHANGED        100
#define MSG_WEATHER_CHANGED     101

#ifdef __cplusplus
}
#endif

#endif // #ifndef GUI_EVENT_DEF_H_
