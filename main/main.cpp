#include "manager.hpp"

Manager *manager = nullptr;
QueueHandle_t queue_handle;
last_sign_display_t last_display = {0};

void ble_recv_cb(uint8_t *data, uint16_t len) {
    if(data[0] == HEADER_SPEED){
        ESP_LOGI("BLE-RECV-CB ", "Car Speed = %d", data[1]);
        if(manager){
            manager->forward_data_speed(data[1]);
        }else{
            ESP_LOGE("BLE-RECV-CB", "Manager not initialized!");
        }
    }else{
        sign_data_t sign_data = sign_handle(data, len);
        sign_display_on_watch_t sign_display = get_sign_display_on_watch(sign_data);
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if(xQueueSendFromISR(queue_handle,&sign_display,&xHigherPriorityTaskWoken) == pdPASS){
            if (manager) {
                manager->forward_data_widget(   sign_display.position_1,
                                                sign_display.position_2,
                                                sign_display.distance_to_ps_2,
                                                sign_display.position_3,
                                                sign_display.distance_to_ps_3
                                            );
            } else {
                ESP_LOGE("BLE-RECV-CB", "Manager not initialized!");
            }
            ESP_LOGI(TAG, "Send OK");
        }
    }
}

void ble_connect_event_cb(int event_id){
    bool connect_b = false;
    switch (event_id)
    {
    case CONNECT_EVENT:
    {
        ESP_LOGI(TAG, "DEVICE CONNECTED");
        connect_b = true;
    }
    break;

    case DISCONNECT_EVENT:
    {
         ESP_LOGI(TAG, "DEVICE DISCONNECTED");
         connect_b = false;
    }
    break;
    
    default:
        ESP_LOGE(TAG, "Unknown event id - ble connect event");
        break;
    }
}


void sound_task(void *param){
    sign_display_on_watch_t receive_data = {0};
    ESP_LOGI(TAG, "Task start");
    while(1){
        if(xQueueReceive(queue_handle,&receive_data,portMAX_DELAY) == pdPASS ){
            ESP_LOGI(TAG, "Receive OK");
            
             if(last_display.last_position_2 != receive_data.position_2){
                play_sound_id(receive_data.position_2);
             }
             if(last_display.last_position_3 != receive_data.position_3){
                play_sound_id(receive_data.position_3);
             }
            last_display.last_position_1 = receive_data.position_1;
            last_display.last_position_2 = receive_data.position_2;
            last_display.last_position_3 = receive_data.position_3;
        }
    }
}

extern "C" void app_main(void)
{
    //check cấu hình - khởi tạo 
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
    queue_handle = xQueueCreate(1, sizeof(sign_display_on_watch_t));
    BLE_SERVER_INIT();
    ble_callback_register_callback(ble_recv_cb);
    ble_connect_event_register_callback(ble_connect_event_cb);
    lcd.init();
    lcd.initDMA();
    lv_init();
    if (lv_display_init() != ESP_OK)
    {
        ESP_LOGE(TAG, "LVGL setup failed!!!");
    }
    ESP_ERROR_CHECK(esp_event_loop_create_default());


    //bắt đầu chương trình 
    lvgl_acquire();
    lv_obj_t  *screen = lv_scr_act();
    manager = new Manager(screen);
    ESP_LOGE(TAG, "\n%s", manager->device_info().c_str());
    lvgl_release();
    manager->create_timer(Manager::update_data_widget_callback,500,manager);//cập nhật dữ liệu từ BLE vào giao diện widget 0.5s
    manager->create_timer(Manager::update_data_speed_callback ,300,manager);//cập nhật dữ liệu từ BLE vào giao diện speed  0.3s

    //delete manager ;

    xTaskCreate((TaskFunction_t)sound_task,"Sound task",4096,NULL,2,NULL);
}