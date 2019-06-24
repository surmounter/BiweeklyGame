## 되도록이면  explicit 키워드를 명시하라.

~~~c++
class Foo{
public:
    int m_foo;
    Foo (int foo) : m_foo (foo) {}
};

void printM_foo (Foo foo){
    cout << foo.m_foo << endl;
}

int main (){
    int num = 43;
    printM_foo(num); // OK. Compile Error가 발생하지 않는다.
}
~~~

* explicit 키워드를 명시하면 컴파일러가 클래스를 인자로 전달할 시 암시적으로 형변환하지 않는다.
  * 위 코드의 main함수에서 컴파일에러가 발생하지 않는 이유은 printM_foo(num)이 호출되면 컴파일러는 Foo 클래스에서 int를 파라미터로 받는 생성자를 호출해 printM_foo(Foo foo)의 적절한 파라미터 타입인 Foo로 알아서 형 변환을 해주기 때문이다.
  * `explicit Foo(int foo) : m_foo(foo) {}`로 바꾸면 컴파일러의 암시적 형변환을 막을 수 있다.
* 따라서 암시적 형변환으로 인한 예기치 않는 작동을 막을 수 있다.
* [TicTacToe 게임](https://github.com/surmounter/BiweeklyGame/issues/2#issue-456746993)

## 가독성을 위해서 enumeration의 값으로 char를 저장하라.
~~~c++
enum Piece
{
  	X = 'X',
  	O = 'O',
  	Invalid = '?',
  	Blank = ' '
};
~~~
* 원칙적으로 enumeration의 값으로 int 타입만 가능하다.
* char 타입은 int 타입으로 아스키코드에 따라 암시적으로 형변환이 가능하므로, char 타입도 enumeration의 값으로 가질 수 있다.
* [TicTacToe 게임](https://github.com/surmounter/BiweeklyGame/issues/4)

## 배열의 길이를 상수로 저장하고 싶다면 constexpr 키워드를 이용하라
~~~c++
constexpr int BOARD_SIZE = 3;
int board[BOARD_SIZE][BOARD_SIZE];
~~~

* [TicTacToe 게임](https://github.com/surmounter/BiweeklyGame/issues/5)

### const와의 차이점
~~~c++
class CTest
{
public:
	CTest();

private:
	const int contV = 1; 								// (1) 런타임중에 생성자의 선처리영역에 의해 초기화된다.
	// constexpr int constExprV = 1; 				(2) 클래스 내에 선언하면 Error
};
~~~

* const는 초기화를 런타임까지로 지연시킬 수 있고, constexpr은 초기화를 컴파일타임에 해야한다.
	* (1)을 보면 const 변수는 **런타임중**에 초기화될 수 있음을 보여준다.
	* (2)을 보면 constexpr 변수는 **컴파일타임에만** 초기화를 할 수 있으므로, 런타임중에 호출되는 생성자(혹은 생성자의 선처리영역)에 의해 초기화될 수 없다.

### const static과의 차이점
~~~c++
const static int arrSize = 1;
int arr[arrSize];

/*
compile time에 아래와 같이 바뀐다.
int arr[1];
*/
~~~
* const static(전역상수)는 컴파일러의 최적화에 의해 따로 메모리를 잡지 않고 매크로처럼 변수를 리터럴 자체로 대체한다.

## #pragma once보다 include guard을 이용하라.
### #pragma의 호환성 문제
* 컴파일러 지시자로 특정 컴파일러에서만 동작하는 지시자이므로 호환성문제가 있다. 
	* 예를들어 `#pragma` 지시자는 VC++5.0 이상에서만 동작한다.
* 따라서 안전하게 ifndef guard를 이용하는 것이 좋다.

### include guard 원리

~~~c++
#ifndef SOME_UNIQUE_NAME_HERE // SOME_UNIQUE_NAME_HERE가 정의되어있다면, #endif로 이동
#define SOME_UNIQUE_NAME_HERE 

// 선언과 정의 

#endif
~~~

* 위 헤더파일이 포함되면(include) SOME_UNIQUE_NAME_HERE가 정의되어있는지 확인한다.
* 헤더파일을 처음 include하면, SOME_UNIQUE_NAME_HERE는 정의되어있지 않다.
* SOME_UNIQUE_NAME_HERE을 정의하고 헤더파일의 내용을 include한다. 
* 그러나 이전에 헤더파일을 include했다면 SOME_UNIQUE_NAME_HERE는 이미 정의되어 있기 때문에 헤더파일 내용이 무시된다.

### include guard Naming Convention

~~~c++
// math.h
#ifndef MATH_H 
#define MATH_H 

int getSquareSides() { return 4; } 

#endif
~~~

* [TicTacToe 게임](https://github.com/surmounter/BiweeklyGame/issues/6)

## EnumFlag 사용법

### Enum 구성법
~~~c#
public enum AttackType {
    // Decimal     // Binary
    None   = 0,    // 000000
    Melee  = 1,    // 000001
    Fire   = 2,    // 000010
    Ice    = 3,    // 000011
    Poison = 4     // 000100
}
~~~

* 2의 지수승으로 EnumValue에 값을 부여해서, 각 EnumValue마다 대응되는 비트자리를 부여해주는 것이다.
* 예를 들어서 Melee는 오른쪽에서 첫번째자리, Fire는 오른쪽에서 두번째자리의 비트자리를 부여받는다.
* 따라서 부여받은 비트자리가 Set(True)되어 있으면, 해당 EnumValue가 의미하는 상태가 Set(True)가 된 것임을 의미한다.

### 상태부여

~~~c#
public static AttackType SetFlag (AttackType a, AttackType b)
{
    return a | b;
}
~~~

* **Bitwise OR** 연산자를 이용한다.
* 예를 들어서 `AttackType attackType = Melee`라면, 여기서 `attack |= Fire; // 000011`이 되어서 Melee와 Fire에 해당하는 비트가 Set(true)가 되는 것을 확인할 수 있다.

### 상태제거

~~~c#
public static AttackType UnsetFlag (AttackType a, AttackType b)
{
    return a & (~b);
}
~~~

* **Bitwise &과 Bitwise And** 연산자를 혼합하여 이용한다.
* 예를 들어서 `AttackType attackType = 000011; //Melee and Fire`에서 Fire 상태값을 Unset 시키려면 `attackType = attacktype & (~Fire)` 하면 Fire에 해당하는 비트자리만 Unset(false)가 된다.

### 상태조회

~~~c#
// Works with "None" as well
public static bool HasFlag (AttackType a, AttackType b)
{
    return (a & b) == b;
}
~~~

* **Bitwise AND**를 이용한다.
* `return (a & b) != 0` 으로 하면, `attackType = NONE // 000000`인 경우에는 제대로 작동하지 않는다. 따라서 위와 같이 코드를 짜야함을 주의해야한다.
	* `HasFlag(NONE, NONE)`이라고 호출하면 true가 나와야하는데, false가 나온다. 

### 상태토글

~~~c#
public static AttackType ToogleFlag (AttackType a, AttackType b)
{
    return a ^ b;
}
~~~

* **Bitwise XOR**을 이용한다.
	* 두 비트중에 하나만 1인 경우에만 1이다.
* 예를 들어서 `attackType = attacktype ^ Fire` 하면 `attackType` 변수에서 `Fire`에 대응되는 비트자리가 1이면 0이되고, 0이면 1이 된다. (Toggle 된다.)

* [source](https://www.alanzucconi.com/2015/07/26/enum-flags-and-bitwise-operators/)

## 네이밍
### 최적의 이름 길이
* 단어 1개~2개. 최대 4개까지 허용하며 대부분이 함수나 변수를 이루는 단어의 수가 1~2개이어야 한다.

### 변수 네이밍
#### 계산값 한정자

~~~
좋은 예 
revenueTotal 
expenseTotal 
revenueAverage 
expenseAverage

나쁜 예 
totalRevenue 
expenseTotal 
revenueAverage 
averageExpense
~~~

* 만약 변수의 이름에 Total, Sub, Average, Max, Min, Record, String, Pointer 등의 한정자를 사용해야 한다면, 이름의 끝이 이런 수정자를 입력하는 것이 좋다.

#### 중첩된 루프에서는 인덱스의 이름을 단어로 지어라.

~~~c++
// 중첩된 루프에서 좋은 루프 이름을 갖는 예제
for ( teamIndex = 0; teamIndex < teamCount; teamIndex++ ) {  
    for ( eventIndex = 0; eventIndex < eventCount[ teamIndex ]; eventIndex++ ) {
        score[ teamIndex ][ eventIndex ] = 0;
    }
}

// score[ teamIndex ][ eventIndex ]는 scores[ i ][ j ] 보다 많은 정보를 제공한다.
~~~

#### 긍정적인 boolean 변수 이름을 사용하라.

~~~c++
if(notFound ==  false) ...  // 가독성이 떨어진다.
~~~

### 함수 네이밍
#### 함수의 이름을 지을때, 리턴 값에 대한 설명을 사용하라.

~~~c++
bool isReady() {}
~~~

* 함수의 이름을 지을때 쉽게 지을 수 있는 방법은 함수에 리턴값이 있는 경우, 그 리턴값에 대해 설명하는 이름을 짓는 것을 목표로 하면 된다.

#### 동사 + 목적어로 함수의 이름을 구성하라.

~~~
PrintDocument(), CalcMonthlyRevenues(), CheckOrderInfo(), RepaginateDocument()
~~~

* 함수의 이름을 동사+목적어로 구성하게 되면, 함수를 호출할때 코드자체가 하나의 문장이 되기 때문이다. 
	* 클래스이름(주어).동사+목적어

## 함수의 부작용을 없애자.
### 생성자에서는 오직 멤버변수의 초기화만을 담당하라.

~~~c++
TicTacToe(){MakeField();DrawField();} // -> TicTacToe() { MakeField(); }
~~~

* 생성자의 역할을 멤버변수의 초기화이다. 그 이외의 역할을 하는 것은 생성자의 부작용을 야기할 뿐이다.
	* 클라이언트는 생성자의 본 역할인 멤버변수의 초기화만을 원할 수 있기 때문이다.

## 이름충돌을 피하기 위해 namespace를 항상 이용하라.

~~~c++
namespace tictactoe {
}
~~~

* 내가 만든 모듈을 기존의 프로그램에 포함시킬경우 이름충돌이 발생할 위험이 있다. 이를 원천적으로 차단하기 위해서 namespace를 항상 사용하면 좋다.
	* 기존의 프로그램에 전역함수나 변수가 선언될 수 있다.
	* 내가 만든 모듈에서 우연히 같은 이름의 전역함수나 변수를 선언하면, 기존의 프로그램에 내가 만든 모듈을 include 시킬때 이름충돌이 발생할 것이다.

## std::array : 배열 대신에 std::array를 이용하라.

~~~c++
#include <array>

std::array<int, 3> myArray;
std::array<int, 5> myArray2 = { 9, 7, 5, 3, 1 }; // initialization list
~~~

* 일반 배열을 사용하면 std algorithm을 이용할 수 없다. 

* [TicTacToe 게임 이슈](https://github.com/surmounter/BiweeklyGame/issues/7)

### R-value는 vector처럼 값이다.

~~~c++
void function(std::array<int> arr) {}
void function(const std::array<int>& arr) {}
~~~

* 일반 배열의 r-value는 주소였다. 따라서 함수에서 배열을 인자로 받기 위해서는 포인터로 받아야했다.
* 하지만 std::array는 std::vector처럼 r-value가 값이다. 따라서 함수에서 std::array를 인자로서 값으로 복사받을 수 있거나 주소값(참조)을 전달받을 수도 있다.

## std::array : fill() 멤버함수를 이용하여 초기화하라.

~~~c++
#include <array>

std::array<int,3> arr;
arr.fill(3); // {3,3,3}
~~~

## \[] 접근자와 .at()함수의 차이점
* `.at()`함수는 원소를 반환할때 읽기전용 원소를 반환한다. 따라서 `arr.at(1) = 1`과 같이 쓰기 연산이 불가능하다.
* `.at()`함수는 또한 유효범위검사를 해주므로 `[]`접근지정자보다 느리지만 안전하다.

## STL + Lambda 클린하게 쓰기 위한 규격

~~~c++
std::algoritm(v.begin(), v.end(),
	[](const int& i)
{
	//...
}
~~~

## count_if : 개수를 세야할때 적극이용하라.

~~~c++
bool TicTacToe::isFull() const
{
    return 0 == std::count_if(grid.begin(), grid.end(),
        [](const char& i)
    {
        return '-';
    });
}
~~~
