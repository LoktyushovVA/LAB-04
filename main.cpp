#include <iostream>
#include <cassert>
using namespace std;


void print_in_hex (uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}
