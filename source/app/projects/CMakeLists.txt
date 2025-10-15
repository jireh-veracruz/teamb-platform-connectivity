# Define options to control which modules to build
option(BUILD_CONNECTIVITY "Build the connectivity module" ON )

# Conditionally add subdirectories
if(BUILD_CONNECTIVITY)
    add_subdirectory(connectivity)
endif()
