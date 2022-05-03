#include "bsp.h"
#include "hw_def.h"
#include "RTE_Components.h"
#include  CMSIS_device_header


#define PLL_SYS_KHZ (133 * 1000)




bool bspInit(void)
{  
  set_sys_clock_khz(PLL_SYS_KHZ, true);

  // configure the specified clock
  clock_configure(
      clk_peri,
      0,                                                // No glitchless mux
      CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, // System PLL on AUX mux
      PLL_SYS_KHZ * 1000,                               // Input frequency
      PLL_SYS_KHZ * 1000                                // Output (must be same as no divider)
  );

  SystemCoreClockUpdate();
  stdio_init_all();
  
  return true;
}

void delay(uint32_t time_ms)
{  
  #ifdef _USE_HW_RTOS
  osDelay(time_ms);
  #else
  sleep_ms(time_ms);
  #endif
}

uint32_t millis(void)
{  
  return to_ms_since_boot(get_absolute_time());
}