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

Token Calculator::Tokenize(QString expr)
{
	QStringList list;
	list = expr.split(QRegExp("\\s+"));
	Token token;
	token.value = list[0];
	token.getPriority();
	return token;
}

void Calculator::getRPN(Token* inputToken)
{	
	do	{		
			bool isNumber;
			int number = inputToken->value.toInt(&isNumber, 10);
			if (isNumber == true)
			{
				RPN->enqueue(inputToken);
			}
			else
			{
				if (inputToken->value == "(")
				{
					operatorStack->push(inputToken);
				}
				else
				{
					if (inputToken->value == ")")
					{
						while (operatorStack->getTop()->value != "(")
						{
							RPN->enqueue(operatorStack->getTop());
							operatorStack->pop();
							if (operatorStack == nullptr) {
								//exception надо бы написать 
							}
						}
						operatorStack->pop();
						delete inputToken;
					}
				}
				while (inputToken->getPriority() <= operatorStack->getTop()->getPriority())
				{
					RPN->enqueue(operatorStack->getTop());
					operatorStack->pop();  //pop the top operator from the operator-stack and write it to output.
				}
				operatorStack->push(inputToken);
			}
	} while (inputToken != nullptr);
	while (operatorStack != nullptr)
	{
		RPN->enqueue(operatorStack->getTop());
		operatorStack->pop();
		if (operatorStack->getTop()->value == "(")
		{
			// и тут тоже exception 
		}
	}
}

//
//BinaryTree* Calculator::RPNtoBT(QString* RPN)
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

