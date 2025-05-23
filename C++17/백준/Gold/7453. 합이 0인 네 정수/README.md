# [Gold II] 합이 0인 네 정수 - 7453 

[문제 링크](https://www.acmicpc.net/problem/7453) 

### 성능 요약

메모리: 330088 KB, 시간: 10312 ms

### 분류

정렬, 이분 탐색, 두 포인터, 중간에서 만나기

### 제출 일자

2025년 5월 23일 12:13:47

# 📝 문제 소개

## 문제

---

정수로 이루어진 크기가 같은 배열 A, B, C, D가 있다.

A[a], B[b], C[c], D[d]의 합이 0인 (a, b, c, d) 쌍의 개수를 구하는 프로그램을 작성하시오.

## 입력

---

첫째 줄에 배열의 크기 n (1 ≤ n ≤ 4000)이 주어진다. 다음 n개 줄에는 A, B, C, D에 포함되는 정수가 공백으로 구분되어져서 주어진다. 배열에 들어있는 정수의 절댓값은 최대 2**²⁸**이다.

## 출력

---

합이 0이 되는 쌍의 개수를 출력한다.

## 제한

---

# 🧩 풀이

이 문제는 **브루트포스로 네 수를 모두 탐색**하면 O(N⁴)의 시간복잡도로 시간 초과가 발생한다.

따라서 다음과 같이 두 배열(A와 B, C와 D)의 합들을 미리 계산하여 벡터에 저장하는 방법으로 최적화할 수 있다.

1. A와 B에서 하나씩 선택해 만들 수 있는 모든 합을 `v1`에 저장한다.
2. C와 D에서 하나씩 선택해 만들 수 있는 모든 합을 `v2`에 저장한다.
3. `v2`를 **정렬**한 뒤, `v1`의 각 원소에 대해 `v1[i]`가 v2에 **몇 번 등장하는지** `lower_bound`, `upper_bound`를 사용하여 개수를 구한다.

**시간 복잡도: O(N² log N) →** N ≤ 4000이므로 제한 시간 내 해결 가능
