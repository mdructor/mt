/*
    MIT License

    Copyright (c) 2020 Mason Dructor

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/

#pragma once

#include <cmath>     // std::pow
#include <stdexcept> // std::runtime_error
#include <string>    // std::string
#include <vector>    // std::vector

namespace mt
{

//! Primitive class used to hold the key type/name of a Pitch
class Key
{
  public:
    /** All of the different keys */
    enum class Type
    {
        A,
        B,
        C,
        D,
        E,
        F,
        G
    };

    Key(Type keyType = Type::C);
    Type getType();
    std::string toString();

  private:
    Type type; //! Stores the current type/name of this key
};

//! Primitive class used to hold the type of Accidental a Pitch has
class Accidental
{
  public:
    enum class Type
    {
        natural,
        flat,
        sharp,
        double_flat,
        double_sharp
    };

    Accidental(Type t = Type::natural);
    Type getType();
    std::string toString();

  private:
    Type type;
};

//! Class used to hold Pitch information.
class Pitch
{
  public:
    Pitch(Key k = Key(Key::Type::C), Accidental a = Accidental(Accidental::Type::natural), unsigned short o = 4);
    Pitch(std::string val);
    Pitch(unsigned short midi_value, bool use_sharps = true);

    Key getKey();
    Accidental getAccidental();
    unsigned short getOctave();
    unsigned short getMidiValue();
    double getFrequency();
    std::string toString();

  private:
    Key key;
    Accidental accidental;
    unsigned short octave;
};

//! Represents a generic interval.
/*!
  Purely based on semitones since there is no root being taken into account.
*/
class Interval
{
  public:
    enum class Quality
    {
        perfect,
        major,
        minor,
        augmented,
        dimished
    };
    Interval(Quality q = Quality::perfect, unsigned short degree = 1);
    Interval(unsigned short semitones);

    Quality getQuality();
    unsigned short getDegree();
    unsigned short getSemitones();
    Pitch getPitchFromRoot(Pitch root);
    std::string toString();

  private:
    Quality quality;
    unsigned short degree;
};

//! Holds a vector of intervals to form a generic scale.
class Scale
{
  public:
    Scale(std::vector<Interval> intervals);

    std::vector<Interval> getIntervals();

    std::vector<Pitch> getPitchesFromRoot(Pitch root);

  private:
    std::vector<Interval> intervals;
};

//! Holds a vector of intervals to form a generic scale.
class Chord
{
  public:
    Chord(std::vector<Interval> intervals);

    std::vector<Interval> getIntervals();

    std::vector<Pitch> getPitchesFromRoot(Pitch root);

  private:
    std::vector<Interval> intervals;
};

//! Exception for when a bad call for a new Pitch happens
/*!
  For example, asking for a Pitch out of range of the MIDI keyboard,
  or trying to parse a Pitch with a garbage string
*/
class PitchParsingException : public std::runtime_error
{
  public:
    PitchParsingException(char const *const message) throw() : std::runtime_error(message)
    {
    }
};

//! Exception for when a bad call for a new Interval happens
class InvalidIntervalException : public std::runtime_error
{
  public:
    InvalidIntervalException(char const *const message) throw() : std::runtime_error(message)
    {
    }
};

/**
 * @brief Simple intervals for convenience
 *
 */
namespace Intervals
{
extern Interval P1;
extern Interval m2;
extern Interval M2;
extern Interval m3;
extern Interval M3;
extern Interval P4;
extern Interval A4;
extern Interval P5;
extern Interval m6;
extern Interval M6;
extern Interval m7;
extern Interval M7;
extern Interval P8;
} // namespace Intervals

} // namespace mt
