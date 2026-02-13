cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(CampoElectrico)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Agregar opciones de compilación
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Archivos fuente
set(SOURCES
    main.cpp
    Carga.cpp
)

# Archivos de encabezado
set(HEADERS
    Carga.h
)

# Crear el ejecutable
add_executable(campo_electrico ${SOURCES} ${HEADERS})

# Incluir el directorio actual para los headers
target_include_directories(campo_electrico PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
