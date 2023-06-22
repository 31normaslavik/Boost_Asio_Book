set(NAME_PROJECT creating_an_active_socket_tcp_ipv4)

add_executable(${NAME_PROJECT} main.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
