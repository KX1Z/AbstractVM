/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_
    #include "IOperand.hpp"

    class Factory {
    public:
        static IOperand* createOperand(eOperandType type, const std::string& value);
    public:
        static IOperand* createInt8(const std::string& value);
        static IOperand* createInt16(const std::string& value);
        static IOperand* createInt32(const std::string& value);
        static IOperand* createFloat(const std::string& value);
        static IOperand* createDouble(const std::string& value);
    };

#endif /* !FACTORY_HPP_ */
