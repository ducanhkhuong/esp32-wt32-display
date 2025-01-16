#include <lvgl.h>


class ArcWidget{
    private :
        lv_obj_t * arc = nullptr;
        lv_obj_t * container = nullptr;
    public :
        ArcWidget() : arc(nullptr),container(nullptr){}

        void Widget(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int32_t min_range, int32_t max_range, uint16_t start_angle, uint16_t end_angle, uint16_t rotation){
            arc = lv_arc_create(parent);
            
            lv_arc_set_mode(arc, LV_ARC_MODE_NORMAL);
            lv_arc_set_range(arc, min_range, max_range);
            lv_arc_set_bg_angles(arc, start_angle, end_angle);
            lv_arc_set_rotation(arc, rotation);
            lv_obj_set_pos(arc, x, y);
            lv_obj_set_size(arc, width, height);
            lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
            lv_obj_set_style_arc_color(arc,lv_color_hex(0x918787),0);

            container = lv_arc_create(parent);
            lv_arc_set_mode(container, LV_ARC_MODE_NORMAL);
            lv_arc_set_range(container, 0, 130);
            lv_arc_set_bg_angles(container, 135, 45);
            lv_arc_set_rotation(container, 0);
            lv_obj_set_pos(container, 24, 17);
            lv_obj_set_size(container, 190, 190);
            lv_obj_remove_style(container, NULL, LV_PART_KNOB);
            lv_obj_set_style_arc_color(container,lv_color_hex(0x918787),0);
        }   

        void arcUpdate(uint8_t value , uint8_t position){
            lv_arc_set_value(arc, value);
            lv_obj_set_style_arc_color(arc,lv_color_hex(0x918787),0);
            lv_arc_set_bg_angles(arc,135,45);

            if (position != ID_SPEED_LIMIT_120)
            {  
                if (value > position * 10)
                {
                    lv_arc_set_value(arc, 0);
                    lv_obj_set_style_arc_color(arc, lv_color_hex(0xff0000), LV_PART_MAIN);
                    lv_arc_set_bg_angles(arc,135,135+value*2);
                    lv_arc_set_bg_angles(container, 135+value*2, 45);
                }
            }
            else
            {
                if (value > 120)
                {
                    lv_arc_set_value(arc, 0);
                    lv_obj_set_style_arc_color(arc, lv_color_hex(0xff0000), 0);
                    lv_arc_set_bg_angles(arc,135,135+value*2);
                    lv_arc_set_bg_angles(container, 135+value*2, 45);
                }
            }
        }

        void show() {
            lv_obj_clear_flag(arc, LV_OBJ_FLAG_HIDDEN);
        }


        void hide() {
            lv_obj_add_flag(arc, LV_OBJ_FLAG_HIDDEN);
        }


        void setValue(int32_t value) {
            lv_arc_set_value(arc, value);
        }


        int32_t getValue() const {
            return lv_arc_get_value(arc);
        }


        void setBgAngles(uint16_t start_angle, uint16_t end_angle) {
            lv_arc_set_bg_angles(arc, start_angle, end_angle);
        }

        lv_obj_t *get() {
            return arc;
        } 
};