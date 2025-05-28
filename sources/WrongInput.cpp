#include "../headers/WrongInput.h"

WrongInput::WrongInput():
	Exception("Enter numbers separated by spaces: ") {
}

WrongInput::WrongInput(const std::string& message) :
	Exception(message) {
}
