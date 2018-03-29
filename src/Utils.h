//
// Created by pasta on 16/03/18.
//

#ifndef RAY_UTILS_H_H
# define RAY_UTILS_H_H

#include <iostream>

# define PRINT(...)     std::cout << __VA_ARGS__ << std::endl;
# define CERR(...)      std::cerr << __VA_ARGS__ << std::endl;
# define LOG(...)      std::cerr << __FILENAME__ << ": " << __LINE__ << ": " << __VA_ARGS__ << std::endl;

# ifndef NDEBUG
#  define TRACE(...)    CERR("[" <<__FILENAME__ << "](line " << __LINE__ << "): " << __VA_ARGS__)
# else
#  define TRACE(...){}
# endif

# endif // !RAY_UTILS_H_H