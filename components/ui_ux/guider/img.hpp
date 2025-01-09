#include <lvgl.h>
#include <string>

class ImgWidget {
private:
    lv_obj_t * img = nullptr;
public:
    ImgWidget(lv_obj_t *parent):img(NULL){}

    void imgWidget(lv_obj_t *parent, const char *src, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height) {        
        if (src == NULL) {
                if (img != NULL) {
                    lv_obj_del(img);
                    img = NULL;
                }
        } else {
            if (img == NULL) {
                img = lv_img_create(parent);
            }
            lv_img_set_src(img, src);
            lv_obj_set_pos(img, x, y);
            lv_obj_set_size(img, width, height);
        }
    }
};
