#include <climits>

#include "Common/Global/Globals.h"
#include "Common/Util/MathUtil/MathUtil.h"

u32 MathUtil::countLeadingBits(s32 value)
{
	// If the value is 0, return 32 automatically.
	if (value == 0)
		return 32;

	// If the sign bit is 1, we invert the bits to 0 for count-leading-zero.
	if (value < 0)
		value = ~value;

	// Perform our count leading zero.
	u32 num_leading_bits = 0;
	for (int i = CHAR_BIT * sizeof value; i > 0; i--)
	{
		if ((value & (1 << (i - 1))) == 0)
			num_leading_bits++;
		else
			break;
	}

	return num_leading_bits;
}

u32 MathUtil::constructMask32(int startPos, int length)
{
	// Due to how x86 (and possibly other arch's) shift, we need a solution for the case when length == 32, as it generates a bad mask.
	// Old method: mask = (1 << param) - 1;
	// Algorithm from here (thanks to Siu Ching Pong): http://stackoverflow.com/questions/1392059/algorithm-to-generate-bit-mask
	return (static_cast<u32>(-(length != 0)) & (static_cast<u32>(-1) >> (32 - length))) << startPos;
}

u32 MathUtil::extractMaskedValue32(u32 value, int maskStartPos, int maskLength)
{
	const u32 mask = constructMask32(maskStartPos, maskLength);
	return ((value & mask) >> maskStartPos);
}

u32 MathUtil::insertMaskedValue32(u32 value, u32 insertValue, int maskStartPos, int maskLength)
{
	const u32 mask = constructMask32(maskStartPos, maskLength);
	const u32 insertValueShifted = (insertValue << maskStartPos) & mask;
	return ((value & ~mask) | insertValueShifted);
}

u16 MathUtil::constructMask16(int startPos, int length)
{
	// Due to how x86 (and possibly other arch's) shift, we need a solution for the case when length == 16, as it generates a bad mask.
	// Old method: mask = (1 << param) - 1;
	// Algorithm from here (thanks to Siu Ching Pong): http://stackoverflow.com/questions/1392059/algorithm-to-generate-bit-mask
	return (static_cast<u16>(-(length != 0)) & (static_cast<u16>(-1) >> (16 - length))) << startPos;
}

u16 MathUtil::extractMaskedValue16(u16 value, int maskStartPos, int maskLength)
{
	const u16 mask = constructMask16(maskStartPos, maskLength);
	return ((value & mask) >> maskStartPos);
}

u16 MathUtil::insertMaskedValue16(u16 value, u16 insertValue, int maskStartPos, int maskLength)
{
	const u16 mask = constructMask16(maskStartPos, maskLength);
	const u16 insertValueShifted = (insertValue << maskStartPos) & mask;
	return ((value & ~mask) | insertValueShifted);
}

s16 MathUtil::saturateWordToHword(s32 value)
{
	if (value > Constants::VALUE_S16_MAX)
		return Constants::VALUE_S16_MAX;
	else if (value < Constants::VALUE_S16_MIN)
		return Constants::VALUE_S16_MIN;
	else 
		return static_cast<s16>(value);
}

s32 MathUtil::saturateDwordToWord(s64 value)
{
	if (value > Constants::VALUE_S32_MAX)
		return Constants::VALUE_S32_MAX;
	else if (value < Constants::VALUE_S32_MIN)
		return Constants::VALUE_S32_MIN;
	else
		return static_cast<s32>(value);
}

u32 MathUtil::log2N(u32 value)
{
	static const u32 b[] = { 0xAAAAAAAA, 0xCCCCCCCC, 0xF0F0F0F0, 0xFF00FF00, 0xFFFF0000 };

	u32 r = (value & b[0]) != 0;

	for (u32 i = 4; i > 0; i--) // unroll for speed...
		r |= ((value & b[i]) != 0) << i;

	return r;
}

bool MathUtil::testOverflow32(s32 x, s32 y)
{
	if (((x > 0) && (y > Constants::VALUE_S32_MAX - x)))
	{
		return true;
	}

	return false;
}

bool MathUtil::testUnderflow32(s32 x, s32 y)
{
	if (((x < 0) && (y < Constants::VALUE_S32_MIN - x)))
	{
		return true;
	}

	return false;
}

bool MathUtil::testOverOrUnderflow32(s32 x, s32 y)
{
	if (((x > 0) && (y > Constants::VALUE_S32_MAX - x))
		|| ((x < 0) && (y < Constants::VALUE_S32_MIN - x)))
	{
		return true;
	}
	
	return false;
}

bool MathUtil::testOverflow64(s64 x, s64 y)
{
	if (((x > 0) && (y > Constants::VALUE_S64_MAX - x)))
	{
		return true;
	}

	return false;
}

bool MathUtil::testUnderflow64(s64 x, s64 y)
{
	if (((x < 0) && (y < Constants::VALUE_S64_MIN - x)))
	{
		return true;
	}

	return false;
}

bool MathUtil::testOverOrUnderflow64(s64 x, s64 y)
{
	if (((x > 0) && (y > Constants::VALUE_S64_MAX - x))
		|| ((x < 0) && (y < Constants::VALUE_S64_MIN - x)))
	{
		return true;
	}

	return false;
}

u32 MathUtil::getHI19(u32 value)
{
	return (value & 0xFFFFE000) >> 19;
}
