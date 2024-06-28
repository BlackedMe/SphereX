#include "events/command.hpp"

class Camera;

class PanDown : public Command{
public:
  PanDown(Camera *camera);
  void execute(float dt) override; 
private:
  Camera *camera;
};

class PanRight : public Command{
public:
  PanRight(Camera *camera);
  void execute(float dt) override; 
private:
  Camera *camera;
};

class PanUp : public Command{
public:
  PanUp(Camera *camera);
  void execute(float dt) override; 
private:
  Camera *camera;
};

class PanLeft : public Command{
public:
  PanLeft(Camera *camera);
  void execute(float dt) override; 
private:
  Camera *camera;
};

class ZoomOut : public Command{
public:
  void execute(float dt) override;
private:
  Camera *camera;
};

class ZoomIn : public Command{
public:
  void execute(float dt) override;
private:
  Camera *camera;
};
