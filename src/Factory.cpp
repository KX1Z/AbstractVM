/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Factory
*/

#include "Factory.hpp"
#include <iostream>
#include "../Operands/Double.hpp"

IOperand* Factory::createInt8(const std::string& value)
{
    int8_t intValue = std::stoi(value);
    return new Int8(intValue);
}

IOperand* Factory::createInt16(const std::string& value)
{
    int16_t intValue = std::stoi(value);
    return new Int16(intValue);
}

IOperand* Factory::createInt32(const std::string& value)
{
    int32_t intValue = std::stoi(value);
    return new Int32(intValue);
}

IOperand* Factory::createFloat(const std::string& value)
{
    float floatValue = std::stof(value);
    return new Float(floatValue);
}

IOperand* Factory::createDouble(const std::string& value)
{
    double doubleValue = std::stod(value);
    return new Double(doubleValue);
}

IOperand* Factory::createOperand(eOperandType type, const std::string& value) {
    switch (type) {
        case eOperandType::Int8:
            return createInt8(value);
        case eOperandType::Int16:
            return createInt16(value);
        case eOperandType::Int32:
            return createInt32(value);
        case eOperandType::Float:
            return createFloat(value);
        case eOperandType::Double:
            return createDouble(value);
        default:
            throw std::runtime_error("Unsupported operand type");
    }
}