#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

char* min(char* s1, char* s2, char* s3);

int main()
{
    char s1[] = "hello", s2[] = "joe", s3[] = "alexander";
    char *smallest = min(s1, s2, s3);
    cout << smallest << endl;

    return 0;
}

char* min(char* s1, char* s2, char* s3)
{
    cout << s1 << " " << s2 << " " << s3 << endl;
    cout << strcmp(s1, s2) << " " << strcmp(s1, s3) << " "
        << strcmp(s2, s3) << endl;
	if (strcmp(s1, s2) < 0 && strcmp(s1, s3) < 0) return s1;
	if (strcmp(s2, s3) < 0) return s2;
	return s3;
}
