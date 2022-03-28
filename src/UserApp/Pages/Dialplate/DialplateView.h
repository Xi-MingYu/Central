//
// Created by 86150 on 2022/3/27.
//

#ifndef ESP32_CENTRAL_DIALPLATEVIEW_H
#define ESP32_CENTRAL_DIALPLATEVIEW_H

#include "../Page.h"

namespace Page
{
    class DialplateView
    {
    public:
        typedef struct
        {
            lv_obj_t *cont;
            lv_obj_t *labelValue;
            lv_obj_t *labelUnit;
        } SubInfo_t;

    public:
        struct
        {
            struct
            {
                lv_obj_t *cont;
                lv_obj_t *labelTime;
                lv_obj_t *labelUnit;
            } topInfo;

            struct
            {
                lv_obj_t* cont;
                SubInfo_t labelInfoGrp[4];
            } bottomInfo;

            struct
            {
                lv_obj_t* cont;
                lv_obj_t* btnMedia;
                lv_obj_t* btnTools;
            } btnCont;

            lv_anim_timeline_t* anim_timeline;

        } ui;

        void Create(lv_obj_t* root);
        void Delete();
        void AppearAnimStart(bool reverse = false);

    private:
        void TopInfo_Create(lv_obj_t* par);
        void BottomInfo_Create(lv_obj_t* par);
        void SubInfoGrp_Create(lv_obj_t* par, SubInfo_t* info, const char* unitText);
        void BtnCont_Create(lv_obj_t* par);
        lv_obj_t* Btn_Create(lv_obj_t* par, const void* img_src, lv_coord_t x_ofs);
    };

}
#endif //ESP32_CENTRAL_DIALPLATEVIEW_H
