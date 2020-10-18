# ColorPrintf

## Why this repository

As we all know, Windows OS does not support Anis
Therefore, `printf` with color codes such as `\033[1;31m` will not work

There are many questions about how to output colors in Stackoverflow. We can also find many methods, such as using Window's API `SetConsoleTextAttribute` or using some libraries that have been implemented to output colors.
However, I can't find any library that can make `printf` use Anis format
I am disappointed
So, here I wrote a simple code that allows you to printf ansi color

## how to use?

1. Download ColorPrintf.h and Console.h
2. Include ColorPrintf.h.

If you want to allow `printf` to work directly instead of using the `ColorPrintf` function, then you can define `USE_COLOR_PRINT` before include
Then, without doing more, we can make our console output color

Here is an example and screenshot

``` cpp
#define USE_COLOR_PRINTF
#include "ColorPrintf.h"

int main(void)
{
    for(int i=3; i<5; i++)
    {
        for(int j=0; j<8; j++)
        {
            printf("\033[%s%d%dm %d \033[0m\t", i==3 ? "0;" : "" , i, j, j);
        }
        printf("\n");
    }
}
```

![](data:image/png;base64,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)


Cheers!

Finally, I'm sorry, `printf` is a function of C language, but this library uses Console.h written in C++, so C language is not supported.

Console.h is downloaded from https://www.codeproject.com/script/Articles/Download.aspx?file=/KB/cpp/AddColorConsole/Console_h_src.zip&rp=https://www.codeproject.com/, thanks Original author
