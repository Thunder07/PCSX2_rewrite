#pragma once

#include "Common/PS2 Resources/EE/EECore/COP1/Types/COP1_BitfieldRegisters_t.h"
#include "Common/Interfaces/PS2ResourcesSubobject.h"
#include "Common/PS2 Resources/EE/EECore/COP1/Types/FPRegister32_t.h"

class COP1_t : public PS2ResourcesSubobject
{
public:
	explicit COP1_t(const PS2Resources_t* const PS2Resources)
		: PS2ResourcesSubobject(PS2Resources)
	{
	}

	/*
	COP1 refers to the FPU (floating-point unit) coprocessor.
	See EE Core Users Manual, chapter 8.
	*/

	// Register Implementations.

	/*
	COP1 defines 32 general purpose registers, called FPR's.
	See EE Core Users Manual, page 157.
	In an 8x4 grid.
	*/
	std::shared_ptr<FPRegister32_t> FPR[32] = {
		std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()),
		std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()),
		std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()),
		std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources()), std::make_shared<FPRegister32_t>(getRootResources())
	};

	/*
	COP1 defines an accumulator register, used for multiply-accumulate type instructions.
	See EE Core Users Manual, page 157.
	*/
	std::shared_ptr<FPRegister32_t> ACC = std::make_shared<FPRegister32_t>(getRootResources());

	// Bitfield Register Implementations.
	/*
	COP1 defines 2 control registers, which are implemented as BitfieldRegisters.
	See EE Core Users Manual, page 158.
	*/
	std::shared_ptr<RegisterIRR_t> IRR = std::make_shared<RegisterIRR_t>(getRootResources()); // Also known as FCR[0].
	std::shared_ptr<RegisterCSR_t> CSR = std::make_shared<RegisterCSR_t>(getRootResources()); // Also known as FCR[31].

	/*
	Checks if the FPU coprocessor (COP1) is unusable. Throws a PS2Exception_t(coprocessor unusable) if not available.
	*/
	bool isCOP1Usable() const;
private:
};
