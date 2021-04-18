#include <iostream>
#include <time.h>

//  Enum : 열거형
//  굉장히 많이 쓰임 (가독성)
//  이것도 자료형 CHARACTER_MOTION type = IDLE; (0)
enum CHARACTER_MOTION
{
    IDLE = 0,
    MOVE,
    JUMP,
    ATTACK,
    HIT,
    DEATH

    /*
        2배수 씩 찍는 법
        IDLE = 2
        MOVE = IDLE + 2,
        JUMP = MOVE + 2
    */
};

struct NumberData
{
    int number;
    bool isCheck;
};

int GetRandomNumber(NumberData containValues[], int index);

void PrintBingo(NumberData values[]);

int main()
{
    int z = rand() % 100;

    std::cout << z << std::endl;

    std::cin >> z;

    if (z > 10)
    {
        std::cout << "0" << std::endl;
    }
    else
    {
        std::cout << "10" << std::endl;
    }

    /*
    //  랜덤한 수를 생성하기 위해 시드를 생성
    srand(time(NULL));
    int a = rand();
    int b = rand() % 100; // 0~ 99까지 랜덤한 수를 받는다
    int c = rand() % 25; // 0 ~ 24까지 랜덤한 수를 받는다
    int d = rand() % 50 + 1; // 0 + 1 ~ 49 + 1 까지 랜덤한 수를 받는다
    //  Why?
    //  rand() % 50이면 0 ~ 49까지 받지만 마지막의 + 1은 사칙연산으로 인해 마지막에 계산된다
    //  그래서, 0 ~ 49 값에서 + 1을 해준다

    //  int 100칸 짜리 방 생성
    int arrays[100];
    for (int i = 0; i < 100; ++i)
    {
        arrays[i] = i;
        //  i 가 0일 때 arrays[0] = 0;
        //  i 가 1일 때 arrays[1] = 1;
        //  i 가 2일 때 arrays[2] = 2;
        //  ...
    }
    */

#pragma region 숙제 + 쌤 코드 스타일 가이드
    /*
        삼항 연산자
        bool isResult;
        if (100 > 0) isResult = true;
        else isResult = false;
        항상 왼쪽이 조건 부 True (C언어)
    */
    //  bool isResult = (100 > 0) ? true : false;

    /*
        멤버 변수는 m_(변수명.ToUpper() -> 앞 글자 대문자)  ex : int m_Number;
        글로벌 변수는 g_(변수명.ToUpper()0 -> 앞 글자 대문자) ex : int g_Value;
        bool isResult -> 조건 변수는 접두 is(변수명)
        Function은 자료형 대문자 + 소문자 + 단어 추가시 앞 대문자 -> void Initialize() { }
        void SetNumber() { }
        대표적인 공식 문자는 C++ google style
        쌤은 c# microsoft 공식 메뉴얼을 c++에 접두해 사용
    */

    /*
        쉬운 숙제
        1. 헝가리안 표기법, 스네이크 표기법, 허스칼 표기법 알아오고 쌤한테 설명할 수 있도록 보고오기
        2. OOP -> 객체지향에 대해서 간단히 알아오기 (ex : 캡슐화, 종, 상속성 등등)
    */
    
    /*
        숙제 아님
        고급 3. DOD -> 데이터 지향 힐끔 보기
        ! Unity DOT 아님
    */
#pragma endregion

    /*
    CHARACTER_MOTION type = IDLE;   //  (int)
    int code = 0;
    std::cin >> code;

    //  명시적 형변환 ? 개발자가 직접 표기하여 해당 형시기을 표기한 형식으로 바꾸는 변환법
    type = (CHARACTER_MOTION)code;

    //  묵시적 형변환 (암묵적 형변환) 컴파일러 (프로그램) 이 해당 형식을 추정하여 변경하는 변환법
    float data = code;

    switch (type)
    {
    case IDLE:
        break;
    case MOVE:
        break;
    case JUMP:
        break;
    case ATTACK:
        break;
    case HIT:
        break;
    case DEATH:
        break;
    default:
        break;
    }
    */

    //  빙고 만들기
    NumberData values[ 25 ] = { 0, };

    //  초기화

    for (int i = 0; i < 25; ++i)
    {
        //  숫자 1 ~ 25까지 넣기
        //  중복 없이 (랜덤)
        values[i].number = GetRandomNumber(values, i);
        //printf_s("%d\t", values[i].number);
    }

    int number = 0;
    while (number != -1)
    {
        system("cls");
        PrintBingo(values);

        std::cin >> number;

        for (int i = 0; i < number; ++i)
        {
            if (values[i].number == number)
            {
                values[i].isCheck = true;
            }
        }
    }

    return 0;
}

int GetRandomNumber(NumberData containValues[], int index)
{
    int value = rand() % 25 + 1;
    for (int i = 0; i < index; ++i)
    {
        if (value == containValues[i].number)
        {
            value = rand() % 25 + 1;
            i = -1;
        }
    }

    return value;
}

void PrintBingo(NumberData values[])
{
    /*
    for (int i = 0; i < 26; ++i)
    {
        std::cout << values[i - 1].number << "\t";

        if (i % 5 == 0) std::cout << std::endl;
    }
    */

    for (int y = 0; y < 5; ++y)
    {
        for (int x = 0; x < 5; ++x)
        {
            std::cout << values[y * 5 + x].number << "\t";
        }
        std::cout << std::endl;
    }
}