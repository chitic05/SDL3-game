cmake_minimum_required(VERSION 3.8)
project(SDL3_Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

include(FetchContent)

add_subdirectory(externals/SDL3-3.2.22)
# Sources
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${MY_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/includes/"
    "${CMAKE_CURRENT_SOURCE_DIR}/externals/json-develop/single_include" #include json
    "${CMAKE_CURRENT_SOURCE_DIR}/externals/stb-master/" #include stb_master for images
)

# Link SDL3 and SDL3_image
target_link_libraries(${PROJECT_NAME} PRIVATE  SDL3::SDL3)

# Copy resources (optional)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res
)
