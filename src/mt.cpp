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

Pitch::Pitch(Key k, Accidental a, unsigned short o)
{
    key = k;
    accidental = a;
    octave = o;
}

Pitch::Pitch(std::string val)
{
    std::string error_string = "Failed to parse note: " + val;

    if(val.length() < 2 || val.length() > 4) {
        throw PitchParsingException(error_string.c_str());
    }

    // Deal with Key value
    auto fc = val.at(0);

    if (fc >= 'a' && fc <= 'g') {
        key = Key( (Key::Type) (fc - 'a')); 
    }
    else if(fc >= 'A' && fc <= 'G') {
        key = Key ( (Key::Type) (fc - 'A'));
    }
    else {
        throw PitchParsingException(error_string.c_str());
    }

    // Deal with Octave value
    auto lc = val.back();

    if (lc >= '0' && lc <= '9') {
        octave = lc - '0';
    }
    else {
        throw PitchParsingException(error_string.c_str());
    }

    // Deal with accidentals

    if (val.length() > 2) {
        auto fb = val.find_first_of('b');
        auto fs = val.find_first_of('#');
        if (fb == std::string::npos && fs == std::string::npos) {
            throw PitchParsingException(error_string.c_str());
        }
        else {
            if (val.length() > 3) {
                if (fb != std::string::npos) {
                    if (val.find_first_of('b', fb + 1) != std::string::npos) {
                        accidental = Accidental(Accidental::Type::double_flat);
                    }
                    else {
                        throw PitchParsingException(error_string.c_str());
                    }
                }
                else {
                    if (val.find_first_of('#', fs + 1) != std::string::npos) {
                        accidental = Accidental(Accidental::Type::double_sharp);

                    }
                    else {
                        throw PitchParsingException(error_string.c_str());
                    }
                }
            }
            else {
                if (fb != std::string::npos) {
                    accidental = Accidental(Accidental::Type::flat);
                }
                else {
                    accidental = Accidental(Accidental::Type::sharp);
                }
            }
        }
    }
    else {
        accidental = Accidental();
    }
}

Pitch::Pitch(unsigned short midi_value, bool use_sharps) 
{
    std::string error_message = "Couldn't parse midi value to note: " + midi_value;
    if (midi_value > 127 || midi_value < 10) {
        throw PitchParsingException(error_message.c_str());
    }

    int r = midi_value % 12;

    if (r == 0) {
        key = Key(Key::Type::C); 
    }
    else if (r == 1) {
        if (use_sharps) {
            key = Key(Key::Type::C); 
            accidental = Accidental(Accidental::Type::sharp);
        }
        else {
            key = Key(Key::Type::D);
            accidental = Accidental(Accidental::Type::flat);
        }
    }
    else if (r == 2) {
        key = Key(Key::Type::D); 
    }
    else if (r == 3) {
        if (use_sharps) {
            key = Key(Key::Type::D); 
            accidental = Accidental(Accidental::Type::sharp);
        }
        else {
            key = Key(Key::Type::E);
            accidental = Accidental(Accidental::Type::flat);
        }
    }
    else if (r == 4) {
        key = Key(Key::Type::E); 
    }
    else if (r == 5) {
        key = Key(Key::Type::F);
    }
    else if (r == 6) {
        if (use_sharps) {
            key = Key(Key::Type::F); 
            accidental = Accidental(Accidental::Type::sharp);
        }
        else {
            key = Key(Key::Type::G);
            accidental = Accidental(Accidental::Type::flat);
        }
    }
    else if (r == 7) {
        key = Key(Key::Type::G);
    }
    else if (r == 8) {
        if (use_sharps) {
            key = Key(Key::Type::G); 
            accidental = Accidental(Accidental::Type::sharp);
        }
        else {
            key = Key(Key::Type::A);
            accidental = Accidental(Accidental::Type::flat);
        }
    }
    else if (r == 9) {
        key = Key(Key::Type::A);
    }
    else if (r == 10) {
        if (use_sharps) {
            key = Key(Key::Type::A); 
            accidental = Accidental(Accidental::Type::sharp);
        }
        else {
            key = Key(Key::Type::B);
            accidental = Accidental(Accidental::Type::flat);
        }
    }
    else {
        key = Key(Key::Type::B);
    }

    octave = (midi_value - 12) / 12;
}

Key Pitch::getKey() 
{
    return key;
}

Accidental Pitch::getAccidental() 
{
    return accidental;
}

unsigned short Pitch::getOctave()
{
    return octave;
}

unsigned short Pitch::getMidiValue()
{
    int midi_val;
    switch (key.getType()) {
        case Key::Type::A: 
            midi_val = 21; 
            break;
        case Key::Type::B: 
            midi_val = 23;
            break;
        case Key::Type::C:
            midi_val = 12;
            break;
        case Key::Type::D:
            midi_val = 14;
            break;
        case Key::Type::E:
            midi_val = 16;
            break;
        case Key::Type::F:
            midi_val = 17;
            break;
        case Key::Type::G:
            midi_val = 19;
            break;
    }
    switch (accidental.getType()) {
        case Accidental::Type::sharp:
            ++midi_val;
            break;
        case Accidental::Type::flat:
            --midi_val;
            break;
        case Accidental::Type::double_sharp:
            midi_val += 2;
            break;
        case Accidental::Type::double_flat:
            midi_val -= 2;
            break;
        default: break;
    }
    midi_val += (octave * 12);
    return midi_val;
}

double Pitch::getFrequency() 
{
  return std::pow(2, (getMidiValue() - 69)/12.0) * 440;
}

std::string Pitch::toString() 
{
    return key.toString() + accidental.toString() + std::to_string(octave);
}

} // namespace mt