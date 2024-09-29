#include <set/set.h>
#include <random>
#include <chrono>
#include <vector>

using namespace set;

int main() {

	setlocale(LC_CTYPE, "");
	/*
	int sum = 0;
	for (int j = 0; j < 100; ++j) {
		Set a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 1000; ++i) {
			a.insert(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " ����������� - ������� ����� ���������� ��������� 1000 ����������" << endl;

	sum = 0;
	for (int j = 0; j < 100; ++j) {
		Set a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 10000; ++i) {
			a.insert(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " ����������� - ������� ����� ���������� ��������� 10000 ����������" << endl;
	sum = 0;
	for (int j = 0; j < 100; ++j) {
		Set a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 100000; ++i) {
			a.insert(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " ����������� - ������� ����� ���������� ��������� 100000 ����������" << endl;

	cout << "���������\t��������\t����������" << endl;

	Set a;

	for (int i = 0; i < 1000; ++i) {
		a.insert(lcg());
	}

	int sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		Set b(a);
		auto start = chrono::steady_clock::now();
		b.contains(lcg());
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.erase(lcg());
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.insert(lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;


	for (int i = 0; i < 10000; ++i) {
		a.insert(lcg());
	}

	sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		Set b(a);
		auto start = chrono::steady_clock::now();
		b.contains(lcg());
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.erase(lcg());
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.insert(lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;


	for (int i = 0; i < 100000; ++i) {
		a.insert(lcg());
	}

	sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		Set b(a);
		auto start = chrono::steady_clock::now();
		b.contains(lcg());
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.erase(lcg());
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		b.insert(lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;
*/


	

	Set k1, k2;
	for (int i = 0; i < 10; ++i) {
		k1.insert(rand() % 10);
		k2.insert(rand() % 10);
	}
	k1.print_set();
	cout << endl;
	k2.print_set();
	cout << endl;
	uni(k1, k2).print_set();
	cout << endl;
	symmetrical_difference(k1, k2).print_set();
	
	
/*
	int sum = 0;
	for (int j = 0; j < 100; ++j) {
		vector<int> a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 1000; ++i) {
			a.push_back(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " ����������� - ������� ����� ���������� ������� 1000 ����������" << endl;

	sum = 0;
	for (int j = 0; j < 100; ++j) {
		vector<int> a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 10000; ++i) {
			a.push_back(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " ����������� - ������� ����� ���������� ������� 10000 ����������" << endl;
	sum = 0;
	for (int j = 0; j < 100; ++j) {
		vector<int> a;
		auto start = chrono::steady_clock::now();
		for (int i = 0; i < 100000; ++i) {
			a.push_back(lcg());
		}
		auto end = chrono::steady_clock::now();
		sum = sum + chrono::duration_cast<chrono::microseconds>(end - start).count();
	}
	cout << 1.0 * sum / 100 << " ����������� - ������� ����� ���������� ������� 100000 ����������" << endl;

	cout << "���������\t��������\t����������" << endl;

	vector<int> a;
	for (int i = 0; i < 1000; ++i) {
		a.push_back(lcg());
	}

	int sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		int index_contains = a[rand() % 1000], index_remove = rand() % 1000, index_insert = rand() % 1000;
		auto beg = a.cbegin(), end1 = a.cend();
		auto start = chrono::steady_clock::now();
		find(a.cbegin(), a.cend(), index_contains);
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		a.erase(a.cbegin() + index_remove);
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		a.insert(a.cbegin() + index_insert - 1, lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;

	for (int i = 0; i < 10000; ++i) {
		a.push_back(lcg());
	}

	sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		int index_contains = a[rand() % 1000], index_remove = rand() % 1000, index_insert = rand() % 1000;
		auto beg = a.cbegin(), end1 = a.cend();
		auto start = chrono::steady_clock::now();
		find(a.cbegin(), a.cend(), index_contains);
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		a.erase(a.cbegin() + index_remove);
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		a.insert(a.cbegin() + index_insert - 1, lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;


	for (int i = 0; i < 100000; ++i) {
		a.push_back(lcg());
	}

	sum_contains = 0, sum_erase = 0, sum_insert = 0;
	for (int j = 0; j < 1000; ++j) {
		int index_contains = a[rand() % 1000], index_remove = rand() % 1000, index_insert = rand() % 1000;
		auto beg = a.cbegin(), end1 = a.cend();
		auto start = chrono::steady_clock::now();
		find(a.cbegin(), a.cend(), index_contains);
		auto end = chrono::steady_clock::now();
		sum_contains = sum_contains + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		a.erase(a.cbegin() + index_remove);
		end = chrono::steady_clock::now();
		sum_erase = sum_erase + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		start = chrono::steady_clock::now();
		a.insert(a.cbegin() + index_insert - 1, lcg());
		end = chrono::steady_clock::now();
		sum_insert = sum_insert + chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	}
	cout << 1.0 * sum_contains / 1000 << "\t" << 1.0 * sum_erase / 1000 << "\t" << 1.0 * sum_insert / 1000 << "\t" << endl;

	
	return 0;*/

}