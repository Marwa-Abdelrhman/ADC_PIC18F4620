/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"
//#include"MCAL_Layer/EEPROM/hal_eeprom.h"
#include"MCAL_Layer/Interrupt/mcal_external_interrupt.h"
#include"MCAL_Layer/ADC/hal_adc.h"
#include"ECU_Layer/Char_LCD/ecu_char_LDC.h"

lcd_t lcd_1={
    .en_pin.port=PORTC_INDEX,
    .en_pin.pin=GPIO_PIN1,
    .en_pin.direction=GPIO_DIRECTION_OUTPUT,
    .en_pin.state=GPIO_STATE_LOW,
    
    .rs_pin.port=PORTC_INDEX,
    .rs_pin.pin=GPIO_PIN0,
    .rs_pin.direction=GPIO_DIRECTION_OUTPUT,
    .rs_pin.state=GPIO_STATE_LOW,
    
   
    .lcd_8bit_pins[0].port=PORTC_INDEX,
    .lcd_8bit_pins[0].pin=GPIO_PIN2,
    .lcd_8bit_pins[0].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[0].state=GPIO_STATE_LOW,
    
    .lcd_8bit_pins[1].port=PORTC_INDEX,
    .lcd_8bit_pins[1].pin=GPIO_PIN3,
    .lcd_8bit_pins[1].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[1].state=GPIO_STATE_LOW,
    
    .lcd_8bit_pins[2].port=PORTC_INDEX,
    .lcd_8bit_pins[2].pin=GPIO_PIN4,
    .lcd_8bit_pins[2].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[2].state=GPIO_STATE_LOW,
    
    .lcd_8bit_pins[3].port=PORTC_INDEX,
    .lcd_8bit_pins[3].pin=GPIO_PIN5,
    .lcd_8bit_pins[3].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[3].state=GPIO_STATE_LOW,
            
    .lcd_8bit_pins[4].port=PORTC_INDEX,
    .lcd_8bit_pins[4].pin=GPIO_PIN6,
    .lcd_8bit_pins[4].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[4].state=GPIO_STATE_LOW,
    
    .lcd_8bit_pins[5].port=PORTC_INDEX,
    .lcd_8bit_pins[5].pin=GPIO_PIN7,
    .lcd_8bit_pins[5].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[5].state=GPIO_STATE_LOW,
    
    .lcd_8bit_pins[6].port=PORTD_INDEX,
    .lcd_8bit_pins[6].pin=GPIO_PIN0,
    .lcd_8bit_pins[6].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[6].state=GPIO_STATE_LOW,
    
    .lcd_8bit_pins[7].port=PORTD_INDEX,
    .lcd_8bit_pins[7].pin=GPIO_PIN1,
    .lcd_8bit_pins[7].direction=GPIO_DIRECTION_OUTPUT,
    .lcd_8bit_pins[7].state=GPIO_STATE_LOW
};
adc_t adc_1={//.ADC_Interrupt_Handler=NULL,
                .acqui_time=ADC_12_TAD,
                .chnl=ADC_CHANNEL_AN0,
                .conv_clk=ADC_CONVERSION_CLOCK_FOSC_DIV_16,
                .result_format=ADC_RESULT_TO_RIGHT,
                .voltage_cfg=ADC_DISABLE_VOLT_REF

};
uint16 lm35_res,lm35_C;
uint8 lm35_txt[7];

Std_RetrunType ret=E_NOK;


int main() {
    app_init();
    ret=lcd_send_string_data_position(&lcd_1,"LM35 Temp Test",1,5);
    
    ret=lcd_send_string_data_position(&lcd_1,"Temperature = ",2,1);
    while(1){                  
        ret=ADC_get_conversion_result_blocking(&adc_1,ADC_CHANNEL_AN0,&lm35_res);
        lm35_C=(lm35_res*4.88)/10;
        ret=convert_uint16_to_string(lm35_C,lm35_txt);
        ret=lcd_send_string_data_position(&lcd_1,lm35_txt,2,15);
       
    }
        return (EXIT_SUCCESS);
}

void app_init(void){
 
     
    //ecu_layer_initialize();
    ret=ADC_Init(&adc_1);
    ret=lcd_init(&lcd_1);
     
}
