cmake_minimum_required(VERSION 3.25)

project(google_tests LANGUAGES CXX)




add_executable(google_tests
                            InvertedIndexTest.cpp
                            SearchServerTest.cpp
                            ${INCLUDE_DIR}/SearchServer.h
                            ${INCLUDE_DIR}/InvertedIndex.h
                            ${SOURCE_DIR}/SearchServer.cpp
                            ${SOURCE_DIR}/InvertedIndex.cpp
                            )

target_link_libraries(google_tests PRIVATE gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(google_tests)

target_include_directories(google_tests PUBLIC ${INCLUDE_DIR})
target_include_directories(google_tests PUBLIC ${SOURCE_DIR})
target_link_libraries(google_tests PRIVATE nlohmann_json::nlohmann_json)
