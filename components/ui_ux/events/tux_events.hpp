#ifndef TUX_EVENT_SOURCE_H_
#define TUX_EVENT_SOURCE_H_

#include "esp_event.h"
//#include "esp_timer.h"

#ifdef __cplusplus
extern "C" {
#endif

// Declare an event base
ESP_EVENT_DECLARE_BASE(TUX_EVENTS);        // declaration of the TUX_EVENTS family

// declaration of the specific events under the TUX_EVENTS family
enum {                                       
    TUX_EVENT_DATETIME_SET,                  // Date updated through SNTP 

    TUX_EVENT_OTA_STARTED,                   // Invoke OTA START
    TUX_EVENT_OTA_IN_PROGRESS,               // OTA Progress including %
    TUX_EVENT_OTA_ROLLBACK,                  // OTA Rollback
    TUX_EVENT_OTA_COMPLETED,                 // OTA Completed
    TUX_EVENT_OTA_FAILED,                    // OTA Failed
    TUX_EVENT_OTA_ABORTED,                   // OTA Aborted

    TUX_EVENT_WEATHER_UPDATED,               // Weather updated
    TUX_EVENT_THEME_CHANGED                  // raised when the theme changes
};

#ifdef __cplusplus
}
#endif

#endif // #ifndef TUX_EVENT_SOURCE_H_