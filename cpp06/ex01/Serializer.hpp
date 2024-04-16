/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:32:37 by sycourbi          #+#    #+#             */
/*   Updated: 2024/03/12 12:58:04 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <stdint.h> //uintptr_t

struct Data {
    int number;
    Data* next;
};

class Serializer {

public:
    ~Serializer() {};
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer() {};
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
};

# endif