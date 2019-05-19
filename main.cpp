#include <iostream>
#include <cassert>
using namespace std;


void print_in_hex (uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);
}
const uint8_t* as_bytes(const void* data)
{
    return reinterpret_cast<const uint8_t*>(data);
}
void print_in_hex(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}
