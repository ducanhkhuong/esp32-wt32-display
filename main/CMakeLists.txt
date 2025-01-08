idf_component_register(SRCS "main.cpp"
	REQUIRES ui_ux #BLE_lib speaker_ns4168_i2s utils esp_wifi
	)
spiffs_create_partition_image(storage ${PROJECT_DIR}/fatfs FLASH_IN_PROJECT)