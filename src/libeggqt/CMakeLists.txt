qt_add_library(eggqt STATIC
    lib.cpp
    )

target_link_libraries(eggqt PRIVATE Qt6::Core)
