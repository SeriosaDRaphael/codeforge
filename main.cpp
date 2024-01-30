#include <iostream>
#include <cstring>
#include <fstream>
#include <filesystem>
#include "new_file.h"
#include "new_proj.h"
#include "boilerplate.h"
#include "init.h"
#include "runandbuild.h"
#include "newclass.h"

std::string global_path;
std::string output_file;

std::string get_newdir_path() {
    std::string path;
    std::cout << "Enter path: ";
    std::cin >> path;

    return path;
}

std::string get_new_file_name() {
    std::string path;
    std::cout << "Enter new file name: ";
    std::cin >> path;

    return path;
}

int main(int argc, char** argv) {
    if(argv[1]) {
        if(strcmp(argv[1], "new") == 0) {
            if(argv[2]) {
                create_new_project(argv[2]);
                global_path = argv[2];
            } else {
                std::string p = get_newdir_path();
                global_path = p;
                create_new_project(p);
            }
        } else if(strcmp(argv[1], "new_file") == 0) {

            std::string file_path = ".projname";
            std::ifstream inputFile(file_path);

            if(inputFile.is_open()) {
                std::string pname;

                if(std::getline(inputFile, pname)) {
                    global_path = pname;
                } else {
                    std::cout << "error!\n";
                }
            }

            std::string full_path = global_path + "/src";
            std::filesystem::path fpath = full_path;

            if(std::filesystem::exists(fpath)) {
                if(argv[2]) {
                    new_file(full_path, argv[2]);
                } else {
                    std::string fn = get_new_file_name();
                    new_file(full_path, fn);
                }
            } else {
                if(argv[2]) {
                    new_file(global_path, argv[2]);
                } else {
                    std::string fn = get_new_file_name();
                    new_file(global_path, fn);
                }
            }
        } else if(strcmp(argv[1], "build") == 0) {
            std::string build_fpath = ".projname";

            std::ifstream build_projname(build_fpath);
        
            if(build_projname.is_open()) {
                std::string line;

                if(std::getline(build_projname, line)) {
                    global_path = line;
                }                

                build(global_path);
            
                build_projname.close();
            }
        } else if(strcmp(argv[1], "run") == 0) {
            std::string run_path = ".projname";

            std::ifstream run_projname(run_path);
        
            if(run_projname.is_open()) {
                std::string line;

                if(std::getline(run_projname, line)) {
                    global_path = line;
                }

                run_projname.close();
            }

            std::string run_ofile_path = global_path + "/output.cbspf";
            std::ifstream run_ofile(run_ofile_path);

            if(run_ofile.is_open()) {
                std::string line;

                if(std::getline(run_ofile, line)) {
                    output_file = line;
                }

                run_ofile.close();
            }

            run(global_path, output_file);
        } else if(strcmp(argv[1], "new_class") == 0) {
            std::string nf_path = ".projname";

            std::ifstream nf(nf_path);
        
            if(nf.is_open()) {
                std::string line;
                if(std::getline(nf, line)) {
                    global_path = line;
                }

                nf.close();
            }

            new_class(global_path);
        }
    }

    return 0;
}