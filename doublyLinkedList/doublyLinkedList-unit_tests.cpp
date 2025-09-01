#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "doublyLinkedList.h"  

TEST_CASE("DLList Count Function", "[DLList][count]") 
{

    SECTION("Occurrence of an element in a list") 
    {
        DLList<int> list;
        list += 3;
        list += 5;
        list += 3;
        list += 7;
        list += 3;

        
    REQUIRE(DLList<int>::count(&list, 3) == 3);
    REQUIRE(DLList<int>::count(&list, 5) == 1);
    REQUIRE(DLList<int>::count(&list, 7) == 1);
    REQUIRE(DLList<int>::count(&list, 42) == 0);
    }

}