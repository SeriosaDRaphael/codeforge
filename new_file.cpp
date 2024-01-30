#include <iostream>
#include <fstream>
#include "new_file.h"

void new_file(std::string path, std::string file_name) {
    std::ofstream h_outputFile(path + "/" + file_name + ".h");
    std::ofstream cpp_outputFile(path + "/" + file_name + ".cpp");

    if(h_outputFile.is_open()) {
        h_outputFile << "#ifndef _" << file_name << "_H_\n";
        h_outputFile << "#define _" << file_name << "_H_\n";
        h_outputFile << "\n";
        h_outputFile << "#endif\n";
    
        h_outputFile.close();
        std::cout << "Created " << file_name << ".h\n";
    }

    if(cpp_outputFile.is_open()) {
        cpp_outputFile << "#include <iostream>\n";
        cpp_outputFile << "#include \"" << file_name << ".h\"\n";
        cpp_outputFile << "\n";

        cpp_outputFile.close();
        std::cout << "Created " << file_name << ".cpp\n";
    }
}