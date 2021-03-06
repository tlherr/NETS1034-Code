//1. Write a C program in Linux (or your favorite language) that creates an overflow

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char**argv) {
    int flag(0);
    cout << "Overflow Example!" << endl;

    //Allocate Memory for buffer (Reserving 6 Bytes)
    char buffer[6];

    //Output the size of the buffer and the input
    cout << "Buffer is:\t\t" << sizeof(buffer) << " bytes" << endl;
    cout << "Input is:\t\t" << sizeof(argv[1]) << " bytes" << endl;

    //Output the memory locations of the buffer and the flag
    cout << "Buffer is at location:\t\t" << &buffer << endl;
    cout << "Flag is at location:\t\t" << &flag << endl;

    auto *buff_loc = reinterpret_cast<int *>(&buffer);
    auto *flag_loc = reinterpret_cast<int *>(&flag);

    cout << "Distance Between Flag and Buffer:\t\t" << (flag_loc-buff_loc) * sizeof(int) << " bytes" << endl;


    strcpy(buffer, argv[1]);

    cout << "Value of flag: " << flag << endl;

    return 0;
}