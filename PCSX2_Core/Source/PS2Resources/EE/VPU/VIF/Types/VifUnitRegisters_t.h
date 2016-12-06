#pragma once

#include "Common/Global/Globals.h"
#include "Common/Types/Registers/BitfieldRegister32_t.h"

/*
The VIF CYCLE register - Data write cycle.
See EE Users Manual page 127.
*/
class VifUnitRegister_CYCLE_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 CL = 0;
		static constexpr u8 WL = 1;
	};

	VifUnitRegister_CYCLE_t();

};

/*
The VIF MASK register - Write mask pattern.
See EE Users Manual page 128.
*/
class VifUnitRegister_MASK_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 m0 = 0;
		static constexpr u8 m1 = 1;
		static constexpr u8 m2 = 2;
		static constexpr u8 m3 = 3;
		static constexpr u8 m4 = 4;
		static constexpr u8 m5 = 5;
		static constexpr u8 m6 = 6;
		static constexpr u8 m7 = 7;
		static constexpr u8 m8 = 8;
		static constexpr u8 m9 = 9;
		static constexpr u8 m10 = 10;
		static constexpr u8 m11 = 11;
		static constexpr u8 m12 = 12;
		static constexpr u8 m13 = 13;
		static constexpr u8 m14 = 14;
		static constexpr u8 m15 = 15;
	};

	VifUnitRegister_MASK_t();

};

/*
The VIF MODE register - Addition mode.
See EE Users Manual page 129.
*/
class VifUnitRegister_MODE_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 MOD = 0;
	};

	VifUnitRegister_MODE_t();

};

/*
The VIF ITOP register - ITOP value.
See EE Users Manual page 130.
*/
class VifUnitRegister_ITOP_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 ITOP = 0;
	};

	VifUnitRegister_ITOP_t();

};

/*
The VIF ITOPS register - Following ITOP value.
See EE Users Manual page 131.
*/
class VifUnitRegister_ITOPS_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 ITOPS = 0;
	};

	VifUnitRegister_ITOPS_t();

};

/*
The VIF BASE register - Double buffer base address.
See EE Users Manual page 132.
*/
class VifUnitRegister_BASE_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 BASE = 0;
	};

	VifUnitRegister_BASE_t();

};

/*
The VIF OFST register - Double buffer offset.
See EE Users Manual page 133.
*/
class VifUnitRegister_OFST_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 OFFSET = 0;
	};

	VifUnitRegister_OFST_t();

};

/*
The VIF TOP register - TOP value.
See EE Users Manual page 134.
*/
class VifUnitRegister_TOP_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 TOP = 0;
	};

	VifUnitRegister_TOP_t();

};

/*
The VIF TOPS register - Next TOP value / data write address.
See EE Users Manual page 135.
*/
class VifUnitRegister_TOPS_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 TOPS = 0;
	};

	VifUnitRegister_TOPS_t();

};

/*
The VIF MARK register - Mark value.
See EE Users Manual page 136.
*/
class VifUnitRegister_MARK_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 MARK = 0;
	};

	VifUnitRegister_MARK_t();

};

/*
The VIF NUM register - Amount of unwritten data.
See EE Users Manual page 137.
*/
class VifUnitRegister_NUM_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 NUM = 0;
	};

	VifUnitRegister_NUM_t();

};

/*
The VIF CODE register - Most recently processed VIFcode.
See EE Users Manual page 139.
*/
class VifUnitRegister_CODE_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 IMMEDIATE = 0;
		static constexpr u8 NUM = 1;
		static constexpr u8 CMD = 2;
	};

	VifUnitRegister_CODE_t();

};

/*
The VIF STAT register - VIF status.
Some fields are unused for the VIF0 unit (VGW, DBF and FDR).
See EE Users Manual page 140.
*/
class VifUnitRegister_STAT_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 VPS = 0;
		static constexpr u8 VEW = 1;
		static constexpr u8 VGW = 2;
		static constexpr u8 MRK = 3;
		static constexpr u8 DBF = 4;
		static constexpr u8 VSS = 5;
		static constexpr u8 VFS = 6;
		static constexpr u8 VIS = 7;
		static constexpr u8 INT = 8;
		static constexpr u8 ER0 = 9;
		static constexpr u8 ER1 = 10;
		static constexpr u8 FDR = 11;
		static constexpr u8 FQC = 12;
	};

	VifUnitRegister_STAT_t();

};

/*
The VIF FBRST register - VIF operation control.
See EE Users Manual page 141.
*/
class VifUnitRegister_FBRST_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 RST = 0;
		static constexpr u8 FBK = 1;
		static constexpr u8 STP = 2;
		static constexpr u8 STC = 3;
	};

	VifUnitRegister_FBRST_t();

};

/*
The VIF ERR register - VIF error status.
See EE Users Manual page 142.
*/
class VifUnitRegister_ERR_t : public BitfieldRegister32_t
{
public:
	struct Fields
	{
		static constexpr u8 MII = 0;
		static constexpr u8 ME0 = 1;
		static constexpr u8 ME1 = 2;
	};

	VifUnitRegister_ERR_t();

};