cmake_minimum_required(VERSION 3.28)
project(embedded_systems C)

set(CMAKE_CXX_COMPILER "/usr/bin/clang-17")
set(CMAKE_C_STANDARD 90)

add_executable(embedded_systems
        hardware/stepper_motor.c
        hardware/LPC17xx.h
        hardware/seven_segment_display.c
        hardware/buzzer.c
        hardware/pulse_width_modulation.c
        hardware/key_pad.c
        hardware/lcd.h
        hardware/external_interrupt.c
)
