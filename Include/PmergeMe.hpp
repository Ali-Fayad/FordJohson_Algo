/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:02:58 by afayad            #+#    #+#             */
/*   Updated: 2025/06/15 16:55:20 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JACOBSEQUENCE_HPP
# define JACOBSEQUENCE_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>
#include <iomanip>
#include <ctime>

extern int count;
extern int count_deque;

bool			ParsingAv(char **av);
int				*MakeArray(char **av);
size_t			SizeArray(int *array);

std::vector<int>	MakeVector(int *array);
std::vector<int>	generateJacobsthal(int limit);
std::vector<int>	jacob(int n);
std::vector<int>	fordJohnson(const std::vector<int>& arr);
void				binaryInsertUpTo(std::vector<int>& vec, int value, int maxValue);
bool				isSorted(const std::vector<int>& vec);
bool				isSorted2(const std::deque<int>& deq);
void				binaryInsertUpTo2(std::deque<int>& deq, int value, int maxValue);
std::deque<int>		fordJohnson2(const std::deque<int>& arr);
std::deque<int>		jacob2(int n);
std::deque<int>		generateJacobsthal2(int limit);
std::deque<int>		MakeDeque(int *array);




#endif

