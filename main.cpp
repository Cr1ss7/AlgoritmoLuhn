#include <iostream>
#include <string>

using namespace std;

//Algoritmo para verificar si una tarjeta es valida
bool AlgoritmoLuhn(string data) {
	bool x = false;
	int j = data.size();
	int i = 1;
	int sum = 0;
	string num;
	int s;
	while (x == false) {
		if (j == 1) {
			if (i % 2 == 0) {
				num = to_string(((int)data[j-1] - 48)  * 2);
				if (num.size() == 2) {
					s = (int)num[0] - 48;
					s = s + (int)num[1] - 48;
					sum += s;
				}
				else
					sum += (int)num[0] - 48;
			}
			else
				sum += (int)(data[j-1]) - 48;
			x = true;
		}
		else {
			if (i % 2 == 0) {
				num = to_string(((int)data[j-1] - 48)  * 2);
				if (num.size() == 2) {
					s = (int)num[0] - 48;
					s = s + (int)num[1] - 48;
					sum += s;
				}
				else
					sum += (int)(num[0]) - 48;
			}else
				sum += (int)(data[j-1]) - 48;
			j--;
			i++;
		}
	}

	cout << sum;

	if (sum % 10 == 0)
		return true;
	else
		return false;
}

int main() {
	string targeta;
	try {
		cout << "Digite el numero de la targeta sin espacios: \n";
		cin >> targeta;
		if (AlgoritmoLuhn(targeta))
			cout << "\nLa targeta es valida!\n";
		else
			cout << "\nLa targeta no es valida!\n";
	}
	catch(int e){
		cout << "Cerrando el programa...";
	}
	return 0;
}
