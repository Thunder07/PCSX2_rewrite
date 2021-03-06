#include "Resources/EE/EECore/Types/EECoreCOP0Registers_t.h"

EECoreCOP0Register_Index_t::EECoreCOP0Register_Index_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::Index, "Index", 0, 6, 0);
	registerField(Fields::P, "P", 31, 1, 0);
}

EECoreCOP0Register_Random_t::EECoreCOP0Register_Random_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::Random, "Random", 0, 6, 47);
}

EECoreCOP0Register_EntryLo0_t::EECoreCOP0Register_EntryLo0_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::G, "G", 0, 1, 0);
	registerField(Fields::V, "V", 1, 1, 0);
	registerField(Fields::D, "D", 2, 1, 0);
	registerField(Fields::C, "C", 3, 3, 0);
	registerField(Fields::PFN, "PFN", 6, 20, 0);
	registerField(Fields::S, "S", 31, 1, 0);
}

EECoreCOP0Register_EntryLo1_t::EECoreCOP0Register_EntryLo1_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::G, "G", 0, 1, 0);
	registerField(Fields::V, "V", 1, 1, 0);
	registerField(Fields::D, "D", 2, 1, 0);
	registerField(Fields::C, "C", 3, 3, 0);
	registerField(Fields::PFN, "PFN", 6, 20, 0);
}

EECoreCOP0Register_System_t::EECoreCOP0Register_System_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::BadVPN2, "BadVPN2", 4, 19, 0);
	registerField(Fields::PTEBase, "PTEBase", 23, 9, 0);
}

EECoreCOP0Register_PageMask_t::EECoreCOP0Register_PageMask_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::MASK, "MASK", 13, 12, 0);
}

EECoreCOP0Register_Wired_t::EECoreCOP0Register_Wired_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::Wired, "Wired", 0, 6, 0);
}

EECoreCOP0Register_Count_t::EECoreCOP0Register_Count_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	Register32_t(mnemonic, debugReads, debugWrites)
{
}

void EECoreCOP0Register_Count_t::increment(const System_t context, const size_t value)
{
	writeWord(context, readWord(context) + static_cast<u32>(value));
}

EECoreCOP0Register_EntryHi_t::EECoreCOP0Register_EntryHi_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::ASID, "ASID", 0, 8, 0);
	registerField(Fields::VPN2, "VPN2", 13, 19, 0);
}

EECoreCOP0Register_Status_t::EECoreCOP0Register_Status_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::IE, "IE", 0, 1, 0);
	registerField(Fields::EXL, "EXL", 1, 1, 0);
	registerField(Fields::ERL, "ERL", 2, 1, 1);
	registerField(Fields::KSU, "KSU", 3, 2, 0);
	registerField(Fields::IM, "IM", 8, 8, 0);
	registerField(Fields::EIE, "EIE", 16, 1, 0);
	registerField(Fields::EDI, "EDI", 17, 1, 0);
	registerField(Fields::CH, "CH", 18, 1, 0);
	registerField(Fields::BEV, "BEV", 22, 1, 1);
	registerField(Fields::DEV, "DEV", 23, 1, 0);
	registerField(Fields::CU, "CU", 28, 4, 0);
}

bool EECoreCOP0Register_Status_t::isInterruptsMasked(const System_t context)
{
	return !((getFieldValue(context, Fields::ERL) == 0)
		&& (getFieldValue(context, Fields::EXL) == 0)
		&& (getFieldValue(context, Fields::IE) > 0) 
		&& (getFieldValue(context, Fields::EIE) > 0));
}

EECoreCOP0Register_Cause_t::EECoreCOP0Register_Cause_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::ExcCode, "ExcCode", 2, 5, 0);
	registerField(Fields::IP, "IP", 8, 8, 0);
	registerField(Fields::EXC2, "EXC2", 16, 3, 0);
	registerField(Fields::CE, "CE", 28, 2, 0);
	registerField(Fields::BD2, "BD2", 30, 1, 0);
	registerField(Fields::BD, "BD", 31, 1, 0);
}

void EECoreCOP0Register_Cause_t::clearIP(const System_t context)
{
	u32 temp = readWord(context) & 0xFFFF00FF;
	writeWord(context, temp);
}

void EECoreCOP0Register_Cause_t::setIRQLine(const System_t context, const int irq)
{
	auto temp = getFieldValue(context, Fields::IP) | (1 << irq);
	setFieldValue(context, Fields::IP, temp);
}

void EECoreCOP0Register_Cause_t::clearIRQLine(const System_t context, const int irq)
{
	auto temp = (getFieldValue(context, Fields::IP) & (~(1 << irq))) & 0xFF; // 0xFF mask to strip off any other bits as a safety precaution.
	setFieldValue(context, Fields::IP, temp);
}

EECoreCOP0Register_PRId_t::EECoreCOP0Register_PRId_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::Rev, "Rev", 0, 8, 0x20); // Same as old PCSX2.
	registerField(Fields::Imp, "Imp", 8, 8, 0x2E);
}

EECoreCOP0Register_Config_t::EECoreCOP0Register_Config_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::K0, "K0", 0, 3, 0);
	registerField(Fields::DC, "DC", 6, 3, 1);
	registerField(Fields::IC, "IC", 9, 3, 2);
	registerField(Fields::BPE, "BPE", 12, 1, 0);
	registerField(Fields::NBE, "NBE", 13, 1, 0);
	registerField(Fields::DCE, "DCE", 16, 1, 0);
	registerField(Fields::ICE, "ICE", 17, 1, 0);
	registerField(Fields::DIE, "DIE", 18, 1, 0);
	registerField(Fields::EC, "EC", 28, 3, 0);
}

EECoreCOP0Register_BadPAddr_t::EECoreCOP0Register_BadPAddr_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::BadPAddr, "BadPAddr", 4, 28, 0);
}

EECoreCOP0Register_BPC_t::EECoreCOP0Register_BPC_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::IAB, "IAB", 0, 1, 0);
	registerField(Fields::DRB, "DRB", 1, 1, 0);
	registerField(Fields::DWB, "DWB", 2, 1, 0);
	registerField(Fields::BED, "BED", 15, 1, 0);
	registerField(Fields::DTE, "DTE", 16, 1, 0);
	registerField(Fields::ITE, "ITE", 17, 1, 0);
	registerField(Fields::DXE, "DXE", 18, 1, 0);
	registerField(Fields::DKE, "DKE", 19, 1, 0);
	registerField(Fields::DSE, "DSE", 20, 1, 0);
	registerField(Fields::DUE, "DUE", 21, 1, 0);
	registerField(Fields::IXE, "IXE", 23, 1, 0);
	registerField(Fields::IKE, "IKE", 24, 1, 0);
	registerField(Fields::ISE, "ISE", 25, 1, 0);
	registerField(Fields::IUE, "IUE", 26, 1, 0);
	registerField(Fields::DVE, "DVE", 28, 1, 0);
	registerField(Fields::DWE, "DWE", 29, 1, 0);
	registerField(Fields::DRE, "DRE", 30, 1, 0);
	registerField(Fields::IAE, "IAE", 31, 1, 0);
}

EECoreCOP0Register_PCCR_t::EECoreCOP0Register_PCCR_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::EXL0, "EXL0", 1, 1, 0);
	registerField(Fields::K0, "K0", 2, 1, 0);
	registerField(Fields::S0, "S0", 3, 1, 0);
	registerField(Fields::U0, "U0", 4, 1, 0);
	registerField(Fields::EVENT0, "EVENT0", 5, 5, 0);
	registerField(Fields::EXL1, "EXL1", 11, 1, 0);
	registerField(Fields::K1, "K1", 12, 1, 0);
	registerField(Fields::S1, "S1", 13, 1, 0);
	registerField(Fields::U1, "U1", 14, 1, 0);
	registerField(Fields::EVENT1, "EVENT1", 15, 5, 0);
	registerField(Fields::CTE, "CTE", 31, 1, 0);
}

EECoreCOP0Register_PCR0_t::EECoreCOP0Register_PCR0_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::VALUE, "VALUE", 0, 31, 0);
	registerField(Fields::OVFL, "OVFL", 31, 1, 0);
}

EECoreCOP0Register_PCR1_t::EECoreCOP0Register_PCR1_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::VALUE, "VALUE", 0, 31, 0);
	registerField(Fields::OVFL, "OVFL", 31, 1, 0);
}

EECoreCOP0Register_TagLo_t::EECoreCOP0Register_TagLo_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::L, "L", 3, 1, 0);
	registerField(Fields::R, "R", 4, 1, 0);
	registerField(Fields::V, "V", 5, 1, 0);
	registerField(Fields::D, "D", 6, 1, 0);
	registerField(Fields::PTagLo, "PTagLo", 12, 31, 0);
}

EECoreCOP0Register_TagHi_t::EECoreCOP0Register_TagHi_t(const char * mnemonic, const bool debugReads, const bool debugWrites) :
	BitfieldRegister32_t(mnemonic, debugReads, debugWrites)
{
	registerField(Fields::L, "L", 3, 1, 0);
	registerField(Fields::R, "R", 4, 1, 0);
	registerField(Fields::V, "V", 5, 1, 0);
	registerField(Fields::D, "D", 6, 1, 0);
	registerField(Fields::PTagHi, "PTagHi", 12, 31, 0);
}