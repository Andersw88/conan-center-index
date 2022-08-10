cmake_minimum_required(VERSION 3.0)
project(SDL2_gfx VERSION 1.0.4 LANGUAGES C)

include(conanbuildinfo.cmake)
conan_basic_setup()

set(CONFIG_NAME "sdl2-gfx")

find_package(SDL2 REQUIRED)

# builtin formats
set(SDL_GFX_DEFINES WIN32)
if(BUILD_SHARED_LIBS)
    list(APPEND SDL_GFX_DEFINES DLL_EXPORT)
endif()

set(SOURCES
    source_subfolder/SDL2_framerate.c
    source_subfolder/SDL2_gfxPrimitives.c
    source_subfolder/SDL2_imageFilter.c
    source_subfolder/SDL2_rotozoom.c
)

set(HEADERS
    source_subfolder/SDL2_framerate.h
    source_subfolder/SDL2_gfxPrimitives.h
    source_subfolder/SDL2_imageFilter.h
    source_subfolder/SDL2_rotozoom.h
    source_subfolder/SDL2_gfxPrimitives_font.h
)

add_library(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME} PUBLIC source_subfolder)

if(WIN32)
    add_compile_definitions(${SDL_GFX_DEFINES})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

set_target_properties(${PROJECT_NAME} PROPERTIES
    DEFINE_SYMBOL DLL_EXPORT
    PUBLIC_HEADER "${HEADERS}"
)

install(TARGETS ${PROJECT_NAME}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/SDL2
)

