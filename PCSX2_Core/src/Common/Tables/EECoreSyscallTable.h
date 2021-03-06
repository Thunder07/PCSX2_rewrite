#pragma once

#include "Common/Global/Globals.h"

/*
Lists the EECore's OS list of syscalls available (mnemonics).
From PCSX2 source code.
*/
struct EECoreSyscallTable
{
	struct EECoreSyscallInfo_t
	{
		const char * mMnemonic;
	};

	static constexpr EECoreSyscallInfo_t EECORE_SYSCALL_TABLE[Constants::EE::EECore::R5900::NUMBER_SYSCALLS] =
	{
		{ "RFU000_FullReset" }, // 000.
		{ "ResetEE" }, // 001.
		{ "SetGsCrt" }, // 002.
		{ "RFU003" }, // 003.
		{ "Exit" }, // 004.
		{ "RFU005" }, // 005.
		{ "LoadExecPS2" }, // 006.
		{ "ExecPS" }, // 007.
		{ "RFU008" }, // 008.
		{ "RFU009" }, // 009.
		{ "AddSbusIntcHandler" }, // 010.
		{ "RemoveSbusIntcHandler" }, // 011.
		{ "Interrupt2Iop" }, // 012.
		{ "SetVTLBRefillHandler" }, // 013.
		{ "SetVCommonHandler" }, // 014.
		{ "SetVInterruptHandler" }, // 015.
		{ "AddIntcHandler" }, // 016.
		{ "RemoveIntcHandler" }, // 017.
		{ "AddDmacHandler" }, // 018.
		{ "RemoveDmacHandler" }, // 019.
		{ "_EnableIntc" }, // 020.
		{ "_DisableIntc" }, // 021.
		{ "_EnableDmac" }, // 022.
		{ "_DisableDmac" }, // 023.
		{ "SetAlarm" }, // 024.
		{ "ReleaseAlarm" }, // 025.
		{ "_iEnableIntc" }, // 026.
		{ "_iDisableIntc" }, // 027.
		{ "_iEnableDmac" }, // 028.
		{ "_iDisableDmac" }, // 029.
		{ "iSetAlarm" }, // 030.
		{ "iReleaseAlarm" }, // 031.
		{ "CreateThread" }, // 032.
		{ "DeleteThread" }, // 033.
		{ "StartThread" }, // 034.
		{ "ExitThread" }, // 035.
		{ "ExitDeleteThread" }, // 036.
		{ "TerminateThread" }, // 037.
		{ "iTerminateThread" }, // 038.
		{ "DisableDispatchThread" }, // 039.
		{ "EnableDispatchThread" }, // 040.
		{ "ChangeThreadPriority" }, // 041.
		{ "iChangeThreadPriority" }, // 042.
		{ "RotateThreadReadyQueue" }, // 043.
		{ "_iRotateThreadReadyQueue" }, // 044.
		{ "ReleaseWaitThread" }, // 045.
		{ "iReleaseWaitThread" }, // 046.
		{ "GetThreadId" }, // 047.
		{ "ReferThreadStatus" }, // 048.
		{ "iReferThreadStatus" }, // 049.
		{ "SleepThread" }, // 050.
		{ "WakeupThread" }, // 051.
		{ "_iWakeupThread" }, // 052.
		{ "CancelWakeupThread" }, // 053.
		{ "iCancelWakeupThread" }, // 054.
		{ "SuspendThread" }, // 055.
		{ "_iSuspendThread" }, // 056.
		{ "ResumeThread" }, // 057.
		{ "iResumeThread" }, // 058.
		{ "JoinThread" }, // 059.
		{ "RFU060" }, // 060.
		{ "RFU061" }, // 061.
		{ "EndOfHeap" }, // 062.
		{ "RFU063" }, // 063.
		{ "CreateSema" }, // 064.
		{ "DeleteSema" }, // 065.
		{ "SignalSema" }, // 066.
		{ "iSignalSema" }, // 067.
		{ "WaitSema" }, // 068.
		{ "PollSema" }, // 069.
		{ "iPollSema" }, // 070.
		{ "ReferSemaStatus" }, // 071.
		{ "iReferSemaStatus>:" }, // 072.
		{ "RFU073" }, // 073.
		{ "SetOsdConfigParam" }, // 074.
		{ "GetOsdConfigParam" }, // 075.
		{ "GetGsHParam" }, // 076.
		{ "GetGsVParam" }, // 077.
		{ "SetGsHParam" }, // 078.
		{ "SetGsVParam" }, // 079.
		{ "RFU080_CreateEventFlag" }, // 080.
		{ "RFU081_DeleteEventFlag" }, // 081.
		{ "RFU082_SetEventFlag" }, // 082.
		{ "RFU083_iSetEventFlag" }, // 083.
		{ "RFU084_ClearEventFlag" }, // 084.
		{ "RFU085_iClearEventFlag" }, // 085.
		{ "RFU086_WaitEvnetFlag" }, // 086.
		{ "RFU087_PollEvnetFlag" }, // 087.
		{ "RFU088_iPollEvnetFlag" }, // 088.
		{ "RFU089_ReferEventFlagStatus" }, // 089.
		{ "RFU090_iReferEventFlagStatus" }, // 090.
		{ "RFU091" }, // 091.
		{ "(i)EnableIntcHandler" }, // 092.
		{ "(i)DisableIntcHandler" }, // 093.
		{ "(i)EnableDmacHandler" }, // 094.
		{ "(i)DisableDmacHandler" }, // 095.
		{ "KSeg0" }, // 096.
		{ "EnableCache" }, // 097.
		{ "DisableCache" }, // 098.
		{ "GetCop0" }, // 099.
		{ "FlushCache" }, // 100.
		{ "Unknown" }, // 101.
		{ "CpuConfig" }, // 102.
		{ "iGetCop0" }, // 103.
		{ "iFlushCache" }, // 104.
		{ "Unknown" }, // 105.
		{ "iCpuConfig" }, // 106.
		{ "sceSifStopDma" }, // 107.
		{ "SetCPUTimerHandler" }, // 108.
		{ "SetCPUTimer" }, // 109.
		{ "SetOsdConfigParam2" }, // 110.
		{ "GetOsdConfigParam2" }, // 111.
		{ "(i)GsGetIMR" }, // 112.
		{ "(i)GsPutIMR" }, // 113.
		{ "SetPgifHandler" }, // 114.
		{ "SetVSyncFlag" }, // 115.
		{ "RFU116" }, // 116.
		{ "_print" }, // 117.
		{ "(i)sceSifDmaStat" }, // 118.
		{ "(i)sceSifSetDma" }, // 119.
		{ "(i)sceSifSetDChain" }, // 120.
		{ "sceSifSetReg" }, // 121.
		{ "sceSifGetReg" }, // 122.
		{ "ExecOSD" }, // 123.
		{ "Deci2Call" }, // 124.
		{ "PSMode" }, // 125.
		{ "MachineType" }, // 126.
		{ "GetMemorySize" }, // 127.
		{ "Unknown" }, // 128.
		{ "Unknown" }, // 129.
		{ "Unknown" }, // 130.
		{ "Unknown" }, // 131.
		{ "Unknown" }, // 132.
		{ "Unknown" }, // 133.
		{ "Unknown" }, // 134.
		{ "Unknown" }, // 135.
		{ "Unknown" }, // 136.
		{ "Unknown" }, // 137.
		{ "Unknown" }, // 138.
		{ "Unknown" }, // 139.
		{ "Unknown" }, // 140.
		{ "Unknown" }, // 141.
		{ "Unknown" }, // 142.
		{ "Unknown" }, // 143.
		{ "Unknown" }, // 144.
		{ "Unknown" }, // 145.
		{ "Unknown" }, // 146.
		{ "Unknown" }, // 147.
		{ "Unknown" }, // 148.
		{ "Unknown" }, // 149.
		{ "Unknown" }, // 150.
		{ "Unknown" }, // 151.
		{ "Unknown" }, // 152.
		{ "Unknown" }, // 153.
		{ "Unknown" }, // 154.
		{ "Unknown" }, // 155.
		{ "Unknown" }, // 156.
		{ "Unknown" }, // 157.
		{ "Unknown" }, // 158.
		{ "Unknown" }, // 159.
		{ "Unknown" }, // 160.
		{ "Unknown" }, // 161.
		{ "Unknown" }, // 162.
		{ "Unknown" }, // 163.
		{ "Unknown" }, // 164.
		{ "Unknown" }, // 165.
		{ "Unknown" }, // 166.
		{ "Unknown" }, // 167.
		{ "Unknown" }, // 168.
		{ "Unknown" }, // 169.
		{ "Unknown" }, // 170.
		{ "Unknown" }, // 171.
		{ "Unknown" }, // 172.
		{ "Unknown" }, // 173.
		{ "Unknown" }, // 174.
		{ "Unknown" }, // 175.
		{ "Unknown" }, // 176.
		{ "Unknown" }, // 177.
		{ "Unknown" }, // 178.
		{ "Unknown" }, // 179.
		{ "Unknown" }, // 180.
		{ "Unknown" }, // 181.
		{ "Unknown" }, // 182.
		{ "Unknown" }, // 183.
		{ "Unknown" }, // 184.
		{ "Unknown" }, // 185.
		{ "Unknown" }, // 186.
		{ "Unknown" }, // 187.
		{ "Unknown" }, // 188.
		{ "Unknown" }, // 189.
		{ "Unknown" }, // 190.
		{ "Unknown" }, // 191.
		{ "Unknown" }, // 192.
		{ "Unknown" }, // 193.
		{ "Unknown" }, // 194.
		{ "Unknown" }, // 195.
		{ "Unknown" }, // 196.
		{ "Unknown" }, // 197.
		{ "Unknown" }, // 198.
		{ "Unknown" }, // 199.
		{ "Unknown" }, // 200.
		{ "Unknown" }, // 201.
		{ "Unknown" }, // 202.
		{ "Unknown" }, // 203.
		{ "Unknown" }, // 204.
		{ "Unknown" }, // 205.
		{ "Unknown" }, // 206.
		{ "Unknown" }, // 207.
		{ "Unknown" }, // 208.
		{ "Unknown" }, // 209.
		{ "Unknown" }, // 210.
		{ "Unknown" }, // 211.
		{ "Unknown" }, // 212.
		{ "Unknown" }, // 213.
		{ "Unknown" }, // 214.
		{ "Unknown" }, // 215.
		{ "Unknown" }, // 216.
		{ "Unknown" }, // 217.
		{ "Unknown" }, // 218.
		{ "Unknown" }, // 219.
		{ "Unknown" }, // 220.
		{ "Unknown" }, // 221.
		{ "Unknown" }, // 222.
		{ "Unknown" }, // 223.
		{ "Unknown" }, // 224.
		{ "Unknown" }, // 225.
		{ "Unknown" }, // 226.
		{ "Unknown" }, // 227.
		{ "Unknown" }, // 228.
		{ "Unknown" }, // 229.
		{ "Unknown" }, // 230.
		{ "Unknown" }, // 231.
		{ "Unknown" }, // 232.
		{ "Unknown" }, // 233.
		{ "Unknown" }, // 234.
		{ "Unknown" }, // 235.
		{ "Unknown" }, // 236.
		{ "Unknown" }, // 237.
		{ "Unknown" }, // 238.
		{ "Unknown" }, // 239.
		{ "Unknown" }, // 240.
		{ "Unknown" }, // 241.
		{ "Unknown" }, // 242.
		{ "Unknown" }, // 243.
		{ "Unknown" }, // 244.
		{ "Unknown" }, // 245.
		{ "Unknown" }, // 246.
		{ "Unknown" }, // 247.
		{ "Unknown" }, // 248.
		{ "Unknown" }, // 249.
		{ "Unknown" }, // 250.
		{ "Unknown" }, // 251.
		{ "Unknown" }, // 252.
		{ "Unknown" }, // 253.
		{ "Unknown" }, // 254.
		{ "Unknown" } // 255.
	};

	/*
	Returns the syscall properties from above given the syscall number.
	*/
	static const EECoreSyscallInfo_t * getInfo(const int syscallNumber);
};

