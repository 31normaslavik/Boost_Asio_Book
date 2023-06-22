set(NAME_PROJECT connecting_a_socket_dns_name)

add_executable(${NAME_PROJECT} main.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
