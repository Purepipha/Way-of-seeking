// Bitmap.h -- definition of class Bitmap
#include <fstream>
class Bitmap{//位图Bitmap类
private:
    char * M; int N; //比特图所存放的空间M[]，容量为N*sizeof(char)*8比特
protected:
    void memset(char * M, int N, bool b);
    void memcpy(char * T, int TN, char * S, int SN);
    void init(int n) { M = new char[N = (n + 7) / 8]; memset(M, N, 0);}
    void expand(int k);
public:
    Bitmap(int n = 8) { init(n); }//按指定默认创造Bitmap图(测试时选用较小的默认值)
    Bitmap(char * file, int n) //按指定或默认规模，从指定文件读取比特图
    {init(n); std::FILE * fp = fopen(file, "r");fread(M, sizeof(char), N, fp);fclose(fp);}
    ~Bitmap() {delete []M, M = NULL; } //析构时释放比特图空间

    void set(int k)  { expand(k);       M[k >> 3] |=  (0x80 >> (k & 0x07)); }
    void clear(int k){ expand(k);       M[k >> 3] &= ~(0x80 >> (k & 0x07)); }
    bool test(int k) { expand(k);return M[k >> 3] &   (0x80 >> (k & 0x07)); }

    void dump(char * file)//将位图整体导出至指定的文件，以便对此后的新位图批量初始化
    {   std::FILE * fp = fopen(file, "w"); fwrite (M, sizeof(char), N, fp); fclose(fp); }
    char * bits2string(int n){//将前n位转换为字符串——
        expand(n - 1); //此时可能被访问的最高位为bitmap[n-1]
        char * s = new char[n + 1]; s[n] = '\0';//字符串所占空间
        for (int i = 0; i < n; i++) s[i] = test(i) ? '1' : '0';
        return s; //返回字符串位置
    }

};
void Bitmap::expand(int k)
{
    if (k < 8 * N)
        return;
    int oldN = N; char * oldM = M;
    init(2 * k);
    memcpy(M, N, oldM, oldN);   //原数据转移至新空间
    delete []oldM;
}