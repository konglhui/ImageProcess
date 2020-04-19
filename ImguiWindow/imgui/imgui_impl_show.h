#pragma once#define STB_IMAGE_IMPLEMENTATION
#include <filesystem>
#include <GL/gl3w.h>
#include <opencv2\opencv.hpp>
#include <imgui.h>
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



//class ImageTexture {
// private:
//  int width, height;
//  GLuint my_opengl_texture;
//
// public:
//  ~ImageTexture();
//  void setImage(cv::Mat *frame);    // from cv::Mat (BGR)
//  void setImage(string filename);  // from file
//  void* getOpenglTexture();
//  ImVec2 getSize();
//};
//
//ImageTexture::~ImageTexture() {
//  glBindTexture(GL_TEXTURE_2D, 0);  // unbind texture
//  glDeleteTextures(1, &my_opengl_texture);
//}


// Simple helper function to load an image into a OpenGL texture with common settings
//bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height)
//{
//    // Load from file
//    
//    cv::Mat image = cv::imread(filename);// stbi_load(filename, &image_width, &image_height, NULL, 4);
//    if (image.empty())
//        return false;
//    //cv::cvtColor(image, image, cv::COLOR_BGR2BGRA);
//    const int image_width = image.cols;
//    const int image_height = image.rows;
//    // Create a OpenGL texture identifier
//    GLuint image_texture;
//    glGenTextures(1, &image_texture);
//    glBindTexture(GL_TEXTURE_2D, image_texture);
//
//    // Setup filtering parameters for display
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    // Upload pixels into texture
//    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_width, image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image.data);
//    image.release();
//
//    *out_texture = image_texture;
//    *out_width = image_width;
//    *out_height = image_height;
//
//    return true;
//}

//
//#include <cstdio>
//#include <fstream>
//#include <iostream>
//#include <string>
//
//#include <opencv2/opencv.hpp>
//
//#include "imgui.h"
//#include "imgui_impl_opengl3.h"
//#include "imgui_impl_glfw.h"
//
//#include <GL/gl3w.h>
//#include <GLFW/glfw3.h>
//
//using namespace std;
//
////---------------------------------------------------------------------
//
//class ImageTexture {
// private:
//  int width, height;
//  GLuint my_opengl_texture;
//
// public:
//  ~ImageTexture();
//  void setImage(cv::Mat *frame);    // from cv::Mat (BGR)
//  void setImage(string filename);  // from file
//  void* getOpenglTexture();
//  ImVec2 getSize();
//};
//
//ImageTexture::~ImageTexture() {
//  glBindTexture(GL_TEXTURE_2D, 0);  // unbind texture
//  glDeleteTextures(1, &my_opengl_texture);
//}
//
//void ImageTexture::setImage(cv::Mat *pframe) {
//  width = pframe->cols;
//  height = pframe->rows;
//
//  glGenTextures(1, &my_opengl_texture);
//  glBindTexture(GL_TEXTURE_2D, my_opengl_texture);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
//
//  // Some enviromnent doesn't support GP_BGR
//  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR,
//               GL_UNSIGNED_BYTE, (pframe->data));
//}
//
//void ImageTexture::setImage(string filename) {
//  cv::Mat frame = cv::imread(filename);
//  setImage(&frame);
//}
//
//void* ImageTexture::getOpenglTexture() {
//  return (void*)(intptr_t)my_opengl_texture;
//}
//ImVec2 ImageTexture::getSize() { return ImVec2(width, height); };
//
////---------------------------------------------------------------------
//
//class ImageViewer {
// private:
//  // common
//  SDL_Window* window;
//  SDL_GLContext gl_context;
//  ImGuiIO* io;
//
//  // static contents
//  ImVec4 clear_color;
//
//  // dynamic contents
//  vector<string> frame_names;
//  vector<cv::Mat*> frames;
//  float gain;
//
//  void init();
//  void initContents();
//  void render();
//  void showMainContents();
//
// public:
//  ImageViewer();
//  bool handleEvent();
//  void imshow(string, cv::Mat*);
//  void imshow(cv::Mat*);
//  void show();
//  void exit();
//  float getGain();
//};
//
//ImageViewer::ImageViewer() {
//  init();
//  initContents();
//
//  io = &ImGui::GetIO();
//  (void)&io;
//
//  // dynamic contents
//  gain=1.0f;
//}
//
//float ImageViewer::getGain(){
//  return gain;
//}
//
//void ImageViewer::init() {
//  // Setup SDL
//  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) !=
//      0) {
//    printf("Error: %s\n", SDL_GetError());
//    exit();
//  }
//
//  const char* glsl_version = "#version 150";
//  SDL_GL_SetAttribute(
//      SDL_GL_CONTEXT_FLAGS,
//      SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);  // Always required on Mac
//  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
//
//  // Create window with graphics context
//  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
//  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
//  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
//  SDL_WindowFlags window_flags = (SDL_WindowFlags)(
//      SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
//  // SDL_Window*
//  window = SDL_CreateWindow("OpenCV/ImGUI Viewer", SDL_WINDOWPOS_CENTERED,
//                            SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
//  // SDL_GLContext
//  gl_context = SDL_GL_CreateContext(window);
//  SDL_GL_SetSwapInterval(1);  // Enable vsync
//
//  bool err = gl3wInit() != 0;
//  if (err) {
//    fprintf(stderr, "Failed to initialize OpenGL loader!\n");
//    exit();
//  }
//
//  // Setup Dear ImGui context
//  IMGUI_CHECKVERSION();
//  ImGui::CreateContext();
//
//  // Setup Dear ImGui style
//  ImGui::StyleColorsDark();
//
//  // Setup Platform/Renderer bindings
//  ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
//  ImGui_ImplOpenGL3_Init(glsl_version);
//}
//
//void ImageViewer::render() {
//  // Rendering
//  ImGui::Render();
//  SDL_GL_MakeCurrent(window, gl_context);
//  glViewport(0, 0, (int)io->DisplaySize.x, (int)io->DisplaySize.y);
//  glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
//  glClear(GL_COLOR_BUFFER_BIT);
//  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//  SDL_GL_SwapWindow(window);
//}
//
//void ImageViewer::exit() {
//  // Cleanup
//  ImGui_ImplOpenGL3_Shutdown();
//  ImGui_ImplSDL2_Shutdown();
//  ImGui::DestroyContext();
//
//  SDL_GL_DeleteContext(gl_context);
//  SDL_DestroyWindow(window);
//  SDL_Quit();
//}
//
//void ImageViewer::initContents() {
//  clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
//}
//
//void ImageViewer::imshow(string frame_name, cv::Mat *frame) {
//  frame_names.push_back(frame_name);
//  frames.push_back(frame);
//}
//
//void ImageViewer::imshow(cv::Mat *frame) {
//  imshow("image:" + to_string(frames.size()), frame);
//}
//
//void ImageViewer::showMainContents(){
//  ImGui::Begin("Main");
//
//  ImGui::SliderFloat("gain", &gain, 0.0f, 2.0f, "%.3f");
//
//  ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
//                ImGui::GetIO().Framerate);
//  ImGui::End();
//}
//
//void ImageViewer::show() {
//  // Start the Dear ImGui frame
//  ImGui_ImplOpenGL3_NewFrame();
//  ImGui_ImplSDL2_NewFrame(window);
//  ImGui::NewFrame();
//
//  showMainContents();
//
//  // initialize textures
//  vector<ImageTexture*> my_textures;
//  for (int i = 0; i < frames.size(); i++) {
//    my_textures.push_back(new ImageTexture());
//  }
//
//  // imshow windows
//  for (int i = 0; i < frames.size(); i++) {
//    cv::Mat *frame = frames[i];
//
//    string window_name;
//    if (frame_names.size() <= i) {
//      window_name = "image:" + to_string(i);
//    } else {
//      window_name = frame_names[i];
//    }
//    ImGui::Begin(window_name.c_str());
//
//    my_textures[i]->setImage(frame);
//    ImGui::Image(my_textures[i]->getOpenglTexture(), my_textures[i]->getSize());
//    ImGui::End();
//  }
//
//  render();
//
//  // clear resources
//  for (int i = 0; i < frames.size(); i++) {
//    delete my_textures[i];
//  }
//
//  frame_names.clear();
//  frames.clear();
//  my_textures.clear();
//
//}
//
//bool ImageViewer::handleEvent() {
//  SDL_Event event;
//  bool done = false;
//  while (SDL_PollEvent(&event)) {
//    ImGui_ImplSDL2_ProcessEvent(&event);
//    if (event.type == SDL_QUIT) done = true;
//    if (event.type == SDL_WINDOWEVENT &&
//        event.window.event == SDL_WINDOWEVENT_CLOSE &&
//        event.window.windowID == SDL_GetWindowID(window))
//      done = true;
//  }
//  return done;
//}
