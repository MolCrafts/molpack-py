cmake_minimum_required(VERSION 3.16)

project(molpackcpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MOLPACK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/external/molpack)
set(BINDER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/binder)

add_subdirectory(${MOLPACK_PATH})
add_subdirectory(${BINDER_PATH})

target_include_directories(molpackcpp PRIVATE extern/molpack/include)
target_link_libraries(molpackcpp PRIVATE molpack)

set_target_properties(molpackcpp PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/molpack
)

# install(
#     TARGETS molpackcpp
#     LIBRARY DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/src/molpack
# )