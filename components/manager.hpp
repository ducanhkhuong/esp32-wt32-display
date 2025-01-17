#include "setup.hpp"
#include <lvgl.h>
#include <string>

class Manager
{
private:
    //data widget 
    uint8_t position_1;
    uint8_t position_2;
    uint8_t position_3;
    uint16_t distance_2;
    uint16_t distance_3;

    //check data change
    uint8_t last_position_1, last_position_2, last_position_3;
    uint16_t last_distance_2, last_distance_3;

    //obj 
    ImgWidget img1;
    ImgWidget img2;
    ImgWidget img3;
    LabelWidget label_distance2;
    LabelWidget label_distance3;
    ArcWidget arc;

    //data speed 
    uint8_t speed;
    
public:
    Manager(lv_obj_t *scr) : last_position_1(-1),
                             last_position_2(-1),
                             last_position_3(-1),
                             last_distance_2(-1),
                             last_distance_3(-1),
                             img1(scr),
                             img2(scr),
                             img3(scr),
                             speed(0)
    {
        lv_obj_set_style_bg_color(scr, lv_color_hex(0x130709), 0);

        arc.Widget(scr,24,17,190, 190, 0, 130, 135, 45, 0);

        labels[0] = lv_label_create(scr);
        lv_label_set_text(labels[0], "10");
        lv_label_set_long_mode(labels[0], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[0], 20, 172);
        lv_obj_set_size(labels[0], 30, 30);
        lv_obj_set_style_text_color(labels[0], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[0], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[0], LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_flag(labels[0], LV_OBJ_FLAG_HIDDEN);

        labels[1] = lv_label_create(scr);
        lv_label_set_text(labels[1], "20");
        lv_label_set_long_mode(labels[1], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[1], 6, 137);
        lv_obj_set_size(labels[1], 30, 30);
        lv_obj_set_style_text_color(labels[1], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[1], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[1], LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_flag(labels[1], LV_OBJ_FLAG_HIDDEN);

        labels[2] = lv_label_create(scr);
        lv_label_set_text(labels[2], "30");
        lv_label_set_long_mode(labels[2], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[2], 2, 99);
        lv_obj_set_size(labels[2], 30, 30);
        lv_obj_set_style_text_color(labels[2], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[2], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[2], LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_flag(labels[2], LV_OBJ_FLAG_HIDDEN);

        labels[3] = lv_label_create(scr);
        lv_label_set_text(labels[3], "40");
        lv_label_set_long_mode(labels[3], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[3], 11, 62);
        lv_obj_set_size(labels[3], 30, 30);
        lv_obj_set_style_text_color(labels[3], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[3], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[3], LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_flag(labels[3], LV_OBJ_FLAG_HIDDEN);

        labels[4] = lv_label_create(scr);
        lv_label_set_text(labels[4], "50");
        lv_label_set_long_mode(labels[4], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[4], 35, 28);
        lv_obj_set_size(labels[4], 30, 30);
        lv_obj_set_style_text_color(labels[4], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[4], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[4], LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_flag(labels[4], LV_OBJ_FLAG_HIDDEN);

        labels[5] = lv_label_create(scr);
        lv_label_set_text(labels[5], "60");
        lv_label_set_long_mode(labels[5], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[5], 73, 5);
        lv_obj_set_size(labels[5], 30, 30);
        lv_obj_set_style_text_color(labels[5], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[5], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[5], LV_TEXT_ALIGN_LEFT, 0);
        lv_obj_add_flag(labels[5], LV_OBJ_FLAG_HIDDEN);

        labels[6] = lv_label_create(scr);
        lv_label_set_text(labels[6], "70");
        lv_label_set_long_mode(labels[6], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[6], 110, -2);
        lv_obj_set_size(labels[6], 30, 30);
        lv_obj_set_style_text_color(labels[6], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[6], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[6], LV_TEXT_ALIGN_CENTER, 0);
        lv_obj_add_flag(labels[6], LV_OBJ_FLAG_HIDDEN);

        labels[7] = lv_label_create(scr);
        lv_label_set_text(labels[7], "80");
        lv_label_set_long_mode(labels[7], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[7], 130, 5);
        lv_obj_set_size(labels[7], 40, 40);
        lv_obj_set_style_text_color(labels[7], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[7], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[7], LV_TEXT_ALIGN_RIGHT, 0);
        lv_obj_add_flag(labels[7], LV_OBJ_FLAG_HIDDEN);

        labels[8] = lv_label_create(scr);
        lv_label_set_text(labels[8], "90");
        lv_label_set_long_mode(labels[8], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[8], 163, 28);
        lv_obj_set_size(labels[8], 40, 40);
        lv_obj_set_style_text_color(labels[8], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[8], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[8], LV_TEXT_ALIGN_RIGHT, 0);
        lv_obj_add_flag(labels[8], LV_OBJ_FLAG_HIDDEN);

        labels[9] = lv_label_create(scr);
        lv_label_set_text(labels[9], "100");
        lv_label_set_long_mode(labels[9], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[9], 190, 62);
        lv_obj_set_size(labels[9], 40, 40);
        lv_obj_set_style_text_color(labels[9], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[9], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[9], LV_TEXT_ALIGN_RIGHT, 0);
        lv_obj_add_flag(labels[9], LV_OBJ_FLAG_HIDDEN);

        labels[10] = lv_label_create(scr);
        lv_label_set_text(labels[10], "110");
        lv_label_set_long_mode(labels[10], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[10], 200, 99);
        lv_obj_set_size(labels[10], 40, 40);
        lv_obj_set_style_text_color(labels[10], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[10], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[10], LV_TEXT_ALIGN_RIGHT, 0);
        lv_obj_add_flag(labels[10], LV_OBJ_FLAG_HIDDEN);

        labels[11] = lv_label_create(scr);
        lv_label_set_text(labels[11], "120");
        lv_label_set_long_mode(labels[11], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[11], 196, 137);
        lv_obj_set_size(labels[11], 40, 40);
        lv_obj_set_style_text_color(labels[11], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[11], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[11], LV_TEXT_ALIGN_RIGHT, 0);
        lv_obj_add_flag(labels[11], LV_OBJ_FLAG_HIDDEN);

        labels[12] = lv_label_create(scr);
        lv_label_set_text(labels[12], "130");
        lv_label_set_long_mode(labels[12], LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(labels[12], 182, 172);
        lv_obj_set_size(labels[12], 40, 40);
        lv_obj_set_style_text_color(labels[12], lv_color_hex(0xffffff), 0);
        lv_obj_set_style_text_font(labels[12], &lv_font_montserrat_14, 0);
        lv_obj_set_style_text_align(labels[12], LV_TEXT_ALIGN_RIGHT, 0);
        lv_obj_add_flag(labels[12], LV_OBJ_FLAG_HIDDEN);

        for (int i = 0; i < NUM_LABEL; i++)
        {
            lv_timer_create(show_label, i * 200, (void *)i);
        }
    }

    ~Manager(){
        ESP_LOGE(TAG,"delete manager");
    }

    // show - label
    static void show_label(lv_timer_t *timer)
    {
        int index = (int)timer->user_data;
        if (index < NUM_LABEL && index >= 0)
        {
            lv_obj_clear_flag(labels[index], LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_timer_del(timer);
        }
    }

    // update - data widget to ble
    void forward_data_widget(uint8_t pos1, uint8_t pos2, uint16_t dist2, uint8_t pos3, uint16_t dist3)
    {
        this->position_1 = pos1;
        this->position_2 = pos2;
        this->distance_2 = dist2;
        this->position_3 = pos3;
        this->distance_3 = dist3;
    }

    // check data change
    bool has_data_changed()
    {
        bool data_changed = false;
        if (position_1 != last_position_1 || position_2 != last_position_2 ||
            position_3 != last_position_3 || distance_2 != last_distance_2 || distance_3 != last_distance_3)
        {
            data_changed = true;
            last_position_1 = position_1;
            last_position_2 = position_2;
            last_position_3 = position_3;
            last_distance_2 = distance_2;
            last_distance_3 = distance_3;
        }
        return data_changed;
    }


    //update - data speed to ble
    void forward_data_speed(uint8_t value)
    {
        this->speed = value;
    }



    // handle logic and ui-ux
    void ui_show(lv_obj_t *scr)
    {
        //ESP_LOGI(TAG, "Position 1: %d", position_1);
        //ESP_LOGI(TAG, "Position 2: %d, Distance: %d", position_2, distance_2);
        //ESP_LOGI(TAG, "Position 3: %d, Distance: %d", position_3, distance_3);

        switch (position_1)
        {
        case ID_NOTHING:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            break;

        case ID_SPEED_LIMIT_40:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo40.bin", 78, 140, 80, 80);
            break;

        case ID_SPEED_LIMIT_50:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo50.bin", 78, 140, 80, 80);
            break;

        case ID_SPEED_LIMIT_60:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo60.bin", 78, 140, 80, 80);
            break;

        case ID_SPEED_LIMIT_70:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo70.bin", 78, 140, 80, 80);
            break;

        case ID_SPEED_LIMIT_80:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo80.bin", 78, 140, 80, 80);
            break;

        case ID_SPEED_LIMIT_90:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo90.bin", 78, 140, 80, 80);
            break;

        case ID_SPEED_LIMIT_100:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo100.bin", 78, 140, 80, 80);
            break;

        case ID_SPEED_LIMIT_120:
            //img1.imgUpdate(scr, NULL, 78, 140, 80, 80);
            img1.imgDelete();
            img1.imgUpdate(scr, "F:/80x80/gioihantocdo120.bin", 78, 140, 80, 80);
            break;

        default:
            ESP_LOGE(TAG, "position 1 - INVALID DATA");
            break;
        };

        switch (position_2)
        {
        case ID_NOTHING:
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/nothing.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_40:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/4.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_50:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/5.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_60:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/6.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_70:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/7.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_80:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/8.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_90:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/9.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_100:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/10.bin", 53, 58, 55, 55);
            break;

        case ID_SPEED_LIMIT_120:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/11.bin", 53, 58, 55, 55);
            break;

        case ID_TS_ENTER_URBAN_AREA:
            //img2.imgUpdate(scr, NULL, 58, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/12.bin", 58, 58, 55, 45);
            break;

        case ID_TS_EXIT_URBAN_AREA:
            //img2.imgUpdate(scr, NULL, 58, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/13.bin", 58, 58, 55, 45);
            break;

        case ID_TS_NO_OVER_TAKING_ZONE:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/14.bin", 53, 58, 55, 55);
            break;

        case ID_TS_END_OF_NO_OVER_TAKING_ZONE:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/15.bin", 53, 58, 55, 55);
            break;

        case ID_TS_SLOW_DOWN_ZONE:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/16.bin", 58, 58, 55, 55);
            break;

        case ID_TS_REST_STATIOMN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/17.bin", 58, 58, 55, 55);
            break;

        case ID_TS_TOLL_STATION:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/18.bin", 58, 58, 55, 55);
            break;

        case ID_TS_CROSSING_RAILING_WITHOUT_BARRIER_SIGN :
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 60);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/19.bin", 58, 58, 55, 60);
            break;

        case ID_OTS_NO_LEFT_TURN_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/21.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_RIGHT_TURN_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/22.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_LEFT_TURN_AND_UTURN_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/23.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_RIGHT_TURN_AND_UTURN_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/24.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_LEFT_UTURN_SIGN :
            // img2.imgUpdate(screen, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/25.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_RIGHT_UTURN_SIGN :
            // img2.imgUpdate(screen, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/26.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_STRAIGHT_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/27.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_PARKING_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/28.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_STOP_AND_PARKING_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/29.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_PARKING_ON_ODD_DAYS_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/30.bin", 53, 58, 55, 55);
            break;

        case ID_OTS_NO_PARKING_ON_EVENT_DAYS_SIGN:
            //img2.imgUpdate(scr, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/31.bin", 53, 58, 55, 55);
            break;

        case ID_TRAFFIC_CAMERA:
            // img2.imgUpdate(screen, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/32.bin", 53, 58, 55, 55);
            break;

        case ID_PENALTY_CAMERA:
            // img2.imgUpdate(screen, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/33.bin", 53, 58, 55, 55);
            break;

        case ID_RED_LIGHT_SURVEILLANCE_CAMERA:
            // img2.imgUpdate(screen, NULL, 53, 58, 55, 55);
            img2.imgDelete();
            img2.imgUpdate(scr, "F:/55x55/34.bin", 53, 58, 55, 55);
            break;

        default:
            ESP_LOGE(TAG, "position 2 - INVALID DATA");
            break;
        }


        switch (position_3)
        {
        case ID_NOTHING:
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/nothing.bin", 130, 58, 55, 55);
            break;

        case ID_TS_ENTER_URBAN_AREA:
            //img3.imgUpdate(scr, NULL, 127, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/12.bin", 127, 58, 55, 45);
            break;

        case ID_TS_EXIT_URBAN_AREA:
            //img3.imgUpdate(scr, NULL, 127, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/13.bin", 127, 58, 55, 45);
            break;

        case ID_TS_NO_OVER_TAKING_ZONE:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/14.bin", 130, 58, 55, 55);
            break;

        case ID_TS_END_OF_NO_OVER_TAKING_ZONE:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/15.bin", 130, 58, 55, 55);
            break;

        case ID_TS_SLOW_DOWN_ZONE:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/16.bin", 130, 58, 55, 55);
            break;

        case ID_TS_REST_STATIOMN:
            //img3.imgUpdate(scr, NULL, 127, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/17.bin", 127, 58, 55, 55);
            break;

        case ID_TS_TOLL_STATION:
            //img3.imgUpdate(scr, NULL, 127, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/18.bin", 127, 58, 55, 55);
            break;

        case ID_TS_CROSSING_RAILING_WITHOUT_BARRIER_SIGN :
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 60);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/19.bin", 130, 58, 55, 60);
            break;

        case ID_OTS_NO_LEFT_TURN_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/21.bin", 130, 58, 55, 55); 
            break;

        case ID_OTS_NO_RIGHT_TURN_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/22.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_LEFT_TURN_AND_UTURN_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/23.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_RIGHT_TURN_AND_UTURN_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/24.bin", 130, 58, 55, 55);
            break;

	    case ID_OTS_NO_LEFT_UTURN_SIGN :
            // img3.imgUpdate(screen, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/25.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_RIGHT_UTURN_SIGN :
            // img3.imgUpdate(screen, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/26.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_STRAIGHT_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/27.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_PARKING_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/28.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_STOP_AND_PARKING_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/29.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_PARKING_ON_ODD_DAYS_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/30.bin", 130, 58, 55, 55);
            break;

        case ID_OTS_NO_PARKING_ON_EVENT_DAYS_SIGN:
            //img3.imgUpdate(scr, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/31.bin", 130, 58, 55, 55);
            break;

        case ID_TRAFFIC_CAMERA:
            // img3.imgUpdate(screen, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/32.bin", 130, 58, 55, 55);
            break;

        case ID_PENALTY_CAMERA:
            // img3.imgUpdate(screen, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/33.bin", 130, 58, 55, 55);
            break;

        case ID_RED_LIGHT_SURVEILLANCE_CAMERA:
            // img3.imgUpdate(screen, NULL, 130, 58, 55, 55);
            img3.imgDelete();
            img3.imgUpdate(scr, "F:/55x55/34.bin", 130, 58, 55, 55);
            break;

        default:
            ESP_LOGE(TAG, "position 3 - INVALID DATA");
            break;
        }

        label_distance2.labelUpdate(scr,distance_2,28,115,110,110,lv_color_white(),&lv_font_montserrat_16);
        label_distance3.labelUpdate(scr,distance_3,103,115,110,110,lv_color_white(),&lv_font_montserrat_16);
    }

    // handle logic speed
    void speed_show()
    {
        arc.arcUpdate(speed,position_1);
    }

    // callback data widget
    static void update_data_widget_callback(lv_timer_t *timer)
    {
        Manager *manager = (Manager *)timer->user_data;
        if (manager)
        {
            if (manager->has_data_changed())
            {
                manager->ui_show(lv_scr_act());
            }
        }
    }

    //callback data speed
    static void update_data_speed_callback(lv_timer_t *timer){
        Manager *manager = (Manager *)timer->user_data;
        if (manager)
        {
            manager->speed_show();
        }
    }

    // config-timer
    void create_timer(lv_timer_cb_t callback, uint32_t delay, void *user_data)
    {
        lv_timer_create(callback, delay, user_data);
    }

    // device - information
    string device_info()
    {
        std::string s_chip_info = "";
        esp_chip_info_t chip_info;
        uint32_t flash_size;
        esp_chip_info(&chip_info);

        rtc_cpu_freq_config_t conf;
        rtc_clk_cpu_freq_get_config(&conf);

        multi_heap_info_t info;
        heap_caps_get_info(&info, MALLOC_CAP_SPIRAM);
        float psramsize = (info.total_free_bytes + info.total_allocated_bytes) / (1024.0 * 1024.0);

        const esp_partition_t *running = esp_ota_get_running_partition();
        esp_app_desc_t running_app_info;

        if (esp_ota_get_partition_description(running, &running_app_info) == ESP_OK)
        {
            s_chip_info += fmt::format("Firmware Ver : {}\n", running_app_info.version);
            s_chip_info += fmt::format("Project Name : {}\n", running_app_info.project_name);
        }
        s_chip_info += fmt::format("IDF Version  : {}\n", esp_get_idf_version());

        s_chip_info += fmt::format("Controller   : {} Rev.{}\n", CONFIG_IDF_TARGET, chip_info.revision);
        s_chip_info += fmt::format("CPU Cores    : {}\n", (chip_info.cores == 2) ? "Dual Core" : "Single Core");
        s_chip_info += fmt::format("CPU Speed    : {}Mhz\n", conf.freq_mhz);
        if (esp_flash_get_size(NULL, &flash_size) == ESP_OK)
        {
            s_chip_info += fmt::format("Flash Size   : {}MB {}\n", flash_size / (1024 * 1024),
                                       (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "[embedded]" : "[external]");
        }
        s_chip_info += fmt::format("PSRAM Size   : {}MB {}\n", static_cast<int>(round(psramsize)),
                                   (chip_info.features & CHIP_FEATURE_EMB_PSRAM) ? "[embedded]" : "[external]");

        s_chip_info += fmt::format("Connectivity : {}{}{}\n", (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "2.4GHz WIFI" : "NA",
                                   (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                                   (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
        return s_chip_info;
    }
};
