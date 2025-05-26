cmake_minimum_required(VERSION 3.16)
project(dxl_wsl)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Compiler warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

# Include directories
include_directories(include)

# Build publisher
add_executable(pub_wsl src/pub_wsl.cpp)
ament_target_dependencies(pub_wsl rclcpp geometry_msgs)

# Build subscriber (dxl.cpp 제거!)
add_executable(sub src/sub.cpp)
ament_target_dependencies(sub rclcpp geometry_msgs)

# Install targets
install(TARGETS
  pub_wsl
  sub
  DESTINATION lib/${PROJECT_NAME})

ament_package()
