#ifndef TEST_CLASS_H
#define TEST_CLASS_H

class TestClass {
private:
	int test_int;
	float test_float;
public:
	/*****************************************************Constructors/Destructors*/
	TestClass();
	/**********************************************************************Get/Set*/
	void setTestInt(int test_int) { this->test_int = test_int; }
	void setTestFloat(float test_float) { this->test_float = test_float; }
	int getTestInt() { return this->get_test_int; }
	float getTestFloat() { return this->get_test_float; }
	/**********************************************************************Methods*/
	void func_name(int new_int, float new_float);
	/********************************************************************Overloads*/
};

#endif