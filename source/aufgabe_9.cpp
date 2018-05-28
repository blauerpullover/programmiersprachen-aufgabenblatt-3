#include <cstdlib> // std :: rand ()
#include <vector> // std::vector<>
#include <list> // std::list<>
#include <iostream> // std :: cout
#include <iterator> // std::ostream_iterator <>
#include <algorithm> // std::reverse, std::generate
  

int main () {

    std::vector<int> v_0(10); //vektor

    for (auto& v : v_0) { // v = int
        v = std::rand();
    }

    std::copy(std::cbegin(v_0), std::cend(v_0), // iterator per const& reference
    std::ostream_iterator<int>(std::cout, "\n")); // objekt, wie ein liste copiert von anfang bis ende von v_0
                                                    // (ausgabe, trennzeichen)

    std::list<int> l_0(std::cbegin(v_0),std::cend(v_0)); //list l_0 = v_0
    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0)); // liste l_1 = l_0
    std::reverse(std::begin(l_1), std::end(l_1)); //l_1 umgekehrt
    std::copy(std::cbegin(l_1), std::cend(l_1), // ausgabe wie oben von l_1
    std::ostream_iterator<int>(std::cout, "\n"));
    
    l_1.sort(); // l_1 sortiert von klein nach groß
    std::copy(l_1.cbegin(), l_1.cend(), // ausgabe l_1, c steht für konstant
    std::ostream_iterator<int>(std::cout, "\n"));

    std::generate(std::begin(v_0), std::end(v_0), std::rand); //neue zufallswerte in v_0, wahrscheinlich die gleichen wegen srand time dng
    std::copy(v_0.crbegin(), v_0.crend(),          // const-reverse-iterator -> iteriert rückwärts
    std::ostream_iterator<int>(std::cout, "\n")); // std::cout sind objekte

    return 0; 
}