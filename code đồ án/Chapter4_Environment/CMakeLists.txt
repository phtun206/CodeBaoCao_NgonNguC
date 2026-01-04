cmake_minimum_required(VERSION 3.13)
project(bare VERSION 1.0.6)

enable_language(C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Toolchain
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")
set(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")

# Cờ biên dịch
set(CDEFS "-DUSE_HAL_DRIVER -DSTM32F072xB")
set(MCU "-mcpu=cortex-m0 -mthumb")
set(COMMON_FLAGS "${MCU} ${CDEFS} -fdata-sections -ffunction-sections -Wall -Wextra")

set(CMAKE_C_FLAGS "${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -fno-exceptions -fno-rtti -fno-threadsafe-statics")

# Thư mục include
include_directories(
    ${CMAKE_SOURCE_DIR}/platform/inc
    ${CMAKE_SOURCE_DIR}/platform/CMSIS/Device/ST/STM32F0xx/Include
    ${CMAKE_SOURCE_DIR}/platform/CMSIS/Include
    ${CMAKE_SOURCE_DIR}/platform/STM32F0xx_HAL_Driver/Inc
    ${CMAKE_SOURCE_DIR}/app/inc
    ${CMAKE_SOURCE_DIR}/hal/uart/inc
    ${CMAKE_SOURCE_DIR}/hal/inc
)

# Mục tiêu
set(EXECUTABLE ${PROJECT_NAME}.elf)
add_executable(${EXECUTABLE}
    platform/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.c
    platform/startup_stm32f072xb.s
    app/src/main.cpp
    hal/uart/src/uart_stm32.cpp
)

# Liên kết
target_link_options(${EXECUTABLE} PUBLIC
    -T${CMAKE_SOURCE_DIR}/platform/STM32F072C8Tx_FLASH.ld
    -mcpu=cortex-m0 -mthumb
    -specs=nano.specs
    -Wl,--gc-sections
)