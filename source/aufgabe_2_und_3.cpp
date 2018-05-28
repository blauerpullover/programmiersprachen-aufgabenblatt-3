#include <iostream>
#include <list>
#include <set>
#include <map>
#include <vector>

int main ()
{   
    //////////////////////////////////3.2/////////////////////////////////////
    
    srand(time(NULL));
    // Liste
    std::list<unsigned int> list(100,0);
    std::list<unsigned int> newlist;
    // Funktor für random
    auto random = [] () -> unsigned int { return rand() % 101;};

    generate(list.begin(), list.end(), random);

    //std::cout << "mylist stores " << list.size() << " numbers.\n";

   /*  //ausgabe liste
    for (auto i = list.begin(); i != list.end(); ++i){
        std::cout << *i <<" ";
    } */

    std::set<unsigned int> set_of_list (list.begin(), list.end());
    //std::cout << "\n my list stores " << set_of_list.size() << " different numbers.\n";

    for(int j = 0; j < 100; ++j){
        if(set_of_list.find(j) == set_of_list.end()){
            newlist.push_back (j);
        }
    }
   /*  //Ausgabe newlist mit Nummern, die nicht in list sind
    for (auto i = newlist.begin(); i != newlist.end(); ++i){
        std::cout << *i <<" ";
    } */

    //////////////////////////////////3.3/////////////////////////////////////
    //(Zahl : Häufigkeit)
    std::map<int, int> map1;
    std::map<unsigned int,int>::iterator it;


    for(auto i : list){
        map1.insert(std::make_pair(i,0));
        ++map1[i];
    }

    for(auto i = map1.begin(); i != map1.end(); ++i){
        std::cout << i->first << " : "<< i->second << "\n";
    }


    ///////////////////////////3.10/////////////////////////////////////////

    std::vector<unsigned int> v(100);
    std::copy ( list.begin(), list.end(), std::back_inserter(v) );


   return 0;
}
