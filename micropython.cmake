# Aggregates all user C modules for CMake-based ports (rp2, esp32, etc.)
# This file is referenced by USER_C_MODULES in the build.


# mymod
add_library(usermod_mymod INTERFACE)
target_sources(usermod_mymod INTERFACE ${CMAKE_CURRENT_LIST_DIR}/mymod/examplemodule.c)
# Add this folder to includes for the module if you later add headers
target_include_directories(usermod_mymod INTERFACE ${CMAKE_CURRENT_LIST_DIR}/mymod)


# Optional: if your CI fails due to warnings-as-errors in your module only, uncomment:
# target_compile_options(usermod_mymod INTERFACE -Wno-error)


# Link into MicroPython's usermod umbrella target
# (usermod target is created by the port's CMake)
target_link_libraries(usermod INTERFACE usermod_mymod)
