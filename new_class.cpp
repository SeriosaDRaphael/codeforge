#include <iostream>
#include <fstream>
#include <cctype>
#include "newclass.h"

void new_class(std::string path) {
    std::string className;
    std::cout << "enter classname: ";
    std::cin >> className;

    std::string src_dir = path + "/src";
    std::string src_file = src_dir + "/" + className + ".cpp";
    std::string header_file = src_dir  + "/" + className + ".hpp";

    std::ofstream h_file(header_file);
    std::ofstream srf(src_file);

    if(h_file.is_open()) {
        h_file << "#ifndef " << className << "_h_\n"; 
        h_file << "#define " << className << "_h_\n";
        h_file << "\n";
        h_file << "class " << className << "{\n";
        h_file << "public: \n";
        h_file << " " << className << "();\n";
        h_file << " ~" << className << "();\n";
        h_file << "};\n";
        h_file << "\n";
        h_file << "#endif";

        h_file.close();
    }

    if(srf.is_open()) {
        srf << "#include <iostream>\n";
        srf << "#include \"" << className << ".hpp\"\n";
        srf << "\n";

        srf << className << "::" << className << "() {}\n";
        srf << className << "::" << "~" << className << "() {}\n";

        srf.close();
    }
}