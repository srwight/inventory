cmake_minimum_required(VERSION 3.10)

project(InventoryProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and include directories
set(SRC_DIR src)
set(INCLUDE_DIR include)
set(IMPL_INCLUDE_DIR include/implementation)
set(TEST_DIR tests)
set(MOCK_DIR tests/mocks)

# Find Catch2 (if you're using it)
find_package(Catch2 3 REQUIRED)

# Create the static library
add_library(inventory_lib ${SRC_DIR}/item.cpp)

# Set target include directories for the library (public for interface, private for implementation)
target_include_directories(inventory_lib PUBLIC ${INCLUDE_DIR})
target_include_directories(inventory_lib PRIVATE ${IMPL_INCLUDE_DIR})

# Add the main executable
add_executable(inventory_app ${SRC_DIR}/main.cpp)
target_link_libraries(inventory_app PRIVATE inventory_lib)  # Link with the static library
target_include_directories(inventory_app PUBLIC ${INCLUDE_DIR}) # Include interface for main

# Add the test executable
if(TARGET Catch2::Catch2)
    add_executable(inventory_tests
        ${SRC_DIR}/inventory.cpp 
        ${TEST_DIR}/test_item.cpp 
        ${TEST_DIR}/test_inventory.cpp)
    target_link_libraries(inventory_tests PRIVATE inventory_lib Catch2::Catch2WithMain) # Link with lib and Catch2
    target_include_directories(inventory_tests PUBLIC ${INCLUDE_DIR}) # Include interface for tests
    target_include_directories(inventory_tests PRIVATE ${IMPL_INCLUDE_DIR} ${MOCK_DIR}) # Implementation is still private.

    add_custom_target(run_tests
        COMMAND $<TARGET_FILE:inventory_tests>
        DEPENDS inventory_tests
    )

endif()


# Install targets (optional)
install(TARGETS inventory_app DESTINATION bin)
install(TARGETS inventory_lib DESTINATION lib) # Install the static library