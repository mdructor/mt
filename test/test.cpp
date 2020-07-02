/*
    MIT License

    Copyright (c) 2020 Mason Dructor 

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#define CATCH_CONFIG_MAIN // tells Catch to provide a main()
#include "../src/mt.hpp"
#include "catch.hpp"

TEST_CASE( "Keys can be made of different types", "[Key]" ) {
    REQUIRE( mt::Key(mt::Key::Type::A).toString() == "A" );
    REQUIRE( mt::Key(mt::Key::Type::B).toString() == "B" );
    REQUIRE( mt::Key(mt::Key::Type::C).toString() == "C" );
    REQUIRE( mt::Key(mt::Key::Type::D).toString() == "D" );
    REQUIRE( mt::Key(mt::Key::Type::D).toString() == "E" );
    REQUIRE( mt::Key(mt::Key::Type::D).toString() == "F" );
    REQUIRE( mt::Key(mt::Key::Type::D).toString() == "G" );
}