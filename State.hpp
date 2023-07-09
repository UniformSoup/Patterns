#pragma once

#include <memory>

// Remember to give StateType a virtual destructor
// This will make sure that deleting the StateType* calls the destructor for the derived class too.
template <typename StateType>
class StateMachine
{
		std::unique_ptr<StateType> currentState;

	public:

		StateMachine(std::unique_ptr<StateType>&& state) : currentState(std::move(state)) {}
		void	   transition(std::unique_ptr<StateType>&& newState) { nextState = std::move(newState); }
		StateType& state() { return *currentState; }
};