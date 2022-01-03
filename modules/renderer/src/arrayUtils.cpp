#define STB_IMAGE_IMPLEMENTATION
#include "arrayUtils.hpp"

namespace JRenderer {

std::vector<float> toFloatVector(const float (&array)[], int size) {
    return std::vector<float>(array, array + size);
} 

std::vector<unsigned int> toUIntVector(const unsigned int (&array)[], int size) {
    return std::vector<unsigned int>(array, array + size);
} 

}
