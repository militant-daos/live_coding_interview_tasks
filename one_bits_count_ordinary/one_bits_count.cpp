/*
 * Given: a non-negative int number, 1 < n < 10e9.
 * Task: implement bit_count(int) function that should
 *       count all the bits set to '1'.
 */

#include <iostream>

int bits_count(int number)
{
    int count = 0;

    while(number != 0)
    {
        if (number & 1)
        {
            count++;
        }

        number >>= 1; // Move to tghe next bit.
    }

    return count;
}

int main()
{
    int number = 11; // 1011 -> 3 bits
    std::cout << bits_count(number) << std::endl;
}
