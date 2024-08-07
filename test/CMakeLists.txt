include(cmake/catch2_setup.cmake)
include(cmake/path.cmake)

add_executable(${PROJECT_NAME}-test test/main.cc test/test_DataModel.cc ${SOURCE_PATH} ${HEADER_PATH})

target_link_libraries(${PROJECT_NAME}-test PRIVATE Catch2::Catch2)
target_link_libraries(${PROJECT_NAME}-test PRIVATE Qt6::Widgets)