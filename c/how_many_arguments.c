#include <stdarg.h>
unsigned args_count (const char *arg1, ...)
{
	unsigned count = 0;

    va_list args;
    va_start(args, arg1);

    const char *arg = arg1;
    while (arg != 0) {
        count++;
        arg = va_arg(args, const char *);
    }

    va_end(args);
    return count;
}