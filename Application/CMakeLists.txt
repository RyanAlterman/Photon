cmake_minimum_required(VERSION 3.31.4)

project(Application CXX)

set(srcFiles
    "src/Main.cpp"
)

set(includeDirs
    "../Photon/src"
)

set(externalLibs
    "Photon"
)

add_executable(${PROJECT_NAME} ${srcFiles})
target_include_directories(${PROJECT_NAME} PUBLIC ${includeDirs})
target_link_libraries(${PROJECT_NAME} PUBLIC ${externalLibs})