﻿#pragma once

#include <string>

#include "Common/Global/Globals.h"
#include "Common/Types/System_t.h"
#include "Common/Types/DebugBaseObject_t.h"

/*
Register type and size definitions.
Register8, Register16, Register32, Register64 and Register128 define the base register sizes used thoughout the emulator.
Upon initialisation, set to the user defined value if provided (defualt 0).

These registers are implemented (at core) as a union of the unsigned sums (to the register size) of these types.
However, they should be accessed by the read/write functions instead to account for overriden functionality.

TODO: Check byte order / endianess - it is assumed within the emulator that, for example in a 128-bit register:
 Register128_t.UW[0] = bits 0-31.    Least significant bits
 Register128_t.UW[1] = bits 32-63.              |
 Register128_t.UW[2] = bits 64-95.              ↓
 Register128_t.UW[3] = bits 96-127.  Most significant bits

The primary difference between a Register type and Memory type is that registers are accessed by the size index, not by the byte index.
For example, a writeWordU(0, value) will write to the first 0-31 bits, while writeWord(1, value) will write to bits 32-63.
See the Memory type for the counter-example.
*/
class Register8_t : public DebugBaseObject_t
{
public:
	Register8_t(const char * mnemonic, bool debugReads, bool debugWrites, const u8 initialisationValue = 0);
	virtual ~Register8_t() = default;

	/*
	Read/write functions to access the register, with subclassed functionality. 
	*/
	virtual u8 readByte(const System_t context);
	virtual void writeByte(const System_t context, const u8 value);

	/*
	Initialise register (set back to default value).
	*/
	virtual void initialise();

protected:
	/*
	Underlying storage for register.
	*/
	union
	{
		u8 UB;
	};

	/*
	Default initialisation value.
	*/
	u8 mInitialisationValue;
};