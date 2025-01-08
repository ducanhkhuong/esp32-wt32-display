#include <lvgl.h>

class LabelWidget {
private:
    lv_obj_t *label;

public:
    LabelWidget(lv_obj_t *parent, const char *text, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, lv_color_t color, const lv_font_t *font) {
        label = lv_label_create(parent);
        lv_label_set_text(label, text);
        lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
        lv_obj_set_pos(label, x, y);
        lv_obj_set_size(label, width, height);
        lv_obj_set_style_text_color(label, color, 0);
        lv_obj_set_style_text_font(label, font, 0);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
        //lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
    }

    void show() {
        lv_obj_clear_flag(label, LV_OBJ_FLAG_HIDDEN);
    }

    void hide() {
        lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
    }

    void setText(const char *newText) {
        lv_label_set_text(label, newText);
    }

    void setColor(lv_color_t newColor) {
        lv_obj_set_style_text_color(label, newColor, 0);
    }

    lv_obj_t *get() {
        return label;
    }
};
