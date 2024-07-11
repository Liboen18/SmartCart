/*
 * sys.h
 *
 *  Created on: 2024��7��5��
 *      Author: ��Ԫ
 */

#ifndef USER_SYS_H_
#define USER_SYS_H_
#include "ch32v30x.h"
#include "stdio.h"

/**
 * SYS_SUPPORT_OS���ڶ���ϵͳ�ļ����Ƿ�֧��OS
 * 0,��֧��OS
 * 1,֧��OS
 */
#define SYS_SUPPORT_OS          0

/********************************************************************************************/

void gpio_toggle_pin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);                   /* �л����ŵ�ƽ */
void sys_intx_disable(void);                                                    /* �ر������ж� */
void sys_intx_enable(void);                                                     /* ���������ж� */
void sys_wfi_set(void);


#endif /* USER_SYS_H_ */
