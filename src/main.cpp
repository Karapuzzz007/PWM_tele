#include <libopencm3/stm32/timer.h> 
#include <libopencm3/stm32/rcc.h> 
#include <libopencm3/stm32/gpio.h> 
#include <libopencm3/cm3/common.h> 
#include <libopencm3/cm3/systick.h> 
 
void clock_setup(void) { 
    /* Включаем тактирование GPIOA и TIM2 */ 
    rcc_periph_clock_enable(RCC_GPIOA); 
    rcc_periph_clock_enable(RCC_TIM2); 
} 
 
void gpio_setup(void) { 
    /* Настраиваем PA0 (TIM2_CH1) как альтернативную функцию */ 
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO0); 
    gpio_set_af(GPIOA, GPIO_AF1, GPIO0); // TIM2_CH1 
} 
 
void timer_setup(void) { 
    /* Настраиваем таймер TIM2 для генерации ШИМ */ 
    timer_disable_counter(TIM2); 
     
    /* Устанавливаем предделитель и период */ 
    timer_set_prescaler(TIM2, 0); // Предделитель
    timer_set_period(TIM2, 1000); // Период 
 
    /* Настраиваем режим ШИМ */ 
    timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1); 
    timer_enable_oc_output(TIM2, TIM_OC1); 
     
    /* Устанавливаем начальное значение ШИМ */ 
    timer_set_oc_value(TIM2, TIM_OC1, 800); //скважность 
 
    /* Включаем таймер */ 
    timer_enable_counter(TIM2); 
} 
 
int main(void) { 
    clock_setup(); 
    gpio_setup(); 
    timer_setup(); 
 
    while (1) { 

    } 
 
    return 0; 
}
