/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Int8
*/

#ifndef INT8_HPP_
    #define INT8_HPP_
    #include "../src/IOperand.hpp"
    #include "Float.hpp"
    #include "Double.hpp"
    #include "Int16.hpp"
    #include "Int32.hpp"

class Int8 : public IOperand {
    public:
        Int8(int8_t value) : value(value) {}
        std::string toString() const override ;
        eOperandType getType() const override { return eOperandType::Int8; }
        IOperand* operator+(const IOperand &rhs) const override ;
        IOperand* operator-(const IOperand &rhs) const override ;
        IOperand* operator*(const IOperand &rhs) const override ;
        IOperand* operator/(const IOperand &rhs) const override ;
        IOperand* operator%(const IOperand &rhs) const override ;
    public:
        int8_t value;
};

#endif /* !INT8_HPP_ */
