set(NAME_PROJECT binding_a_socket_tcp_passive)

add_executable(${NAME_PROJECT} main.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
