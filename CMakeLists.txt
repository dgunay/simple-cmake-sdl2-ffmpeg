# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
# set (CMAKE_TOOLCHAIN_FILE "/usr/vcpkg/scripts/buildsystems/vcpkg.cmake")
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

include_directories(/home/linuxbrew/.linuxbrew/include)
link_directories(/home/linuxbrew/.linuxbrew/lib)

project(trycmake)

include_directories(include src)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

find_package(SDL2 REQUIRED COMPONENTS SDL2::SDL2)

# ffmpeg
# wow so I guess it works like this under the hood, it's calling pkg-config to
# show where the linker should link. e.g. if I do this in the shell:
# $ pkg-config --libs libavformat
# I get "-L/home/linuxbrew/.linuxbrew/Cellar/ffmpeg/4.4_1/lib -lavformat"
# That's pretty cool
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET libavformat libavutil)
pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)



# find_path(AVFORMAT_INCLUDE_DIR libavformat/avformat.h)
# find_library(AVFORMAT_LIBRARY avformat)

add_executable(myprogram ${SOURCES} ${HEADERS})
target_link_libraries(myprogram PkgConfig::SDL2 PkgConfig::LIBAV)