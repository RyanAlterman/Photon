# Build the Photon library
project(Photon CXX)

set(srcFiles
    "src/Math/Point.cpp"
    "src/Math/Vector.cpp"
    "src/Color/Color.cpp"
)

set(includeDirs
    "./include/Photon"
)

set(externalLibs
)

add_library(${PROJECT_NAME} ${srcFiles})
target_include_directories(${PROJECT_NAME} PRIVATE ${includeDirs})
target_link_libraries(${PROJECT_NAME} PRIVATE ${externalLibs})

# Build the unit tests
project(PhotonTests CXX)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(testFiles
    "test/Math/PointTests.cpp"
    "test/Math/VectorTests.cpp"
)

set(testIncludeDirs
    "include"
)

set(testExternalLibs
    GTest::gtest_main
    Photon
)

add_executable(${PROJECT_NAME} ${testFiles})
target_include_directories(${PROJECT_NAME} PRIVATE ${testIncludeDirs})
target_link_libraries(${PROJECT_NAME} PRIVATE ${testExternalLibs})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})