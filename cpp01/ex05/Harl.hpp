/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:55:16 by sycourbi          #+#    #+#             */
/*   Updated: 2024/01/25 13:59:49 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>

class Harl {

public:
    Harl();
    ~Harl();

    void complain(std::string level);
    
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

};

# endif