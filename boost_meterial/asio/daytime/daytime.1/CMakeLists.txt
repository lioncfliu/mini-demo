include_directories("/usr/local/include")
link_directories("/usr/local/lib")

SET(TARGET "dayteime-client")
aux_source_directory(. SRC_DIR)

SET(DEP_LIBS "boost_chrono")
list(APPEND DEP_LIBS "boost_thread")
add_executable(${TARGET} ${SRC_DIR})
target_link_libraries(${TARGET} ${DEP_LIBS})
