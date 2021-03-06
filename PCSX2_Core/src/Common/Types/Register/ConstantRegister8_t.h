#pragma once

#include "Common/Global/Globals.h"
#include "Common/Types/Register/Register8_t.h"

/*
ConstantRegister8_t is used as a register with a constant value. Any writes are discarded, and any reads are the value set at creation.
By default set to all 0.
*/
class ConstantRegister8_t : public Register8_t
{
public:
	ConstantRegister8_t(const char * mnemonic, const bool debugReads, const bool debugWrites, const u8 B = 0);
	
	/*
	Overwritten write functions that discard any value.
	*/
	void writeByte(const System_t context, const u8 value) override;

	/*
	Initialise register (set to do nothing).
	*/
	void initialise() override;
};

