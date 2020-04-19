#include "imgui/imgui_impl_show.h"

MatToTexture::MatToTexture()
{
	_image_mat = cv::Mat(0, 0, CV_8UC1);
	_width = 0;
	_height = 0;
}

MatToTexture::~MatToTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);  // unbind texture
	glDeleteTextures(1, &_gl_texture);
}

MatToTexture::MatToTexture(const cv::Mat& image_mat)
{
	setImage(image_mat);
}


bool MatToTexture::setImage(const cv::Mat& image_mat)
{
	if (image_mat.empty())
		return false;
	_image_mat = image_mat;
	if (_image_mat.cols % 4 != 0)
		cv::resize(_image_mat, _image_mat, cv::Size((_image_mat.cols / 4 + 1) * 4, _image_mat.rows));
	_width = _image_mat.cols;
	_height = _image_mat.rows;
	genGLTexture();
	return true;
}


bool MatToTexture::setImage(const std::string& image_path)
{
	if (!std::filesystem::exists(std::filesystem::path(image_path)))
		return false;
	const auto temp_image = cv::imread(image_path);
	return setImage(temp_image);
}

void* MatToTexture::getImageTexture() const
{
	if (_image_mat.empty()) 
		return nullptr;
	return reinterpret_cast<void*>(static_cast<intptr_t>(_gl_texture));
}

ImVec2 MatToTexture::getSize() const
{
	return ImVec2(static_cast<float>(_width), static_cast<float>( _height));
}

void MatToTexture::genGLTexture()
{
	glGenTextures(1, &_gl_texture);
	glBindTexture(GL_TEXTURE_2D, _gl_texture);

	// Setup filtering parameters for display
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Upload pixels into texture
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
	//opengl 是rgb排序，opencv 是bgr排序
	//GLenum input_color_format = GL_BGR;
	if (_image_mat.channels() == 1)
		cv::cvtColor(_image_mat, _image_mat, cv::COLOR_GRAY2BGR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_BGR, GL_UNSIGNED_BYTE, _image_mat.data);
}

void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

GuiWindow::GuiWindow()
{

    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return;

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only


    // Create window with graphics context
    _window = glfwCreateWindow(1280, 720, "Dear ImGui GLFW+OpenGL3 example", NULL, NULL);
    if (_window == NULL)
        return;
    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1); // Enable vsync


    const bool err = gl3wInit() != 0;

    if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();
    //ImGui::Image()
    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(_window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    //// Our state
    //bool show_demo_window = true;
    //bool show_another_window = false;
   

}

GuiWindow::~GuiWindow()
{
    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(_window);
    glfwTerminate();
}

void GuiWindow::show(showFunc func)
{
    _shut_down_window = false;
    // Main loop
    while (!glfwWindowShouldClose(_window) && !_shut_down_window)
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        //显示
        func();
    	
        //关闭按钮
        {
            ImGui::Begin("shut down window");
            ImGui::Checkbox("shut down!", &_shut_down_window);
            ImGui::End();
        }
#pragma region 展示案例
        //// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        //if (show_demo_window)
        //    ImGui::ShowDemoWindow(&show_demo_window);

        //// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
        //{
        //    static float f = 0.0f;
        //    static int counter = 0;

        //    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        //    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        //    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        //    ImGui::Checkbox("Another Window", &show_another_window);

        //    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        //    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        //    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        //        counter++;
        //    ImGui::SameLine();
        //    ImGui::Text("counter = %d", counter);

        //    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        //    ImGui::End();
        //}

        //if (ret == true)
        //{
        //    image_texture = texture.getImageTexture();
        //    ImVec2 texture_size = texture.getSize();

        //    ImGui::Begin("ShowImage");
        //    ImGui::Image(image_texture, texture_size);
        //    ImGui::End();
        //}

        //// 3. Show another simple window.
        //if (show_another_window)
        //{
        //    ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        //    ImGui::Text("Hello from another window!");
        //    if (ImGui::Button("Close Me"))
        //        show_another_window = false;
        //    ImGui::End();
        //}
#pragma endregion 
        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(_window);
    }
}

void showWindow(showFunc func)
{
	
}
