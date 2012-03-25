
#include <CL/Graphics/Image>
#include "ImageImplementer.h"

ImagePtr Image::create(int width, int height, int bitCount, Error *error) {
	return ImagePtr((Image *)Implementer::create(width, height, bitCount, error));
}

Image::Image() {
}

Image::~Image() {
	imp()->~Implementer();
}

int Image::width() const {
	return imp()->width;
}

int Image::height() const {
	return imp()->height;
}

int Image::bitCount() const {
	return imp()->bitCount;
}

int Image::lineWidth() const {
	return imp()->lineWidth;
}
