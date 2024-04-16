/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:25:26 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/12 12:48:47 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

#include <iostream>
#include <sstream> // Pour std::istringstream
#include <string>
#include <cctype> // Pour std::isprint
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter {

public:
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();
    static void convert(const std::string& literal);

private:
    ScalarConverter();
};

# endif