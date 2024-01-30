#include <iostream>
#include "boilerplate.h"

#include <filesystem>
#include <fstream>

void boilerplate(std::string path) {
    std::filesystem::path p = path;

    std::filesystem::path docs = path + "/docs";
    std::filesystem::path src = path + "/src";
    std::filesystem::path bin = path + "/bin";

    if(std::filesystem::is_directory(p)) {
        std::filesystem::create_directory(docs);
        std::filesystem::create_directory(src);
        std::filesystem::create_directory(bin);
        std::cout << "Created " << docs << " directory. \n";
        std::cout << "Created " << src << " directory. \n";
        std::cout << "Created " << bin << " directory. \n";
    } else {
        std::cout << "Path not a directory!\n";
    }

    std::ofstream readme(path + "/docs/README.md");
    std::ofstream main(path + "/src/main.cpp");

    if(readme.is_open()) {
        readme << "# " << path << "\n";

        readme.close();

        std::cout << "Created " << path << "/docs/README.md\n";
    }

    if(main.is_open()) {
        main << "#include <iostream>\n";
        main << "\n";
        main << "int main()\n";
        main << "{\n";
        main << "   return 0;\n";
        main << "}\n";

        main.close();

        std::cout << "Created " << path << "/src/main.cpp\n";
    }
}