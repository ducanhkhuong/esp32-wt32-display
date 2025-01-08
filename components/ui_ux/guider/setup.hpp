#ifndef __SETUP_H_
#define __SETUP_H_

static const char *TAG = "ESP32-LCD";

//config-include-core
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"
#include "nvs_flash.h"
#include <cmath>
#include <inttypes.h>
#include <string>
#include <esp_chip_info.h>
#include <esp_ota_ops.h>
#include <spi_flash_mmap.h>
#include <esp_flash.h>
#include <fmt/core.h>
#include <fmt/format.h>   
#include "helper_sntp.hpp"      
#include "helper_spiff.hpp"
#include "helper_lv_fs.hpp"
#include "soc/rtc.h"
#include "freertos/queue.h"



using namespace std ;
extern "C" {   
    #include "ble_server_lib.h" //ble-core
    #include "speaker_ns4168.h" //speaker-core
    #include "utils.h"          //support-ble
    #include "stdint.h"
}

//config device - driver
#if defined(CONFIG_TUX_DEVICE_WT32_SC01)
/* Enable one of the devices from below (shift to bsp selection later) */
#include "conf_WT32SCO1.h"              // WT32-SC01 (ESP32)
#elif defined(CONFIG_TUX_DEVICE_WT32_SC01_PLUS)
// WT32-SC01 Plus (ESP32-S3 + 8Bit Parellel) with SD Card, Audio support
#include "conf_WT32SCO1-Plus.h"         
#elif defined(CONFIG_TUX_DEVICE_ESP32S3SPI35)
// Makerfabs ESP32S335D (ESP32-S3 + SPI) with SD Card, Audio support
#include "conf_Makerfabs_S3_STFT.h" 
#elif defined(CONFIG_TUX_DEVICE_ESP32S335D)
// Makerfabs ESP32S335D (ESP32-S3 + 16Bit Parellel) with SD Card, Audio support
#include "conf_Makerfabs_S3_PTFT.h"    
#else
    #error Unsupported device. Configure device in menuconfig
#endif

//config sd-card
#include "helper_display.hpp"
#if defined(SD_SUPPORTED)
    #if defined(WT32_SC01)
        #include "helper_storage_shared.hpp"
    #else
        #include "helper_storage.hpp"
    #endif
#endif
#include "events/tux_events.hpp"
#include "events/gui_events.hpp"

//config-font-text-and-labels
#define NUM_LABEL 13
extern lv_font_t lumi_font_helvetica_14;
extern lv_font_t lumi_font_helvetica_30;
extern lv_font_t lumi_font_helvetica_20;
       lv_obj_t  *labels[NUM_LABEL]={};

//config-object
#include "arc.hpp"
#include "img.hpp"
#include "label.hpp"

//config-path



#endif