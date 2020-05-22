set(DEP_LIBS "pthread")
add_executable(thread_cond_mutex thread_cond_mutex.c)
target_link_libraries(thread_cond_mutex ${DEP_LIBS})
