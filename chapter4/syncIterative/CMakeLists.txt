set(NAME_PROJECT syncIterative)

add_executable(
  ${NAME_PROJECT}
  service.h
  service.cpp
  acceptor.h
  acceptor.cpp
  server.h
  server.cpp
  main.cpp)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
