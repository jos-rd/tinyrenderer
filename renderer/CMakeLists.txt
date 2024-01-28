cmake_minimum_required(VERSION 3.28)

set(SOURCES
rasterisation.cpp
tgaimage.cpp
)

set(HEADERS
rasterisation.h
tgaimage.h
)

add_executable(main main.cpp)

add_library(rendererLib STATIC ${SOURCES} ${HEADERS})
target_link_libraries(main rendererLib)