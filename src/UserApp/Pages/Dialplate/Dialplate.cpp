//
// Created by 86150 on 2022/3/27.
//

#include "Dialplate.h"

using namespace Page;

Dialplate::Dialplate()
        :
        lastFocus(nullptr)
{
}

Dialplate::~Dialplate()
{
}

void Dialplate::onCustomAttrConfig()
{
    SetCustomLoadAnimType(PageManager::LOAD_ANIM_NONE);
}

void Dialplate::onViewLoad()
{
    Model.Init();
    View.Create(root);

    AttachEvent(View.ui.btnCont.btnMedia);
    AttachEvent(View.ui.btnCont.btnTools);
}

void Dialplate::onViewDidLoad()
{

}

void Dialplate::onViewWillAppear()
{
    lv_indev_wait_release(lv_indev_get_act());
    lv_group_t* group = lv_group_get_default();

    lv_group_set_wrap(group, false);

    lv_group_add_obj(group, View.ui.btnCont.btnMedia);
    lv_group_add_obj(group, View.ui.btnCont.btnTools);

    if (lastFocus)
    {
        lv_group_focus_obj(lastFocus);
    }

    //StatusBar::SetStyle(StatusBar::STYLE_TRANSP);

    Update();

    View.AppearAnimStart();
}

void Dialplate::onViewDidAppear()
{
    timer = lv_timer_create(onTimerUpdate, 1000, this);
}

void Dialplate::onViewWillDisappear()
{
    lv_group_t* group = lv_group_get_default();
    lastFocus = lv_group_get_focused(group);
    lv_group_remove_all_objs(group);
    lv_timer_del(timer);
    //View.AppearAnimStart(true);
}

void Dialplate::onViewDidDisappear()
{
}

void Dialplate::onViewDidUnload()
{
    Model.Deinit();
    View.Delete();
}

void Dialplate::AttachEvent(lv_obj_t* obj)
{
    lv_obj_add_event_cb(obj, onEvent, LV_EVENT_ALL, this);
}

void Dialplate::Update()
{
    char buf[16];
    lv_label_set_text_fmt(View.ui.topInfo.labelSpeed, "%02d", (int)Model.GetSpeed());

    lv_label_set_text_fmt(View.ui.bottomInfo.labelInfoGrp[0].lableValue, "%0.1f km/h", Model.GetAvgSpeed());
    lv_label_set_text(
            View.ui.bottomInfo.labelInfoGrp[1].lableValue,
            DataProc::MakeTimeString(Model.sportStatusInfo.singleTime, buf, sizeof(buf))
    );
    lv_label_set_text_fmt(
            View.ui.bottomInfo.labelInfoGrp[2].lableValue,
            "%0.1f km",
            Model.sportStatusInfo.singleDistance / 1000
    );
    lv_label_set_text_fmt(
            View.ui.bottomInfo.labelInfoGrp[3].lableValue,
            "%d k",
            int(Model.sportStatusInfo.singleCalorie)
    );
}

void Dialplate::onTimerUpdate(lv_timer_t* timer)
{
    Dialplate* instance = (Dialplate*)timer->user_data;

    instance->Update();
}

void Dialplate::onBtnClicked(lv_obj_t* btn)
{
    if (btn == View.ui.btnCont.btnMedia)
    {
        Manager->Push("Pages/LiveMap");
    }
    else if (btn == View.ui.btnCont.btnTools)
    {
        Manager->Push("Pages/SystemInfos");
    }
}


void Dialplate::onEvent(lv_event_t* event)
{
    Dialplate* instance = (Dialplate*)lv_event_get_user_data(event);
    LV_ASSERT_NULL(instance);

    lv_obj_t* obj = lv_event_get_target(event);
    lv_event_code_t code = lv_event_get_code(event);

    if (code == LV_EVENT_SHORT_CLICKED)
    {
        instance->onBtnClicked(obj);
    }
}
