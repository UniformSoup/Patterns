#pragma once

#include <memory>

// Remember to give StateType a virtual destructor
template <typename StateType>
class StateMachine
{
    std::unique_ptr<StateType> currentState;
    std::unique_ptr<StateType> nextState = nullptr;

public:
    StateMachine(std::unique_ptr<StateType>&& state) : currentState(std::move(state)) {}
    void transition(std::unique_ptr<StateType>&& newState) { nextState = std::move(newState); }
    void update() { if (nextState != nullptr) { currentState = std::move(nextState); nextState = nullptr; } }
    StateType& state() { return *currentState; }
};