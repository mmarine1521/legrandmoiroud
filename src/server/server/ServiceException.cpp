#include "ServiceException.hpp"


ServiceException::ServiceException (HttpStatus status, string msg) 
    : httpStatus(status),msg(msg) {    
}

HttpStatus ServiceException::status () const {
    return httpStatus;
}

const char* ServiceException::what () const noexcept {
    return msg.c_str();
}
