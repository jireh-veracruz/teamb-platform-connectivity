# Define options to control which modules to build
option(BUILD_CONNECTIVITY "Build the connectivity module" OFF )
option(BUILD_OILMS "Build the oilms module" OFF)
option(BUILD_CONTROLBOARD "Build the controlBoard module" ON )

# Conditionally add subdirectories
if(BUILD_CONNECTIVITY)
    add_subdirectory(connectivity)
endif()

if(BUILD_OILMS)
    add_subdirectory(oilms)
endif()

if(BUILD_CONTROLBOARD)
    add_subdirectory(controlBoard)
endif()
