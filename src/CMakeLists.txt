add_executable(main
        Lottery.cpp
        ../include/Lottery.h
        main.cpp
        Staff.cpp
        ../include/Staff.h
        )
target_link_libraries(main pthread)

