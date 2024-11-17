cmake_minimum_required(VERSION 3.15)

include(proj.conf)
find_package(bouffalo_sdk REQUIRED HINTS $ENV{BL_SDK_BASE})
# LiteOS 
sdk_add_subdirectory_ifdef(CONFIG_LITEOS_M liteos_m)

file(GLOB_RECURSE sources "${CMAKE_CURRENT_SOURCE_DIR}/application/*.c")

# Include directories for the application and its components
sdk_add_include_directories(appentry config)
#sdk_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/application/service/wifi)
sdk_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/application/guiguider/custom)
sdk_add_include_directories(${CMAKE_CURRENT_SOURCE_DIR}/application/guiguider/generated)

target_sources(app PRIVATE ${sources})
#加GUIGUIDER宏定义
sdk_add_compile_definitions_ifdef(LV_LVGL_H_INCLUDE_SIMPLE -DLV_LVGL_H_INCLUDE_SIMPLE)
sdk_add_compile_definitions_ifdef(LV_USE_LOG -DLV_USE_LOG)

sdk_set_main_file(appentry/main.c)
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})