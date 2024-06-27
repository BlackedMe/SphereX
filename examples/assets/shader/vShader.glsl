#version 420 core
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
  vec2 gridPlane[4] = vec2[](vec2(-1, -1), vec2(1, -1), vec2(1, 1), vec2(-1, 1));
  gl_Position = proj * view * model * vec4(gridPlane[gl_VertexID], 0, 1);
}
