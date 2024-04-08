#include "pch.h"
#include "framework.h"

namespace SortingLib {
	template <typename T> void Sorting::BubbleSort(T a[], const int n, comparatorType<T> comparator) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (comparator(a[j + 1], a[j])) {
					Sorting::Swap(a[j], a[j + 1]);
				}
			}
		}
	}

	template void Sorting::BubbleSort<int>(int a[], const int n, comparatorType<int> comparator);
	template void Sorting::BubbleSort<float>(float a[], const int n, comparatorType<float> comparator);
	template void Sorting::BubbleSort<double>(double a[], const int n, comparatorType<double> comparator);

	template <typename T> void Sorting::ShellSort(T a[], const int n, comparatorType<T> comparator) {
		int max = (int)log2(n) - 1;
		int* hArr = new int[max]; hArr[0] = 1;
		for (int i = 1; i < max; i++) hArr[i] = 2 * hArr[i - 1] + 1;
		T temp; int k, j, l = max - 1;

		for (k = hArr[l]; l >= 0; l--, k = hArr[l]) {
			for (int i = k; i < n; i++) {
				temp = a[i];
				j = i - k;

				while (j >= 0 && comparator(temp, a[j])) {
					a[j + k] = a[j];
					j -= k;
				}

				a[j + k] = temp;
			}
		}

		delete[] hArr;
	}

	template void Sorting::ShellSort<int>(int a[], const int n, comparatorType<int> comparator);
	template void Sorting::ShellSort<float>(float a[], const int n, comparatorType<float> comparator);
	template void Sorting::ShellSort<double>(double a[], const int n, comparatorType<double> comparator);

	template <typename T> void Sorting::InsertSort(T a[], const int n, comparatorType<T> comparator) {
		for (int i = 1; i < n; i++) {
			T key = a[i];
			int j = i - 1;

			while (j >= 0 && comparator(key, a[j])) {
				a[j + 1] = a[j];
				j -= 1;
			}

			a[j + 1] = key;
		}
	}

	template void Sorting::InsertSort<int>(int a[], const int n, comparatorType<int> comparator);
	template void Sorting::InsertSort<float>(float a[], const int n, comparatorType<float> comparator);
	template void Sorting::InsertSort<double>(double a[], const int n, comparatorType<double> comparator);

	template <typename T> void Sorting::SelectSort(T a[], const int n, comparatorType<T> comparator) {
		for (int step = 0; step < n - 1; step++) {
			int minIndex = step;

			for (int i = step + 1; i < n; i++) {
				if (comparator(a[i], a[minIndex])) minIndex = i;
			}

			Sorting::Swap(a[minIndex], a[step]);
		}
	}

	template void Sorting::SelectSort<int>(int a[], const int n, comparatorType<int> comparator);
	template void Sorting::SelectSort<float>(float a[], const int n, comparatorType<float> comparator);
	template void Sorting::SelectSort<double>(double a[], const int n, comparatorType<double> comparator);

	template <typename T> void Sorting::Swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	template void Sorting::Swap<int>(int& a, int& b);
	template void Sorting::Swap<float>(float& a, float& b);
	template void Sorting::Swap<double>(double& a, double& b);
}