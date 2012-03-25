
#include <iostream>
#include <soko/Charset>

int main(int argc, char *argv[]) {
	char buffer[64];
	sprintf(buffer, "=%02x", 'a');

	CharsetPtr charset = Charset::forName("UTF-8");
	std::string result;
	charset->encode(L"ÄãºÃ", 2, result);

	return 0;
}
