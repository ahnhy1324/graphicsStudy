# CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(
	GraphicsDemo  #project name
	VERSION 0.0.1 
	DESCRIPTION "Graphics Code Demo"
	LANGUAGES C #using C	
)
set(VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(VERSION_PATCH ${PROJECT_VERSION_PATCH})
configure_file( 
	generics.h.in
	../include/generics.h
)
set(CMAKE_C_STANDARD 99)
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(X11 REQUIRED)
include_directories(BEFORE include)
include_directories(${X11_INCLUDE_DIR})
#add_compile_options(-lglfw -lGL -lm -lX11)
add_executable(OpenglDemo ../src/main.c)
target_link_libraries(OpenglDemo PRIVATE glfw ${OPENGL_LIBRARIES} ${X11_LIBRARIES} m)
