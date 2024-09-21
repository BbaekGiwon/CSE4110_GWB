2024/03/11

## <p.3>

Instructor 저장 - 관계형 DB (table 형태 - column=attributes) 

column 저장할때 data type 정해줘야함

tuple = row

## <p.4>

A_1, ... A_n : Attribute

R = relation schema

r(R) - 행들의 집합?

t = tuple = row

## <p.5>

### 속성

* domain = 속성 - 대충 규칙 - datatype
* atomic: 정보는 세부정보로 쪼갤 수 없어야 함 (교과목id - 어느학과 유추 ㅇㅇ -> 근데 여기서 추가적인 정보를 끄집어 내는데 활용 X)
* null: 뭔 datatype이든 들어올 수 있음, 대충 모를때 쓰면 됨

## <p.6>

tuple은 order X

## <p.7>

Database schema: 규칙

Database instance: 그 순간의 tuple 상태, 값

## <p.8>

### Keys - 중요함

[[R > k > candidate key > primary key]]

K: R(속성의 집합)의 부분집합

K: superkey(tuple을 unique하게 식별) - 예시상에서 ID가 해당, {ID, name} 이렇게 페어도 가능

candidate key: superkey K중에서 최소 원소 - ID만 해당

primary key: 이게 정의되면 모든 tuple을 unique하게 식별

foreign key: 데이터 입력시 reference 되는 primary key를 가지고 어쩌고, primary key 수출하는 얘, reference 할때,  항상 확인해서 규칙 유지

foreign이 아닌데 값 확인하고 싶으면 refernetial integrity constraint 사용 - 근데 비효율적 - 왠만하면 안함

## <p.9>

대충 밑줄친거 다 있어야 식별 가능 - primary key

course - dept_name은 department에 존재해야함

advisor: s_id가 primary이므로 1인 1advisor, foreign key: s_id(student), i_id(instructor)

takes: foreign key 5개

teaches: foreign key 5개

section: time_slot_id - foreign 아님 - reference 한 곳에서 primary 아님





2024/03/13

## <p.9>

takes - 5개 다 모여야 primary

teaches - 5개 다 모여야 primary, 4개의 속성이 모여서 section refrence -> 4개가 모여서 foreign key

prereq - 2개 모여서 primary, course_id - foreign, 각각 foreign

advisor: 2개 모여서 primary, foreign key 2개, 



foreign 일라면 reference 하는 곳에서 primary가 되야함

foreign key constraints: 없는거 입력할라면 막는거



section - time_slot_id - reference 한 곳에서 primary 아님 -> foreign 아님

-> reference constraints(화살표 두개따리)로 확인 가능 -> 근데 잘 안함

section - building + room_number 모여서 foreign key임

## <p.10>

### Relational Query Languages

* Procedural : How 까지 / Non-Procedural  / declarative

Relational algebra : SQL 기반임, universal 하지 않음, 제약 O, Operation 6개 - Turing-machine X(대충 코딩 안됨)

Tuple relational calculus : 대충 안배움

Domain relational calculus : 대충 안배움

근데 세개다 원리는 같음

## <p.12>

### Selcet

6개 operation & predicates(and, or, not) - 예시만 한 번 보기

## <p.14>

### Project

속성 몇개 선택

primary key 선택 안함 -> 중복 발생 가능 -> 그럼 중복 제거

## <p.16>

대충 operation 섞어 쓸 수 있음

operation의 결과물은 임시 테이블(이름 사용자는 모름/DB 엔진은 앎) -> "Einstein", "Gold" 출력

## <p.17>

두 개 relation combine

합칠때 속성 이름 중복 되면 앞에 뭐 붙임

## <p.19>

### Join

Cartesian-Product

180 -> 12 (의미있는 거) - select를 이용해서 의미 있는 것만 도출

theta: join과 select를 섞어서 의미있는 거만 곱한거에서 선택하는 것

## <p.22>

### Union

합집합임 걍

합칠때 사용

조건: r,s 속성 개수 동일(arity), 데이터 타입 동일(compatible)

## <p.24>

### Set-Intersection

교집합임 걍

조건: r,s 속성 개수 동일(arity), 데이터 타입 동일(compatible)

## <p.25>

### Set-Difference

차집합임 걍

조건: r,s 속성 개수 동일(arity), 데이터 타입 동일(compatible)

## <p.26>

### The Assignment

변수에 Assign(table assign이 아닌 그냥 operation 저장)

대충 편하대

## <p.27>

### The Rename

access 할 수 있는 다른 이름 설정?

table의 이름/ 속성의 이름

새로운 table 만드는 거 아님

ex) instructor -> w로 rename -> table w의 id 12121 select -> instructor table을 i로 rename -> X 계산 해서 합침 -> w salary보다 큰거 고름 -> 그중 ID, name만 출력

## <p.28>

query 1이 빠름 -> 1번만 훑어도 돼서

2는 2번 훑어야 함

## <p.29>

instructor, teaches table 결합 필요 -> cartesion product

query1: id 같은애들 합치기 - 180개

query2:  30개 -> id 같은지 확인 

-> query 2 효율적 - cartesian product 해야되는게 적다
