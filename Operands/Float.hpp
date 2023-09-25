/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Float
*/

#ifndef FLOAT_HPP_
    #define FLOAT_HPP_
    #include "../src/IOperand.hpp"
    #include "Double.hpp"
    #include "Int8.hpp"
    #include "Int16.hpp"
    #include "Int32.hpp"

class Float : public IOperand {
    public:
        Float(float value) : value(value) {}
        std::string toString() const override ;
        eOperandType getType() const override { return eOperandType::Float; }
        IOperand* operator+(const IOperand &rhs) const override ;
        IOperand* operator-(const IOperand &rhs) const override ;
        IOperand* operator*(const IOperand &rhs) const override ;
        IOperand* operator/(const IOperand &rhs) const override ;
        IOperand* operator%(const IOperand &rhs) const override ;
    public:
        float value;
};

#endif /* !FLOAT_HPP_ */
