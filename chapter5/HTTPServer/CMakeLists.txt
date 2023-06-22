
set(NAME_PROJECT HTTPServer)

add_executable(
  ${NAME_PROJECT}
  main.cpp
  service.cpp
  acceptor.cpp
  server.cpp
  service.h
  acceptor.h
  server.h)

target_link_libraries(${NAME_PROJECT} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})

install(TARGETS ${NAME_PROJECT} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
