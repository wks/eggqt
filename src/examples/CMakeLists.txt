add_executable(hello
    hello.cpp
    )

target_include_directories(hello
    PRIVATE
    ../libeggqt
    )

target_link_libraries(hello
    eggqt
    )
