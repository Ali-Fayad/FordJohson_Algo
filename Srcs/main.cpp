/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:10:17 by afayad            #+#    #+#             */
/*   Updated: 2025/06/17 15:40:10 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/PmergeMe.hpp"

extern int	count;
extern int count_deque;

void	processVector(std::vector<int> &vec)
{
	std::vector<int>	sorted;
	std::clock_t		start;
	std::clock_t		end;
	double				duration;

	std::cout << "Before: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	extern int	count;
	count = 0;

	start = std::clock();
	sorted = fordJohnson(vec);
	end = std::clock();

	duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

	std::cout << "After: ";
	for (size_t i = 0; i < sorted.size(); ++i)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : ";
	std::cout << std::fixed << std::setprecision(5)
		<< duration << " us" << std::endl;

		//  std::cout << "Count: " << count << std::endl;
}

void	processDeque(std::deque<int> &deq)
{
	std::deque<int>		sorted;
	std::clock_t		start;
	std::clock_t		end;
	double				duration;

	// std::cout << "Before: ";
	// for (size_t i = 0; i < deq.size(); ++i)
	// 	std::cout << deq[i] << " ";
	// std::cout << std::endl;

	extern int	count;
	count = 0;

	start = std::clock();
	sorted = fordJohnson2(deq);
	end = std::clock();

	duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;

	// std::cout << "After: ";
	// for (size_t i = 0; i < sorted.size(); ++i)
	// 	std::cout << sorted[i] << " ";
	// std::cout << std::endl;

	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque : ";
	std::cout << std::fixed << std::setprecision(5)
		<< duration << " us" << std::endl;

	// std::cout << "Count2: " << count_deque << std::endl;
}

int	main(int ac, char **av)
{
	int					*array;
	std::vector<int>	vec;
	std::deque<int>		deq;

	if (ac < 2)
	{
		std::cout << "Error: No numbers here\n";
		return (1);
	}
	if (ParsingAv(av) == false)
		return (1);

	array = MakeArray(av);
	vec = MakeVector(array);
	deq = MakeDeque(array);

	processVector(vec);
	processDeque(deq);

	delete[] array;
	return (0);
}

