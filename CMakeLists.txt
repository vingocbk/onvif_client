cmake_minimum_required(VERSION 3.20)
project(onvifclinet LANGUAGES CXX)
add_executable(app)
target_sources(app PUBLIC src/main.cpp libOnvif/stdsoap2.cpp)
set(CXXFLAGS "-DWITH_OPENSSL -Wall -g -DWITH_DOM -DWITH_ZLIB -I. -lcrypto -lssl -lz -ljsoncpp -lpthread -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXXFLAGS}")
message(${CMAKE_CXX_FLAGS})
target_compile_options (app PUBLIC -Wall -g -I.)
target_compile_features (app PUBLIC cxx_std_11)
target_compile_definitions (app PUBLIC WITH_OPENSSL WITH_DOM WITH_ZLIB)
target_link_libraries (app PUBLIC crypto ssl z jsoncpp pthread)
include_directories(app PUBLIC 
                                "${PROJECT_SOURCE_DIR}"
                                "${PROJECT_SOURCE_DIR}/libOnvif"
                                "${PROJECT_SOURCE_DIR}/include")
add_subdirectory("libOnvif")
target_link_libraries(app PUBLIC onvif)
# add_subdirectory("include")