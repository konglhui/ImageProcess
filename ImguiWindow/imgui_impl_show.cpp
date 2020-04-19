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
	//opengl  «rgb≈≈–Ú£¨opencv  «bgr≈≈–Ú
	//GLenum input_color_format = GL_BGR;
	if (_image_mat.channels() == 1)
		cv::cvtColor(_image_mat, _image_mat, cv::COLOR_GRAY2BGR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_BGR, GL_UNSIGNED_BYTE, _image_mat.data);
}

