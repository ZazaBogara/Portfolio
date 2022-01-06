#include <iostream>
#include <math.h>

using namespace std;

/*
Створити клас “Бензопила” котрий містить поля:
- назва
- потужність (в ватах)
- кількість обертів ланцюга (одиниць за хвилину)
*/

class benzopila
{
private:
	char* name;
	int	power;
	int rotation_per_second;
public:
	void what_is_it()
	{
		cout << "Name: " << name << "\n" << "power: " << "\n" << "Rotation/sec: " << rotation_per_second;
	}
};

int main()
{
	benzopila first_one();
	first_one().what_is_it();
	return 0;
}