#include <iostream>
#include "file_parser.h"
#include "config.h"

int main() {
    Config config = Config::loadFromFile("config.json");
    
    std::cout << "Radius multiplier: " << config.algorithm.radius_multiplier << std::endl;
    std::cout << "Duplicate tolerance: " << config.algorithm.duplicate_tolerance << std::endl;

    FileParser parser;
    auto points = parser.readXYZ("input.xyz");
    parser.writeMesh("output.txt", points, TriangleMesh());
    
    return 0;
}