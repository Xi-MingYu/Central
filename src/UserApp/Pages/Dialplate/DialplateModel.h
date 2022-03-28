//
// Created by 86150 on 2022/3/27.
//

#ifndef ESP32_CENTRAL_DIALPLATEMODEL_H
#define ESP32_CENTRAL_DIALPLATEMODEL_H

#include "UserApp/DataProc/DataProc.h"

namespace Page
{
    class DialplateModel
    {

    public:
        HAL::Host_Info_t HostInfo;///主机状态信息

    public:
        void Init();
        void Deinit();

        float GetInfo_CPU()
        {
            return 0;
        }

        float GetInfo_GPU()
        {
            return 0;
        }

        float GetInfo_RAM()
        {
            return 0;
        }

        float GetInfo_FPS()
        {
            return 0;
        }

    private:
        Account* account;
    private:
        static int onEvent(Account* account, Account::EventParam_t* param);
    };
}
#endif //ESP32_CENTRAL_DIALPLATEMODEL_H
