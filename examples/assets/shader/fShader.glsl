#version 420 core
out vec4 color;

void main()
{
  vec2 s = gl_FragCoord.xy / vec2(200, 200);
  color = vec4(s.x, s.y, 0.2f, 1.0f);
}
