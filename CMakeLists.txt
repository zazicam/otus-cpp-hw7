cmake_minimum_required(VERSION 3.2)

project(bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
include_directories(${PROJECT_BINARY_DIR})

add_executable(bulk
	main.cpp 
	bulk.cpp
	command.cpp
)

set_target_properties(bulk PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

install(TARGETS bulk RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)

