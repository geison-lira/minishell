add_library(cliprompt prompt.c)

target_include_directories(cliprompt
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(cliprompt PRIVATE types)