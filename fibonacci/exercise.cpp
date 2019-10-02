#include <iostream>
#include <map>

std::map<int, int> cache;

int fibonacci(int const val)
{
    if (val == 0 || val == 1)
    {
        return val;
    }
    int fibMinusOne, fibMinusTwo;
    auto firstElIterator = cache.find(val-1);
    auto secondElIterator = cache.find(val-2);
    if (firstElIterator != cache.end())
        fibMinusOne = firstElIterator->second;
    else
    {
        fibMinusOne = fibonacci(val - 1);
        cache.insert(std::pair<int, int>(val-1, fibMinusOne));
    }

    if (secondElIterator != cache.end())
        fibMinusTwo = secondElIterator->second;
    else
    {
        fibMinusTwo = fibonacci(val - 2);
        cache.insert(std::pair<int, int>(val-2, fibMinusTwo));
    }   

    return fibMinusOne + fibMinusTwo;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    int res = fibonacci(atoi(argv[1]));
    std::cout << "fibonacci(" << atoi(argv[1]) << ") = " << res << std::endl;
}

