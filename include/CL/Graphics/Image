#ifndef CL_GRAPHICS_IMAGE_H
#define CL_GRAPHICS_IMAGE_H

#include <CL/Config>
#include <CL/Error>
#include <memory>

BEGIN_CL_NAMESPACE

namespace Graphics {

	class Image;
	typedef SharedPtr<Image> ImagePtr;
	
	class Image
	{
		class Implementer;

	public:

		static ImagePtr create(int width, int height, int bitCount, Error *error);

		~Image();

		int width() const;
		int height() const;
		int bitCount() const;
		int lineWidth() const;

	private:
		
		Image();
		
		Implementer* imp() const {
			return (Implementer *)this;
		}

	};

}

END_CL_NAMESPACE

using CL::Graphics::Image;
using CL::Graphics::ImagePtr;

#endif // CL_GRAPHICS_IMAGE_H