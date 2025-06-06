# [Gold III] 소수의 연속합 - 1644 

[문제 링크](https://www.acmicpc.net/problem/1644) 

### 성능 요약

메모리: 5712 KB, 시간: 28 ms

### 분류

수학, 정수론, 두 포인터, 소수 판정, 에라토스테네스의 체

### 제출 일자

2025년 5월 28일 12:25:50

### 문제 설명

<p>하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.</p>

<ul>
	<li>3 : 3 (한 가지)</li>
	<li>41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)</li>
	<li>53 : 5+7+11+13+17 = 53 (두 가지)</li>
</ul>

<p>하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.</p>

<p>자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)</p>

### 출력 

 <p>첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.</p>

# 💡 문제 접근

이 문제는 다음 두 가지 핵심 아이디어가 필요합니다:

1. **N 이하의 모든 소수를 빠르게 구해야 하며**,
2. **그 소수들 중 연속된 부분합이 N이 되는 경우의 수를 찾아야 합니다.**

모든 구간을 하나하나 탐색하는 **브루트포스 방식은 비효율적**이므로,

이를 해결하기 위해 **투 포인터(two-pointer) 알고리즘**을 활용합니다.

---

# 🧩 풀이 방식

### ✅ 1. 소수 구하기: 에라토스테네스의 체

- N 이하의 소수를 빠르게 구하는 방법으로 가장 널리 쓰이는 방법입니다.
- 시간복잡도는 `O(N log log N)`이며, `bool` 배열을 이용해 소수를 선별합니다.

### ✅ 2. 연속된 소수의 합 찾기: 투 포인터

- 구한 소수들을 배열에 저장한 후,
    
    투 포인터(`st`, `en`)를 사용하여 연속된 구간의 합을 탐색합니다.
    
- 현재 구간의 합이 N보다 작으면 `en`를 늘리고, 크면 `st`를 옮깁니다.
- 합이 N과 같을 때마다 카운트를 증가시킵니다.

---

# 🧠 시간 복잡도

| 단계 | 설명 | 시간복잡도 |
| --- | --- | --- |
| 소수 구하기 | 에라토스테네스의 체 | `O(N log log N)` |
| 연속합 찾기 | 투 포인터 | `O(N)` |
| 전체 | 두 과정의 합 | `O(N)` |
