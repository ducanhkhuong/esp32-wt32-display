idf_component_register(SRCS 
    "fonts/lumi_font_helvetica_14.c"
    "fonts/lumi_font_helvetica_30.c"
    "fonts/lumi_font_helvetica_20.c"

    INCLUDE_DIRS "." "guider" "devices" "helpers" "events"
	REQUIRES json LovyanGFX lvgl fatfs fmt spi_flash
				app_update esp_event esp_timer esp_wifi wifi_provisioning spiffs esp_partition
				esp_hw_support BLE_lib speaker_ns4168_i2s utils 
)

#không xóa cấu hình mẫu 
#idf_component_register(SRCS "main.cpp"
#
#					#config font text
#					"fonts/font_fa_14.c" 
#					"fonts/font_fa_weather_42.c"
#					"fonts/font_robotomono_13.c"
#					"fonts/font_7seg_56.c"
#					"fonts/lumi_font_helvetica_14.c"
#					"fonts/lumi_font_helvetica_30.c"
#					"fonts/lumi_font_helvetica_20.c"

#               INCLUDE_DIRS "." "devices" "helpers"
#				REQUIRES json LovyanGFX lvgl fatfs fmt spi_flash
#				app_update esp_event esp_timer esp_wifi wifi_provisioning spiffs esp_partition
#				esp_hw_support BLE_lib speaker_ns4168_i2s utils ui_ux
#				)

#spiffs_create_partition_image(storage ${PROJECT_DIR}/fatfs FLASH_IN_PROJECT)
#fatfs_create_spiflash_image(storage ${PROJECT_DIR}/fatfs FLASH_IN_PROJECT PRESERVE_TIME)