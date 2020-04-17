add_executable(unittest
        ../src/Lottery.cpp
        ../include/Lottery.h
        ../src/Staff.cpp
        ../include/Staff.h
        unittest.cpp)

target_link_libraries(unittest gtest gtest_main pthread)

