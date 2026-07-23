#pragma once
#include "geometry.h"

class Preprocessor {
public:
    static PointCloud getUniquePoints(const PointCloud& points, double tolerance);
};