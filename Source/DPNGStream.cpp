#include "stdafx.h"
#include "DPNGStream.h"
#include "DStream.h"
#include "DApp.h"
#include "DDebugManager.h"

DPNGStream::DPNGStream(DResourceLoader *fileLoader)
	:FileLoader(fileLoader),
	PNGString(""),
	FileStream(nullptr),
	_Width(0), _Height(0),
	image_data(nullptr),
	row_pointers(nullptr)
{

}


DPNGStream::~DPNGStream()
{
}

void DPNGStream::Open()
{
	int _HeaderCount = 0;
	FileStream = new DStream(this->FileLoader);
	FileStream->Read((char*)header, 8);

	this->PNG_Validate();
	this->PNG_Create();
}
void DPNGStream::PNG_Validate()
{
	if (png_sig_cmp(header, 0, 8))
	{
		DApp::DF->DebugManager->Error(this, "This is not a PNG");
		return;
	}
}

void DPNGStream::PNG_Create()
{

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr)
	{
		DApp::DF->DebugManager->Error(this, "png failed to create structure");
		return;
	}
	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr)
	{
		DApp::DF->DebugManager->Error(this, "png_create_info_struct returned 0");
		png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
		return;
	}

	end_info = png_create_info_struct(png_ptr);
	if (!end_info)
	{
		DApp::DF->DebugManager->Error(this, "png_create_info_struct returned 0");
		return;
	}
	if (setjmp(png_jmpbuf(png_ptr))) {
		DApp::DF->DebugManager->Error(this, "error from libpng");
		png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
		return;
	}
	png_set_read_fn(png_ptr, (png_voidp)FileStream, DPNGStream::ReadData);

	png_set_sig_bytes(png_ptr, 8);
	png_read_info(png_ptr, info_ptr);

	png_uint_32 imgWidth = png_get_image_width(png_ptr, info_ptr);
	png_uint_32 imgHeight = png_get_image_height(png_ptr, info_ptr);
	png_byte bitdepth = png_get_bit_depth(png_ptr, info_ptr);
	png_byte channels = png_get_channels(png_ptr, info_ptr);
	png_byte color_type = png_get_color_type(png_ptr, info_ptr);

	this->_Width = imgWidth; this->_Height = imgHeight;

	switch(color_type) 
	{
        case PNG_COLOR_TYPE_PALETTE:
			png_set_palette_to_rgb(png_ptr);
			channels = 3;
			break;
		case PNG_COLOR_TYPE_GRAY:
			if (bitdepth < 8)
				png_set_expand_gray_1_2_4_to_8(png_ptr);
			bitdepth = 8;
			break;
	}

	if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS)) {
		png_set_tRNS_to_alpha(png_ptr);
		channels += 1;
	}
	if (bitdepth == 16)
		png_set_strip_16(png_ptr);

	row_pointers = new png_bytep[imgHeight];
	image_data = new png_byte[imgWidth * imgHeight * bitdepth * channels / 8];
	const unsigned int stride = imgWidth * bitdepth * channels / 8;


	for (size_t i = 0; i < imgHeight; i++) 
	{
		png_uint_32 q = (imgHeight - i - 1) * stride;
		row_pointers[i] = (png_bytep)image_data + q;
	}
	png_read_image(png_ptr, row_pointers);
}

void DPNGStream::ReadData(png_structp png_ptr, png_bytep data, png_size_t length)
{
	png_voidp src = png_get_io_ptr(png_ptr);
	((DStream*)src)->Read((char*)data, length);
}

void DPNGStream::Close()
{
	delete[](png_bytep)row_pointers;
	//And don't forget to clean up the read and info structs !
	png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp)0);
	DDel(FileStream);
}


void DPNGStream::Buffer()
{
}
