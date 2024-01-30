#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <fstream>
#include "runandbuild.h"

void run(std::string path, std::string ofile) {
    std::system(("./" + path + "/bin/" + ofile).c_str());
}

void ifsrc_exists(std::string path, std::string opath) {
    std::string compile_shell = path + "/compile.sh";

    std::ofstream cshell(compile_shell);

    if(cshell.is_open()) {
        cshell << "#!/bin/bash\n";

        cshell << "directory=" << path << "/src\n";

        cshell << "cpp_files=$(find " << "\"$directory\"" << " -type f -name \"*.cpp\")\n";

        cshell << "g++ -o " << opath << " $cpp_files\n";

        cshell.close();
    }
}

void ifsrc_notexists(std::string path, std::string opath) {
    std::string compile_shell = path + "/compile.sh";

    std::ofstream cshell(compile_shell);

    if(cshell.is_open()) {
        cshell << "#!/bin/bash\n";

        cshell << "directory=" << path << "\n";

        cshell << "cpp_files=$(find " << "\"$directory\"" << " -type f -name \"*.cpp\")\n";
    
        cshell << "g++ -o " << opath << " $cpp_files\n";

        cshell.close();
    }
}

void build(std::string path) {
    std::string output_file_line;
    std::string w_file_line;
    std::string all;
    int count = 0;

    std::ifstream of(path + "/output.cbspf");
    std::ifstream w(path + "/warning.cbspf");
    std::ifstream ifiles(path + "/files.cbspf");

    if(of.is_open()) {
        std::string output_file;

        if(std::getline(of, output_file)) {
            output_file_line = output_file;
        }
    
        of.close();
    }

    if(w.is_open()) {
        std::string w_file;

        if(std::getline(w, w_file)) {
            w_file_line = w_file;
        }

        w.close();
    }

    if(ifiles.is_open()) {
        std::string line;
        while(std::getline(ifiles, line)) {
            all += " " + line + " ";
            count += 1;
        }

        ifiles.close();
    }

    std::string src_path_str = path + "/src";
    std::filesystem::path src_path = src_path_str;

    if(std::filesystem::exists(src_path)) {
        std::string output_path = path + "/bin/" + output_file_line;
        // std::string src_path = path + "/src";
        // std::string compile_commands = "g++ -o " + output_path + " " + path +  "/" + all + " " + w_file_line ;
        // std::system(compile_commands.c_str());
    
        ifsrc_exists(path, output_path);
        std::system(("chmod +x " + path + "/compile.sh").c_str());
        std::system(("./" + path + "/compile.sh").c_str());
    } 
}