#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()

#include "test_manager.h"
#include "rotate.h"

using namespace graal;

#define which_lib graal
//#define which_lib std // descomente para testar a mesma função usando a biblioteca padrão.

int main ( void )
{
    TestManager tm{ "Graal Test Suite" };
    {
        BEGIN_TEST( tm,"Rotate2", "Block");
        int A[]{ 1, 2, 3, 4, 5, 6, 7 };
        size_t sz{sizeof(A)/sizeof(A[0])};
        int A_E[ ][7]{
            { 1, 2, 3, 4, 5, 6, 7 },
            { 2, 3, 4, 5, 6, 7, 1 },
            { 3, 4, 5, 6, 7, 1, 2 },
            { 4, 5, 6, 7, 1, 2, 3 },
            { 5, 6, 7, 1, 2, 3, 4 },
            { 6, 7, 1, 2, 3, 4, 5 },
            { 7, 1, 2, 3, 4, 5, 6 }
        };

        for ( size_t i{0} ; i <  sz ; ++i ) {
            // Reset original array: copy row 0 over other rows, before rotating.
            std::copy( std::begin(A_E[0]), std::end(A_E[0]), A );
            which_lib::rotate( std::begin(A), std::begin(A)+i, std::end(A) );
            EXPECT_TRUE( std::equal( std::begin(A), std::end(A), std::begin(A_E[i]) ) );
        }

    }

    tm.summary();
    std::cout << std::endl;
    //== Reverse
    return EXIT_SUCCESS;

}
