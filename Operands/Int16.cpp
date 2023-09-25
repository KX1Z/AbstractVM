/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Int16
*/

#include "Int16.hpp"
#include "../src/Exception.hpp"

std::string Int16::toString() const
{
    return std::to_string(value);
}

IOperand *Int16::operator+(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            long double result = value + std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int16: {
            long double result = value + std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw std::overflow_error("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int32: {
            long double result = value + std::stod(rhs.toString());
            if (result > INT32_MAX || result < INT32_MIN) {
                throw exception::OverflowError("Overflow on a int32.");
            }

            return new Int32(static_cast<int32_t>(result));
        }
        case eOperandType::Float: {
            std::cout << rhs.toString() << std::endl;
            long double result = (value) + std::stod(rhs.toString());
            if (result > FLT_MAX || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }
            return new Float(result);
        }
        case eOperandType::Double: {
            long double result = static_cast<double>(value) + std::stod(rhs.toString());
            if (result > DBL_MAX || result < -DBL_MAX) {
                throw exception::OverflowError("Overflow on a double.");
            }
            return new Double(result);
        }
    }
}

IOperand *Int16::operator-(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            long double result = value - std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int16: {
            long double result = value - std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int32: {
            long double result = value - std::stod(rhs.toString());
            if (result > INT32_MAX || result < INT32_MIN) {
                throw exception::OverflowError("Overflow on a int32.");
            }

            return new Int32(static_cast<int32_t>(result));
        }
        case eOperandType::Float: {
            long double result = static_cast<float>(value) - std::stod(rhs.toString());
            if (result > FLT_MAX || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }
            return new Float(result);
        }
        case eOperandType::Double: {
            long double result = static_cast<double>(value) - std::stod(rhs.toString());
            if (result > DBL_MAX || result < -DBL_MAX) {
                throw exception::OverflowError("Overflow on a double.");
            }
            return new Double(result);
        }
    }
}

IOperand *Int16::operator*(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            long double result = value * std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int16: {
            long double result = value * std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int32: {
            long double result = value * std::stod(rhs.toString());
            if (result > INT32_MAX || result < INT32_MIN) {
                throw exception::OverflowError("Overflow on a int32.");
            }

            return new Int32(static_cast<int32_t>(result));
        }
        case eOperandType::Float: {
            long double result = static_cast<float>(value) * std::stod(rhs.toString());
            if (result > FLT_MAX || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }
            return new Float(result);
        }
        case eOperandType::Double: {
            long double result = static_cast<double>(value) * std::stod(rhs.toString());
            if (result > DBL_MAX || result < -DBL_MAX) {
                throw exception::OverflowError("Overflow on a double.");
            }
            return new Double(result);
        }
    }
}

IOperand *Int16::operator/(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = value / std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int16: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = value / std::stod(rhs.toString());
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int32: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = value / std::stod(rhs.toString());
            if (result > INT32_MAX || result < INT32_MIN) {
                throw exception::OverflowError("Overflow on a int32.");
            }

            return new Int32(static_cast<int32_t>(result));
        }
        case eOperandType::Float: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = static_cast<float>(value) / std::stod(rhs.toString());
            if (result > FLT_MAX || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }
            return new Float(result);
        }
        case eOperandType::Double: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = static_cast<double>(value) / std::stod(rhs.toString());
            if (result > DBL_MAX || result < -DBL_MAX) {
                throw exception::OverflowError("Overflow on a double.");
            }
            return new Double(result);
        }
    }
}

IOperand *Int16::operator%(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            // long double result = value % std::stod(rhs.toString());
            long double value_double = static_cast<double>(value);
            long double result = std::fmod(value_double, std::stod(rhs.toString()));
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int16: {
            // long double result = value % std::stod(rhs.toString());
            long double value_double = static_cast<double>(value);
            long double result = std::fmod(value_double, std::stod(rhs.toString()));
            if (result > INT16_MAX || result < INT16_MIN) {
                throw exception::OverflowError("Overflow on a int16.");
            }

            return new Int16(static_cast<int16_t>(result));
        }
        case eOperandType::Int32: {
            // long double result = value % std::stod(rhs.toString());
            long double value_double = static_cast<double>(value);
            long double result = std::fmod(value_double, std::stod(rhs.toString()));
            if (result > INT32_MAX || result < INT32_MIN) {
                throw exception::OverflowError("Overflow on a int32.");
            }

            return new Int32(static_cast<int32_t>(result));
        }
        case eOperandType::Float: {
            long double result = std::fmod(static_cast<float>(value), std::stod(rhs.toString()));
            if (result > FLT_MAX || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }
            return new Float(result);
        }
        case eOperandType::Double: {
            long double result = std::fmod(static_cast<double>(value), std::stod(rhs.toString()));
            if (result > DBL_MAX || result < -DBL_MAX) {
                throw exception::OverflowError("Overflow on a double.");
            }
            return new Double(result);
        }
    }
}