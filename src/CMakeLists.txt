cmake_minimum_required(VERSION 3.25)

add_executable(${PROJECT_NAME} main.cpp
                               ConverterJSON.cpp
                               SearchServer.cpp
                               InvertedIndex.cpp
                               SearchExeption.cpp
                               Handlers.cpp
                               ${INCLUDE_DIR}/main.h
                               ${INCLUDE_DIR}/Handlers.h
                               ${INCLUDE_DIR}/ConverterJSON.h
                               ${INCLUDE_DIR}/SearchServer.h
                               ${INCLUDE_DIR}/InvertedIndex.h
                               ${INCLUDE_DIR}/SearchExeption.h
                               )

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)


