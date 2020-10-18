#pragma once

#include <cstdio>
#include <cstring>

#include "Console.h"

#define CMP_COLOR(from, text, ansi, index)          \
    if( strncmp(from, text, strlen(text)) == 0){    \
        std::cout<< ansi;                           \
        index += strlen(text);                      \
    }else

inline int ColorPrintf(char * _format,...)
{
    int len = 0;
    char format[4996];
    va_list ap;
    va_start(ap, _format);
    vsprintf(format, _format, ap);
    va_end(ap);

    for(size_t i=0; i<strlen(format); ++i)
    {
        char ch = format[i];
        if( ch == '\033' )
        {
            // start check which color
            i++;
            CMP_COLOR(format + i, "[0;30m", Ansi::fg_black, i)
            CMP_COLOR(format + i, "[0;31m", Ansi::fg_red, i)
            CMP_COLOR(format + i, "[0;32m", Ansi::fg_green, i)
            CMP_COLOR(format + i, "[0;33m", Ansi::fg_yellow, i)
            CMP_COLOR(format + i, "[0;34m", Ansi::fg_blue, i)
            CMP_COLOR(format + i, "[0;35m", Ansi::fg_magenta, i)
            CMP_COLOR(format + i, "[0;36m", Ansi::fg_cyan, i)
            CMP_COLOR(format + i, "[0;37m", Ansi::fg_white, i)

            CMP_COLOR(format + i, "[1;30m", Ansi::fg_black, i)
            CMP_COLOR(format + i, "[1;31m", Ansi::fg_red, i)
            CMP_COLOR(format + i, "[1;32m", Ansi::fg_green, i)
            CMP_COLOR(format + i, "[1;33m", Ansi::fg_yellow, i)
            CMP_COLOR(format + i, "[1;34m", Ansi::fg_blue, i)
            CMP_COLOR(format + i, "[1;35m", Ansi::fg_magenta, i)
            CMP_COLOR(format + i, "[1;36m", Ansi::fg_cyan, i)
            CMP_COLOR(format + i, "[1;37m", Ansi::fg_white, i)

            CMP_COLOR(format + i, "[40m", Ansi::bg_black, i)
            CMP_COLOR(format + i, "[41m", Ansi::bg_red, i)
            CMP_COLOR(format + i, "[42m", Ansi::bg_green, i)
            CMP_COLOR(format + i, "[43m", Ansi::bg_yellow, i)
            CMP_COLOR(format + i, "[44m", Ansi::bg_blue, i)
            CMP_COLOR(format + i, "[45m", Ansi::bg_magenta, i)
            CMP_COLOR(format + i, "[46m", Ansi::bg_cyan, i)
            CMP_COLOR(format + i, "[47m", Ansi::bg_white, i)

            if (strncmp(format + i, "[0m", strlen("[0m")) == 0)
            {
                std::cout << Ansi::rest_color;
                i += strlen("[0m");
            }
            else;
            i--;
        }
        else
        {
            len += printf("%c", ch);
        }
    }
    return len;
}

#if defined(USE_COLOR_PRINTF)
#undef printf
#define printf ColorPrintf
#endif
