# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  rectangle.cpp
  

  )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  window.cpp
  glew.c
  tests.cpp
  vec2.cpp
  mat2.cpp
  color.cpp
  circle.cpp
  rectangle.cpp
  
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

#Build clockexamples
add_executable(clockexample
  window.cpp
  glew.c
  clockexample.cpp
  vec2.cpp
  color.cpp
  circle.cpp
  clock.cpp
)
target_link_libraries(clockexample
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(clockexample glfw nanovg ${COPY_BINARY})

add_executable(aufgabe_2_und_3
aufgabe_2_und_3.cpp)

add_executable(aufgabe_6
glew.c
aufgabe_6.cpp
circle.cpp
vec2.cpp
color.cpp
window.cpp)
target_link_libraries(aufgabe_6
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(clockexample glfw nanovg ${COPY_BINARY})

add_executable(aufgabe_9
aufgabe_9.cpp)

add_executable(aufgabe_11
glew.c
aufgabe_11.cpp
circle.cpp
vec2.cpp
color.cpp
window.cpp)
target_link_libraries(aufgabe_11
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )