#include "stdafx.h"

#include "VM/ExecutionCore/Interpreter/IOP/IOPCoreInterpreter/IOPCoreInterpreter.h"
#include "VM/ExecutionCore/Interpreter/IOP/IOPCoreInterpreter/IOPCoreMMUHandler/IOPCoreMMUHandler.h"
#include "VM/VMMain.h"
#include "PS2Resources/PS2Resources_t.h"
#include "PS2Resources/IOP/IOP_t.h"
#include "PS2Resources/IOP/IOPCore/IOPCore_t.h"
#include "PS2Resources/IOP/IOPCore/Types/IOPCoreR3000_t.h"
#include "PS2Resources/IOP/IOPCore/Types/IOPCoreCOP0_t.h"
#include "PS2Resources/IOP/IOPCore/Types/IOPCoreExceptions_t.h"
#include "PS2Resources/IOP/IOPCore/Types/IOPCoreException_t.h"
#include "Common/Types/Registers/Register32_t.h"
#include "Common/Types/Registers/BitfieldRegister32_t.h"

void IOPCoreInterpreter::MFC0()
{
	if (!getResources()->IOP->IOPCore->COP0->isCoprocessorUsable())
	{
		auto& Exceptions = getResources()->IOP->IOPCore->Exceptions;
		COPExceptionInfo_t copExInfo = { 0 };
		Exceptions->setException(IOPCoreException_t(ExType::EX_COPROCESSOR_UNUSABLE, nullptr, nullptr, &copExInfo));
		return;
	}

	auto& destReg = getResources()->IOP->IOPCore->R3000->GPR[mInstruction.getRRt()];
	auto& sourceReg = getResources()->IOP->IOPCore->COP0->Registers[mInstruction.getRRd()];

	destReg->writeWordU(static_cast<u32>(sourceReg->readWordU()));
}

void IOPCoreInterpreter::MTC0()
{
	if (!getResources()->IOP->IOPCore->COP0->isCoprocessorUsable())
	{
		auto& Exceptions = getResources()->IOP->IOPCore->Exceptions;
		COPExceptionInfo_t copExInfo = { 0 };
		Exceptions->setException(IOPCoreException_t(ExType::EX_COPROCESSOR_UNUSABLE, nullptr, nullptr, &copExInfo));
		return;
	}

	auto& sourceReg = getResources()->IOP->IOPCore->R3000->GPR[mInstruction.getRRt()];
	auto& destReg = getResources()->IOP->IOPCore->COP0->Registers[mInstruction.getRRd()];

	destReg->writeWordU(sourceReg->readWordU());
}

void IOPCoreInterpreter::MFHI()
{
	// Rd = HI. No exceptions.
	auto& destReg = getResources()->IOP->IOPCore->R3000->GPR[mInstruction.getRRd()];
	auto& source1Reg = getResources()->IOP->IOPCore->R3000->HI;

	destReg->writeWordU(source1Reg->readWordU());
}

void IOPCoreInterpreter::MFLO()
{
	// Rd = LO. No exceptions.
	auto& destReg = getResources()->IOP->IOPCore->R3000->GPR[mInstruction.getRRd()];
	auto& source1Reg = getResources()->IOP->IOPCore->R3000->LO;

	destReg->writeWordU(source1Reg->readWordU());
}

void IOPCoreInterpreter::MTHI()
{
	// HI = Rd. No exceptions.
	auto& source1Reg = getResources()->IOP->IOPCore->R3000->GPR[mInstruction.getRRd()];
	auto& destReg = getResources()->IOP->IOPCore->R3000->HI;

	destReg->writeWordU(source1Reg->readWordU());
}

void IOPCoreInterpreter::MTLO()
{
	// LO = Rd. No exceptions.
	auto& source1Reg = getResources()->IOP->IOPCore->R3000->GPR[mInstruction.getRRd()];
	auto& destReg = getResources()->IOP->IOPCore->R3000->LO;

	destReg->writeWordU(source1Reg->readWordU());
}
