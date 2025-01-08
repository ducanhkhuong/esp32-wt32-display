#include "manager.hpp"

Manager * manager = nullptr;

void ble_recv_cb(uint8_t *data, uint16_t len) {
    sign_data_t sign_data = sign_handle(data, len);
    sign_display_on_watch_t sign_display = get_sign_display_on_watch(sign_data);

    if (manager) {
        manager->forward_data(sign_display.position_1,sign_display.position_2,sign_display.distance_to_ps_2,sign_display.position_3,sign_display.distance_to_ps_3);
    } else {
        ESP_LOGE("BLE-RECV-CB", "Manager not initialized!");
    }
}


extern "C" void app_main(void)
{
    //check cấu hình - check 
    esp_log_level_set(TAG, ESP_LOG_DEBUG);
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);
    init_spiff();
    init_sound_spiffs();
    speaker_config();
    BLE_SERVER_INIT();
    ble_callback_register_callback(ble_recv_cb);
    lcd.init();
    lcd.initDMA();
    lv_init();
    if (lv_display_init() != ESP_OK)
    {
        ESP_LOGE(TAG, "LVGL setup failed!!!");
    }
    ESP_ERROR_CHECK(esp_event_loop_create_default());



    // Thử nghiệm LVGL
    lvgl_acquire();
    lv_obj_t  *screen = lv_scr_act();
    manager = new Manager(screen);
    ESP_LOGE(TAG, "\n%s", manager->device_info().c_str());
    lvgl_release();

    //cập nhật dữ liệu từ BLE vào giao diện
    manager->create_timer(Manager::update_data_callback, 500, manager);
}


