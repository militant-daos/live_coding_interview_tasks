/*
 * Given: a non-negative int number, 1 < n < 10e9.
 * Task: implement bit_count(int) function that should
 *       - count all the bits set to '1'.
 *       - return a vector that contains the number of bits
 *         having '1' value in the first element. Rest of the
 *         elements should contain positions of the bits set
 *         to '1'.
 *       - Leading zeroes should be ignored and should not be 
 *         counted.
 *       - Bits positions should start with 1 (not zero) and
 *         the number should be processed from left to right.
 *         For example: 10(dec) -> 000...01010 yields the following
 *         output: 2, 1, 3.
 */

#include <iostream>
#include <vector>

std::vector<int> bit_count(int number)
{
    // We're goting from left to right so
    // we cannot shift the input itself.
    // We'll use a mask which will help us
    // with testing individual bit values.

    // 31-th bit is the sign bit. Since the
    // input is always greater than zero we
    // don't care about it.
    // 30-th bit = effectively half of the
    // signed int range.
    int mask = (1 << 30);

    int ones_count = 0;
    int pos = 1;
    bool first_one_found = false; // Used to skip leading zeros.

    std::vector<int> result;

    // Reserve space for the ones count.
    result.push_back(0);

    while (mask != 0)
    {
        if (number & mask)
        {
            // The very first non-zero bit found,
            // start the counter.
            first_one_found = true;
            ones_count++;
            result.push_back(pos);
        }

        if (first_one_found)
        {
            pos++;
        }

        mask >>= 1; // Move to the next bit.
    }

    result[0] = ones_count;
    return result;
}

int main()
{
    int test_number = 161; // 3 bits: 1,3,8

    auto res = bit_count(test_number);
    for (auto v : res)
    {
        std::cout << v << std::endl;
    }
}
