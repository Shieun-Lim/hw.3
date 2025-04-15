#include <iostream>

int inputScore(); //콘솔창으로 int형 값 입력받고 이를 리턴

void inputScore(int& score); //콘솔창으로 매개변수 값 입력
//오버로딩(함수 이름이 같고 같은 작업을 하지만, 리턴 타입과 매개변수가 다름)

bool isValid(int score);//매개변수가 0~100이면 true, 그렇지 않으면 false를 리턴

void score2grade(const int& score, char& grade); 
//매개변수는 const int형 참조, char형 참조 (총 2개)
//int형 매개변수 값 (90이상,80이상,70이상,60이상,그외)
//에 따라 char형에 ('A','B','C','D','F')값을 할당
//int형 매개변수를 const한 이유 : 매개변수를 함수 내에서 수정하지 않기 위해서(매개변수 보호)

void showScoreGrade(const int& score = 100, const char& grade = 'A');
//기본값은 순서대로 100, 'A'
//콘솔창으로 매개변수 출력
//이 함수는 기본값을 갖는 매개변수를 받아 콘솔창에 출력하는 함수
//기본값이 설정되어 있어 인자를 전달하지 않으면 100과 'A'가 기본값으로 사용됨





int main()
{
	std::cout << "03, 2593249, 임시은\n";
	int score{};
	std::cout << &score << std::endl;
	inputScore(score);//주소가 같은 이유 : inputScore 함수가 int형 변수의 참조를 매개변수로 받기 때문에, 함수 안에서도 원래 변수와 동일한 메모리 주소를 사용함.
	if (!isValid(score))//주소가 다른 이유 : isValid 함수에서는 score가 값에 의한 복사로 전달되기 때문에 함수 내부의 score는 main의 score와는 다른 주소를 가짐. 
	{
		std::cout << score << "is NOT valid!\n";
		std::exit(-1);
	}

	char grade{};
	score2grade(score, grade);
	showScoreGrade(score, grade);
	showScoreGrade();//인자를 넣지 않아도 되는 이유 : showScoreGrade 함수에서 매개변수에 기본값을 설정했기 때문에 인자를 전달하지 않아도 컴파일러가 기본값을 사용하여 호출 가능함.

	return 0;
}

int inputScore()
{
	std::cout << "Enter your score: ";
	int score{};
	std::cin >> score;
	return score;
}

void inputScore(int& score)
{
	std::cout << "pass-by-reference: " << &score << std::endl;
	std::cout << "Enter your score: ";
	std::cin >> score;
	// 리턴값 없음 -> 입력값이 위에 score 자리로 들어감
}

bool isValid(int score)
{
	std::cout << "pass-by-value: " << &score << std::endl;
	return score >= 0 && score <= 100;
}

void score2grade(const int& score, char& grade)
{
	if (score >= 90) grade = 'A';
	else if (score >= 80) grade = 'B';
	else if (score >= 70) grade = 'C';
	else if (score >= 60) grade = 'D';
	else grade = 'F';
}

void showScoreGrade(const int& score, const char& grade)
{
	std::cout << score << " , " << grade << std::endl;
}
