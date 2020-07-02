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

#pragma once

#include <string>

namespace mt
{

// primitive class used to hold "Key" information of a Pitch
class Key
{
    public:
        enum class Type { A, B, C, D, E, F, G };
        
        Key (Type keyType = Type::C);
        Type getType();
        std::string toString();

    private:
        Type type;

};


// primitive class used to hold the type of Accidental a Pitch has
class Accidental
{
    public:
        enum class Type { natural, flat, sharp, double_flat, double_sharp };

        Accidental( Type t = Type::natural );
        Type getType();
        std::string toString();
    
    private:
        Type type;
};

// class used to hold Pitch information.
class Pitch
{
    public:
        Pitch( Key k = Key(Key::Type::C), Accidental a = Accidental(Accidental::Type::natural), unsigned short o = 4 );
        Pitch( std::string val );
        Pitch( unsigned short midi_value, bool use_sharps = true );

        Key getKey();
        Accidental getAccidental();
        unsigned short getOctave();
        unsigned short getMidiValue();
        unsigned short getMidiValue(std::string val);
        double getFrequency();
        std::string toString();

    private:
        Key key;
        Accidental accidental;
        unsigned short octave;
};

} // namespace mt
