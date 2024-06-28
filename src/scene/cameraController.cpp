#include "scene/cameraController.hpp"
#include"scene/camera.hpp"

class Camera;

PanDown::PanDown(Camera *camera) : camera(camera) {};

void PanDown::execute(float dt)
{
  camera->translate(glm::vec2(0, camera->movingSpeed * dt));
}

PanRight::PanRight(Camera *camera) : camera(camera) {};

void PanRight::execute(float dt)
{
  camera->translate(glm::vec2(-camera->movingSpeed * dt, 0));
}

PanUp::PanUp(Camera *camera) : camera(camera) {};

void PanUp::execute(float dt)
{
  camera->translate(glm::vec2(0, -camera->movingSpeed * dt));
}

PanLeft::PanLeft(Camera *camera) : camera(camera) {};

void PanLeft::execute(float dt)
{
  camera->translate(glm::vec2(camera->movingSpeed * dt, 0));
}

void ZoomOut::execute(float dt)
{
  // camera
}
