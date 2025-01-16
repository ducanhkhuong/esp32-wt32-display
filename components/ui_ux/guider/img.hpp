#include <lvgl.h>
#include <string>

class ImgWidget
{
private:
    lv_obj_t * img = nullptr;

public:
    ImgWidget(lv_obj_t *parent) : img(NULL) {}

    void Widget()
    {
        ;
    }

    void imgUpdate(lv_obj_t *parent, const char *src, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height)
    {
        if (src == NULL)
        {
            if (img != NULL)
            {
                lv_obj_del(img);
                img = NULL;
            }
        }
        else
        {
            if (img == NULL)
            {
                img = lv_img_create(parent);
            }
            lv_img_set_src(img, src);
            lv_obj_set_pos(img, x, y);
            lv_obj_set_size(img, width, height);
        }
    }

    void setAlignment(lv_align_t align, lv_coord_t x_offset = 0, lv_coord_t y_offset = 0)
    {
        if (img != NULL)
        {
            lv_obj_align(img, LV_ALIGN_CENTER, x_offset, y_offset);
        }
    }

    void setRotation(int16_t angle)
    {
        if (img != NULL)
        {
            lv_img_set_angle(img, angle);
        }
    }

    void setOpacity(lv_opa_t opa)
    {
        if (img != NULL)
        {
            lv_obj_set_style_opa(img, opa, 0);
        }
    }

    void setZoom(uint16_t zoom)
    {
        if (img != NULL)
        {
            lv_img_set_zoom(img, zoom);
        }
    }

    lv_obj_t *getImageObject() const
    {
        return img;
    }

    void imgDelete()
    {
        if (img != NULL)
        {
            lv_obj_del(img);
            img = NULL;
        }
    }
};
