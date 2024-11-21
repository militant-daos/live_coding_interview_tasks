/*
 * Given: a sorted vector of ints.
 * Task: implement binary search over the given vector.
 */

#include <cmath>
#include <iostream>
#include <vector>

int binary_search(const std::vector<int>& input, int search_item)
{
    auto left = 0;
    auto right = input.size() - 1;

    while (left <= right)
    {
        auto middle = std::floor((left + right) / 2);
        const auto pick = input[middle];
        if (pick == search_item)
        {
            return middle;
        }
        else if (pick < search_item)
        {
            // Shift middle to right.
            left = middle + 1;
        }
        else 
        {
            // Shift to left.
            right = middle - 1;
        }
    }

    std::cout << "Item " << search_item << " not found." << std::endl;
    return -1;
}

int main()
{
    std::vector<int> input {1,2,8,20,34,72,150,200,411};
    int search_item = 20;
    auto index = binary_search(input, search_item);
    if (index >= 0)
    {
        std::cout << "v[" << index << "]=" << input[index] << std::endl;
    }

    search_item = 411;
    index = binary_search(input, search_item);
    if (index >= 0)
    {
        std::cout << "v[" << index << "]=" << input[index] << std::endl;
    }
    
    search_item = 1;
    index = binary_search(input, search_item);
    if (index >= 0)
    {
        std::cout << "v[" << index << "]=" << input[index] << std::endl;
    }

    search_item = 3;
    index = binary_search(input, search_item);
    if (index >= 0)
    {
        std::cout << "v[" << index << "]=" << input[index] << std::endl;
    }
}
