// 배열의 성질 중
// Cache hit rate 가 높다.
// 배열이 메모리 캐시와 잘 맞아서 성능이 향상된다는 의미
/*
캐시 히트율(Cache hit rate): CPU가 필요한 데이터를 캐시에서 찾을 수 있는 비율.
배열의 캐시 히트율이 높은 이유: 배열은 메모리에 연속적으로 저장되므로, 순차적으로 접근할 때 공간적 지역성과 시간적 지역성을 최대한 활용할 수 있습니다.
캐시 메모리: 주 메모리보다 빠른 메모리로, 최근에 사용된 데이터를 저장하여 CPU 성능을 향상시킵니다.
*/


//초기화 구현
// memset, for, fill

//vector

//0x01강 연습문제

int func2(int arr[], int N){
    int occur[101] = {};
    for(int i = 0; i < N; i++){
        if(occur[100-arr[i]] == 1)
        return 1;
        occur[arr[i]] = 1;
    }
    return 0;
}