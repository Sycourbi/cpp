/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:04:20 by sycourbi          #+#    #+#             */
/*   Updated: 2024/04/16 12:19:11 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {

public:
    PmergeMe();
    PmergeMe(const std::vector<int>& input_sequence);
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void printSequence() const;
    void printSequencedeque() const;

    void mergeInsertSort();
    
private:
    std::vector<int> sequence_vector;
    std::deque<int> sequence_deque;

    void FordJohnsonSort(std::vector<int>& arr);
    void FordJohnsonSort(std::deque<int>& arr);
    

};
#endif