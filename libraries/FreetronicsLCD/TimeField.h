/*
 * Copyright (C) 2012 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef TimeField_h
#define TimeField_h

#include "Field.h"

#define TIMEFIELD_READ_ONLY     true
#define TIMEFIELD_READ_WRITE    false

class TimeField : public Field {
public:
    explicit TimeField(const String &label);
    TimeField(Form &form, const String &label, int maxHours, bool readOnly);

    int dispatch(int event);

    void enterField(bool reverse);
    void exitField();

    unsigned long value() const { return _value; }
    void setValue(unsigned long value);

    int maxHours() const { return _maxHours; }
    void setMaxHours(int maxHours) { _maxHours = maxHours; }

    bool readOnly() const { return _readOnly; }
    void setReadOnly(bool value);

private:
    unsigned long _value;
    int _maxHours;
    int _printLen;
    bool _readOnly;
    uint8_t editField;

    void printTime();
    int printField(unsigned long value);
};

#endif
