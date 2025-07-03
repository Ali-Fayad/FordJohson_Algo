/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:10:07 by afayad            #+#    #+#             */
/*   Updated: 2025/06/17 15:37:54 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/PmergeMe.hpp"

int count;
int count_deque;


bool ParsingAv(char **av)
{
	av++;

	for (int i = 1; *av != NULL; av++, i++)
	{
		char *arg = *av;

		if (arg[0] == '-')
		{
			std::cout << "Error: Negative number found: " << arg << std::endl;
			return false;
		}

		for (size_t j = 0; j < strlen(arg); j++)
		{
			if (!isdigit(arg[j]))
			{
				std::cout << "Error: Non-digit character found in argument " << i << ": " << arg << std::endl;
				return false;
			}
		}

		for (int j = 1; j < i; j++)
		{
			if (strcmp(av[-j], *av) == 0)
			{
				std::cout << "Error: Duplicate number found: " << *av << std::endl;
				return false;
			}
		}
	}

	return true;
}


int	*MakeArray(char **av)
{
	int		count = 0;
	int		*array;

	while (av[count + 1] != NULL)
		count++;
	array = new int[count + 1];
	if (!array)
	{
		std::cerr << "Error: Memory allocation failed" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < count; i++)
		array[i] = std::atoi(av[i + 1]);
	array[count] = -1;
	return (array);
}

size_t	SizeArray(int *array)
{
	size_t	size = 0;

	if (array)
	{
		while (array[size] != -1)
			size++;
	}
	return (size);
}

std::vector<int>	MakeVector(int *array)
{
	std::vector<int>	vec;
	size_t				size;

	if (!array)
		return (vec);
	size = SizeArray(array);
	vec.reserve(size);
	for (size_t i = 0; i < size; i++)
		vec.push_back(array[i]);
	return (vec);
}

std::vector<int> generateJacobsthal(int limit)
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < limit)
	{
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	return jacobsthal;
}

std::vector<int> jacob(int n)
{
	if (n <= 0)
		return std::vector<int>();

	std::vector<int> jacobsthal = generateJacobsthal(n);
	std::vector<int> order;

	for (size_t k = 1; k < jacobsthal.size(); ++k)
	{
		int end = std::min(jacobsthal[k], n);
		int start = jacobsthal[k - 1] + 1;

		for (int i = end; i >= start; --i)
		{
			if (i <= n)
				order.push_back(i);
		}
	}

	return order;
}


std::vector<int>	fordJohnson(const std::vector<int>& arr)
{
	std::vector<std::pair<int, int> >	Pairs;
	std::vector<int>					Main;
	std::vector<int>					Pending;
	std::vector<int>					SMain;
	std::vector<int>					SPending;
	std::vector<int>					Result;
	std::vector<int>					Jacob;
	size_t								pairCount;
	bool								hasOdd;
	size_t								i;
	size_t								j;

	if (arr.empty())
		return std::vector<int>();
	if (arr.size() == 1)
		return arr;
	if (arr.size() == 2)
	{
		Result = arr;
		count++;
		if (Result[0] > Result[1])
			std::swap(Result[0], Result[1]);
		return Result;
	}

	pairCount = arr.size() / 2;
	hasOdd = (arr.size() % 2 == 1);

	for (i = 0; i < pairCount; ++i)
	{
		count++;
		if (arr[2 * i] > arr[2 * i + 1])
		{
			Main.push_back(arr[2 * i]);
			Pending.push_back(arr[2 * i + 1]);
		}
		else
		{
			Main.push_back(arr[2 * i + 1]);
			Pending.push_back(arr[2 * i]);
		}
	}

	if (hasOdd)
		Pending.push_back(arr[arr.size() - 1]);

	SMain = fordJohnson(Main);

	SPending.clear();
	SPending.resize(SMain.size());

	for (i = 0; i < SMain.size(); ++i)
	{
		for (j = 0; j < Main.size(); ++j)
		{
			if (Main[j] == SMain[i])
			{
				SPending[i] = Pending[j];
				break;
			}
		}
	}
	if (hasOdd)
		SPending.push_back(Pending[Pending.size() - 1]);

	for (i = 0; i < SMain.size(); ++i)
		Result.push_back(SMain[i]);

	if (SPending.size() > 1)
	{
		std::vector<int>		Jacob = jacob(SPending.size());
		std::vector<bool>		inserted(SPending.size(), false);
		std::vector<size_t>		allIndexes;
		size_t					i;

		for (i = 0; i < Jacob.size(); ++i)
		{
			if (Jacob[i] > 0)
			{
				size_t index = Jacob[i] - 1;
				if (index < SPending.size())
					allIndexes.push_back(index);
			}
		}
		for (i = 0; i < SPending.size(); ++i)
			allIndexes.push_back(i);

		std::vector<bool>	seen(SPending.size(), false);
		std::vector<size_t>	finalOrder;

		for (i = 0; i < allIndexes.size(); ++i)
		{
			if (!seen[allIndexes[i]])
			{
				seen[allIndexes[i]] = true;
				finalOrder.push_back(allIndexes[i]);
			}
		}

		for (i = 0; i < finalOrder.size(); ++i)
		{
			size_t	index = finalOrder[i];
			int		maxValue = (index < SMain.size()) ? SMain[index] : Result.back();

			binaryInsertUpTo(Result, SPending[index], maxValue);
		}
	}


	return Result;
}

void	binaryInsertUpTo(std::vector<int>& vec, int value, int maxValue)
{
	int	left = 0;
	int	right = 0;

	for (right = 0; right < static_cast<int>(vec.size()); ++right)
	{
		if (vec[right] == maxValue)
			break;
	}

	int	mid;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		count++;
		if (vec[mid] > value)
			right = mid;
		else
			left = mid + 1;
	}
	vec.insert(vec.begin() + left, value);
}

bool isSorted(const std::vector<int>& vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
	{
		if (vec[i] < vec[i - 1])
			return false;
	}
	return true;
}

// vector

std::deque<int>	MakeDeque(int *array)
{
	std::deque<int>	deq;
	size_t			size;

	if (!array)
		return (deq);
	size = SizeArray(array);
	for (size_t i = 0; i < size; i++)
		deq.push_back(array[i]);
	return (deq);
}

std::deque<int> generateJacobsthal2(int limit)
{
	std::deque<int> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < limit)
	{
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	return jacobsthal;
}

std::deque<int> jacob2(int n)
{
	if (n <= 0)
		return std::deque<int>();

	std::deque<int> jacobsthal = generateJacobsthal2(n);
	std::deque<int> order;

	for (size_t k = 1; k < jacobsthal.size(); ++k)
	{
		int end = std::min(jacobsthal[k], n);
		int start = jacobsthal[k - 1] + 1;

		for (int i = end; i >= start; --i)
		{
			if (i <= n)
				order.push_back(i);
		}
	}

	return order;
}

std::deque<int>	fordJohnson2(const std::deque<int>& arr)
{
	std::deque<std::pair<int, int> >	Pairs;
	std::deque<int>					Main;
	std::deque<int>					Pending;
	std::deque<int>					SMain;
	std::deque<int>					SPending;
	std::deque<int>					Result;
	std::vector<int>				Jacob;
	size_t							pairCount;
	bool							hasOdd;
	size_t							i;
	size_t							j;

	if (arr.empty())
		return std::deque<int>();
	if (arr.size() == 1)
		return arr;
	if (arr.size() == 2)
	{
		Result = arr;
		count++;
		if (Result[0] > Result[1])
			std::swap(Result[0], Result[1]);
		return Result;
	}

	pairCount = arr.size() / 2;
	hasOdd = (arr.size() % 2 == 1);

	for (i = 0; i < pairCount; ++i)
	{
		count++;
		if (arr[2 * i] > arr[2 * i + 1])
		{
			Main.push_back(arr[2 * i]);
			Pending.push_back(arr[2 * i + 1]);
		}
		else
		{
			Main.push_back(arr[2 * i + 1]);
			Pending.push_back(arr[2 * i]);
		}
	}

	if (hasOdd)
		Pending.push_back(arr[arr.size() - 1]);

	SMain = fordJohnson2(Main);

	SPending.clear();
	SPending.resize(SMain.size());

	for (i = 0; i < SMain.size(); ++i)
	{
		for (j = 0; j < Main.size(); ++j)
		{
			if (Main[j] == SMain[i])
			{
				SPending[i] = Pending[j];
				break;
			}
		}
	}
	if (hasOdd)
		SPending.push_back(Pending[Pending.size() - 1]);

	for (i = 0; i < SMain.size(); ++i)
		Result.push_back(SMain[i]);

	if (SPending.size() > 1)
	{
		Jacob = jacob(SPending.size());
		std::vector<bool>		inserted(SPending.size(), false);
		std::vector<size_t>		allIndexes;

		for (i = 0; i < Jacob.size(); ++i)
		{
			if (Jacob[i] > 0)
			{
				size_t index = Jacob[i] - 1;
				if (index < SPending.size())
					allIndexes.push_back(index);
			}
		}
		for (i = 0; i < SPending.size(); ++i)
			allIndexes.push_back(i);

		std::vector<bool>	seen(SPending.size(), false);
		std::vector<size_t>	finalOrder;

		for (i = 0; i < allIndexes.size(); ++i)
		{
			if (!seen[allIndexes[i]])
			{
				seen[allIndexes[i]] = true;
				finalOrder.push_back(allIndexes[i]);
			}
		}

		for (i = 0; i < finalOrder.size(); ++i)
		{
			size_t	index = finalOrder[i];
			int		maxValue = (index < SMain.size()) ? SMain[index] : Result.back();

			binaryInsertUpTo2(Result, SPending[index], maxValue);
		}
	}
	return Result;
}


void	binaryInsertUpTo2(std::deque<int>& deq, int value, int maxValue)
{
	int	left = 0;
	int	right = 0;

	for (right = 0; right < static_cast<int>(deq.size()); ++right)
	{
		if (deq[right] == maxValue)
			break;
	}

	int	mid;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		count_deque++;
		if (deq[mid] > value)
			right = mid;
		else
			left = mid + 1;
	}
	deq.insert(deq.begin() + left, value);
}

bool isSorted2(const std::deque<int>& deq)
{
	for (size_t i = 1; i < deq.size(); ++i)
	{
		if (deq[i] < deq[i - 1])
			return false;
	}
	return true;
}



// std::vector<int>	fordJohnson(const std::vector<int>& arr)
// {
// 	std::vector<std::pair<int, int> >	Pairs;
// 	std::vector<int>					Main;
// 	std::vector<int>					Pending;
// 	std::vector<int>					SMain;
// 	std::vector<int>					SPending;
// 	std::vector<int>					Result;
// 	std::vector<int>					Jacob;
// 	size_t								pairCount;
// 	bool								hasOdd;
// 	size_t								i;
// 	size_t								j;

// 	if (arr.empty())
// 		return std::vector<int>();
// 	if (arr.size() == 1)
// 		return arr;
// 	if (arr.size() == 2)
// 	{
// 		Result = arr;
// 		count++;
// 		if (Result[0] > Result[1])
// 			std::swap(Result[0], Result[1]);
// 		return Result;
// 	}

// 	pairCount = arr.size() / 2;
// 	hasOdd = (arr.size() % 2 == 1);

// 	for (i = 0; i < pairCount; ++i)
// 	{
// 		count++;
// 		if (arr[2 * i] > arr[2 * i + 1])
// 		{
// 			Main.push_back(arr[2 * i]);
// 			Pending.push_back(arr[2 * i + 1]);
// 		}
// 		else
// 		{
// 			Main.push_back(arr[2 * i + 1]);
// 			Pending.push_back(arr[2 * i]);
// 		}
// 	}

// 	if (hasOdd)
// 		Pending.push_back(arr[arr.size() - 1]);

// 	SMain = fordJohnson(Main);

// 	SPending.clear();
// 	SPending.resize(SMain.size());

// 	for (i = 0; i < SMain.size(); ++i)
// 	{
// 		for (j = 0; j < Main.size(); ++j)
// 		{
// 			if (Main[j] == SMain[i])
// 			{
// 				SPending[i] = Pending[j];
// 				break;
// 			}
// 		}
// 	}
// 	if (hasOdd)
// 		SPending.push_back(Pending[Pending.size() - 1]);

// 	for (i = 0; i < SMain.size(); ++i)
// 		Result.push_back(SMain[i]);

// 	if (SPending.size() > 1)
// 	{
// 		std::vector<int> Jacob = jacob(SPending.size());
// 		for (i = 0; i < Jacob.size(); ++i)
// 			Jacob[i] -= 1;

// 		for (i = 0; i < Jacob.size(); ++i)
// 		{
// 			int pi = Jacob[i];
// 			int maxValue = SMain[pi];
// 			binaryInsertUpTo(Result, SPending[pi], maxValue);
// 		}
// 	}

// 	return Result;
// }
