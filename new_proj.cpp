#include <iostream>
#include "new_proj.h"
#include "init.h"
#include "boilerplate.h"

#include <filesystem>
#include <fstream>

void create_new_project(std::string path) {
    std::filesystem::path new_project_path = path;

    if(!std::filesystem::exists(new_project_path)) {
        std::filesystem::create_directory(new_project_path);
        std::cout << "Created " << new_project_path << " directory.\n";
    } else {
        std::cout << "Directory already exists!\n";
    }

    std::string full_path = path + "/" + path + ".cbspf";
    std::string proj_name = ".projname";
    std::string compile_shell = path + "/" + "compile.sh";

    std::ofstream cbspf(full_path);
    std::ofstream pn(proj_name);
    std::ofstream cshell(compile_shell);

    if(cshell.is_open()) {
        cshell << "#!/bin/bash\n";

        cshell.close();
    }


    if(cbspf.is_open()) {
        cbspf << "[Project]\n";
        cbspf << "name: " << path << "\n";

        cbspf.close();

        std::cout << "Created " << full_path << "\n";
    }

    if(pn.is_open()) {
        pn << path;

        pn.close();
    }

    boilerplate(path);
    init(path);

}