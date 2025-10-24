# CMakeList.txt: projeto de CMake para wscan, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
# Adicione a origem ao executável deste projeto.
add_executable(
    main
    "wscan.cpp"
    "wscan.h"
    "../src/ping.cpp"
    "../src/ping_config.hpp"
    "../src/server/server.cpp"
    "../src/server/servercfg.hpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET main PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.
