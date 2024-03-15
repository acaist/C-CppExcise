#include <cstdio>

#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) \
        do { \
                std::printf(fmt, ##__VA_ARGS__); \
        } while (0)
#else
    #define DEBUG_PRINT(fmt, ...) do {} while (0)
#endif

int main() {
    int value = 42;

    // Debug print
    DEBUG_PRINT("Value: %d\n", value);

    return 0;
}