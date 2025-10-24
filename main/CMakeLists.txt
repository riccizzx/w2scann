
# executables

add_executable(
    main
    "wscan.cpp"
    "wscan.h"
    "../src/features/ping.cpp"
    "../src/features/ping_config.hpp"
    "../src/server/server.cpp"
    "../src/server/servercfg.hpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

# 