#include "../Stack/Stack_vector.h"
double evaluate (char* S, char*& RPN){//对(已删除白空格的表达式S求值)，并转换为逆波兰式RPN
    Stack<double> opnd; Stack<char> optr;//运算数栈、运算符栈
    optr.push('\0');//尾哨兵'\0'也作为头哨兵首先入栈
    while (!optr.empty()){//在运算符非空之前，逐个处理表达式中的各字符
        if (isdigit( *S )){//当前字符为操作数，则
            readNumber(S, opnd); append(RPN, opnd.top());
        } else{//若当前字符为运算符，则
            switch ( orderBetween (optr.top(), *S)){//将其与栈顶运算符之间的优先级高低分别处理
                case '<'://栈顶运算符优先级更低时
                    optr.push( *S ); S++;//计算推迟，当前运算符进栈
                    break;
                case '='://优先级相等(右括号和尾部哨兵'\0'时)
                    optr.pop(); S++;
                    break;
                case '>':{//栈顶运算符优先级更高时，可实施相应的计算，并将结果重新入栈
                    char op = optr.pop(); append(RPN, op);
                    if ('!' == op){//若属于一元运算符
                        double pOpnd = opnd.pop();//只需取出一个操作数，并
                        opnd.push(calcu(op, pOpnd));//实施一元计算，结果入栈
                    }else{//对于其它(二元)运算符
                        double pOpnd2 = opnd.pop(); double pOpnd1 = opnd.pop();//取出后、前操作数
                        opnd.push(calcu(pOpnd1, op, pOpnd2));
                    }
                    break;
                }
                default : exit(-1);//逢语法错误，不做处理直接退出
            }//switch
        }//while
    }
    return opnd.pop();//弹出并返回计算结果
}