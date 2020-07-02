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

#include "mt.hpp"

namespace mt 
{

Key::Key(Key::Type t) 
{
    type = t;
}

Key::Type Key::getType() 
{
    return type;
}

std::string Key::toString() 
{
    switch(type) {
        case Type::A: return "A";
        case Type::B: return "B";
        case Type::C: return "C";
        case Type::D: return "D";
        case Type::E: return "E";
        case Type::F: return "F";
        case Type::G: return "G";
    }
    return "";
}

Accidental::Accidental(Accidental::Type t)
{
    type = t;
}

Accidental::Type Accidental::getType()
{
    return type;
}

std::string Accidental::toString()
{
    switch(type) {
        case Type::natural: return "";
        case Type::flat: return "b";
        case Type::double_flat: return "bb";
        case Type::sharp: return "#";
        case Type::double_sharp: return "##";
    }
    return "";
}


}