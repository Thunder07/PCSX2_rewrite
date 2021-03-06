#include "Common/Global/Globals.h"
#include "Common/Types/Register/PCRegister32_t.h"
#include "Common/Types/Register/LinkRegister128_t.h"
#include "Common/Types/Register/Register128_t.h"

#include "VM/Systems/EE/EECoreInterpreter/EECoreInterpreter_s.h"

#include "Resources/EE/EECore/EECore_t.h"
#include "Resources/EE/EECore/Types/EECoreR5900_t.h"

void EECoreInterpreter_s::BGEZAL()
{
	// BRANCH_LINK(Rs >= 0). No exceptions.
	auto& source1Reg = mEECore->R5900->GPR[mEECoreInstruction.getRs()];
	auto offset = mEECoreInstruction.getIImmS();

	auto source1Val = static_cast<s64>(source1Reg->readDword(getContext(), 0));

	if (source1Val >= 0)
	{
		mEECore->R5900->LinkRegister->setLinkAddress(getContext());
		mEECore->R5900->PC->setBranchPCIOffset(getContext(), offset, 2);
	}
}

void EECoreInterpreter_s::BGEZALL()
{
	// BRANCH_LINK(Rs >= 0). No exceptions.
	auto& source1Reg = mEECore->R5900->GPR[mEECoreInstruction.getRs()];
	auto offset = mEECoreInstruction.getIImmS();

	auto source1Val = static_cast<s64>(source1Reg->readDword(getContext(), 0));

	if (source1Val >= 0)
	{
		mEECore->R5900->LinkRegister->setLinkAddress(getContext());
		mEECore->R5900->PC->setBranchPCIOffset(getContext(), offset, 2);
	}
	else
		mEECore->R5900->PC->next(getContext()); // Immediate jump to the instruction at PC + 8 (nullify next instruction).
}

void EECoreInterpreter_s::BLTZAL()
{
	// BRANCH_LINK(Rs < 0). No exceptions.
	auto& source1Reg = mEECore->R5900->GPR[mEECoreInstruction.getRs()];
	auto offset = mEECoreInstruction.getIImmS();

	auto source1Val = static_cast<s64>(source1Reg->readDword(getContext(), 0));

	if (source1Val < 0)
	{
		mEECore->R5900->LinkRegister->setLinkAddress(getContext());
		mEECore->R5900->PC->setBranchPCIOffset(getContext(), offset, 2);
	}
}

void EECoreInterpreter_s::BLTZALL()
{
	// BRANCH_LINK(Rs < 0). No exceptions.
	auto& source1Reg = mEECore->R5900->GPR[mEECoreInstruction.getRs()];
	auto offset = mEECoreInstruction.getIImmS();

	auto source1Val = static_cast<s64>(source1Reg->readDword(getContext(), 0));

	if (source1Val < 0)
	{
		mEECore->R5900->LinkRegister->setLinkAddress(getContext());
		mEECore->R5900->PC->setBranchPCIOffset(getContext(), offset, 2);
	}
	else
		mEECore->R5900->PC->next(getContext()); // Immediate jump to the instruction at PC + 8 (nullify next instruction).
}

void EECoreInterpreter_s::JAL()
{
	// JUMP_LINK(). No exceptions.
	mEECore->R5900->LinkRegister->setLinkAddress(getContext());
	mEECore->R5900->PC->setBranchPCJRegion(getContext(), mEECoreInstruction.getJRegionAddress(), 2);
}

void EECoreInterpreter_s::JALR()
{
	// JUMP_LINK_REGISTER(). Address error exception generated upon instruction load - but not in this instruction.
	auto& sourceReg = mEECore->R5900->GPR[mEECoreInstruction.getRs()];
	auto& destReg = mEECore->R5900->GPR[mEECoreInstruction.getRRd()];

	destReg->writeDword(getContext(), 0, static_cast<u64>(mEECore->R5900->PC->readWord(getContext()) + Constants::MIPS::SIZE_MIPS_INSTRUCTION * 2));
	mEECore->R5900->PC->setBranchPCAbsolute(sourceReg->readWord(getContext(), 0), 2);
}
