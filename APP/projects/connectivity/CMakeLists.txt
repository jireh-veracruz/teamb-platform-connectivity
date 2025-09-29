cmake_minimum_required(VERSION 3.15)
project(connectivityBoard C)

# Add subdirectories for each core
add_subdirectory(hal)
add_subdirectory(common)
add_subdirectory(CA7)
add_subdirectory(CM4)