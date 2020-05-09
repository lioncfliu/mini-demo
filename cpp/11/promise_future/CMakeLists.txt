
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set(DEP_LIBS "pthread")


add_executable(demo_promise_simple demo_promise_simple_01.cpp)
target_link_libraries(demo_promise_simple ${DEP_LIBS})

add_executable(demo_promise_move demo_promise_move_01.cpp)
target_link_libraries(demo_promise_move ${DEP_LIBS})

add_executable(demo_promise_exception demo_promise_exception_01.cpp)
target_link_libraries(demo_promise_exception ${DEP_LIBS})
