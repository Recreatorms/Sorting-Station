#include "Calculator.h"


Calculator::Calculator()
{
	operatorStack = new Stack;
	RPN = new Queue;
	bt = new BinaryTree;
}


Calculator::~Calculator()
{
	delete operatorStack;
	delete RPN;
	delete bt;
}

std::vector<Token> Calculator::Tokenize(QString expr)
{
	std::vector <Token> tokens;
	Token currentToken;
	QString buf = "";
	for (int i = 0; i < sizeof(expr); ++i) 
	{
		if (expr.at(i) == " ") 
		{
			continue;
		}
		buf += expr.at(i);
	}

	for (int i = 0; i < sizeof(buf); ++i)
	{
		if (buf.at(i) == "(")
		{
			currentToken.value = "(";
			tokens.push_back(currentToken);
		}
	}
	return tokens;
}

void Calculator::getRPN(std::vector <Token>& tokens)
{	
	for (int i = 0; i < tokens.size(); ++i)
	{
		Token inputToken = tokens[i];
		bool isNumber;
		int number = inputToken.value.toInt(&isNumber, 10);
		if (isNumber == true)
		{
			RPN->enqueue(inputToken);
		}
		else
		{
			if (inputToken.value == "(")
			{
				operatorStack->push(inputToken);
			}
			else
			{
				if (inputToken.value == ")")
				{
					while (operatorStack->getTop().value != "(")
					{
						RPN->enqueue(operatorStack->getTop());
						operatorStack->pop();
						if (operatorStack == nullptr) {
							//exception надо бы написать 
						}
					}
					operatorStack->pop();
				}
			}
			while (inputToken.getPriority() <= operatorStack->getTop().getPriority())
			{
				RPN->enqueue(operatorStack->getTop());
				operatorStack->pop();  //pop the top operator from the operator-stack and write it to output.
			}
			operatorStack->push(inputToken);
		}
	
	}
	while (operatorStack != nullptr)
	{
		RPN->enqueue(operatorStack->getTop());
		operatorStack->pop();
		if (operatorStack->getTop().value == "(")
		{
			// и тут тоже exception 
		}
	}
}

//
/*
	короч как я понял на лекции
		нужно создать 2й стек
		и с его помощью закидывать данные в дерево
		хрен его знает
		типа есть найс очередь
		Queue RPN
		(допустим получили её без ошибок)
		и нужно закинуть ее примерно тем же способ как токены в стек и очередь, а из стека в очередь
		то есть
		берем RPN
		кидаем на стек
		со стека на бт
*/
//BinaryTree* Calculator::RPNtoBT(QString* RPN) //
//{
//	for (int i = sizeof(RPN); i > 0; --i)
//	{
//		bt->addNode(bt, RPN[i]);
//	}
//	return bt;
//}
//
//int Calculator::Calculate(BinaryTree* bt)
//{
//	int result = 5;
//	/*if (!bt->isNumber(bt))
//	{
//		if (bt->value == '+')
//		{
//			if (bt->right->isNumber(bt) && bt->left->left->isNumber(bt))
//			{
//				result = bt->left->value.toInt(nullptr,10) + bt->right->value.toInt(nullptr, 10);
//			}
//		}
//	}
//	else
//	{
//		if (bt->right->isNumber(bt))
//		{
//			Calculate(bt->right);
//		}
//		if (bt->left->isNumber(bt))
//		{
//			Calculate(bt->left);
//		}
//	}
//	*/
//	return result;
//}

