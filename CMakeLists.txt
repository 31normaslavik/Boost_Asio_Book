cmake_minimum_required(VERSION 3.20)

project(Boost_Asio_Book LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++20 -Wall -Wextra -Wpedantic -Wno-unused-parameter"
)

message("cmake_cxx_standard ${CMAKE_CXX_STANDARD}")

set(SOURCES main.cpp
            # functions.cpp
)

message("source files ${SOURCES}")

set(HEADERS # countries.h
    # functions.h
)

message("headers ${HEADERS}")

set(MAIN_PROJECT_SRC_LIST main)
message("main_project_source_list ${MAIN_PROJECT_SRC_LIST}")

# add_subdirectory(sync-ssl)

set(Boost_USE_STATIC_LIBS ON) # only find static libs
set(Boost_USE_DEBUG_LIBS ON) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS OFF) # only find release libs
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(
  Boost 1.82.0
  COMPONENTS # thread
  REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
message("Boost_include_dirs ${Boost_INCLUDE_DIRS}")

find_package(OpenSSL)
set(OPENSSL_USE_STATIC_LIBS ON)

# add_subdirectory(cert) add_subdirectory(sync-ssl)

add_executable(boost_asio_book ${SOURCES} ${HEADERS})

target_link_libraries(
  boost_asio_book ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} # certlib httplib
)
message("Boost_libraries ${Boost_LIBRARIES}")
message("openssl_libraries ${OPENSSL_LIBRARIES}")

install(TARGETS boost_asio_book LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
