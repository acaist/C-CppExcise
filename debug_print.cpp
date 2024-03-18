#include <cstdio>

#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) \
    printf(fmt, ##__VA_ARGS__);
#else
    #define DEBUG_PRINT(fmt, ...)
#endif

int main() {
    int value = 42;

    // Debug print
    DEBUG_PRINT("Value: %d\n", value);

    return 0;
}