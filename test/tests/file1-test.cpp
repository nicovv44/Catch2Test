#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>

#include "../../src/file1.cpp"

TEST_CASE( "int return1()", "test return 1" ) {

    SECTION("the only case"){
        REQUIRE( return1() == 1 );
    }
}

TEST_CASE( "int returnDoube()", "test return the double" ) {

    SECTION("positive"){
        int x;
        for (x=0; x<100; x++){
            REQUIRE( returnDouble(x) == 2*x );
        }
        
    }
}