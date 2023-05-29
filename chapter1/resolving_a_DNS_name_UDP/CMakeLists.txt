set(SOURCES main.cpp)

set(HEADERS)

set(NAME_PROJECT resolving_a_dns_name_udp)

add_executable(${NAME_PROJECT} ${SOURCES} ${HEADERS})

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
