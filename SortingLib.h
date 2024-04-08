#pragma once

#ifndef SORTING_LIB_H
#define SORTING_LIB_H

#include <math.h>

namespace SortingLib {
	template<typename T> using comparatorType = bool (*) (T, T);
	template<typename T> using sortType = void (*) (T[], const int, comparatorType<T>);

	class Sorting {
	public:
		template <typename T> static void BubbleSort(T[], const int, comparatorType<T>);

		template <typename T> static void ShellSort(T[], const int, comparatorType<T>);

		template <typename T> static void InsertSort(T[], const int, comparatorType<T>);

		template <typename T> static void SelectSort(T[], const int, comparatorType<T>);

		template <typename T> static void Swap(T&, T&);
	};
}

#endif // !SORTING_LIB_H