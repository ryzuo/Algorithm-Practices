#ifndef P_STRINGS_H
#define P_STRINGS_H

#include <string>
#include <cstring>

#define CSTR_NTS    -1001
#define MAX_STRING_LEN    20000


#ifndef CPP_SOL
char *Reverse(char *source, size_t len = CSTR_NTS);
#else
std::string Reverse(std::string &&source);
#endif

#endif
