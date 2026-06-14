add_library(cliexecutor executor.c)

target_include_directories(cliexecutor
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(cliexecutor PRIVATE types)