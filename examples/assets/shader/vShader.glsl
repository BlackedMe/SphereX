#version 420 core
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in float aTexIndex;
out vec2 texCoord;
out float texIndex;

void main()
{
  gl_Position = proj * view * model * vec4(pos, 1);
  texCoord = aTexCoord;
  texIndex = aTexIndex;
}
