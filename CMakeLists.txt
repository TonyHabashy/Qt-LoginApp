cmake_minimum_required(VERSION 3.5)

project(LoginApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()


# Find Qt modules (Widgets, Test)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)


# Add the Source, Header, and UI files
set(SOURCE_FILES
    src/main.cpp
    src/mainwindow.cpp
    src/secdialog.cpp
)

set(HEADER_FILES
    include/mainwindow.h
    include/secdialog.h
)

set(UI_FILES
    forms/mainwindow.ui
    forms/secdialog.ui
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/forms)


# Add the main application executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(LoginApp
        MANUAL_FINALIZATION
        ${SOURCE_FILES} ${HEADER_FILES} ${UI_FILES}

    )
else()
    add_executable(LoginApp ${SOURCE_FILES} ${HEADER_FILES} ${UI_FILES})
endif()

# Link Qt libraries
target_link_libraries(LoginApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Ensure MOC, UIC, and RCC work correctly
set_target_properties(LoginApp PROPERTIES AUTOMOC ON AUTOUIC ON)

# Enable testing
enable_testing()

# Download and add Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

# Test executable creation
add_executable(tests
    tests/test_mainwindow.cpp
    src/mainwindow.cpp
    src/secdialog.cpp
    include/mainwindow.h
    include/secdialog.h
)

# Ensure MOC is enabled for tests
set_target_properties(tests PROPERTIES AUTOMOC ON)

# Link the Qt Test and GTest libraries to the tests target
target_link_libraries(tests PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test gtest gtest_main)

# Register the test
add_test(NAME MainTests COMMAND tests)

# Print GoogleTest Path for debugging
message(STATUS "GoogleTest Path: ${googletest_SOURCE_DIR}")

# Ensure resources are correctly added in Qt6
if(${QT_VERSION_MAJOR} EQUAL 6)
    qt_add_resources(LoginApp "resources.qrc")  # Ensure the qrc file is processed
endif()

# Finalize the executable for Qt6 if needed
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(LoginApp)
endif()
