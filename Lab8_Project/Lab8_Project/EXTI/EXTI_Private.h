#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#include "Utils.h"

// #define EXTI_BASE_ADDR 0x40013C00
typedef struct 
{
    uint32 MEMRMP;
	uint32 PMC;
    uint32 EXTICR1; // from 0:3
    uint32 EXTICR2; // from 4:7
    uint32 EXTICR3; // from 8:11
    uint32 EXTICR4; // from 12:15
    uint32 CMPCR;
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
#define SYSCFG_EXTICR1 (*(uint32*) (0x40013800 + 0x08))
#define SYSCFG_EXTICR2 (*(uint32*) (0x40013800 + 0x0C))
#define SYSCFG_EXTICR3 (*(uint32*) (0x40013800 + 0x10))
#define SYSCFG_EXTICR4 (*(uint32*) (0x40013800 + 0x14))
#endif /* EXTI_PRIVATE_H */
