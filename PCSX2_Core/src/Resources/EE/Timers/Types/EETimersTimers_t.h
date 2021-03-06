#pragma once

#include <memory>

#include "Common/Global/Globals.h"

class EETimersTimerRegister_MODE_t;
class EETimersTimerRegister_COUNT_t;
class Register32_t;

/*
A base type representing an EE Timers Timer.
See EE Users Manual page 35 for the list of registers declared forming this type.
If the timer contains a Hold register, set the constructor parameter to true. Hold is set to nullptr otherwise.
*/
class EETimersTimer_t
{
public:
	EETimersTimer_t(const int timerID);

	/*
	EE Timers timer registers.
	See EE Users Manual page 35.
	The MODE, COUNT and COMP registers are always defined for each timer, and HOLD only for timers 0 and 1.
	COUNT must be initialised before MODE due to dependency.
	*/
	std::shared_ptr<EETimersTimerRegister_COUNT_t> COUNT;
	std::shared_ptr<EETimersTimerRegister_MODE_t>  MODE;
	std::shared_ptr<Register32_t>                  COMP;
	std::shared_ptr<Register32_t>                  HOLD;

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
Represents EE Timer0.
*/
class EETimersTimer_TIM0_t : public EETimersTimer_t
{
public:
	EETimersTimer_TIM0_t();

	static constexpr int TIMER_ID = 0;
};

/*
Represents EE Timer1.
*/
class EETimersTimer_TIM1_t : public EETimersTimer_t
{
public:
	EETimersTimer_TIM1_t();

	static constexpr int TIMER_ID = 1;
};

/*
Represents EE Timer2.
*/
class EETimersTimer_TIM2_t : public EETimersTimer_t
{
public:
	EETimersTimer_TIM2_t();

	static constexpr int TIMER_ID = 2;
};

/*
Represents EE Timer3.
*/
class EETimersTimer_TIM3_t : public EETimersTimer_t
{
public:
	EETimersTimer_TIM3_t();

	static constexpr int TIMER_ID = 3;
};
