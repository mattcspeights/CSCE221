#include <iostream>
#include <string>

using namespace std::string_literals;

template <typename T>
void increment(T t)
{
    ++t;
}

template <typename Addable>
class Adder
{
    Addable a;
    Addable b;

public:
    Adder(const Addable& a, const Addable& b): a{a}, b{b} {}

    Addable add() const { return a + b; }
};

int main(){
    increment<int>(1);
    increment<double>(3.14);
    increment<char>('a');

    increment("c-string");
}