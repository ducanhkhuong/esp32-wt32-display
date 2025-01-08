#include <lvgl.h>

class ArcWidget {
private:
    lv_obj_t *arc;

public:
    ArcWidget(lv_obj_t *parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, int32_t min_range, int32_t max_range, uint16_t start_angle, uint16_t end_angle, uint16_t rotation) {
        arc = lv_arc_create(parent);
        lv_arc_set_mode(arc, LV_ARC_MODE_NORMAL);
        lv_arc_set_range(arc, min_range, max_range);
        lv_arc_set_bg_angles(arc, start_angle, end_angle);
        lv_arc_set_value(arc, min_range);
        lv_arc_set_rotation(arc, rotation);
        lv_obj_set_pos(arc, x, y);
        lv_obj_set_size(arc, width, height);
        lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
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
