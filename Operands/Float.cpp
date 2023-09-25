/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Float
*/

#include "Float.hpp"
#include "../src/Exception.hpp"

std::string Float::toString() const
{
    return std::to_string(value);
}

IOperand *Float::operator+(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            long double result = value + std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int16: {
            long double result = value + std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX ) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int32: {
            long double result = value + std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX ) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Float: {
            long double result = static_cast<float>(value) + std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
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

IOperand *Float::operator-(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            long double result = value - std::stod(rhs.toString());
            if (result > FLT_MAX || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int16: {
            long double result = value - std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int32: {
            long double result = value - std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
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

IOperand *Float::operator*(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            long double result = value * std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int16: {
            long double result = value * std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int32: {
            long double result = value * std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
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

IOperand *Float::operator/(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = value / std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int16: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = value / std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int32: {
            if (rhs.toString() == "0") {
                throw exception::InvalidArgument("Division by zero is not allowed.");
            }
            long double result = value / std::stod(rhs.toString());
            if (result > FLT_MAX  || result < -FLT_MAX ) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
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

IOperand *Float::operator%(const IOperand &rhs) const
{
    switch (rhs.getType()) {
        case eOperandType::Int8: {
            // long double result = static_cast<int8_t>(value) % std::stod(rhs.toString());
            long double result = static_cast<int8_t>(value) % static_cast<int8_t>(std::stod(rhs.toString()));
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int16: {
            // long double result = static_cast<int16_t>(value) % std::stod(rhs.toString());
            long double result = static_cast<int16_t>(value) % static_cast<int16_t>(std::stod(rhs.toString()));
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
        }
        case eOperandType::Int32: {
            long double result = std::fmod(value, static_cast<float>(std::stod(rhs.toString())));
            if (result > FLT_MAX  || result < -FLT_MAX) {
                throw exception::OverflowError("Overflow on a float.");
            }

            return new Float((result));
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