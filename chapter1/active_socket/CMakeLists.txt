set(SOURCES main.cpp
            # functions.cpp
)

# message("source files ${SOURCES}")

set(HEADERS # countries.h
    # functions.h
)

# message("headers ${HEADERS}")

set(MAIN_PROJECT_SRC_LIST main)
# message("main_project_source_list ${MAIN_PROJECT_SRC_LIST}")

include_directories(${Boost_INCLUDE_DIRS})
message("Boost_include_dirs ${Boost_INCLUDE_DIRS}")

set(NAME_PROJECT active_socket)

add_executable(${NAME_PROJECT} ${SOURCES} ${HEADERS})

target_link_libraries(
  ${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} # certlib httplib
)

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
