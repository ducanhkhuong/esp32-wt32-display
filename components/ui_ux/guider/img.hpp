#include <lvgl.h>
#include <string>

class ImgWidget {
private:
    lv_obj_t * img;
public:

    void imgWidget(lv_obj_t *parent, const char *src, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height) {
        if (src == NULL) {
            lv_obj_t * parent_null = lv_obj_create(parent);
            lv_obj_set_pos(parent_null, x, y);
            lv_obj_set_size(parent_null, width, height);
            lv_obj_set_style_bg_color(parent_null, lv_color_hex(0x130709), 0);
            lv_obj_set_style_border_width(parent_null, 0, 0);
        } else {
            img = lv_img_create(parent);
            lv_img_set_src(img, src);
            lv_obj_set_pos(img, x, y);
            lv_obj_set_size(img, width, height);
        }
    }

    void show() {
        if (img) {
            lv_obj_clear_flag(img, LV_OBJ_FLAG_HIDDEN);
        }
    }

    void hide() {
        if (img) {
            lv_obj_add_flag(img, LV_OBJ_FLAG_HIDDEN);
        }
    }

    void setSource(const char *src) {
        if (src == NULL) {
            if (img) {
                lv_obj_del(img);
                img = nullptr;
            }
        } else {
            if (img == nullptr) {
                img = lv_img_create(lv_obj_get_parent(img));
            }
            lv_img_set_src(img, src);
        }
    }

    const void *getSource() const {
        if (img) {
            return lv_img_get_src(img);
        }
        return nullptr;
    }

    void setPosition(lv_coord_t x, lv_coord_t y) {
        if (img) {
            lv_obj_set_pos(img, x, y);
        }
    }

    void setSize(lv_coord_t width, lv_coord_t height) {
        if (img) {
            lv_obj_set_size(img, width, height);
        }
    }

    lv_obj_t *get() {
        return img;
    }
};
