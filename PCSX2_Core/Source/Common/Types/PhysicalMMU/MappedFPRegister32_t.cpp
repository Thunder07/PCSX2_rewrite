#include "stdafx.h"

#include <memory>

#include "Common/Global/Globals.h"
#include "Common/Types/PhysicalMMU/MappedFPRegister32_t.h"

MappedFPRegister32_t::MappedFPRegister32_t(const u32 physicalAddress, const std::shared_ptr<FPRegister32_t> & fpRegister32) :
	PhysicalMapped_t(physicalAddress),
	mFPRegister32(fpRegister32)
{
}

size_t MappedFPRegister32_t::getSize()
{
	return Constants::NUMBER_BYTES_IN_QWORD;
}

const char* MappedFPRegister32_t::getMnemonic() const
{
	return mFPRegister32->getMnemonic();
}

u8 MappedFPRegister32_t::readByte(const System_t context, size_t storageIndex)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with smaller than allowed size. Not allowed.");
}

void MappedFPRegister32_t::writeByte(const System_t context, size_t storageIndex, u8 value)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with smaller than allowed size. Not allowed.");
}

u16 MappedFPRegister32_t::readHword(const System_t context, size_t storageIndex)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with smaller than allowed size. Not allowed.");
}

void MappedFPRegister32_t::writeHword(const System_t context, size_t storageIndex, u16 value)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with smaller than allowed size. Not allowed.");
}

u32 MappedFPRegister32_t::readWord(const System_t context, size_t storageIndex)
{
	if (storageIndex % Constants::NUMBER_BYTES_IN_WORD != 0)
		throw std::runtime_error("Tried to access MappedFPRegister32_t with unaligned index. Not allowed.");
	return mFPRegister32->readWord(context);
}

void MappedFPRegister32_t::writeWord(const System_t context, size_t storageIndex, u32 value)
{
	if (storageIndex % Constants::NUMBER_BYTES_IN_WORD != 0)
		throw std::runtime_error("Tried to access MappedFPRegister32_t with unaligned index. Not allowed.");
	mFPRegister32->writeWord(context, value);
}

u64 MappedFPRegister32_t::readDword(const System_t context, size_t storageIndex)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with larger than allowed size. Not allowed.");
}

void MappedFPRegister32_t::writeDword(const System_t context, size_t storageIndex, u64 value)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with larger than allowed size. Not allowed.");
}

u128 MappedFPRegister32_t::readQword(const System_t context, size_t storageIndex)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with larger than allowed size. Not allowed.");
}

void MappedFPRegister32_t::writeQword(const System_t context, size_t storageIndex, u128 value)
{
	throw std::runtime_error("Tried to access MappedFPRegister32_t with larger than allowed size. Not allowed.");
}
