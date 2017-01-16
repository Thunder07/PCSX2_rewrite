#include "stdafx.h"

#include "Common/Global/Globals.h"
#include "Common/Types/Context_t.h"
#include "Common/Types/Registers/FPRegister32_t.h"
#include "Common/Util/FPUUtil/FPUUtil.h"

#include "VM/ExecutionCore/Interpreter/EE/EECoreInterpreter/EECoreInterpreter.h"

#include "PS2Resources/PS2Resources_t.h"
#include "PS2Resources/EE/EE_t.h"
#include "PS2Resources/EE/EECore/EECore_t.h"
#include "PS2Resources/EE/EECore/Types/EECoreFPU_t.h"
#include "PS2Resources/EE/EECore/Types/EECoreFPURegisters_t.h"

void EECoreInterpreter::ADD_S()
{
	// Fd = Fs + Ft (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRShamt()]; // Fd
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source1Reg->readFloat(Context_t::EE) + source2Reg->readFloat(Context_t::EE), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::ADDA_S()
{
	// ACC = Fs + Ft (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->ACC; // ACC
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source1Reg->readFloat(Context_t::EE) + source2Reg->readFloat(Context_t::EE), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::MADD_S()
{
	// Fd = ACC + (Fs * Ft) (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	// TODO: Check if this needs to be done in 2 stages (with checks), where stage 1 does multiply, stage 2 does addition. Old PCSX2 clamps/rounds all values before doing anything and only checks conditions at the end.
	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& source3Reg = getResources()->EE->EECore->FPU->ACC; // ACC
	auto& destReg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRShamt()]; // Fd
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source3Reg->readFloat(Context_t::EE) + (source1Reg->readFloat(Context_t::EE) * source2Reg->readFloat(Context_t::EE)), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::MADDA_S()
{
	// ACC = ACC + (Fs * Ft) (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	// TODO: Check if this needs to be done in 2 stages (with checks), where stage 1 does multiply, stage 2 does addition. Old PCSX2 clamps/rounds all values before doing anything and only checks conditions at the end.
	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->ACC; // ACC
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(destReg->readFloat(Context_t::EE) + (source1Reg->readFloat(Context_t::EE) * source2Reg->readFloat(Context_t::EE)), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::MUL_S()
{
	// Fd = Fs * Ft (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRShamt()]; // Fd
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source1Reg->readFloat(Context_t::EE) * source2Reg->readFloat(Context_t::EE), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::MULA_S()
{
	// ACC = Fs * Ft (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->ACC; // ACC
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source1Reg->readFloat(Context_t::EE) * source2Reg->readFloat(Context_t::EE), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::DIV_S()
{
	// Fd = Fs / Ft (Exception on FPU unusable).
	// TODO: Check if status bits need to be set.
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRShamt()]; // Fd
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Set flags when special conditions occur.
	f32 result;
	CSR->clearFlags();
	if (source1Reg->readFloat(Context_t::EE) != 0 && source2Reg->readFloat(Context_t::EE) == 0)
	{
		CSR->setFieldValueSticky(EECoreFPURegister_CSR_t::Fields::D, 1);
		result = static_cast<f32>(PS2Constants::EE::EECore::FPU::FMAX_POS);
	}
	else if (source1Reg->readFloat(Context_t::EE) == 0 && source2Reg->readFloat(Context_t::EE) == 0)
	{
		CSR->setFieldValueSticky(EECoreFPURegister_CSR_t::Fields::I, 1);
		result = static_cast<f32>(PS2Constants::EE::EECore::FPU::FMAX_POS);
	}
	else
	{
		// Calculate value and update flags.
		FPUFlags_t flags;
		result = FPUUtil::formatIEEEToPS2Float(source1Reg->readFloat(Context_t::EE) / source2Reg->readFloat(Context_t::EE), flags);
		CSR->updateResultFlags(flags);
	}

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::MSUB_S()
{
	// Fd = ACC - (Fs * Ft) (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	// TODO: Check if this needs to be done in 2 stages (with checks), where stage 1 does multiply, stage 2 does addition. Old PCSX2 clamps/rounds all values before doing anything and only checks conditions at the end.
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& source3Reg = getResources()->EE->EECore->FPU->ACC; // ACC
	auto& destReg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRShamt()]; // Fd
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source3Reg->readFloat(Context_t::EE) - (source1Reg->readFloat(Context_t::EE) * source2Reg->readFloat(Context_t::EE)), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::MSUBA_S()
{
	// ACC = ACC - (Fs * Ft) (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	// TODO: Check if this needs to be done in 2 stages (with checks), where stage 1 does multiply, stage 2 does addition. Old PCSX2 clamps/rounds all values before doing anything and only checks conditions at the end.
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->ACC; // ACC
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(destReg->readFloat(Context_t::EE) - (source1Reg->readFloat(Context_t::EE) * source2Reg->readFloat(Context_t::EE)), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::SUB_S()
{
	// Fd = Fs - Ft (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRShamt()]; // Fd
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source1Reg->readFloat(Context_t::EE) - source2Reg->readFloat(Context_t::EE), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

void EECoreInterpreter::SUBA_S()
{
	// ACC = Fs - Ft (Exception on FPU unusable).
	// FPU status bits set on exponent overflow/underflow (no exception generated).
	if (!checkCOP1Usable())
        return;

	auto& source1Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRd()]; // Fs
	auto& source2Reg = getResources()->EE->EECore->FPU->FPR[mInstruction.getRRt()]; // Ft
	auto& destReg = getResources()->EE->EECore->FPU->ACC; // ACC
	auto& CSR = getResources()->EE->EECore->FPU->CSR;

	// Calculate value and update flags.
	FPUFlags_t flags;
	f32 result = FPUUtil::formatIEEEToPS2Float(source1Reg->readFloat(Context_t::EE) - source2Reg->readFloat(Context_t::EE), flags);
	CSR->clearFlags();
	CSR->updateResultFlags(flags);

	destReg->writeFloat(Context_t::EE,result);
}

