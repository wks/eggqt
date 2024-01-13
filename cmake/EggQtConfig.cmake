include("${CMAKE_CURRENT_LIST_DIR}/EggQtTargets.cmake")

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

find_package(Boost REQUIRED COMPONENTS coroutine)
find_package(fmt REQUIRED)
