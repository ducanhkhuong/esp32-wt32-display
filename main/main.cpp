#include "manager.hpp"

Manager *manager = nullptr;
QueueHandle_t queue_speed_sound_handle;
QueueHandle_t queue_sign_data_handle;
last_sign_display_t last_display = {0};
sign_display_on_watch_t receive_data = {0};
const uint8_t no_sound[] = {0, 17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

void sound_task(void *param)
{
    sign_data_t sign_data_queue = {0};
    ESP_LOGI(TAG, "Task start");
    bool is_playing = false;
    uint8_t current_speed = 0;
    while (1)
    {
        if (xQueueReceive(queue_sign_data_handle, &sign_data_queue, 1000 / portTICK_PERIOD_MS) == pdPASS)
        {
            receive_data = get_sign_display_on_watch(sign_data_queue);
            if (manager)
            {
                manager->forward_data_widget(receive_data.position_1,
                                             receive_data.position_2,
                                             receive_data.distance_to_ps_2,
                                             receive_data.position_3,
                                             receive_data.distance_to_ps_3);
            }
            check_sign_two_position(receive_data.position_2, receive_data.position_3);

            if (last_display.last_position_2 != receive_data.position_2)
            {
                switch (receive_data.position_2)
                {
                case ID_SPEED_LIMIT_40:
                    if (sound_id_4 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_40);
                        sound_id_4 = true;
                    }

                    break;
                case ID_SPEED_LIMIT_50:
                    if (sound_id_5 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_50);
                        sound_id_5 = true;
                    }
                    break;
                case ID_SPEED_LIMIT_60:
                    if (sound_id_6 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_60);
                        sound_id_6 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_70:
                    if (sound_id_7 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_70);
                        sound_id_7 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_80:
                    if (sound_id_8 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_80);
                        sound_id_8 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_90:
                    if (sound_id_9 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_90);
                        sound_id_9 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_100:
                    if (sound_id_10 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_100);
                        sound_id_10 = true;
                    }
                    break;
                case ID_SPEED_LIMIT_120:
                    if (sound_id_11 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_120);
                        sound_id_11 = true;
                    }
                    break;
                case ID_TS_ENTER_URBAN_AREA:
                    if (sound_id_12 == false)
                    {
                        play_sound_id(ID_TS_ENTER_URBAN_AREA);
                        sound_id_12 = true;
                    }
                    break;
                case ID_TS_EXIT_URBAN_AREA:
                    if (sound_id_13 == false)
                    {
                        play_sound_id(ID_TS_EXIT_URBAN_AREA);
                        sound_id_13 = true;
                    }
                    break;
                case ID_TS_NO_OVER_TAKING_ZONE:
                    if (sound_id_14 == false)
                    {
                        play_sound_id(ID_TS_NO_OVER_TAKING_ZONE);
                        sound_id_14 = true;
                    }
                    break;
                case ID_TS_END_OF_NO_OVER_TAKING_ZONE:
                    if (sound_id_15 == false)
                    {
                        play_sound_id(ID_TS_END_OF_NO_OVER_TAKING_ZONE);
                        sound_id_15 = true;
                    }
                    break;
                case ID_TS_SLOW_DOWN_ZONE:
                    if (sound_id_16 == false)
                    {
                        play_sound_id(ID_TS_SLOW_DOWN_ZONE);
                        sound_id_16 = true;
                    }
                    break;
                case ID_TS_TOLL_STATION:
                    if (sound_id_18 == false)
                    {
                        play_sound_id(ID_TS_TOLL_STATION);
                        sound_id_18 = true;
                    }
                    break;
                case ID_TRAFFIC_CAMERA:
                    if (sound_id_32 == false)
                    {
                        play_sound_id(ID_TRAFFIC_CAMERA);
                        sound_id_32 = true;
                    }
                    break;
                case ID_PENALTY_CAMERA:
                    if (sound_id_33 == false)
                    {
                        play_sound_id(ID_PENALTY_CAMERA);
                        sound_id_33 = true;
                    }
                    break;

                case ID_RED_LIGHT_SURVEILLANCE_CAMERA:
                    if (sound_id_34 == false)
                    {
                        play_sound_id(ID_RED_LIGHT_SURVEILLANCE_CAMERA);
                        sound_id_34 = true;
                    }

                default:
                    break;
                }
            }

            if (last_display.last_position_3 != receive_data.position_3)
            {
                switch (receive_data.position_3)
                {
                case ID_SPEED_LIMIT_40:
                    if (sound_id_4 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_40);
                        sound_id_4 = true;
                    }

                    break;
                case ID_SPEED_LIMIT_50:
                    if (sound_id_5 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_50);
                        sound_id_5 = true;
                    }
                    break;
                case ID_SPEED_LIMIT_60:
                    if (sound_id_6 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_60);
                        sound_id_6 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_70:
                    if (sound_id_7 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_70);
                        sound_id_7 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_80:
                    if (sound_id_8 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_80);
                        sound_id_8 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_90:
                    if (sound_id_9 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_90);
                        sound_id_9 = true;
                    }
                    break;

                case ID_SPEED_LIMIT_100:
                    if (sound_id_10 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_100);
                        sound_id_10 = true;
                    }
                    break;
                case ID_SPEED_LIMIT_120:
                    if (sound_id_11 == false)
                    {
                        play_sound_id(ID_SPEED_LIMIT_120);
                        sound_id_11 = true;
                    }
                    break;
                case ID_TS_ENTER_URBAN_AREA:
                    if (sound_id_12 == false)
                    {
                        play_sound_id(ID_TS_ENTER_URBAN_AREA);
                        sound_id_12 = true;
                    }
                    break;
                case ID_TS_EXIT_URBAN_AREA:
                    if (sound_id_13 == false)
                    {
                        play_sound_id(ID_TS_EXIT_URBAN_AREA);
                        sound_id_13 = true;
                    }
                    break;
                case ID_TS_NO_OVER_TAKING_ZONE:
                    if (sound_id_14 == false)
                    {
                        play_sound_id(ID_TS_NO_OVER_TAKING_ZONE);
                        sound_id_14 = true;
                    }
                    break;
                case ID_TS_END_OF_NO_OVER_TAKING_ZONE:
                    if (sound_id_15 == false)
                    {
                        play_sound_id(ID_TS_END_OF_NO_OVER_TAKING_ZONE);
                        sound_id_15 = true;
                    }
                    break;
                case ID_TS_SLOW_DOWN_ZONE:
                    if (sound_id_16 == false)
                    {
                        play_sound_id(ID_TS_SLOW_DOWN_ZONE);
                        sound_id_16 = true;
                    }
                    break;
                case ID_TS_TOLL_STATION:
                    if (sound_id_18 == false)
                    {
                        play_sound_id(ID_TS_TOLL_STATION);
                        sound_id_18 = true;
                    }
                    break;
                case ID_TRAFFIC_CAMERA:
                    if (sound_id_32 == false)
                    {
                        play_sound_id(ID_TRAFFIC_CAMERA);
                        sound_id_32 = true;
                    }
                    break;
                case ID_PENALTY_CAMERA:
                    if (sound_id_33 == false)
                    {
                        play_sound_id(ID_PENALTY_CAMERA);
                        sound_id_33 = true;
                    }
                    break;

                case ID_RED_LIGHT_SURVEILLANCE_CAMERA:
                    if (sound_id_34 == false)
                    {
                        play_sound_id(ID_RED_LIGHT_SURVEILLANCE_CAMERA);
                        sound_id_34 = true;
                    }

                default:
                    break;
                }
            }
            if (receive_data.position_1 == ID_SPEED_LIMIT_120)
            {
                if (current_speed > 120)
                {
                    play_sound_id(CENSOR_BEEP);
                    play_sound_id(OVER_LMIT_SPEED);
                }
            }
            else
            {
                if (current_speed > receive_data.position_1 * 10)
                {
                    play_sound_id(CENSOR_BEEP);
                    play_sound_id(OVER_LMIT_SPEED);
                }
            }
            current_speed = 0;
            last_display.last_position_1 = receive_data.position_1;
            last_display.last_position_2 = receive_data.position_2;
            last_display.last_position_3 = receive_data.position_3;
        }
        else if (xQueueReceive(queue_speed_sound_handle, &current_speed, 10 / portTICK_PERIOD_MS) == pdPASS)
        {
        }
    }
}

void ble_recv_cb(uint8_t *data, uint16_t len)
{
    if (data[0] == HEADER_SPEED)
    {
        if (manager)
        {
            manager->forward_data_speed(data[1]);
            BaseType_t xHigherPriorityTaskWoken = pdFALSE;
            if (xQueueSendFromISR(queue_speed_sound_handle, &data[1], &xHigherPriorityTaskWoken) == pdPASS)
            {
            }
        }
        else
        {
            // ESP_LOGE("BLE-RECV-CB", "Manager not initialized!");
        }
    }
    else
    {
        sign_data_t sign_data = sign_handle(data, len);
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;
        if (xQueueSendFromISR(queue_sign_data_handle, &sign_data, &xHigherPriorityTaskWoken) == pdPASS)
        {
        }
    }
}

void ble_connect_event_cb(int event_id)
{
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

extern "C" void app_main(void)
{
    // check cấu hình - khởi tạo
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
    queue_sign_data_handle = xQueueCreate(1, sizeof(sign_data_t));
    queue_speed_sound_handle = xQueueCreate(1, sizeof(uint8_t));

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

    // bắt đầu chương trình
    lvgl_acquire();
    lv_obj_t *screen = lv_scr_act();
    manager = new Manager(screen);
    ESP_LOGE(TAG, "\n%s", manager->device_info().c_str());
    lvgl_release();
    
    manager->create_timer(Manager::update_data_widget_callback, 500, manager); // cập nhật dữ liệu từ BLE vào giao diện widget 0.5s
    manager->create_timer(Manager::update_data_speed_callback, 300, manager);  // cập nhật dữ liệu từ BLE vào giao diện speed  0.3s

    // delete manager ;

    xTaskCreate((TaskFunction_t)sound_task, "Sound task", 4096, NULL, 2, NULL);
}