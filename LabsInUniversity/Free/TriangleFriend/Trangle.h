#pragma once
class Trangle
{
private:
	int a, b, c;
	int ab, bc, ac;
	void angle();
	static int self_static;
	
public:
	Trangle();
	Trangle(const Trangle &obj);
	Trangle(int,int,int);//a,b,c

	//get-set functions
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_ab() { return ab; }
	int get_bc() { return bc; }
	int get_ac() { return ac; }
	void set_a(int a) { this->a = a; angle(); }
	void set_b(int b) { this->b = b; angle(); }
	void set_c(int c) { this->c = c; angle(); }
	
	static void set_static(int);
	int square();
	int perimetr();
	int h(int);
	void whatItIs();
};

