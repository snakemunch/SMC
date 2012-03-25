#ifndef CL_SRC_GRAPHICS_IMAGE_IMPLEMENTER_H
#define CL_SRC_GRAPHICS_IMAGE_IMPLEMENTER_H

#include <CL/Graphics/Color>
#include <CL/Error>
#include <CL/Localization>

class Image::Implementer
{
public:

	int			width;
	int			height;
	int			bitCount;
	int			clrUsed;
	int			lineWidth;
	uint8_t *	bits;
	Color		colors[1];

	Implementer() {
		// Do nothing, data members will be initialized by create method.
	}
	
	~Implementer() {
		// Frees the data member.
		operator delete(bits);
	}
	
	//
	// Allocates memory for Image::Implementer and initializes the data member.
	//
	static Implementer* create(int width, int height, int bitCount, Error *error) {

		error->init(0);
		
		if (width < 0 || height < 0) {
			error->init(kErrorInvalidParameters);
			return 0;
		}

		const int clrUsed = (bitCount == 1 || bitCount == 4 || bitCount == 8) ? 2 << bitCount : 0;
		const int lineWidth = 4 * ((width * bitCount + 31) / 32);

		uint32_t size = sizeof(Implementer);
		if (clrUsed != 0) {
			size += sizeof(Color) * clrUsed;
		}
		
		void *p = (Implementer *)operator new(size);
		Implementer *imp = new (p) Implementer;
		
		if (imp != 0) {
			size = lineWidth * height;
			imp->bits = (uint8_t *)operator new(size);
			if (imp->bits != 0) {
				memset(imp->bits, 0, size);
				imp->width = width;
				imp->height = height;
				imp->bitCount = bitCount;
				imp->clrUsed = clrUsed;
				imp->lineWidth = lineWidth;
				imp->initPalette();
			}
			else {
				error->init(kErrorOutOfMemory);
				delete imp;
				imp = 0;
			}
		}
		
		return imp;
	}

	void initPalette() {
		assert(this->clrUsed > 0 && this->clrUsed < 256);
		const int spacing = 255 / this->clrUsed;
		for (int i = 0; i < this->clrUsed; ++i) {
			int n = i * spacing;
			Color &color = this->colors[i];
			color.red = n;
			color.green = n;
			color.blue = n;
			color.alpha = 0;
		}
	}

};

#endif // CL_SRC_GRAPHICS_IMAGE_IMPLEMENTER_H