#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Queue
{
private:
	int max_len = 10;
	vector<int> queue;
	int now;
public:
	Queue(int);
	bool isEmpty();
	bool isFull();
	void EnQueue(int);
	int DeQueue(); 
	const int size();
	
};

class Priority_Queue
{
private:
	struct prior
	{
		int x;
		int priority;
	};
	int max_len = 10;
	vector<prior> queue;
	int now;
public:
	Priority_Queue(int);
	bool isEmpty();
	bool isFull();
	void EnQueue(int, int);
	int DeQueue();
	const int size();

};
