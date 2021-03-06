#pragma once

#include <memory>

#include "Common/Global/Globals.h"

class IOPTimersTimerRegister_MODE_t;
class IOPTimersTimerRegister_COUNT_t;
class Register32_t;

/*
A base type representing an IOP Timers Timer.
Documentation taken from PCSX2 and No$PSX docs.
*/
class IOPTimersTimer_t
{
public:
	IOPTimersTimer_t(const int timerID);

	/*
	IOP Timers timer registers.
	The Mode, Count and Compare registers are defined for each timer.
	Count must be initialised before Mode due to dependency.
	*/
	std::shared_ptr<IOPTimersTimerRegister_COUNT_t> COUNT;
	std::shared_ptr<IOPTimersTimerRegister_MODE_t>  MODE;
	std::shared_ptr<Register32_t>                   COMP;

	/*
	Returns the ID of this timer.
	*/
	int getTimerID() const;

private:
	/*
	The ID of this timer.
	*/
	int mTimerID;
};

/*
Represents IOP Timer0.
*/
class IOPTimersTimer_TIM0_t : public IOPTimersTimer_t
{
public:
	IOPTimersTimer_TIM0_t();

	static constexpr int TIMER_ID = 0;
};

/*
Represents IOP Timer1.
*/
class IOPTimersTimer_TIM1_t : public IOPTimersTimer_t
{
public:
	IOPTimersTimer_TIM1_t();

	static constexpr int TIMER_ID = 1;
};

/*
Represents IOP Timer2.
*/
class IOPTimersTimer_TIM2_t : public IOPTimersTimer_t
{
public:
	IOPTimersTimer_TIM2_t();

	static constexpr int TIMER_ID = 2;
};

/*
Represents IOP Timer3.
*/
class IOPTimersTimer_TIM3_t : public IOPTimersTimer_t
{
public:
	IOPTimersTimer_TIM3_t();

	static constexpr int TIMER_ID = 3;
};

/*
Represents IOP Timer4.
*/
class IOPTimersTimer_TIM4_t : public IOPTimersTimer_t
{
public:
	IOPTimersTimer_TIM4_t();

	static constexpr int TIMER_ID = 4;
};

/*
Represents IOP Timer5.
*/
class IOPTimersTimer_TIM5_t : public IOPTimersTimer_t
{
public:
	IOPTimersTimer_TIM5_t();

	static constexpr int TIMER_ID = 5;
};