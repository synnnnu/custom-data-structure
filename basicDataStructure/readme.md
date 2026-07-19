# Custom Data Structures (C++)

임베디드/시스템 개발 관점에서 표준 자료구조를 직접 구현해보는 프로젝트입니다.

동적 할당 컨테이너 대신 고정 크기 정적 배열 기반으로 구현하는 것을 목표로 합니다.

<br>

## 진행 로드맵

- [x] Stack

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
