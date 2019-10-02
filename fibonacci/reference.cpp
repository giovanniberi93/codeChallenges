#include <iostream>
#include <vector>

int fibonacci(int const val)
{
    if (val == 0 || val == 1)
    {
        return val;
    }
    else
    {
        return fibonacci(val - 1) + fibonacci(val - 2);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    int res = fibonacci(atoi(argv[1]));
    std::cout << "fibonacci(" << atoi(argv[1]) << ") = " << res << std::endl;
}

