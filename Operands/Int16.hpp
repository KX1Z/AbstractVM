/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Int16
*/

#ifndef INT16_HPP_
    #define INT16_HPP_
    #include "../src/IOperand.hpp"
    #include "Float.hpp"
    #include "Int8.hpp"
    #include "Double.hpp"
    #include "Int32.hpp"

class Int16 : public IOperand {
    public:
        Int16(int16_t value) : value(value) {}
        std::string toString() const override ;
        eOperandType getType() const override { return eOperandType::Int16; }
        IOperand* operator+(const IOperand &rhs) const override ;
        IOperand* operator-(const IOperand &rhs) const override ;
        IOperand* operator*(const IOperand &rhs) const override ;
        IOperand* operator/(const IOperand &rhs) const override ;
        IOperand* operator%(const IOperand &rhs) const override ;
    public:
        int16_t value;
};

#endif /* !INT16_HPP_ */
