set(NAME_PROJECT HTTPClient)

add_executable(${NAME_PROJECT} main.cpp httpclient.cpp httpclient.h
                               http_errors.h http_errors.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
