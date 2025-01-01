#include <iostream>
#include <vector>
#include <cassert>
 
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
 
    for (const int& i : v) // access by const reference
        std::cout << i << ' ';
    std::cout << '\n';
 
    for (auto i : v) // access by value, the type of i is int
        std::cout << i << ' ';
    std::cout << '\n';
    
    for (auto&& i : v) // access by forwarding reference, the type of i is int&
        std::cout << i << ' ';
    std::cout << '\n';

    int a[] = {0, 1, 2, 3, 4, 5};
    for (int n : a) // the initializer may be an array
        std::cout << n << ' ';
    std::cout << '\n';
 
    for (auto n = v.size(); auto i : v) // the init-statement (C++20)
        std::cout << i + n << ' ';
    std::cout << '\n';
    
    auto print = [](const int& n) { std::cout << n << ' '; };

    std::cout << "before:\t";
    std::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';
    
    // increment elements in-place
    std::for_each(v.begin(), v.end(), [](int &n) { n++; });
 
    std::cout << "after:\t";
    std::for_each(v.cbegin(), v.cend(), print);
    std::cout << '\n';
    
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << ' ';

    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    if (std::find(std::begin(v), std::end(v), 5) != std::end(v))
        std::cout << "Found a 5 in vector v!\n";
 
    assert(std::size(v) == 5);
    std::cout << v.size();
    
    std::vector<int>::reverse_iterator vi = std::rbegin(v);
    std::cout << "\n*vi = " << *vi << '\n';
 
    *std::rbegin(v) = 42; // OK: after assignment v[2] == 42
    //*std::crbegin(v) = 13; // error: the location is read-only
 
    int arr[] = {-5, 10, 15};
    std::reverse_iterator<int*> ai = std::rbegin(arr); // the type of “ai” is std::reverse_iterator<int*>
    std::cout << "*ai = " << *ai << '\n';
 
    auto il = {3, 1, 4};
    // the type of “it” below is std::reverse_iterator<int const*>:
    for (auto it = std::rbegin(il); it != std::rend(il); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';
 
}