/*
 * MIT License
 * Copyright (c) 2021 _VIFEXTech
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __HAL_INTERNAL_H
#define __HAL_INTERNAL_H

#include "Arduino.h"
#include "HAL_Def.h"
#include "Configs/Configs.h"
#include "CommonMacro.h"
#include "FreeRTOS.h"

namespace HAL
{
    void Init();
    void Update();

    /* Backlight */
    void Backlight_Init();
    uint32_t Backlight_GetValue();
    void Backlight_SetValue(int32_t val);
    void Backlight_SetGradual(uint32_t target, uint16_t time = 500);
    void Backlight_ForceLit(bool en);

    /* Power */
    void Power_Init();
    void Power_HandleTimeUpdate();
    void Power_SetAutoLowPowerTimeout(uint16_t sec);
    uint16_t Power_GetAutoLowPowerTimeout();
    void Power_SetAutoLowPowerEnable(bool en);
    void Power_Shutdown();
    void Power_Update();
    void Power_EventMonitor();
    void Power_GetInfo(Power_Info_t* info);
    typedef void(* Power_CallbackFunction_t)(void);
    void Power_SetEventCallback(Power_CallbackFunction_t callback);

    /* Bluetooth */
    bool BT_Init();
    void BT_Update();

    /* Encoder */
    void Encoder_Init();
    void Encoder_Update();
    int16_t Encoder_GetDiff();
    bool Encoder_GetIsPush();
    void Encoder_SetEnable(bool en);


}

#endif
