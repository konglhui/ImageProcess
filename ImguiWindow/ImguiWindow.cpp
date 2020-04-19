
#include "imgui.h"

#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_show.h"

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

void* image_texture;// = texture.getImageTexture();
ImVec2 texture_size;// = texture.getSize();


void showImage()
{
   
    ImGui::Begin("ShowImage");
    ImGui::Image(image_texture, texture_size);
    ImGui::End();
}


int main(int, char**)
{
    cv::Mat img = cv::imread("..//src//test//11.bmp");
    GuiWindow window;
	
    MatToTexture texture = MatToTexture(img);
    image_texture = texture.getImageTexture();
    texture_size = texture.getSize();
    window.show(showImage);
	
	return 0;
}
