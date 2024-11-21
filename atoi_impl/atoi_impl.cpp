/*
 * Task: implement int atoi(const char *str) function.
 */

#include <iostream>
#include <cctype>
#include <cstring>

int _atoi(const char* str)
{
    if (!str)
    {
        return 0; // Do not trigger UB.
    }

    // 1. Check signedness.
    bool is_negative = false;
    if (str[0] == '-')
    {
        is_negative = true;
    }

    // 2. Check minimal length not including trailing zero.
    const auto min_length = (is_negative) ? 2 : 1;
    const auto input_length = std::strlen(str);

    if (input_length < min_length)
    {
        return 0; // Do not trigger UB.
    }

    int multiplicator = 1;
    int accumulator = 0;
    for (int i = input_length - 1; i >= (is_negative) ? 1 : 0; --i)
    {
        const char c = str[i];

        if (!std::isdigit(c))
        {
            return 0;
        }

        int digit = c - '0';
        accumulator += digit * multiplicator;
        multiplicator = (multiplicator << 3) + (multiplicator << 1);
    }

    if (is_negative)
    {
        accumulator *= -1;
    }
    return accumulator;
}

int main()
{
    const char* input1 = "12345";
    auto i = _atoi(input1);
    std::cout << i << std::endl;

    const char* input2 = "-100";
    i = _atoi(input2);
    std::cout << i << std::endl;

    const char* input3 = "0";
    i = _atoi(input3);
    std::cout << i << std::endl;
    
    const char* input4 = "-1";
    i = _atoi(input4);
    std::cout << i << std::endl;
    
    const char* input5 = "!";
    i = _atoi(input5);
    std::cout << i << std::endl;
    
    const char* input6 = "-";
    i = _atoi(input6);
    std::cout << i << std::endl;
    
    const char* input7 = "-#";
    i = _atoi(input7);
    std::cout << i << std::endl;
    
    const char* input8 = "";
    i = _atoi(input8);
    std::cout << i << std::endl;
    
    const char* input9 = nullptr;
    i = _atoi(input9);
    std::cout << i << std::endl;
}
