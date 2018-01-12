#include <FileReader.h>
#include <string.h>
using namespace redbud;

FileReader::FileReader(const char* file):fin_(fopen(file,"rb"))
{
    if(fin_ == NULL)
    {
        printf("FATAL ERROR: training data file is not found\n");
        exit(1);
    }
}
FileReader::~FileReader()
{
    fclose(fin_);
}
// Reads a single word from a file, assuming space + tab + EOL to be word boundaries
int FileReader::readWord(char *word) {
  int a = 0, ch;
  while (!feof(fin_))
  {
    ch = fgetc(fin_);
    if (ch == 13) continue;
    if ((ch == ' ') || (ch == '\t') || (ch == '\n'))
    {
      if (a > 0)
      {
        if (ch == '\n')
        {
            ungetc(ch, fin_);
        }
        break;
      }
      if (ch == '\n')
      {
        return 0;
      }
      else
      {
        continue;
      }
    }
    word[a] = ch;
    a++;
    if (a >= MAX_WORD_SIZE - 1) a--;   // Truncate too long words
  }
  word[a] = 0;
  return a;
}
