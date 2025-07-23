cmake_minimum_required(VERSION 3.10)
project(P2POverlay)

set(CMAKE_CXX_STANDARD 17)

find_package(Poco REQUIRED Net Util Foundation)

add_executable(P2POverlay main.cpp)
target_link_libraries(P2POverlay PRIVATE Poco::Net Poco::Util Poco::Foundation)
