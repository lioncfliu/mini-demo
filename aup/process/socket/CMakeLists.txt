set(DEP_LIBS "pthread")

add_executable(server server.c)
target_link_libraries(server ${DEP_LIBS})

add_executable(client client.c)
target_link_libraries(client ${DEP_LIBS})


add_executable(socket_pair socket_pair.c)
target_link_libraries(socket_pair ${DEP_LIBS})
