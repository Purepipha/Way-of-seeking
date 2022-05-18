bool paren(const char exp[], int lo, int hi){//表达式匹配检查，可兼顾三种括号
    Stack<char> S;
    for (int i = lo; i <= hi; i++){//逐一检查当前字符
        switch (exp[i]){//左括号直接进栈；右括号若与栈顶失配，则表达式必不匹配
            case '(': case '[': case '{': S.push(exp[i]);break;
            case ')': if (S.empty() || ')' != S.pop()) return false;break;
            case ']': if (S.empty() || ']' != S.pop()) return false;break;
            case '}': if (S.empty() || '}' != S.pop()) return false;break;
            default: break;//非括号字符一律忽略
        }
    }
    return S.empty();//整个表达式扫描过后，栈中仍残留左括号，则不匹配，栈为空，匹配
}