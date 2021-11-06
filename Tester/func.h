#pragma once
#include <iostream>
#include <string>
#include <io.h> 
#include <fcntl.h>
#include <Windows.h>
using namespace std;

struct Question		//Cтруктура вопросов
{
	wstring question;			//вопрос
	wstring answers[4];			//возможные ответ
	short answer_numb;			//правильный ответ
};

struct Test
{
	Question* questions;
	size_t numberOfQuestions;
	int correctAnswers;
	int mark;
};

void SetFont(const wchar_t*);

void InitTest(Test& test);
void InitQuestionsARR(Question&, const size_t);
void InitAnswersARR(Question&, const size_t);
void InitCorrectAnswersARR(Question&, const size_t);



void initQuestions		//Передача значений в структуру Qustion
(
	Question* q,				//массив структур с вопросами
	wstring* QuestionsARR,		//массив вопросов
	wstring** AnswersARR,		//массив возможных ответов
	int* CorrectAnswer,			//массив правильных ответов
	const size_t SIZE_Q,		//кол-во вопросов
	const size_t SIZE_ANSW		//кол-во ответов
);

void StartTest			//Начать тест
(
	Question* q,				//массив структур с вопросами
	wstring TestName,			//название теста
	const size_t SIZE_Q,		//кол-во вопросов
	const size_t SIZE_ANSW,		//кол-во ответов
	short* mark,				//оценка
	short* correct_answers		//кол-во правильных ответов
);