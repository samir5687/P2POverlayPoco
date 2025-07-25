cmake_minimum_required(VERSION 3.10)
project(P2POverlayPoco)

set(CMAKE_CXX_STANDARD 17)

find_package(Poco REQUIRED Foundation Net Util)

include_directories(${Poco_INCLUDE_DIRS})

add_executable(P2POverlay
    main.cpp
    ServerManager.cpp
)

target_link_libraries(P2POverlay
    Poco::Foundation
    Poco::Net
    Poco::Util
)

add_executable(ClientApp
    main_client.cpp
    client.cpp
)

target_link_libraries(ClientApp
    Poco::Foundation
    Poco::Net
)