#include <iostream>
#include "file_parser.h"

int main() {
    try {
        FileParser parser;
        auto points = parser.readXYZ("input.xyz");
        std::cout << "Successfully loaded " << points.size() << " points" << std::endl;
        
        TriangleMesh empty_mesh;
        parser.writeMesh("output.txt", points, empty_mesh);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}