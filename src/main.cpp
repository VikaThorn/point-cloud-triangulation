#include <iostream>
#include "file_parser.h"
#include "config.h"
#include "preprocessor.h"

int main() {
    Config config = Config::loadFromFile("config.json");

    FileParser parser;
    PointCloud all_points = parser.readXYZ("input.xyz");

    std::cout << "All points" << std::endl;
    for (const auto& p : all_points) {
        std::cout << "ID: " << p.node_id 
                  << " | X: " << p.x 
                  << " Y: " << p.y 
                  << " Z: " << p.z << std::endl;
    }

    PointCloud unique_points = Preprocessor::getUniquePoints(all_points, config.algorithm.duplicate_tolerance);

    std::cout << "\nUnique points" << std::endl;
    for (const auto& p : unique_points) {
        std::cout << "ID: " << p.node_id 
                  << " | X: " << p.x 
                  << " Y: " << p.y 
                  << " Z: " << p.z << std::endl;
    }

    TriangleMesh empty_mesh;
    parser.writeMesh("output.txt", all_points, empty_mesh);
    
    return 0;
}