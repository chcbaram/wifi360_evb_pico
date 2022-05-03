#include "ap.h"


static void cliThread(void *arg);

const osThreadAttr_t cli_attr = { .stack_size = 4096 };


void apInit(void) 
{  
  cliOpen(_DEF_UART1, 115200);

  osThreadNew(cliThread, NULL, &cli_attr);
}

void apMain(void) 
{
  uint32_t millis();
  while(1)
  {
    ledToggle(_DEF_LED1);
    delay(500);
  }
}

void cliThread(void *arg) 
{  
  while(1)
  {
    cliMain();
    osDelay(1);
  }
}