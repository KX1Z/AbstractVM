/*
** EPITECH PROJECT, 2023
** B-SYN-400-LYN-4-1-abstractVM-keziah.picq
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP_
    #define EXCEPTIONS_HPP_

    #pragma once

    #include <exception>
    #include <string>
    #include <utility>

    namespace exception
    {
        class InvalidArgument : public std::exception
        {
        private:
            std::string message;

        public:
            InvalidArgument(const std::string& msg) : message(msg) {}

            virtual const char* what() const throw()
            {
                return message.c_str();
            }
        };

        class OverflowError : public std::exception
        {
        private:
            std::string message;

        public:
            OverflowError(const std::string& msg) : message(msg) {}

            virtual const char* what() const throw()
            {
                return message.c_str();
            }
        };

        class EmptyStack : public std::exception
        {
        private:
            std::string message;

        public:
            EmptyStack(const std::string& msg) : message(msg) {}

            virtual const char* what() const throw()
            {
                return message.c_str();
            }
        };

        class TooSmallStack : public std::exception
        {
        private:
            std::string message;

        public:
            TooSmallStack(const std::string& msg) : message(msg) {}

            virtual const char* what() const throw()
            {
                return message.c_str();
            }
        };
    }



#endif /* !EXCEPTIONS_HPP_ */
