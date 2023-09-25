/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** VirtualMachine
*/

#include "VirtualMachine.hpp"
#include "Exception.hpp"

void VirtualMachine::pop()
{
    if (stack.empty())
        throw exception::EmptyStack("Error: Empty Stack.");
    stack.pop();
}

bool VirtualMachine::checkIfDot(const std::string& str)
{
    size_t dotPos = str.find('.');
    return (dotPos != std::string::npos);
}

void VirtualMachine::clear()
{
    while (!stack.empty()) {
        stack.pop();
    }
}

void VirtualMachine::dup()
{
    if (!stack.empty()) {
        auto topElement = stack.top();
        stack.push(topElement);
    }
    else {
        throw exception::EmptyStack("Error: Empty Stack.");
    }
}

void VirtualMachine::swap()
{
    if (stack.size() < 2) {
        throw exception::TooSmallStack("Error : Stack too small.");
    }

    auto top = stack.top();
    stack.pop();

    auto last = stack.top();
    stack.pop();

    stack.push(top);
    stack.push(last);
}

void VirtualMachine::dump()
{
    std::stack<IOperand*> tempStack = stack;

    while (!tempStack.empty()) {
        auto* element = tempStack.top();
        tempStack.pop();

        if (this->checkIfDot(element->toString()) == true) {
            std::string str = element->toString();
            size_t dotPos = str.find('.');
            if (dotPos != std::string::npos) {
                if (element->getType() == eOperandType::Float) {
                    std::string numberBeforeDot = str.substr(0, dotPos);
                    std::string numberAfterDot = str.substr(dotPos + 1, 3);
                    char lastDigit = numberAfterDot.back();
                    if (lastDigit >= '5' && lastDigit <= '9'){
                        numberAfterDot.erase(numberAfterDot.size() - 1);
                        auto numberTmp = stoi(numberAfterDot);
                        numberTmp++;
                        numberAfterDot = std::to_string(numberTmp);
                    }
                    else {
                        numberAfterDot.erase(numberAfterDot.size() - 1);
                    }
                    std::cout << numberBeforeDot << "." << numberAfterDot << std::endl;
                }
                if (element->getType() == eOperandType::Double) {
                    std::string numberBeforeDot = str.substr(0, dotPos);
                    std::string numberAfterDot = str.substr(dotPos + 1);
                    std::size_t pos = numberAfterDot.find_last_not_of('0');
                    if (pos != std::string::npos && pos != numberAfterDot.length() - 1) {
                        numberAfterDot = numberAfterDot.substr(0, pos + 1);
                    }
                    std::cout << numberBeforeDot << "." << numberAfterDot << std::endl;
                }
            }
        }
        else
            std::cout << element->toString() << std::endl;
    }
}

void VirtualMachine::add()
{
    if (stack.size() < 2) {
        throw exception::TooSmallStack("Error : Stack too small.");
    }

    auto val = stack.top();
    stack.pop();

    auto second_value = stack.top();
    stack.pop();

    auto result = *second_value + *val;
    stack.push(result);
}

void VirtualMachine::sub()
{
    if (stack.size() < 2) {
        throw exception::TooSmallStack("Error : Stack too small.");
    }

    auto val = stack.top();
    stack.pop();

    auto second_value = stack.top();
    stack.pop();

    auto result = *second_value - *val;
    stack.push(result);
}

void VirtualMachine::mul()
{
    if (stack.size() < 2) {
        throw exception::TooSmallStack("Error : Stack too small.");
    }

    auto val = stack.top();
    stack.pop();

    auto second_value = stack.top();
    stack.pop();

    auto result = (*second_value) * (*val);
    stack.push(result);
}

void VirtualMachine::div()
{
    if (stack.size() < 2) {
        throw exception::TooSmallStack("Error : Stack too small.");
    }

    auto val = stack.top();
    stack.pop();

    auto second_value = stack.top();
    stack.pop();

    if (val->toString() == "0")
        throw exception::InvalidArgument("Division by 0.");
    auto result = (*second_value) / (*val);
    stack.push(result);
}

void VirtualMachine::mod()
{
    if (stack.size() < 2) {
        throw exception::TooSmallStack("Error : Stack too small.");
    }

    auto val = stack.top();
    stack.pop();

    auto second_value = stack.top();
    stack.pop();

    if (val->toString() == "0")
        throw exception::InvalidArgument("Modulo by 0.");

    auto result = (*second_value) % (*val);
    stack.push(result);
}

void VirtualMachine::print()
{
    std::stack<IOperand*> tempStack = stack;

    while (!tempStack.empty()) {
        auto* element = tempStack.top();
        tempStack.pop();

        std::cout << element->toString() << std::endl;
    }
}

void VirtualMachine::exit_prog()
{
    exit(0);
}
