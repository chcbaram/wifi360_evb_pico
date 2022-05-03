# CMake minimum required version
cmake_minimum_required(VERSION 3.12)


include(wizfi360_evb_pico_c-patch.cmake)
include(wizfi360_evb_pico_c_sdk_version.cmake)


# Set the project root directory if it's not already defined, as may happen if
# the tests folder is included directly by a parent project, without including
# the top level CMakeLists.txt.

if(NOT DEFINED CMSIS_5_DIR)
    set(CMSIS_5_DIR ${CMAKE_SOURCE_DIR}/external/CMSIS_5)
    message(STATUS "CMSIS_5_DIR = ${CMSIS_5_DIR}")
endif()

if(NOT DEFINED CMSIS_FREERTOS_DIR)
    set(CMSIS_FREERTOS_DIR ${CMAKE_SOURCE_DIR}/external/CMSIS-FreeRTOS/CMSIS/RTOS2/FreeRTOS)
    message(STATUS "CMSIS_FREERTOS_DIR = ${CMSIS_FREERTOS_DIR}")
endif()

if(NOT DEFINED WIZFI360_DRIVER_DIR)
    set(WIZFI360_DRIVER_DIR ${CMAKE_SOURCE_DIR}/external/CMSIS-Driver/WiFi/WizFi360)
    message(STATUS "WIZFI360_DRIVER_DIR = ${WIZFI360_DRIVER_DIR}")
endif()

if(NOT DEFINED FREERTOS_DIR)
    set(FREERTOS_DIR ${CMAKE_SOURCE_DIR}/external/CMSIS-FreeRTOS/Source)
    message(STATUS "FREERTOS_DIR = ${FREERTOS_DIR}")
endif()

if(NOT DEFINED WIZNET_DIR)
    set(WIZNET_DIR ${CMAKE_SOURCE_DIR}/external/ioLibrary_Driver)
    message(STATUS "WIZNET_DIR = ${WIZNET_DIR}")
endif()

if(NOT DEFINED MBEDTLS_DIR)
    set(MBEDTLS_DIR ${CMAKE_SOURCE_DIR}/external/mbedtls)
    message(STATUS "MBEDTLS_DIR = ${MBEDTLS_DIR}")
endif()

if(NOT DEFINED PORT_DIR)
    set(PORT_DIR ${CMAKE_SOURCE_DIR}/src/lib/WizFi360-EVB-Pico-C/port)
    message(STATUS "PORT_DIR = ${PORT_DIR}")
endif()

if(NOT DEFINED IOT_SOCKET_DIR)
    set(IOT_SOCKET_DIR ${CMAKE_SOURCE_DIR}/external/IoT_Socket)
    message(STATUS "IOT_SOCKET_DIR = ${IOT_SOCKET_DIR}")
endif()

# Turn off mbedtls test mode 
set(ENABLE_PROGRAMS OFF CACHE BOOL "Build mbedtls programs")
set(ENABLE_TESTING OFF CACHE BOOL "Build mbedtls testing")
add_definitions(-DMBEDTLS_CONFIG_FILE="${PORT_DIR}/mbedtls/inc/ssl_config.h")
add_definitions(-DSET_TRUSTED_CERT_IN_SAMPLES)
add_definitions(-DDRIVER_WIFI_NUM=1)

# Add libraries in subdirectories
#add_subdirectory(${MBEDTLS_DIR})
add_subdirectory(${PORT_DIR})
