#include <cstdio>
#include <filesystem>
#include <iostream>
#include <ostream>
#include <string>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    const char *path = (argc < 2) ? "." : argv[1];
    printf("%s \n", path);

    struct stat sb;

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::filesystem::path outFN = entry.path();
        std::string outFNStr = outFN.string();

        const char* path = outFNStr.c_str();
        if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR)) std::cout << path << std::endl;
    }
    
    return 0;
}
