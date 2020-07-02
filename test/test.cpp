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
    REQUIRE( mt::Key(mt::Key::Type::E).toString() == "E" );
    REQUIRE( mt::Key(mt::Key::Type::F).toString() == "F" );
    REQUIRE( mt::Key(mt::Key::Type::G).toString() == "G" );
}

TEST_CASE( "Accidentals can be made of different types", "[Accidental]" ) {
    REQUIRE( mt::Accidental(mt::Accidental::Type::natural).toString()      == "" );
    REQUIRE( mt::Accidental(mt::Accidental::Type::flat).toString()         == "b" );
    REQUIRE( mt::Accidental(mt::Accidental::Type::double_flat).toString()  == "bb" );
    REQUIRE( mt::Accidental(mt::Accidental::Type::sharp).toString()        == "#" );
    REQUIRE( mt::Accidental(mt::Accidental::Type::double_sharp).toString() == "##" );
}

TEST_CASE( "Pitches and be made with note information, string, or midi value", "[Pitch]" ) {
    REQUIRE( mt::Pitch().toString() == "C4" );
    REQUIRE( mt::Pitch( mt::Key(), mt::Accidental(), 4 ).toString() == "C4" );
    REQUIRE( mt::Pitch("C4").toString() == "C4" );
    REQUIRE( mt::Pitch(60).toString() == "C4" );
}

TEST_CASE( "Pitches can be used to get more information", "[Pitch]" ) {
    mt::Pitch p("Bb3");
    REQUIRE( p.getKey().getType() == mt::Key::Type::B);
    REQUIRE( p.getAccidental().getType() == mt::Accidental::Type::flat );
    REQUIRE( p.getOctave() == 3 );
    REQUIRE( p.toString() == "Bb3" );
    REQUIRE( p.getMidiValue() == 58 );
    REQUIRE( p.getFrequency() == Approx(233.08) );
}