#include "func.h"

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetFont(L"Courier New");
	const size_t SIZE_Q = 5;
	const size_t SIZE_ANSW = 4;
	wstring** AnswersARR;
	wstring* QuestionsARR;
	int* CorrectAnswer;
	wstring testName;
	Question q;
	
	short correct_answers;
	short mark;
	

	initQuestions(&q, QuestionsARR, AnswersARR, CorrectAnswer, SIZE_Q, SIZE_ANSW);
	StartTest(&q, testName, SIZE_Q, SIZE_ANSW, &mark, &correct_answers);
}