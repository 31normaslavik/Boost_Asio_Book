cmake_minimum_required(VERSION 3.25)

project(Boost_Asio_Book LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -Wpedantic
# -Wno-unused-parameter")

message("cmake_cxx_standard ${CMAKE_CXX_STANDARD}")

set(Boost_USE_STATIC_LIBS ON) # only find static libs
set(Boost_USE_DEBUG_LIBS ON) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS OFF) # only find release libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(
  Boost 1.82.0
  COMPONENTS # thread
  REQUIRED)

find_package(OpenSSL)
set(OPENSSL_USE_STATIC_LIBS ON)

message("Boost_libraries ${Boost_LIBRARIES}")
message("openssl_libraries ${OPENSSL_LIBRARIES}")

add_subdirectory(chapter1)
add_subdirectory(chapter2)
