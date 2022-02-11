cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE "vcpkg/scripts/buildsystems/vcpkg.cmake")
set(VCPKG_TARGET_TRIPLET "x64-windows-static")

cmake_policy(SET CMP0091 NEW)

project(OpenCV_Poker)

add_executable(OpenCV_Poker src/Main.cpp src/DataSetCards.cpp src/MatchCards.cpp)

set_property(TARGET OpenCV_Poker PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_compile_options(OpenCV_Poker PRIVATE /Zc:__cplusplus)
target_compile_features(OpenCV_Poker PRIVATE cxx_std_20)

find_package(OpenCV CONFIG REQUIRED)

target_link_libraries(OpenCV_Poker PRIVATE
        ${OpenCV_LIBS})

add_custom_command(TARGET OpenCV_Poker PRE_BUILD
        COMMAND robocopy ${PROJECT_SOURCE_DIR}/resources/ ${PROJECT_BINARY_DIR}/resources /E /NS /NC /NFL /NDL /NP /NJH /NJS  || cmd /c "exit /b 0")
