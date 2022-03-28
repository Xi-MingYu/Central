#ifndef __HAL_DEF_H
#define __HAL_DEF_H

#include <stdint.h>

namespace HAL
{

/* Clock */
typedef struct
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t week;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint16_t millisecond;
} Clock_Info_t;

/* Power */
typedef struct
{
    uint16_t voltage;
    uint8_t usage;
    bool isCharging;
} Power_Info_t;

/* Host */
    typedef struct
    {
        float Usage_CPU;
        float Tem_CPU;
        float Usage_GPU;
        float Tem_GPU;
        float Usage_RAM;
        uint8_t FPS;
    } Host_Info_t;


}

#endif
