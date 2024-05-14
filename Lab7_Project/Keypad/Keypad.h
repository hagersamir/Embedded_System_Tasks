#ifndef KEYPAD_H
#define KEYPAD_H

#include "Gpio.h"

#include "Std_Types.h"
#define ROW_PORT GPIO_B
#define ROW_START_INDEX 0
#define ROW_END_INDEX 3

#define COL_PORT GPIO_B
#define COL_START_INDEX 8
#define COL_END_INDEX 10

#define no_row 4
#define no_col 3

static char rows[4] = {0,1,2,3};
static char cols[3] = {8,9,10};
static char LookUp_table[4][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {0, 0,0}};

static char Current_key;

// provided api functions
void Keypad_Init(void);

void Keypad_Manange(void);

uint8 Keypad_GetKey(void);

// required function implemented by applicaiton
void KeypadCallout_KeyPressNotificaton();

#endif /* KEYPAD_H */
