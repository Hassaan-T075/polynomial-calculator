#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void input(int& terms, int deg[], int coff[]);
void input(const char file_name[], int& terms, int deg[], int coff[]);
int solve(int terms, int deg[], int coff[], int variable);
void add(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int& rterms, int rdeg[], int rcoef[]);
void multiply(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[],
	int& rterms, int rdeg[], int rcoef[]);
void subtract(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int& rterms, int rdeg[], int rcoef[]);
bool equal(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[]);
void print(int terms, int deg[], int coff[]);
void menu();

int main()
{
	menu();
}

void input(int& terms, int deg[], int coff[])
{
	int j, t_deg;
	cout << "\nEnter number of terms > ";
	cin >> terms;

	for (int i = 0; i < terms; i++)
	{
		j = 0;
		cout << "Enter " << i + 1 << " term's coefficient : ";
		cin >> coff[i];
		cout << "Enter term's power : ";
		cin >> t_deg;

		while (j < terms) {
			if (t_deg == deg[j]) {
				cout << "\n This term exists\n Enter a different degree ";
				cin >> t_deg;
				cout << "\n";
				j = -1;
			}
			j++;
		}

		deg[i] = t_deg;

	}

	int t_coef = 0;
	t_deg = 0;
	for (int i = 0; i < terms - 1; i++) {
		for (int j = 0; j < terms - i - 1; j++) {
			if (deg[j] < deg[j + 1]) {
				t_deg = deg[j];
				deg[j] = deg[j + 1];
				deg[j + 1] = t_deg;

				t_coef = coff[j];
				coff[j] = coff[j + 1];
				coff[j + 1] = t_coef;
			}
		}
	}

}

void input(const char file_name[], int& terms, int deg[], int coff[])
{
	ifstream fin(file_name);
	if (fin.is_open())
	{
		fin >> terms;

		for (int i = 0; i < terms; i++)
		{
			fin >> coff[i];
		}

		for (int i = 0; i < terms; i++)
		{
			fin >> deg[i];
		}
	}

	int t_coef = 0;
	int t_deg = 0;
	for (int i = 0; i < terms - 1; i++) {
		for (int j = 0; j < terms - i - 1; j++) {
			if (deg[j] < deg[j + 1]) {
				t_deg = deg[j];
				deg[j] = deg[j + 1];
				deg[j + 1] = t_deg;

				t_coef = coff[j];
				coff[j] = coff[j + 1];
				coff[j + 1] = t_coef;
			}
		}
	}

}

bool equal(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[])
{
	bool flag;
	if (aterms = bterms)
		flag = true;
	else
		return false;

	for (int i = 0; i < aterms; i++) {
		if (adeg[i] == bdeg[i])
			flag = true;
		else
			return false;
	}

	for (int i = 0; i < aterms; i++) {
		if (acoef[i] == bcoef[i])
			flag = true;
		else
			return false;
	}
	return flag;
}

void print(int terms, int deg[], int coff[])
{
	int i = 0;
	if (coff[i] != 0) {
		if (deg[i] == 0)
			cout << "\n 	" << coff[i] << " ";
		else
			cout << "\n 	" << coff[i] << "x^" << deg[i] << " ";
	}
	for (i = 1; i < terms; i++)
	{
		if (coff[i] > 0) {
			if (deg[i] == 0)
				cout << "+" << coff[i] << " ";
			else
				cout << "+" << coff[i] << "x^" << deg[i] << " ";
		}
		else if (coff[i] < 0) {
			if (deg[i] == 0)
				cout << coff[i] << " ";
			else
				cout << coff[i] << "x^" << deg[i] << " ";
		}
	}
	cout << endl;
}

int solve(int terms, int deg[], int coff[], int variable)
{
	int power = 0;
	int answer = 0;
	for (int i = 0; i < terms; i++)
	{
		power = pow(variable, deg[i]);
		power = power * coff[i];

		answer = answer + power;
	}

	return answer;
}

void add(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int& rterms, int rdeg[], int rcoef[])
{
	int i = 0, j = 0, k = 0;

	while (i < aterms && j < bterms)
	{
		if (adeg[i] > bdeg[j])
		{
			rdeg[k] = adeg[i];
			rcoef[k] = acoef[i];

			i++;
			k++;
		}
		else if (adeg[i] < bdeg[j])
		{
			rdeg[k] = bdeg[j];
			rcoef[k] = bcoef[j];

			j++;
			k++;
		}
		else
		{
			rdeg[k] = adeg[i];
			rcoef[k] = acoef[i] + bcoef[j];

			i++;
			j++;
			k++;
		}
	}

	rterms = k;

}

void set_zero(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 1569325055;
	}
}

void subtract(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[], int& rterms, int rdeg[], int rcoef[])
{
	int i = 0, j = 0, k = 0;

	while (i < aterms && j < bterms)
	{
		if (adeg[i] > bdeg[j])
		{
			rdeg[k] = adeg[i];
			rcoef[k] = acoef[i];
			i++;
			k++;
		}
		else if (adeg[i] < bdeg[j])
		{
			rdeg[k] = bdeg[j];
			rcoef[k] = bcoef[j];
			j++;
			k++;
		}
		else
		{
			rdeg[k] = adeg[i];
			rcoef[k] = acoef[i] - bcoef[j];

			j++;
			i++;
			k++;
		}
	}

	rterms = k;

}

void multiply(int aterms, int adeg[], int acoef[], int bterms, int bdeg[], int bcoef[],
	int& rterms, int rdeg[], int rcoef[]) {

	int t_coef = 0;
	int t_deg = 0;
	int index_coef = 0;
	int index_deg = 0;
	int r_deg_terms = 0;

	for (int i = 0; i < aterms; i++) {
		for (int j = 0; j < bterms; j++) {
			t_coef = (acoef[i]) * (bcoef[j]);
			t_deg = (adeg[i]) + (bdeg[j]);

			int result = -1;
			for (int i = 0; i < r_deg_terms; i++) {
				if (rdeg[i] == t_deg) {
					result = i;
				}
			}

			if (result != -1) {
				rcoef[result] += t_coef;
			}
			else {

				rdeg[index_deg] = t_deg;
				rcoef[index_coef] = t_coef;
				index_deg++;
				index_coef++;
				r_deg_terms++;
			}
		}
	}
	rterms = r_deg_terms;

	t_coef = 0;
	t_deg = 0;
	for (int i = 0; i < rterms - 1; i++) {
		for (int j = 0; j < rterms - i - 1; j++) {
			if (rdeg[j] < rdeg[j + 1]) {
				t_deg = rdeg[j];
				rdeg[j] = rdeg[j + 1];
				rdeg[j + 1] = t_deg;

				t_coef = rcoef[j];
				rcoef[j] = rcoef[j + 1];
				rcoef[j + 1] = t_coef;
			}
		}
	}
}

void menu() {

	int choice, iter = 0;
	bool exit = false;

	int acoef_arr[15], bcoef_arr[15], rcoef_arr[30];
	int adeg_arr[15], bdeg_arr[15], rdeg_arr[30];
	int a_no_of_terms = 0, b_no_of_terms = 0, r_no_of_terms = 0;

	cout << "Example of menu options for different values are given below:\n\n"
		"0. Input two polynomials from files.\n"
		"1. Input two polynomials from the user.\n"
		"2. Solve one of the polynomials for a value.\n"
		"3. Print the polynomials.\ni. First polynomial.\nii.Second polynomial\niii.Both\n"
		"4. Compare two polynomials.\n"
		"5. Multiply the polynomials.\n"
		"6. Subtract the polynomials.\n"
		"7. Add the polynomials.\n"
		"8. Exit the program.\n\n";

	while (exit == false) {
		cout << "\tEnter a Number from Menu > ";
		cin >> choice;
		cin.ignore();
		if (choice == 0) {
			if (iter > 0) {
				set_zero(acoef_arr, 15);
				set_zero(bcoef_arr, 15);
				set_zero(rcoef_arr, 30);
				set_zero(adeg_arr, 15);
				set_zero(bdeg_arr, 15);
				set_zero(rdeg_arr, 30);
			}
			char file_1[30];
			char file_2[30];
			cout << "\nEnter 1st file > ";
			cin.getline(file_1, 30);
			cout << "\nEnter 2nd file > ";
			cin.getline(file_2, 30);
			input(file_1, a_no_of_terms, adeg_arr, acoef_arr);
			input(file_2, b_no_of_terms, bdeg_arr, bcoef_arr);
			cout << endl;
		}
		else if (choice == 1) {
			if (iter > 0) {
				set_zero(acoef_arr, 15);
				set_zero(bcoef_arr, 15);
				set_zero(rcoef_arr, 30);
				set_zero(adeg_arr, 15);
				set_zero(bdeg_arr, 15);
				set_zero(rdeg_arr, 30);
			}
			input(a_no_of_terms, adeg_arr, acoef_arr);
			input(b_no_of_terms, bdeg_arr, bcoef_arr);
		}
		else if (choice == 2) {
			int x, poly;
			cout << "\nEnter a value of x > ";
			cin >> x;
			cout << "\nPolynomial 1 or 2 >";
			//enter number
			cin >> poly;

			if (poly == 1)
				cout << solve(a_no_of_terms, adeg_arr, acoef_arr, x) << endl;
			else if (poly == 2)
				cout << solve(b_no_of_terms, bdeg_arr, bcoef_arr, x) << endl;
		}
		else if (choice == 3) {
			int num;
			cout << "\nEnter a preference\n1. First Polynomial\n2. Second Polynomial\n3. Both";
			//enter number
			cin >> num;

			if (num == 1)
				print(a_no_of_terms, adeg_arr, acoef_arr);
			else if (num == 2)
				print(b_no_of_terms, bdeg_arr, bcoef_arr);
			else if (num == 3) {
				print(a_no_of_terms, adeg_arr, acoef_arr);
				print(b_no_of_terms, bdeg_arr, bcoef_arr);
			}
		}
		else if (choice == 4) {
			if (equal(a_no_of_terms, adeg_arr, acoef_arr, b_no_of_terms, bdeg_arr, bcoef_arr) == 1)
				cout << "\nPolynomials are equal\n";
			else if (equal(a_no_of_terms, adeg_arr, acoef_arr, b_no_of_terms, bdeg_arr, bcoef_arr) == 0)
				cout << "\nPolynomials are not equal\n";
		}
		else if (choice == 5) {
			multiply(a_no_of_terms, adeg_arr, acoef_arr, b_no_of_terms, bdeg_arr, bcoef_arr, r_no_of_terms, rdeg_arr, rcoef_arr);
			print(r_no_of_terms, rdeg_arr, rcoef_arr);
		}
		else if (choice == 6) {
			subtract(a_no_of_terms, adeg_arr, acoef_arr, b_no_of_terms, bdeg_arr, bcoef_arr, r_no_of_terms, rdeg_arr, rcoef_arr);
			print(r_no_of_terms, rdeg_arr, rcoef_arr);
		}
		else if (choice == 7) {
			add(a_no_of_terms, adeg_arr, acoef_arr, b_no_of_terms, bdeg_arr, bcoef_arr, r_no_of_terms, rdeg_arr, rcoef_arr);
			print(r_no_of_terms, rdeg_arr, rcoef_arr);
		}
		else if (choice == 8)
			exit = true;
		iter++;
	}
}