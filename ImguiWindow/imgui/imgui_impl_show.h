#pragma once
#include <filesystem>

#include <opencv2\opencv.hpp>
#include <imgui.h>
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_show.h"
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif



/**
 * \brief 此类一定要在guiwindow初始化之后在使用
 */
class MatToTexture
{

public:
    MatToTexture();
	~MatToTexture();
    MatToTexture(const cv::Mat& image_mat);
    //MatToTexture(const std::string& image_path);


	//塞图
    bool setImage(const cv::Mat& image_mat);
    bool setImage(const std::string& image_path);

	//获取结果
    void* getImageTexture() const;

    /**
     * \brief 获取计算尺寸
     * \return 
     */
    ImVec2 getSize() const;
private:
    void genGLTexture();
private:
    cv::Mat _image_mat;
	int _width, _height;
	GLuint _gl_texture;
};

static void glfw_error_callback(int error, const char* description);

typedef std::function<void()> showFunc;


/**
 * \brief gui窗口
 */
class GuiWindow
{
public:
	/**
     * \brief 初始化
     */
    GuiWindow();
	~GuiWindow();
	/**
     * \brief 我们需要显示的内容
     * \param func  我们在外部自定义的函数，可以实时显示，也是imgui的内容
     */
    void show(showFunc func);
private:
    GLFWwindow* _window;
    bool _shut_down_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};
