# 연습 문제
## 바로가기
1. [숫자 골라내기](#1-숫자-골라내기)
2. [이항 계수의 합](#5-이항-계수의-합)

## 1. 숫자 골라내기
### 문제 요약
주어진 숫자들 중 홀수번 등장하는 모든 숫자들을 XOR한 값을 구하여라.

```
ex) 2, 5, 3, 3 -> 2(0010) xor 5(0101) = 7(0111)
```

### 접근 방법
처음에는 주어진 숫자들 중 짝수번 등장하는 숫자를 찾고, 이를 제외한 모든 숫자를 XOR를 취하여 답을 구하려 했다.

하지만 XOR 연산은 **비트 값이 1인 자리에 대해서 비트 반전을 수행**하는 연산의 의미도 가진다.

즉 임의의 숫자에 같은 값으로 XOR 연산을 두번하게 되면, 원래의 숫자대로 되돌아오게 된다.

```
ex) 7(0111) xor 3(0011) = 4(0100)
    4(0100) xor 3(0011) = 7(0111)
```

따라서 임의의 숫자에 같은 값으로 XOR 연산을 짝수번 취하여도 그 수는 변하지 않는다.

그래서 각 숫자의 등장 횟수의 홀짝에 관계 없이, 주어진 모든 수를 XOR 연산하면 된다.

## 5. 이항 계수의 합
### 문제 요약
<a href="https://www.codecogs.com/eqnedit.php?latex=\sum_{i=0}^N&space;\sum_{j=0}^M&space;{_{i&plus;j}C_{i}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sum_{i=0}^N&space;\sum_{j=0}^M&space;{_{i&plus;j}C_{i}}" title="\sum_{i=0}^N \sum_{j=0}^M {_{i+j}C_{i}}" /></a>
의 값을 빠르게 구하여라.

### 첫번째 접근
큰 값의 조합을 빠르게 구해야하므로, 메모이제이션과 함께 재귀호출을 통한 dp 방법으로 조합을 구하고자 하였다.

이항 계수는 
<a href="https://www.codecogs.com/eqnedit.php?latex={_{n}C_{k}}={_{n-1}C_{k-1}&plus;_{n-1}C_{k}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?{_{n}C_{k}}={_{n-1}C_{k-1}&plus;_{n-1}C_{k}}" title="{_{n}C_{k}}={_{n-1}C_{k-1}+_{n-1}C_{k}}" /></a>
와 같은 성질을 가진다.

이를 통해 combination 함수를 단순하게 재귀함수로 구현하면 다음과 같다.

```c++
int combination(int n, int k) 
{
    if (k==0 || n==k)
        return 1;
        
    return combination(n-1, k-1) + combination(n-1, k);
}
```

하지만 이 코드는 같은 combination값을 중복해서 여러번 계산하는 심각한 문제를 가지고 있다. 

이러한 문제는 재귀 호출을 사용할 때 항상 주의해야하는 점이다.

이를 해결하기 위한 방법이 메모이제이션(memoization)이다. 

한번 계산한 값은 기억해두고 있다가, 다음 번에 필요할 때는 다시 새로 계산하지 않고, 기억해둔 값을 불러와서 사용하는 것이다.

메모이제이션을 적용한 combination 함수는 다음과 같다.

```c++
int memo[size_n][size_k];

int combination(int n, int k) 
{
    if (memo[n][k] != 0)
        return memo[n][k];
    
    int result;
    
    if (k==0 || n==k)
        result = 1;
    else
        result = combination(n-1, k-1) + combination(n-1, k);
    
    memo[n][k] = result;
    
    return result;
}
```

n의 값이 작을 때는 두 방법 사이에 실행 시간 차이가 잘 느껴지지 않을 수 있다.

하지만 n이 커지면 커질 수록 기존 방법에서 중복 연산이 기하급수적으로 많아지기 때문에, 상당한 차이가 나게 된다.

### 위 방법의 문제점
위의 방법에서는 재귀 호출에서 발생하는 중복 연산을 피하기 위해 메모리 공간을 소비하여 값을 기억해두었다.

여기서 문제가 발생했는데, 실제로 할당할 수 있는 배열의 크기가 한정되어있다는 점이다.

주어진 문제에서 N과 M은 각각 0 이상 1,000,000 이하로, i+j의 최댓값은 2,000,000이 된다.

따라서 가능한 모든
<a href="https://www.codecogs.com/eqnedit.php?latex={_{i&plus;j}C_{i}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?{_{i&plus;j}C_{i}}" title="{_{i+j}C_{i}}" /></a>
의 값을 표현하기 위해서는 memo 배열의 크기가 다음과 같아야한다.

```c++
int memo[20000001][20000001];
```

이정도 크기의 배열은 컴파일 단계에서부터 다음과 같은 오류를 뱉는다.

```
error: size of array 'memo' exceeds maximum object size '2147483647'
```

저 배열의 크기가 얼마나 크길래 오류까지 나는지 생각해보자.

<a href="https://www.codecogs.com/eqnedit.php?latex=2,000,000&space;=&space;2&space;\times&space;10^6" target="_blank"><img src="https://latex.codecogs.com/gif.latex?2,000,000&space;=&space;2&space;\times&space;10^6" title="2,000,000 = 2 \times 10^6" /></a>
이므로 memo 배열에 포함된 int 변수의 갯수는 
<a href="https://www.codecogs.com/eqnedit.php?latex=4&space;\times&space;10^{12}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?4&space;\times&space;10^{12}" title="4 \times 10^{12}" /></a>
개이다.

int 변수 한개의 크기가 4 byte 이므로 memo 배열은 실제로 
<a href="https://www.codecogs.com/eqnedit.php?latex=16&space;\times&space;10^{12}&space;\&space;\text{Byte}&space;=&space;16&space;\&space;\text{TB}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?16&space;\times&space;10^{12}&space;\&space;\text{Byte}&space;=&space;16&space;\&space;\text{TB}" title="16 \times 10^{12} \ \text{Byte} = 16 \ \text{TB}" /></a>
이다.

현재 평균 RAM 용량이 10GB 대인 것을 생각하면 터무니 없는 크기이다.

이는 memo 배열을 선언하는 방식을 바꾸는 등의 방법으로는 근본적으로 문제를 해결할 수 없음을 의미한다.

### 두번째 접근
조합을
<a href="https://www.codecogs.com/eqnedit.php?latex={_{n}C_{k}}={_{n-1}C_{k-1}&plus;_{n-1}C_{k}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?{_{n}C_{k}}={_{n-1}C_{k-1}&plus;_{n-1}C_{k}}" title="{_{n}C_{k}}={_{n-1}C_{k-1}+_{n-1}C_{k}}" /></a>
의 성질을 통해서 재귀적인 방법으로 구하는 대신
<a href="https://www.codecogs.com/eqnedit.php?latex={_nC_k}=\frac{n!}{k!(n-k)!}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?{_nC_k}=\frac{n!}{k!(n-k)!}" title="{_nC_k}=\frac{n!}{k!(n-k)!}" /></a>
로 직접 구할 것이다.

또한 조합을 계산하는 횟수를 최대한 줄이기 위해 주어진 식을 그대로 사용하지 않고 먼저 정리해서 단순화하였다.

<a href="https://www.codecogs.com/eqnedit.php?latex=\sum_{j=0}^M{_{i&plus;j}C_i}={_iC_i}&plus;{_{i&plus;1}C_i}&plus;\cdots&plus;{_{i&plus;M}C_i}={_{i&plus;M&plus;1}C_{i&plus;1}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sum_{j=0}^M{_{i&plus;j}C_i}={_iC_i}&plus;{_{i&plus;1}C_i}&plus;\cdots&plus;{_{i&plus;M}C_i}={_{i&plus;M&plus;1}C_{i&plus;1}}" title="\sum_{j=0}^M{_{i+j}C_i}={_iC_i}+{_{i+1}C_i}+\cdots+{_{i+M}C_i}={_{i+M+1}C_{i+1}}" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=\sum_{i=0}^N{_{i&plus;M&plus;1}C_{i&plus;1}}={_{M&plus;1}C_{1}}&plus;{_{1&plus;M&plus;1}C_{2}}&plus;\cdots&plus;{_{N&plus;M&plus;1}C_{N&plus;1}}={_{N&plus;M&plus;2}C_{N&plus;1}}-1" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\sum_{i=0}^N{_{i&plus;M&plus;1}C_{i&plus;1}}={_{M&plus;1}C_{1}}&plus;{_{1&plus;M&plus;1}C_{2}}&plus;\cdots&plus;{_{N&plus;M&plus;1}C_{N&plus;1}}={_{N&plus;M&plus;2}C_{N&plus;1}}-1" title="\sum_{i=0}^N{_{i+M+1}C_{i+1}}={_{M+1}C_{1}}+{_{1+M+1}C_{2}}+\cdots+{_{N+M+1}C_{N+1}}={_{N+M+2}C_{N+1}}-1" /></a>

정리하고 보면 조합은 한번만 계산하면 되는 문제로 바뀐다.

일단 먼저 팩토리얼을 계산하는 함수를 단순하게 생각해보면 다음과 같다.

```c++
int factorial(int n)
{   
    int result=1;
    
    for (int i = 1; i <= n; i++)
        result *= i;
    
    return result;
}
```

이렇게 사용할 경우 factorial 함수를 호출할 때마다 1에서 부터 새로 모두 곱하여 답을 구하므로 매우 비효율적이다.

따라서 팩토리얼 값들도 앞에서와 마찬가지로 memoization을 통해 중복되는 연산을 없애면 다음과 같다.

```c++
int Max;
int memo[2000004];

int factorial(int n)
{
    int result = 1;
  
    if (Max == 0)
        memo[0] = 1;
        
    for (int i = Max + 1; i <= n; i++)
        memo[i] = i * memo[i - 1];

    if (Max < n)
        Max = n;

    return memo[n];
}
```

### 모듈로 연산 분배 법칙

이렇게 구한 팩토리얼들로 조합을 계산하기 전에 먼저 짚고 넘어가야할 것이 있다.

N, M의 값이 커지면 팩토리얼과 조합의 값이 기하급수적으로 커진다.

따라서 문제에서는 결과 값의 1,000,000,007로 나눈 나머지를 구하도록 하고있다.

여기서 모듈로 연산의 분배 법칙에 대해서 알아야 한다.

<a href="https://www.codecogs.com/eqnedit.php?latex=(a&space;&plus;&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&plus;(b&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(a&space;&plus;&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&plus;(b&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" title="(a + b) \ \text{mod} \ M = ((a \ \text{mod} \ M)+(b \ \text{mod} \ M)) \ \text{mod} \ M" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=(a&space;-&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)-(b&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(a&space;-&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)-(b&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" title="(a - b) \ \text{mod} \ M = ((a \ \text{mod} \ M)-(b \ \text{mod} \ M)) \ \text{mod} \ M" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=(a&space;\times&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(a&space;\times&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" title="(a \times b) \ \text{mod} \ M = ((a \ \text{mod} \ M) \times (b \ \text{mod} \ M)) \ \text{mod} \ M" /></a>

위와 같이 덧셈, 뺄셈, 곱셈에 대해서는 모듈로 연산이 분배가 성립하지만, 나눗셈에 대해서는 성립하지 않는다.

따라서 나눗셈은 다음과 같이 곱셈으로 바꾸어 계산하여야한다.

<a href="https://www.codecogs.com/eqnedit.php?latex=(a&space;\div&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b^{-1}&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(a&space;\div&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b^{-1}&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" title="(a \div b) \ \text{mod} \ M = ((a \ \text{mod} \ M) \times (b^{-1} \ \text{mod} \ M)) \ \text{mod} \ M" /></a>

이때, M이 소수(prime)이라면 페르마의 소정리에 의해 위의 식은 다음과 같아진다.

<a href="https://www.codecogs.com/eqnedit.php?latex=(a&space;\div&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b^{M-2}&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(a&space;\div&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b^{M-2}&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" title="(a \div b) \ \text{mod} \ M = ((a \ \text{mod} \ M) \times (b^{M-2} \ \text{mod} \ M)) \ \text{mod} \ M" /></a>

위의 분배 법칙에 따라 모듈로 연산을 적용해서 factorial 함수를 수정하였다. 

큰 수에 맞게 자료형도 모두 long long으로 바꾸었다.

```c++
#define D 1000000007
typedef long long ll;

ll Answer, Max;
ll memo[2000004];

ll factorial(int n)
{
    ll result = 1;
    
    if (Max == 0)
        memo[0] = 1;

    for (int i = Max + 1; i <= n; i++)
        memo[i] = ((i % D) * memo[i - 1]) % D;

    if (Max < n)
      Max = n;

    return memo[n];
}
```
### Exponentiation by squaring

아직 문제는 남아있다. 조합을 
<a href="https://www.codecogs.com/eqnedit.php?latex={_nC_k}=\frac{n!}{k!(n-k)!}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?{_nC_k}=\frac{n!}{k!(n-k)!}" title="{_nC_k}=\frac{n!}{k!(n-k)!}" /></a>
로 구하기 때문에 나눗셈에 대해서 모듈로 연산을 해야한다.

이때 나눗셈의 모듈로 연산은 

<a href="https://www.codecogs.com/eqnedit.php?latex=(a&space;\div&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b^{M-2}&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" target="_blank"><img src="https://latex.codecogs.com/gif.latex?(a&space;\div&space;b)&space;\&space;\text{mod}&space;\&space;M&space;=&space;((a&space;\&space;\text{mod}&space;\&space;M)&space;\times&space;(b^{M-2}&space;\&space;\text{mod}&space;\&space;M))&space;\&space;\text{mod}&space;\&space;M" title="(a \div b) \ \text{mod} \ M = ((a \ \text{mod} \ M) \times (b^{M-2} \ \text{mod} \ M)) \ \text{mod} \ M" /></a>

와 같기 때문에, 분모의 (M-2) 제곱을 계산해야한다. 

문제는 주어진 M이 1,000,000,007로 매우 크다는 것이다.

따라서 
<a href="https://www.codecogs.com/eqnedit.php?latex=b^{M-2}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?b^{M-2}" title="b^{M-2}" /></a>
의 연산 횟수를 줄이기 위해서 이산 수학에서 배운 Exponentiation by squaring을 활용해야한다.

```c++
ll fast_power(ll base, ll power)
{
    ll result = 1;
    while (power > 0)
    {
        if (power & 1) // power % 2 == 1
        {
            result = (result * base) % D;
        }
        base = (base * base) % D;
        power >>= 1;   // power /= 2;
    }
    return result;
}

ll combination(int n, int k)
{
  ll numerator, denominator, result;

  numerator = factorial(n);
  denominator = (factorial(k) * factorial(n - k)) % D;
  result = (numerator * fast_power(denominator, D - 2)) % D;

  return result;
}
```


