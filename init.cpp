#include <iostream>
#include <fstream>
#include "init.h"

void init(std::string path) 
{
    std::ofstream output(path + "/output.cbspf");

    if(output.is_open()) {
        output << "main"; // CHANGE THIS TO CHANGE OUTPUT FILE

        output.close();
    }
}