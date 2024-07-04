#include "helpers/texture.hpp"
#include "core/editorLayout.hpp"
#include "imgui/imgui.h"
#include "vendor/stb_image.h"
#include <sys/select.h>

void Editor::render(FrameBuffer &frameBuffer, World &world)
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
      if(ImGui::CollapsingHeader("Transform"))
      {
        bool modified = false;

        glm::vec3 position = gameObjects[selectedGameObject].transform.pos;

        if(ImGui::DragFloat3("Position", (float *) &gameObjects[selectedGameObject].transform.pos))
        {
          modified = true;
        }

        if(ImGui::DragFloat3("Rotation", (float *) &gameObjects[selectedGameObject].transform.rotation))
        {
          modified = true;
        }

        if(ImGui::DragFloat3("Scale", (float *) &gameObjects[selectedGameObject].transform.scale))
        {
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
    // // glGenerateMipmap(GL_TEXTURE_2D);

    // ImVec2 size(32.0f, 32.0f);
    // if(ImGui::ImageButton((void *) (intptr_t) texture, size, ImVec2(0, 1.0), ImVec2(0.1, 0.9)))
    // {
    //   std::cout << "hi" << '\n';
    // }
    //

  //   for(File &file : fileSystem.files)
  //   {
  //     glm::vec2 uv0, uv1;

  //     Texture::extractSubregion()
  //     ImGui::ImageButton()
  //   }
  // }
  ImGui::End();
  }

}
