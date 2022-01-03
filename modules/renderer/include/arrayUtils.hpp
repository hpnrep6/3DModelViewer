#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

#include <vector>
#include <iostream>
namespace JRenderer {

std::vector<float> toFloatVector(const float (&array)[], int size);

std::vector<unsigned int> toUIntVector(const unsigned int (&array)[], int size);

}

#endif