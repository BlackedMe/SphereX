#version 420 core
uniform bool useTexture;
uniform sampler2DArray tex;
in vec2 texCoord;
in float texIndex;
out vec4 color;

void main()
{
  // if(useTexture)
  // {
    color = texture(tex, vec3(texCoord, texIndex));
  // }
  // else color = vec4(1.0f);
}
