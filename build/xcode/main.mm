
#include <iostream>
#include <memory>
#include <CL/StringUtil>
#include <CL/Graphics/Image>
#include <Foundation/Foundation.h>
#include <stdint.h>

int calc(int count, ...) {
	
	int n = 0;
	
	va_list ap;
	va_start(ap, count);
	for (int i = 0; i < count; ++i) {
		n += va_arg(ap, int);
	}
	va_end(ap);
	
	return n;
}

void doMain() {
	
	ImagePtr image = Image::create(3200, 4800, 8, 0);
	
}

class Foo {
private:
    int a;
    float b;
public:
    Foo() {
        a = 1;
        b = 0.2;
    }
};

int main (int argc, char * const argv[]) {

	Foo f;
    int *a = reinterpret_cast<int*>(&f);
    *a = 10;
    double *b = reinterpret_cast<float*>((char *)&f + sizeof(int));
    *b = 0.02;
    return 0;
	
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	doMain();	
	[pool drain];
	
	std::getchar();
	
    return 0;
}

//- (NSString *)GB2312Decode:(NSData *)data {
//	NSStringEncoding encoding = CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000);
//	return [[[NSString alloc] initWithData:data encoding:encoding] autorelease];
//}


