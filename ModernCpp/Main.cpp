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

// Nullptr 구현
const class NullPtr
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T*() const
	{
		return 0;
	}
	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

	void operator&() const = delete; // 주소값 & 막음
}_nullPtr;


int main()
{
#pragma region auto
	//// 1. auto (형식 연역(type deduction)) -> 말이 되게 추론하도록 함
	///*int a = 3;
	//float b = 3.14f;
	//double c = 1.23;
	//Knight d = Knight();
	//const char* e = "윤성";*/
	//auto a = 3;
	//auto b = 3.14f;
	//auto c = 1.23;
	//auto d = Knight();
	//auto e = "윤성";

	//// 규칙이 복잡해질 수 있음.
	//auto f = &d;
	//const auto test1 = b;
	//auto* test2 = e;
	//// auto* test3 = a; ERR
	//
	//// 기본 auto는 const, & 를 무시함.
	//int& ref = a;
	//const int cst = a;
	//auto test3 = ref; // int test3 = ref;
	//auto test4 = cst; // int test4 = cst;
	//
	//// 모든 변수를 auto로 쓰면 가독성에서 떨어지기 때문에 매우 별로
#pragma endregion auto
#pragma region 중괄호 초기화
	//int a = 0;
	//int b(0);
	//int c{ 0 };

	//Knight k1;
	//Knight k2 = k1;// 복사 생성자 (대입 연산자 아님)

	//Knight k3; // 기본 생성자
	//k3 = k1; // 대입 연산자

	//Knight k4{ k2 }; // 중괄호 초기화

	//// 통일되지 않은 기존 초기화 방법에 통일성을 주기 위함.
	//// 1) vector 등 container와 잘 어울림
	//int arr[] = { 1,2,3,4 };

	//vector<int> v1;
	//v1.push_back(1);
	//v1.push_back(1);
	//v1.push_back(1);

	//vector<int> v2(3, 1);

	//vector<int> v3{ 1,2,3 };
	//// 2) 축소 변환 방지
	//int x = 0;
	//double y = x; // ERR없이 그냥 실행됨
	//double z(x); // ERR없이 그냥 실행됨
	//double w{ x }; // ERR -> 축소 변환을 해줘야만 돌아감

	//// 3) 
	//// Knight k(); => 기본 생성자를 호출하여 생성하라는 것 처럼 보이지만, Knight 형을 반환하는 k라는 함수를 선언한게 되어버림.
	//Knight k{}; // ->기본 생성자를 호출하여 생성
	//Knight k5{ 1,2 }; // initializer list를 사용하는 생성자 호출, initializer list를 사용하는 생성자 없으면 int 두개 받는 생성자 호출
	//Knight k6(1, 2); // int 두개 받는 생성자 호출

#pragma endregion 중괄호 초기화
#pragma region nullptr

	////기존에 int* ptr = NULL; 으로 사용
	//// 
	//// 0 NULL

	//Test(0);
	//Test(NULL);// 두 케이스 모두 Test(int) 호출

	//Test(nullptr); // Test(*) 호출
	//Test(_nullPtr);
	////-> 오동작 방지를 위해 nullptr 도입
	////-> 가독성에서 더 좋음

	//auto whoami = nullptr;
	//// nullptr_t
	

#pragma endregion nullptr
	return 0;
}