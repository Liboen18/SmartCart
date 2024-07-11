/*
 * sys.c
 *
 *  Created on: 2024��7��5��
 *      Author: ��Ԫ
 */
#include "sys.h"
void gpio_toggle_pin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
  uint32_t odr;

  odr = GPIOx->OUTDR;

  GPIOx->BSHR = ((odr & GPIO_Pin) << 16U) | (~odr & GPIO_Pin);
}

/**
 * @brief       �ر������ж�
 * @param       ��
 * @retval      ��
 */
void sys_intx_disable(void)
{
    __disable_irq();
}

/**
 * @brief       ���������ж�
 * @param       ��
 * @retval      ��
 */
void sys_intx_enable(void)
{
    __enable_irq();
}

/**
 * @brief       ִ��: WFIָ��(ִ�����ָ�����͹���״̬, �ȴ��жϻ���)
 * @param       ��
 * @retval      ��
 */
void sys_wfi_set(void)
{
    __asm volatile("wfi");
}



