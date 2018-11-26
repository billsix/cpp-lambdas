cmake_minimum_required(VERSION 3.0)
project(cpplambdas)


set(wxWidgets_CONFIGURATION mswu)


find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})




set(cmdline-hello_source
    ./cmdline-hello.cpp
)

add_executable(cmdline-hello ${cmdline-hello_source})


set(cmdline-hello2_source
    ./cmdline-hello2.cpp
)

add_executable(cmdline-hello2 ${cmdline-hello2_source})


set(cmdline-hello3_source
    ./cmdline-hello3.cpp
)

add_executable(cmdline-hello3 ${cmdline-hello3_source})


set(wxapp_source
    ./wxapp.cpp
)

add_executable(wxapp ${wxapp_source})
target_link_libraries(wxapp ${wxWidgets_LIBRARIES})

set(wxapp2_source
    ./wxapp2.cpp
)

add_executable(wxapp2 WIN32 ${wxapp2_source})
target_link_libraries(wxapp2 ${wxWidgets_LIBRARIES})

set(wxapp3_source
    ./wxapp3.cpp
)

add_executable(wxapp3 ${wxapp3_source})
target_link_libraries(wxapp3 WIN32 ${wxWidgets_LIBRARIES})



install(TARGETS cmdline-hello cmdline-hello2 cmdline-hello3 wxapp wxapp2 wxapp3 DESTINATION bin)
