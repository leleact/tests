#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int InitString(int, char **);
int LoopString(int, char **);
int UpperString(int, char **);
void strappend(const char *, const char *);
int TestOperator(int, char **);
int TestStCstPtoStr(int, char **);
int TestStrReplace(int, char **);

int main(int argc, char **argv) {
  // InitString(argc, argv);
  // LoopString(argc, argv);
  // UpperString(argc, argv);
  // TestOperator(argc, argv);
  TestStrReplace(argc, argv);
  return 0;
}

int TestStrReplace(int argc, char **argv)
{
    std::string src = "msgCd,ver,sysId,msgId,creDtTm,instgDrctPty,instgPty,instdDrctPty,instdPty,seqNb,refSeqNb,endToEndId,bizTyp,bizKind,tranChnlTyp,OrgnlGrpHdr,RspnInf,payerAcctNo,drtFlg,procDt";
    std::string des = "origMsgId,origInstgPty,origMsgCd,origBizTyp,origBizKind,origTranChnlTyp,origEndToEndId";
    std::cout << src.replace(127, 11, des);

    std::cout << "src = [" << src << "]" << std::endl;

    return 0;
}

int TestStCstPtoStr(int argc, char **argv) {
  const char *pchT = "abcdefgh";
  std::string sT = static_cast<std::string>(pchT);
  std::cout << "sT = [" << sT << "]" << std::endl;
  return 0;
}


int UpperString(int argc, char **argv) {
  std::string s = "abcde";

  [](std::string &s) {
    for (auto &c : s) {
      if (c >= 'a' && c <= 'z') {
        c = c + ('A' - 'a');
      }
    }
  }(s);

  std::cout << s << std::endl;

  return 0;
}

int LoopString(int argc, char **argv) {
  const string str = "Hello World";
  for (auto &c : str)
    cout << c << endl;

  return 0;
}

int InitString(int argc, char **argv) {
  //Initialize string
  string s1;
  string s2 = s1;
  string s3 = "Hello";
  string s4(10, 'a');
  string s5(s3);
  string s6("World");


  std::cout << "s1 = [" << s1 << "]" << std::endl;
  std::cout << "s2 = [" << s2 << "]" << std::endl;
  std::cout << "s3 = [" << s3 << "]" << std::endl;
  std::cout << "s4 = [" << s4 << "]" << std::endl;
  std::cout << "s5 = [" << s5 << "]" << std::endl;
  std::cout << "s6 = [" << s6 << "]" << std::endl;

  std::cin >> s1 >> s3;
  std::cout << "s1 = [" << s1 << "]" << std::endl;
  std::cout << "s3 = [" << s3 << "]" << std::endl;

  return 0;
}

int TestOperator(int argc, char **argv) {
  char str1[10];
  char str2[10];
  strcpy(str1, "aaa");
  strcpy(str2, "bbb");
  strappend(str1, str2);

  return 0;
}

void strappend(const char *pstr, const char *pstr2) {
  std::string s;
  s = s + pstr + pstr2;
  std::cout << s << std::endl;
  std::cout << s.size() << std::endl;
  std::cout << s.capacity() << std::endl;
}
