set(NAME_PROJECT syncUDPClient)

add_executable(${NAME_PROJECT} syncudpclient.h syncudpclient.cpp main.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
