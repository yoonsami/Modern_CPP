#include "PCH.h"
class Knight
{
public:
	Knight() : _hp(0){}
	Knight(int a, int b) : _hp(0) {}
	Knight(initializer_list<int> li) : _hp(0) {}
public:
	int _hp;
};

void Test(int a)
{
	cout << "Test(int)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// Nullptr ����
const class NullPtr
{
public:
	// �� � Ÿ���� �����Ϳ͵� ġȯ ����
	template<typename T>
	operator T*() const
	{
		return 0;
	}
	// �� � Ÿ���� ��� �����Ϳ͵� ġȯ ����
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

	void operator&() const = delete; // �ּҰ� & ����
}_nullPtr;


int main()
{
#pragma region auto
	//// 1. auto (���� ����(type deduction)) -> ���� �ǰ� �߷��ϵ��� ��
	///*int a = 3;
	//float b = 3.14f;
	//double c = 1.23;
	//Knight d = Knight();
	//const char* e = "����";*/
	//auto a = 3;
	//auto b = 3.14f;
	//auto c = 1.23;
	//auto d = Knight();
	//auto e = "����";

	//// ��Ģ�� �������� �� ����.
	//auto f = &d;
	//const auto test1 = b;
	//auto* test2 = e;
	//// auto* test3 = a; ERR
	//
	//// �⺻ auto�� const, & �� ������.
	//int& ref = a;
	//const int cst = a;
	//auto test3 = ref; // int test3 = ref;
	//auto test4 = cst; // int test4 = cst;
	//
	//// ��� ������ auto�� ���� ���������� �������� ������ �ſ� ����
#pragma endregion auto
#pragma region �߰�ȣ �ʱ�ȭ
	//int a = 0;
	//int b(0);
	//int c{ 0 };

	//Knight k1;
	//Knight k2 = k1;// ���� ������ (���� ������ �ƴ�)

	//Knight k3; // �⺻ ������
	//k3 = k1; // ���� ������

	//Knight k4{ k2 }; // �߰�ȣ �ʱ�ȭ

	//// ���ϵ��� ���� ���� �ʱ�ȭ ����� ���ϼ��� �ֱ� ����.
	//// 1) vector �� container�� �� ��︲
	//int arr[] = { 1,2,3,4 };

	//vector<int> v1;
	//v1.push_back(1);
	//v1.push_back(1);
	//v1.push_back(1);

	//vector<int> v2(3, 1);

	//vector<int> v3{ 1,2,3 };
	//// 2) ��� ��ȯ ����
	//int x = 0;
	//double y = x; // ERR���� �׳� �����
	//double z(x); // ERR���� �׳� �����
	//double w{ x }; // ERR -> ��� ��ȯ�� ����߸� ���ư�

	//// 3) 
	//// Knight k(); => �⺻ �����ڸ� ȣ���Ͽ� �����϶�� �� ó�� ��������, Knight ���� ��ȯ�ϴ� k��� �Լ��� �����Ѱ� �Ǿ����.
	//Knight k{}; // ->�⺻ �����ڸ� ȣ���Ͽ� ����
	//Knight k5{ 1,2 }; // initializer list�� ����ϴ� ������ ȣ��, initializer list�� ����ϴ� ������ ������ int �ΰ� �޴� ������ ȣ��
	//Knight k6(1, 2); // int �ΰ� �޴� ������ ȣ��

#pragma endregion �߰�ȣ �ʱ�ȭ
#pragma region nullptr

	////������ int* ptr = NULL; ���� ���
	//// 
	//// 0 NULL

	//Test(0);
	//Test(NULL);// �� ���̽� ��� Test(int) ȣ��

	//Test(nullptr); // Test(*) ȣ��
	//Test(_nullPtr);
	////-> ������ ������ ���� nullptr ����
	////-> ���������� �� ����

	//auto whoami = nullptr;
	//// nullptr_t
	

#pragma endregion nullptr
	return 0;
}