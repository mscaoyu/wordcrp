#include <FileReader.h>
using namespace redbud;

int main()
{
    FileReader freader("test.txt");
    char buf[128];
    while(1)
    {
        int ret = freader.readWord(buf);
        if(freader.isEof())
            break;
        if(ret > 0)
            printf("read the word is %s\n",buf);
        else
            printf("a newline\n");
    }

}
