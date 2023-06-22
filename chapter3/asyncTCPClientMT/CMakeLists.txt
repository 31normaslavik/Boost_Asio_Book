
set(NAME_PROJECT asyncTCPClientMT)

add_executable(${NAME_PROJECT} main.cpp
    session.h session.cpp
    asynctcpclient.h asynctcpclient.cpp
    function.h function.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
