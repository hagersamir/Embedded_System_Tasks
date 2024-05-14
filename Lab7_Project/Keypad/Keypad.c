

#include "Keypad.h"
#include "Gpio.h"

void Keypad_Init(void)
{
    // config columns
    for (uint8 index = COL_START_INDEX; index <= COL_END_INDEX; index++)
    {
        Gpio_ConfigPin(COL_PORT, index, GPIO_INPUT, GPIO_PULL_UP);
    }
    for (uint8 index = ROW_START_INDEX; index <= ROW_END_INDEX; index++)
    {
        Gpio_ConfigPin(ROW_PORT, index, GPIO_OUTPUT, GPIO_PUSH_PULL);
    }
}

void Keypad_Manange(void)
{
    for (uint8 i = 0; i < no_row; i++)
    {
        for (uint8 i = 0; i < no_row; i++)
        {
            Gpio_WritePin(ROW_PORT, rows[i], 1); // deactivate all rows intially
        }
        Gpio_WritePin(ROW_PORT, rows[i], 0); // activate desired row
        for (uint8 j = 0; j < no_col; j++)
        {
            char key = Gpio_ReadPin(COL_PORT, cols[j]);
            if (key == 0)
            {
                while (Gpio_ReadPin(COL_PORT, cols[j]) == 0)
                    ;
                Current_key = LookUp_table[i][j];
                KeypadCallout_KeyPressNotificaton();
            }
        }
    }
}

uint8 Keypad_GetKey(void)
{
    return Current_key;
}



