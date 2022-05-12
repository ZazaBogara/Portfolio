#include "Sparse_Matrix.h"

Sparse_Matrix::Sparse_Matrix()
{
	cout << "n:"; 
	cin >> n;
	cout << "m:";
	cin >> m; 
	for (int i = 0; i <= n; i++)
		this->indecs_row.push_back(0);
}
Sparse_Matrix::Sparse_Matrix(int** a, int n, int m)
{
	this->n = n;
	this->m = m;
	for (int i = 0; i <= n; i++)
	{
		this->indecs_row.push_back(0);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i-1][j] != 0)
			{
				this->numbers.push_back(a[i-1][j]);
				this->column.push_back(j);
				this->indecs_row[i]++;
			}
		}
		this->indecs_row[i] += this->indecs_row[i - 1];
	}
}
void Sparse_Matrix::printOn(ostream& os)
{
	os << "\nArray:\n";
	int now_indecs=0;
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < m; j++)
		{
			
			if (column.size() != 0)
			{
				if ((now_indecs<indecs_row[i+1])&&(column[now_indecs]==j))//умова з індексами
				{
					os << "\t" << numbers[now_indecs];
					now_indecs++;
				}
				else
				{
					os << "\t" << 0;
				}
			}
			else
				os << "\t" << 0;
			
		}
		os << "\n";
	}
}
void Sparse_Matrix::printMemoryOn(ostream& os)
{
	os << "\n\nMemory:" << (sizeof(numbers) + sizeof(column) + sizeof(indecs_row));
}
int** Sparse_Matrix::asMatrix()
{
	int** out;
	out = new int* [n];
	for (int i = 0; i < n; i++)
	{
		out[i] = new int[m];
	}

	int now_indecs = 0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{

			if (column.size() != 0)
			{
				if ((now_indecs < indecs_row[i + 1]) && (column[now_indecs] == j))//умова з індексами
				{
					out[i][j] = numbers[now_indecs];
					now_indecs++;
				}
				else
				{
					out[i][j] = 0;
				}
			}
			else
				out[i][j] = 0;
		}
	}
	return out;
}
int Sparse_Matrix::get_value(int i_search, int j_search)
{
	int out, now_indecs = 0;
	bool notZero = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (column.size() != 0)
			{
				if ((now_indecs < indecs_row[i + 1]) && (column[now_indecs] == j))//умова з індексами
				{
					if ((i_search == i) && (j_search == j))
					{
						out = numbers[now_indecs];
						notZero = true;
					}	
					now_indecs++;
				}
			}
			else
				out = 0;
		}
	}
	if (notZero == false)
		out = 0;
	return out;
}
void Sparse_Matrix::set_value(int value, int i_search, int j_search)
{
	int now_indecs = 0;
	bool e = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (column.size() != 0)
			{
				if ((now_indecs < indecs_row[i + 1]) && (column[now_indecs] == j))//умова з індексами
				{
					if ((i_search == i) && (j_search == j))
					{

						e = true;
						if (value != 0)
						{
							numbers[now_indecs] = value;
						}
						else
						{
							numbers.erase(numbers.begin() + now_indecs);
							column.erase(column.begin() + now_indecs);
							for (int tmp = i + 1; tmp <= n; tmp++)
							{
								indecs_row[tmp]--;
							}
							
							break;
						}
					}
					now_indecs++;
				}
			}
			//Додати кусочок, коли матриця повністю пуста
			//Зміна планів, коли вона пуста, то число буде вставлятися просто(код нище)
		}
	}

	
	if (e == false)
	{
		if (value != 0)
		{
			if (column.size() != 0)
			{
				int memory=0;
				int now_indecs = 0;
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < m; j++)
					{
						
						if ((now_indecs < indecs_row[i + 1]) && (column[now_indecs] == j))//умова з індексами
						{

							if ((i_search == i) && (j_search >= j))
							{
								memory = now_indecs;
								break;
							}
							now_indecs++;
						}
					}
				}
				for (int tmp = i_search + 1; tmp <= n; tmp++)
				{
					indecs_row[tmp]++;
				}
				column.insert((column.begin() + memory+1), j_search);
				numbers.insert(numbers.begin() + memory+1, value);
				
			}
			else//пуста матриця
			{
				numbers.push_back(value);
				column.push_back(j_search);
				for (int tmp = i_search + 1; tmp <= n; tmp++)
				{
					indecs_row[tmp]++;
				}
			}
		}
		else
		{
			//нічого не робимо
		}
	}
}
void Sparse_Matrix::trans()
{
	vector<int> numbers;
	vector<int> column;
	vector<int> indecs_row;
	int n = this->n, m = this->m;
	int** matr = this->asMatrix();
	int** x = new int* [m];
	for (int i = 0; i < m; i++)
	{
		x[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			x[j][i] = matr[i][j];
		}
	}

	for (int i = 0; i <= m; i++)
	{
		indecs_row.push_back(0);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (x[i - 1][j] != 0)
			{
				numbers.push_back(x[i-1][j]);
				column.push_back(j);
				indecs_row[i]++;
			}
		}
		indecs_row[i] += indecs_row[i - 1];
	}
	this->indecs_row = indecs_row;
	this->column = column;
	this->numbers = numbers;
}