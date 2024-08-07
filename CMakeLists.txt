cmake_minimum_required(VERSION 3.22.1)
project(OpenGL)
add_subdirectory(deps/glad)
add_subdirectory(deps/glfw)
add_subdirectory(deps/glm)
file(GLOB core "src/core/*.cpp")
file(GLOB events "src/events/*.cpp")
file(GLOB geometry "src/geometry/*.cpp")
file(GLOB helpers "src/helpers/*.cpp")
file(GLOB rendering "src/rendering/*.cpp")
file(GLOB scene "src/scene/*.cpp")
file(GLOB imgui "deps/imgui/*.cpp")
add_executable(demo examples/demo.cpp ${core} ${events} ${geometry} ${helpers} ${rendering} ${scene} ${imgui})
find_package(OpenGL REQUIRED)
target_include_directories(demo PRIVATE include PRIVATE deps/glad/include PRIVATE deps)
target_link_libraries(demo glad glfw glm OpenGL::GL)
