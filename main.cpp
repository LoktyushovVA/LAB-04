#include <iostream>
#include <cassert>
using namespace std;

char nibble_to_hex (uint8_t i)
{
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}
void print_in_hex (uint8_t byte)
{ //переводит одну половину потом другую
    cout << nibble_to_hex(byte >> 4)
         << nibble_to_hex(byte & 0xf);//вторая половина
}
const uint8_t* as_bytes(const void* data)
//передаем непонятную херню для того чтобы сделать понятную
//значение одного типа нужна трактовать как значение дргуго


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
char bit_digit(uint8_t byte, uint8_t bit)
{
    if (byte & (0x1 << bit))
    {
        return '1';
    }
    return '0';
}
void print_in_binary(uint8_t byte)
{
    for (uint8_t bit = 7; bit > 0; bit--)
    {
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit(byte, 0);
}
void print_in_binary(const void* data, size_t size)
{
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++)
    {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }
}

void bitcalc()
{
    uint16_t operand1,operand2,result;
    char op; // îïðåàòîð

    cin>> operand1>>op>>operand2;
    assert(op == '&' || op=='|' || op=='^');
    switch (op)
    {
    case '&':
        result = operand1 & operand2;
        break;
    case '|':
        result = operand1 | operand2;
        break;
    case '^':
        result = operand1 ^ operand2;
        break;
  //  default: cout<<"incorrect operator";
    }
    print_in_hex(&operand1, sizeof(operand1));
    cout<<op<<" ";
    print_in_hex(&operand2, sizeof(operand2));
    cout<<"= ";
    print_in_hex(&result, sizeof(result));
    cout<<'\n';

    print_in_binary(&operand1, sizeof(operand1));
    cout<<op<<" ";
    print_in_binary(&operand2, sizeof(operand2));
    cout<<"= ";
    print_in_binary(&result, sizeof(result));
}

struct Student
{
    char name[17];
    uint32_t year;
    float sred_ball;
    int sex:1;
    uint8_t courses;
    Student*starosta;
};
int main()
{
    bitcalc();
    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
    Student studarray[3]=
    {
        {"Nicolai", 2001, 4.7, 0, 7, &studarray[1]},
        {"Sofia", 1999, 4.2, 1, 7, nullptr },
        {"Ruslan", 2000, 3.8, 1, 7, &studarray[1]}
    };
    cout<<"Address of array: "<< &studarray<<'\n';
    cout<<"Size of array: "<< sizeof(studarray)<<'\n';
    cout<<"\t Address of elem:\t Size of elem:\n";
    for (int i=0; i<3; i++)
    {
        cout<<i<<":\t "<<&studarray[i]<<"\t\t "<< sizeof(studarray[i])<<'\n';
    }
    cout<<"FIRST ELEMENT\n";
    cout<<"\t Address of field: \t Size of field\t Offset:\n";
    cout<<"NAME: \t\t"<<&studarray[0].name<<"\t\t"<<sizeof(studarray[0].name)
        <<'\t'<<offsetof(struct Student, name)<<'\n';
    cout<<"Binary: ";
    print_in_binary(&studarray[0].name, sizeof(studarray[0].name));
    cout<<"Hex: ";
    print_in_hex(&studarray[0].name, sizeof(studarray[0].name));
    cout<<"\nYEAR: \t\t"<<&studarray[0].year <<"\t\t"<<sizeof(studarray[0].year)
        <<'\t'<<offsetof(struct Student, year)<<'\n';
    cout<<"Binary: ";
    print_in_binary(&studarray[0].year, sizeof(studarray[0].year));
    cout<<"Hex: ";
    print_in_hex(&studarray[0].year, sizeof(studarray[0].year));
    cout<<"\nSRED BALL: \t\t"<<&studarray[0].sred_ball<<"\t\t"
        <<sizeof(studarray[0].sred_ball)
        <<'\t'<<offsetof(struct Student, sred_ball)<<'\n';
    cout<<"Binary: ";
    print_in_binary(&studarray[0].sred_ball, sizeof(studarray[0].sred_ball));
    cout<<"Hex: ";
    print_in_hex(&studarray[0].sred_ball, sizeof(studarray[0].sred_ball));
    return 0;
}
