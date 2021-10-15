#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert> 
#include <iomanip> 

using namespace std;

void obzac()
{
	cout << "\n\n//============================================================================//\n\n";
}

//task1
class Power
{
private:
	double x_pain;
	double v_pain;
public:
	Power() : x_pain(1.1), v_pain(1.2) {
		setlocale(LC_ALL, "rus");
		cout << "\n" << "Power(Конструктор)\n" << "first - " << x_pain << "\nsecond - " << v_pain << endl;
	}

	void setPower(double duracel, double energy) {

		x_pain = duracel;
		v_pain = energy;
		cout << "\n" << "setPower:\n" << "first - " << duracel << "\n" << "second - " << energy << endl;
	}

	void calculate()
	{
		setlocale(LC_ALL, "rus");

		cout << "\nответ: " << pow(x_pain, v_pain) << endl;
	}
	
};



//task2
class RGBA
{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;

public:
	RGBA() {
		m_red = 0;
		m_green = 0;
		m_blue = 0;
		m_alpha = 255;
	}
	RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
		m_red = r;
		m_green = g;
		m_blue = b;
		m_alpha = a;
	}
	void Print()
	{
		std::cout << "r = " << static_cast<int>(m_red) <<
			" g = " << static_cast<int>(m_green) <<
			" b = " << static_cast<int>(m_blue) <<
			" a = " << static_cast<int>(m_alpha) << '\n';
	}
	
};



//task3
class Stack
{
private:
	int m_array[10]; 
	int m_next;

public:

	void reset()
	{
		m_next = 0;
		for (int i = 0; i < 10; ++i)
			m_array[i] = 0;
	}

	bool push(int value)
	{
		if (m_next == 10)
			return false;

		m_array[m_next++] = value; 
		return true;
	}

	int pop()
	{
		assert(m_next > 0);
		return m_array[--m_next];
	}

	void print()
	{
			cout << "( ";
		for (int i = 0; i < m_next; ++i)
			cout << m_array[i] << ' ';
			cout << ")\n";
	}
	 
};






int main()
{
	{   //task1
		obzac();
		Power method;
		method.setPower(1.4, 8.8);
		method.calculate();

	}




	{   //task2
		obzac();
		int ri, gi, bi, ai;

		cout << "m_red = ";
		cin >> ri;
		cout << "m_green = ";
		cin >> gi;
		cout << "m_blue = ";
		cin >> bi;
		cout << "m_alpha = ";
		cin >> ai;
		RGBA rgba((uint8_t(ri)), (uint8_t(gi)), (uint8_t(bi)), (uint8_t(ai)));
		rgba.Print();
	}




	{   //task3
		obzac();

		Stack stack;
		stack.reset();

		stack.print();

		stack.push(3);
		stack.push(7);
		stack.push(5);
		stack.print();

		stack.pop();
		stack.print();

		stack.pop();
		stack.pop();

		stack.print();

	}
	return 0;
};