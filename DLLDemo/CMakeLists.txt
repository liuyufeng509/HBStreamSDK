project(DLLDemo)
cmake_minimum_required(VERSION 2.8)
set(SRC_LIST errorno.h testdll_global.h main.cpp)
link_libraries(HBStreamSDK)
add_executable(${PROJECT_NAME} ${SRC_LIST})
