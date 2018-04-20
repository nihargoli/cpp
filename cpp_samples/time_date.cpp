#include <cstdio>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
    const static size_t bufsize = 128;
    time_t t = time(nullptr);   //  current system time

    printf("size of time_t is %ld bits. \n", sizeof(time_t) * 8);

    struct tm gmt = *gmtime(&t);        //  time in GMT
    struct tm localt = *localtime(&t);  //  local time

    printf("universal time is now %04d-%02d-%02d %02d:%02d:%02d\n",
        gmt.tm_year + 1900, gmt.tm_mon + 1, gmt.tm_mday,
        gmt.tm_hour, gmt.tm_min, gmt.tm_sec);

    printf("local time is now %04d-%02d-%02d %02d:%02d:%02d\n",
        localt.tm_year + 1900, localt.tm_mon + 1, localt.tm_mday,
        localt.tm_hour, localt.tm_min, localt.tm_sec);

    char buf[bufsize];
    size_t len = strftime(buf, bufsize, "%Y-%m-%d %H:%M:%S", &gmt);
    printf("universal time is now %s (%ld characters)\n", buf, len);

    len = strftime(buf, bufsize, "%Y-%m-%d %H:%M:%S %Z", &localt);
    printf("local time is now %s (%ld characters)\n", buf, len);

    return 0;
}