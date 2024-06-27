#pragma once
#include "glad/glad.h"

class Program{
public:
  void init(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio);
  void reload(const char* vShaderSrc, const char* fShaderSrc, float aspectRatio);
  void use();
  GLuint *get();
private:
  GLuint program;
};
