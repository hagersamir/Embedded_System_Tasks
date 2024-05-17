#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "Utils.h"

// #define EXTI_BASE_ADDR 0x40013C00
typedef struct 
{
    uint32 EXTICR1; // from 0:3
    uint32 EXTICR2; // from 4:7
    uint32 EXTICR3; // from 8:11
    uint32 EXTICR4; // from 12:15
}SyscfgType;

typedef struct
{
    uint32 IMR;   // Interrupt mask register
    uint32 EMR;   // Event mask register
    uint32 RTSR;  // Rising trigger selection register
    uint32 FTSR;  // Falling trigger selection register
    uint32 SWIER; // Software interrupt event register
    uint32 PR;    // Pending register
} ExtiType;


#define SYSCFG ((SyscfgType *)0x40013800)
#define EXTI ((ExtiType *)0x40013C00)

#endif /* EXTI_PRIVATE_H */
