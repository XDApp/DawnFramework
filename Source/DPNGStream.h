#pragma once
#include "DResourceLoader.h"
#include "DBinaryFileResourceLoader.h"

class DStream;

class DPNGStream :
	public DResourceLoader
{
	DClass(DPNGStream)
private:
	DResourceLoader *FileLoader;

	png_byte header[8];
	png_structp png_ptr;
	png_infop info_ptr;
	png_infop end_info;

	DStream* FileStream;
	std::string PNGString;
	void PNG_Create();
	void PNG_Validate();
	static void ReadData(png_structp png_ptr, png_bytep data, png_size_t length);

	int _Width, _Height;

	png_byte * image_data;
	png_bytep * row_pointers;
public:
	DPNGStream(DResourceLoader *fileLoader);
	~DPNGStream();

	virtual void Open();
	virtual void Close();
	virtual void Buffer();
};

