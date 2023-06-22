
set(NAME_PROJECT syncTCPClient)

add_executable(${NAME_PROJECT} main.cpp
    synctcpclient.h synctcpclient.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
