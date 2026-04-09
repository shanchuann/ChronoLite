add_executable(chronolite LogFileTest.cpp ${SRC_LOG})

target_link_libraries(chronolite pthread)