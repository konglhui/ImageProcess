
#include "imgui.h"

#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_show.h"

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include "../ImageProcess/Steger.h"
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
void showImageTest()
{
    cv::Mat img = cv::imread("..//src//test//11.bmp");
    GuiWindow window;
    //cv::flip(img,img,0)
    MatToTexture texture = MatToTexture(img);
    image_texture = texture.getImageTexture();
    texture_size = texture.getSize();
    window.show(showImage);
}


void ExtractPointsTest()
{
    cv::Mat img = cv::imread("..//src//weld//weld.bmp",cv::IMREAD_GRAYSCALE);
    cv::flip(img, img, 0);

    std::vector<cv::Point2f> points;
    stegerExtractPoint(img, points, 15);
    cv::Mat img_color;
    cv::cvtColor(img, img_color, cv::COLOR_GRAY2BGR);
	for(const auto& point :points)
	{
        img_color.at<cv::Vec3b>(point) = cv::Vec3b(0, 255, 255);
	}
    return;
}


int main(int, char**)
{
    //showImageTest();
    ExtractPointsTest();
	
	return 0;
}
