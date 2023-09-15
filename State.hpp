#pragma once

#include <memory>

// Remember to give StateType a virtual destructor
// This will make sure that deleting the StateType* calls the destructor for the derived class too.
template <typename StateType>
class StateMachine
{
		std::shared_ptr<StateType> currentState;

	public:

		StateMachine(std::shared_ptr<StateType>&& state) : currentState(std::move(state)) {}
		void	   transition(std::shared_ptr<StateType>&& newState) { currentState = std::move(newState); }
		std::shared_ptr<StateType> state() { return currentState; }
};