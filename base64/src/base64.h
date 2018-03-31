
#ifndef _BASE64_H
#define _BASE64_H
#include <string>

extern std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len);
extern std::string base64_decode(std::string const& encoded_string);

#endif
