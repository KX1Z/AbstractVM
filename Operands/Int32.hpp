/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Int32
*/

#ifndef INT32_HPP_
    #define INT32_HPP_
    #include "../src/IOperand.hpp"
    #include "Float.hpp"
    #include "Int8.hpp"
    #include "Int16.hpp"
    #include "Double.hpp"

class Int32 : public IOperand {
    public:
        Int32(int32_t value) : value(value) {}
        std::string toString() const override ;
        eOperandType getType() const override { return eOperandType::Int32; }
        IOperand* operator+(const IOperand &rhs) const override ;
        IOperand* operator-(const IOperand &rhs) const override ;
        IOperand* operator*(const IOperand &rhs) const override ;
        IOperand* operator/(const IOperand &rhs) const override ;
        IOperand* operator%(const IOperand &rhs) const override ;
    public:
        int32_t value;
};

#endif /* !INT32_HPP_ */
