cmake_minimum_required(VERSION 3.12.0)
project(sob VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE headers CONFIGURE_DEPENDS inc/*.hpp)

add_executable(sob ${sources} ${headers})
target_include_directories(sob PRIVATE ${CMAKE_SOURCE_DIR}/inc)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(sob PRIVATE sfml-system sfml-window sfml-graphics OpenGL)

find_package(spdlog CONFIG REQUIRED)
target_link_libraries(sob PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

find_package(cereal CONFIG REQUIRED)
target_link_libraries(sob PRIVATE cereal::cereal)

if(MSVC)
  target_compile_options(sob PRIVATE /MP /permissive /W4 /w14640 /w14242 /w14254 /w14263 /w14265 /w14287 /we4289 /w14296 /w14311 /w14545 /w14546 /w14547 /w14549 /w14555 /w14619 /w14640 /w14826 /w14905 /w14906 /w14928)
else()
  target_compile_options(sob PRIVATE -Wall -Wextra -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wdouble-promotion -Wformat=2)
endif()
