
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(DEP_LIBS "pthread")


add_executable(demo_simple demo_simple.cpp)
target_link_libraries(demo_simple ${DEP_LIBS})

add_executable(demo_constructor demo_constructor.cpp)
target_link_libraries(demo_constructor ${DEP_LIBS})

add_executable(demo_mutex demo_mutex.cpp)
target_link_libraries(demo_mutex ${DEP_LIBS})

add_executable(demo_time_mutex demo_time_mutex.cpp)
target_link_libraries(demo_time_mutex ${DEP_LIBS})

add_executable(demo_lock_guard demo_lock_guard.cpp)
target_link_libraries(demo_lock_guard ${DEP_LIBS})

add_executable(demo_unique_lock demo_unique_lock.cpp)
target_link_libraries(demo_unique_lock ${DEP_LIBS})
