#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <iostream>

class my_exception : public std::exception 
{
private: 
    std::string message;

public:
    my_exception(std::string const &Msg)
    {
    	message = "\033[1;31m" + Msg + "\033[0m";
    } 
  
    virtual ~my_exception() throw() {}
  
    virtual const char * what() const throw() {return message.c_str();}
};

#endif