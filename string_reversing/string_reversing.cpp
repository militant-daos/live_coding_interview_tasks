/*
 * Given: a string.
 * Task: reverse the give string.
 */

#include <iostream>
#include <string>

void reverse_string(std::string& input)
{
    auto left = input.begin();
    auto right = input.end() - 1;

    while (left < right)
    {
        auto tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main()
{
    std::string input {"abcdefgh"};
    reverse_string(input);
    std::cout << input << std::endl;
}
