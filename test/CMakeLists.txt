include(cmake/catch2_setup.cmake)

add_executable(${PROJECT_NAME}-test test/main.cc)

target_link_libraries(${PROJECT_NAME}-test PRIVATE Catch2::Catch2)
target_link_libraries(${PROJECT_NAME}-test PRIVATE Qt6::Widgets)