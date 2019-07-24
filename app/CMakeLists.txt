cmake_minimum_required(VERSION 3.4.1)
include_directories(${ANDROID_NDK}/sources/android/native_app_glue)
add_library(
        TestLib
        SHARED
        src/main/cpp/main.cpp
        )
add_library(
        glue
        STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c
)
target_link_libraries(
        TestLib
        log
        android
        glue
        )