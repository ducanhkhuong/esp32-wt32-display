#include <lvgl.h>
#include <string>

class LabelWidget {
private:
    lv_obj_t *label = nullptr;

public:
    LabelWidget() : label(nullptr) {}

    void updateLabel(lv_obj_t *parent, int16_t value, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_color_t color, const lv_font_t *font) {
        if (value <= 0 || value > 300) {
            if (label != nullptr) {
                lv_obj_del(label);
                label = nullptr;
            }
        } else {
            if (label == nullptr) {
                label = lv_label_create(parent);
                lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
            }
            lv_label_set_text_fmt(label, "%dm", value);
            lv_obj_set_pos(label, x, y);
            lv_obj_set_size(label, width, height);
            lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }

    void show() {
        if (label) {
            lv_obj_clear_flag(label, LV_OBJ_FLAG_HIDDEN);
        }
    }

    void hide() {
        if (label) {
            lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
        }
    }

    void setColor(lv_color_t newColor) {
        if (label) {
            lv_obj_set_style_text_color(label, newColor, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }

    lv_obj_t *get() {
        return label;
    }
};
