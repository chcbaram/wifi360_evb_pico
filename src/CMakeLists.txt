
add_subdirectory(lib/WizFi360-EVB-Pico-C)


file(GLOB SRC_FILES CONFIGURE_DEPENDS
  *.cpp
)

file(GLOB_RECURSE SRC_FILES_RECURSE CONFIGURE_DEPENDS
  ap/*.cpp
  bsp/*.c
  common/*.c
  hw/*.c
)


add_executable(
  ${PRJ_NAME}

  ${SRC_FILES}
  ${SRC_FILES_RECURSE}
)

target_include_directories(${PRJ_NAME} PUBLIC 
  ap
  ap/include
  bsp
  common 
  common/core
  common/hw/include 
  hw

  ${PORT_DIR}/FreeRTOS-Kernel/inc

)
message(PORT_DIR "PORT_DIR = ${PORT_DIR}")

target_link_libraries(${PRJ_NAME} 
  pico_stdlib
  pico_multicore

  cmsis_core
  CMSIS_FREERTOS_FILES
  hardware_spi
  hardware_dma
  FREERTOS_FILES
  TIMER_FILES
  WIZFI360_FILES
  IOT_SOCKET_FILES
  )

pico_add_extra_outputs(${PRJ_NAME})
pico_enable_stdio_usb(${PRJ_NAME}  1)
pico_enable_stdio_uart(${PRJ_NAME} 0)

set_target_properties(${PRJ_NAME} PROPERTIES SUFFIX ".elf")
add_custom_command(TARGET ${PRJ_NAME} POST_BUILD
        COMMAND arm-none-eabi-size --format=berkeley --totals "$<TARGET_FILE:${PRJ_NAME}>"
        COMMENT "Invoking: Cross ARM GNU Print Size")