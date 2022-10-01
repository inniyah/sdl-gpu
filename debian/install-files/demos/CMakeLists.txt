find_package(OpenGL)
find_package(GLEW)
find_package(SDL2)

include_directories(${OPENGL_INCLUDE_DIRS} ${SDL2_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

set(DEMO_LIBS m SDL2_gpu ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${GLEW_LIBRARIES})

if(MINGW)
    set(DEMO_LIBS ${DEMO_LIBS} mingw32)
endif(MINGW)

add_executable(init-demo init/main.c)
target_link_libraries (init-demo ${DEMO_LIBS})

add_executable(camera-demo camera/main.c)
target_link_libraries (camera-demo ${DEMO_LIBS})

add_executable(3d-demo 3d/main.c)
target_link_libraries (3d-demo ${DEMO_LIBS})

add_executable(tutorial-space-demo tutorial-space/main.c)
target_link_libraries (tutorial-space-demo ${DEMO_LIBS})

add_executable(simple-shader-demo simple-shader/main.c)
target_link_libraries (simple-shader-demo ${DEMO_LIBS})

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})