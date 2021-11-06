#include "func.h"

void SetFont(const wchar_t* Name)
{

	CONSOLE_FONT_INFOEX f;
	f.cbSize = sizeof f;
	f.nFont = 0;
	f.dwFontSize.X = 0;
	f.dwFontSize.Y = 15;
	f.FontFamily = FF_DONTCARE;
	f.FontWeight = FW_NORMAL;
	//f.FaceName[sizeof f] = Name;
	//f.FaceName[sizeof(Name) + 1];
	wcscpy_s(f.FaceName, Name);
	//wcscpy_s(f.FaceName, 32, &Name);

	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 15, &f);
}

void InitTest(Test& test)
{
	InitQuestionsARR(test.questions, test.numberOfQuestions);
	InitAnswersARR(test.questions, test.numberOfQuestions);
	InitCorrectAnswersARR(test.questions, test.numberOfQuestions);
}

void InitQuestionsARR(Question* questions, const size_t numberOfQuestions)
{

}

void InitAnswersARR(Question* questions, const size_t numberOfQuestions)
{

}

void InitCorrectAnswersARR(Question* questions, const size_t numberOfQuestions)
{

}

void initQuestions
(
	Question* q,
	wstring* QuestionsARR,
	wstring** AnswersARR,
	int* CorrectAnswer,
	const size_t SIZE_Q,	
	const size_t SIZE_ANSW
)
{
	for (size_t i = 0; i < SIZE_Q; i++)
	{
		q[i].question = QuestionsARR[i];
		for (size_t j = 0; j < SIZE_ANSW; j++)
		{
			q[i].answers[j] = AnswersARR[i][j];
		}
		q[i].answer_numb = CorrectAnswer[i];
	}
}

void StartTest
(
	Question* q,
	wstring TestName,
	const size_t SIZE_Q,
	const size_t SIZE_ANSW, 
	short* mark,
	short* correct_answers
)
{
	*correct_answers = 0;
	
	short answer;

	wcout << TestName << endl;// Тема теста
	wcout << L"НАЧАТЬ[Enter]";
	cin.get();
	for (size_t i = 0; i < SIZE_Q; i++)
	{
		system("CLS");
		wcout << '(' << i + 1 << ')' << q[i].question << endl;
		wcout << "1)" << q[i].answers[0] << L'\t';
		wcout << "2)" << q[i].answers[1] + L'\n';
		wcout << "3)" << q[i].answers[2] + L'\t';
		wcout << "4)" << q[i].answers[3] + L'\n';
		wcout << endl << L"Введите ответ : ";
		cin >> answer;
		if (std::cin.fail() || answer > 4 || answer < 1) // если предыдущее извлечение оказалось неудачным,
		{
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			i--;
			continue;
		}
		if (q[i].answer_numb == answer)
		{
			correct_answers++;
		}
	}
	if (correct_answers == 0)
	{
		*mark = 2;
	}
	else
	{
		*mark = *correct_answers * 2;
	}
	system("CLS");
	wcout << L"Вы овтетили на " << correct_answers << "/5" << endl;

	wcout << L"Ваша оценка : " << mark << endl << endl;
	system("pause");

}