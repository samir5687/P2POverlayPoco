cmake_minimum_required(VERSION 3.10)
project(P2POverlayPoco)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Poco libraries
find_package(Poco REQUIRED Net Util Foundation)

# Server executable
add_executable(P2POverlayPoco
    main.cpp
    client.cpp
    client.h
)

target_link_libraries(P2POverlayPoco
    Poco::Net
    Poco::Util
    Poco::Foundation
)

# Client executable
add_executable(ClientApp
    ClientApp.cpp
)

target_link_libraries(ClientApp
    Poco::Net
    Poco::Util
    Poco::Foundation
)
