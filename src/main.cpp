#include "main.h"

static const osThreadAttr_t main_attr = 
{
  .stack_size = 4096U
};

static void threadMain(void *arg);





int main() 
{
  osKernelInitialize();
  osThreadNew(threadMain, NULL, &main_attr);
  osKernelStart();  
  return 0;
}

void threadMain(void *arg) 
{
  hwInit();
  apInit();
  apMain();
}

