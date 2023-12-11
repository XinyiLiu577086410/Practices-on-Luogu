#include <map>
#include <string>
#include <cstdio>
char s1[100+10], s2[100+10];
int main(void) {
	std::map<std::string, std::string> mmap;
	while (1) {
		scanf("%s", s1);
		if(getchar() == '\n') break;
		else scanf("%s", s2);
		mmap[s2] = s1;
	}
	while (1) {
		if(mmap.find(s1) != mmap.end()) printf("%s\n", mmap[s1].c_str());
		else printf("eh\n");
		char t;
		getchar();
		if((t=getchar()) == EOF || t == '\n') break; else ungetc(t, stdin);
		scanf("%s", s1);
	}
	return 0;
}