# Generated CMake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Adicione estas linhas para incluir o Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(Semaforo)

# Inicialize o SDK do Pico
pico_sdk_init()

add_executable(Semaforo
    semaforo.c
)

# Adicione as bibliotecas necessárias
target_link_libraries(Semaforo pico_stdlib)

# Crie o arquivo UF2
pico_add_extra_outputs(Semaforo)
