set(NAME_PROJECT syncSSLClient)

add_executable(${NAME_PROJECT} main.cpp suncsslclient.cpp suncsslclient.h)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
