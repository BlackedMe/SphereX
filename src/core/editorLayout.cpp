#include "core/editorLayout.hpp"
#include "helpers/textureHandler.hpp"
#include "imgui/imgui.h"
#include "vendor/stb_image.h"

void Editor::render(FrameBuffer &frameBuffer, TextureHandler &textureHandler, World &world)
{
  std::vector<GameObject> &gameObjects = world.getGameObjects();
  ImGui::Begin("viewport");
  {
    ImVec2 size = ImGui::GetContentRegionAvail();
    if(frameBuffer.viewportSize != *(glm::vec2 *)&size)
    {
      frameBuffer.viewportSize = *(glm::vec2 *) &size;
      frameBuffer.resize(size.x, size.y);
    }

    ImGui::Image((void *) (intptr_t) frameBuffer.getTexture(), ImGui::GetContentRegionAvail(), ImVec2(0, 1), ImVec2(1, 0));

  }
  ImGui::End();

  ImGui::Begin("Hierarchy");
  {
    for(int i = 0; i < gameObjects.size(); i++)
    {
      ImGui::PushID(i);
      if(ImGui::TreeNode(gameObjects[i].getName().c_str()))
      {
        ImGui::TreePop();
      }
      if(ImGui::IsItemClicked())
      {
        selectedGameObject = i;
      }
      ImGui::PopID();
    }
  }
  ImGui::End();

  ImGui::Begin("Properties");
  {
    if(selectedGameObject != -1)
    {
      GameObject &gameObject = gameObjects[selectedGameObject];
      if(ImGui::CollapsingHeader("Transform"))
      {
        bool modified = false;

        glm::vec3 position = gameObject.transform.pos;

        if(ImGui::DragFloat3("Position", (float *) &gameObject.transform.pos))
        {
          modified = true;
        }

        if(ImGui::DragFloat3("Rotation", (float *) &gameObject.transform.rotation))
        {
          modified = true;
        }

        if(ImGui::DragFloat3("Scale", (float *) &gameObject.transform.scale))
        {
          modified = true;
        }

        if(modified)
        {
          world.modifyGameObject(selectedGameObject);
        }
      }

      if(ImGui::CollapsingHeader("SpriteRenderer"))
      {
        bool modified = false;

        if(ImGui::InputInt("Texture", &gameObject.textureID))
        {
          gameObject.texture = textureHandler.textures[gameObject.textureID];
          modified = true;
        }

        if(modified)
        {
          world.modifyGameObject(selectedGameObject);
        }
      }
    }
  }
  ImGui::End();

  ImGui::Begin("Assets");
  {

  }
  ImGui::End();
}
