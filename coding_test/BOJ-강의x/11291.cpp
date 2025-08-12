#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

static const size_t BUFSZ = 1 << 22; // 4MB(상황에 따라 8~16MB까지 늘려도 됨)
static unsigned char buf[BUFSZ];
static size_t bi = 0, bn = 0;

inline bool refill()
{
    bi = 0;
    bn = ::read(0, buf, BUFSZ);
    return bn > 0;
}

inline int readChar()
{
    if (bi >= bn)
    {
        if (!refill())
            return -1;
    }
    return buf[bi++];
}

inline bool readUInt(uint32_t &x)
{
    int c;

    do
    {
        c = readChar();
        if (c == -1)
            return false;
    } while (c <= ' ');

    // 숫자 파싱
    uint32_t v = 0;
    while (c >= '0' && c <= '9')
    {
        v = v * 10u + (uint32_t)(c - '0');
        c = readChar();
        if (c == -1)
        {
            x = v;
            return true;
        }
    }
    x = v;
    return true;
}

int main()
{
    // iostream 끄기(혹시 사용할 경우 대비)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    uint32_t N;
    if (!readUInt(N))
    {
        printf("0\n0\n");
        return 0;
    }

    uint64_t sum = 0;
    uint32_t M = 0, v;

    // N개 읽기 시도(EOF 만나면 조기 종료)
    while (M < N && readUInt(v))
    {
        sum += v;
        ++M;
    }

    // 출력은 표준 printf가 충분히 빠름
    printf("%u\n%llu\n", M, (unsigned long long)sum);
    return 0;
}
