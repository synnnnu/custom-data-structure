# Custom Data Structures (C++)

임베디드/시스템 개발 관점에서 표준 자료구조를 직접 구현해보는 프로젝트입니다.

동적 할당 컨테이너 대신 고정 크기 정적 배열 기반으로 구현하는 것을 목표로 합니다.

<br>

## 진행 로드맵

- [x] Stack
- [x] Queue
- [x] Circular Queue

<br>

## Stack

### 개요

`template <typename T, int N = 100>` 기반의 LIFO 스택

임의의 타입(int, std::string, 커스텀 구조체 등) 지원

<br>

### 인터페이스

| 함수    | 시그니처                    | 설명                                                        |
| ------- | --------------------------- | ----------------------------------------------------------- |
| 생성자  | `Stack()`                   | 인자 없음, 크기는 템플릿 파라미터 `N`으로 결정              |
| push    | `bool push(const T& value)` | 성공 시 `true`, 가득 찼으면 `false`                         |
| pop     | `bool pop()`                | 제거만 수행 (값은 반환하지 않음), 비어있으면 `false`        |
| peek    | `bool peek(T& outValue)`    | 성공 시 `outValue`에 값을 채우고 `true`, 비어있으면 `false` |
| isEmpty | `bool isEmpty()`            | 비어있는지 여부                                             |
| isFull  | `bool isFull()`             | 가득 찼는지 여부 (`count == N`)                             |
| size    | `int size()`                | 현재 저장된 원소 개수                                       |

<br>

### 사용 예시

```cpp
Stack<int> s1;           // 타입 int, 크기는 기본값 100
Stack<int, 5> s2;        // 타입 int, 크기 5
Stack<std::string, 20> s3;  // 타입 string, 크기 20
```

<br>

## Queue

### 개요

`template <typename T, int N = 100>` 기반의 FIFO 큐

Stack과 동일하게 힙 할당 없이 정적 배열(`T arr[N]`)만 사용

`front`는 항상 배열의 0번 인덱스에 고정되도록 설계했으며 `dequeue` 시 남은 원소를 한 칸씩 앞으로 당기는 방식으로 동작

<br>

### 인터페이스

| 함수      | 시그니처                       | 설명                                                        |
| --------- | ------------------------------ | ----------------------------------------------------------- |
| 생성자    | `Queue()`                      | 인자 없음, 크기는 템플릿 파라미터 `N`으로 결정              |
| enqueue   | `bool enqueue(const T& value)` | 뒤에 추가, 성공 시 `true`, 가득 찼으면 `false`              |
| dequeue   | `bool dequeue()`               | 앞에서 제거만 수행 (값은 반환하지 않음), 비어있으면 `false` |
| peekFront | `bool peekFront(T& outValue)`  | 성공 시 `outValue`에 맨 앞 값을 채우고 `true`               |
| isEmpty   | `bool isEmpty()`               | 비어있는지 여부                                             |
| isFull    | `bool isFull()`                | 가득 찼는지 여부 (`count == N`)                             |
| size      | `int size()`                   | 현재 저장된 원소 개수                                       |

<br>

### 사용 예시

```cpp
Queue<int> q1;              // 타입 int, 크기는 기본값 100
Queue<int, 5> q2;            // 타입 int, 크기 5
Queue<std::string, 20> q3;   // 타입 string, 크기 20
```

<br>

## Circular Queue

### 개요

`template <typename T, int N = 100>` 기반의 FIFO 큐.

인터페이스는 Queue와 동일하지만, 내부적으로 `frontIdx`/`rearIdx`를 `% N` 연산으로 순환시켜 앞쪽 빈 공간을 재활용

Queue는 `dequeue`마다 남은 원소를 전부 앞으로 당겨야 해서 O(n)인 반면, Circular Queue는 인덱스 계산만으로 처리되어 `dequeue`가 O(1)

<br>

### 인터페이스

| 함수      | 시그니처                       | 설명                                                                       |
| --------- | ------------------------------ | -------------------------------------------------------------------------- |
| 생성자    | `CircularQueue()`              | 인자 없음, 크기는 템플릿 파라미터 `N`으로 결정                             |
| enqueue   | `bool enqueue(const T& value)` | `rearIdx` 위치에 저장 후 `(rearIdx + 1) % N`으로 이동, 가득 찼으면 `false` |
| dequeue   | `bool dequeue()`               | `frontIdx`를 `(frontIdx + 1) % N`으로 이동, 비어있으면 `false`             |
| peekFront | `bool peekFront(T& outValue)`  | 성공 시 `outValue`에 `arr[frontIdx]` 값을 채우고 `true`                    |
| isEmpty   | `bool isEmpty()`               | 비어있는지 여부                                                            |
| isFull    | `bool isFull()`                | 가득 찼는지 여부 (`count == N`, `rearIdx == N`이 아님에 주의)              |
| size      | `int size()`                   | 현재 저장된 원소 개수                                                      |

<br>

### 사용 예시

```cpp
CircularQueue<int> cq1;              // 타입 int, 크기는 기본값 100
CircularQueue<int, 5> cq2;            // 타입 int, 크기 5
CircularQueue<std::string, 20> cq3;   // 타입 string, 크기 20
```
