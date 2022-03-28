//
// Created by 86150 on 2022/3/27.
//

#include "DialplateModel.h"

using namespace Page;

void DialplateModel::Init()
{
    account = new Account("DialplateModel", DataProc::Center(), 0, this);
    account->Subscribe("HostInfo");
    account->SetEventCallback(onEvent);
}

void DialplateModel::Deinit()
{
    if (account)
    {
        delete account;
        account = nullptr;
    }
}

int DialplateModel::onEvent(Account* account, Account::EventParam_t* param)
{
    if (param->event != Account::EVENT_PUB_PUBLISH)
    {
        return Account::RES_UNSUPPORTED_REQUEST;
    }

    if (strcmp(param->tran->ID, "HostInfo") != 0
        || param->size != sizeof(HAL::Host_Info_t))
    {
        return -1;
    }

    DialplateModel* instance = (DialplateModel*)account->UserData;
    memcpy(&(instance->HostInfo), param->data_p, param->size);

    return 0;
}
