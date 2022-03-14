# 요구사항 분석
## ex00

### 요구사항
주어진 예시를 보고 동일하게 작동하는 프로그램을 작성하라.

### 해석
- 명령줄로 전해진 모든 인수를 영어 대문자로 변환하여 출력하는 프로그램을 작성하라.
- 공백은 유지된다.

### 구현
인자가 없는 경우, 즉 argc == 1 이라면 정해진 출력을.
있다면 대문자로 변환하여 출력한다.

### 테스트 케이스
1. 인자가 없는 경우
2. 인자가 하나만 주어진 경우
3. 인자가 여러 개 주어진 경우

## ex01
### 요구사항
주어진 예시를 보고 프로그램을 전화번호부 프로그램을 작성하라.
- 프로그램이 지원하는 연산: ADD, SEARCH, EXIT
- 전화번호는 프로그램이 시작될 때 비어있는 상태
- 동적할당을 사용하면 안되고, 8개까지 저장할 수 있다.
- 가득찬 경우 9번째는 가장 먼저 추가된 전화번호부를 덮어쓴다.

### 해석
### 문자열 배열
선언과 동시에 초기화 한다.

### 명령어 ADD
저장한 번호를 지우는 명령을 구현할 필요가 없어서 ADD는 인덱스를 정적변수로
하면 될 것 같다.
- idx = (idx + 1) % 8;

### 명령어 SEARCH
저장된 길이만큼 순회한다. 없으면 못찾았다고 에러 메시지
-  index, first name, last name and nickname.
### 명령어 EXIT
프로그램을 종료한다.
- string으로 선언된 객체는 .clear를 호출하지 않으면 누수가 검출될까.

### 지정되지 않은 명령어
지정하지 않은 명령어라면 무시한다. 공백... 처리할까?

### 구현
- START
- CMD: EXIT
- CMD: ADD
- CMD: SEARCH
- ELSE

폰북에 대한 연산...
연락처 하나에 대한 연산.?

The PhoneBook must be represented as as an instance of a class in your code
it must contain an array of contact.

아무런 입력이 없다면 NULL로 표기하자.

### 참고자료
- https://www.learncpp.com/cpp-tutorial/an-introduction-to-stdstring/
- 

## ex02