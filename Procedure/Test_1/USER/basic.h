#ifndef __BASIC_H
#define __BASIC_H

#include <stdint.h>
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "dout.h"
#include "pwm.h"
#include "tim.h"
#include "rs422.h"
#include "spi.h"
#include "max31856.h"
#include "adc.h"
#include "input.h"

#define Max318561EN  1
#define Max318562EN  0

void AllInit(void);//全部初始化

#endif
