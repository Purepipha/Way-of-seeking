void append(char*& rpn, float opnd){//将操作数接至RPN结尾
    int n = strlen(rpn);//RPN当前长度(以'\0'结尾，长度n + 1)
    char buf[64];
    if ( opnd != (float)(int)opnd )
        std::sprintf(buf, "0.2f \0", opnd);
    else
        std::sprintf(buf, "%d \0",(int)opnd);
    rpn = (char*)realloc(rpn,sizeof(char) * (n + strlen(buf) + 1));//拓展空间
    strcat(rpn, buf);
}
void append(char*& rpn, char optr){//将运算符接至RPN末尾
    int n = strlen(rpn);
    rpn = (char*)realloc(rpn, sizeof(char) * (n + 3));//扩展空间
    sprintf(rpn + n, "%c ", optr);//接入指定的运算符
    rpn[n + 2] = '\0';
}