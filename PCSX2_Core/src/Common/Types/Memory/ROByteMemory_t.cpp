#include "Common/Global/Globals.h"
#include "Common/Types/Memory/ROByteMemory_t.h"

ROByteMemory_t::ROByteMemory_t(const char * mnemonic, bool debugReads, bool debugWrites, const size_t byteSize) :
	ByteMemory_t(mnemonic, debugReads, debugWrites, byteSize)
{
}

void ROByteMemory_t::writeByte(const System_t context, const size_t byteOffset, const u8 value)
{
	// Do not write (read only).
}

void ROByteMemory_t::writeHword(const System_t context, const size_t byteOffset, const u16 value)
{
	// Do not write (read only).
}

void ROByteMemory_t::writeWord(const System_t context, const size_t byteOffset, const u32 value)
{
	// Do not write (read only).
}

void ROByteMemory_t::writeDword(const System_t context, const size_t byteOffset, const u64 value)
{
	// Do not write (read only).
}

void ROByteMemory_t::writeQword(const System_t context, const size_t byteOffset, const u128 value)
{
	// Do not write (read only).
}
