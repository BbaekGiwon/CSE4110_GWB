# ch.6



2024/03/18

## <p.4>

Initial phase: 사용자 요구사항 -

Second phase: (수업에선) E-R모델로 구현

## <p.5>

Bus~ & computer ~ 잘못들어간 거라고함

Final Phase: design 단계

## <p.6>

두가지 실수를 피해야함

* Redundancy: 정보 중복 -> 일관성 파괴
  * ex) takes(ID, cousrse_id, sec_id, semester, year, grade) & course(cousrse_id, title, dept_name, cedit) 
  * TakesCourse(ID, course_id, title, dept_name, cedit, sec_id, semester, year, grade)
  * 위가 아닌 아래와 같이 두개를 하나로 합치면 불필요한 정보 계속 반복, 과목명을 바꾸고 싶을때 -> update해야하는게 학생수만큼 -> 만약 몇개 까먹고 안바꾸면 data inconsistency
  * 위와 같이 두개로 구성했을 때, 과목명 update할 때 course table가서 하나의 튜플만 수정하면 됨.
  * 아래것도 장점이 있긴함 ㅇㅇ <- join 연산 안해도 됨
* Incompleteness: 특정 정보 모델화 안되게 하는 것
  * ex)새로운 과목 개설시 TakeCourse table에 관련 정보를 넣을 때 <- 듣는 학생이 없음 <- primary key인 ID가 Null이 되면 안됨 <- 새로운 과목 못 넣음

## <p.7>

ER 모델 = entity + relationship

entity: set of attributes

relationship: associations

Entity-relationship diagram 표현가능

## <p.9>

### ER model

컨셉 세개

* entity set<- 학생(entity) 모아놓은거
* relationship set <- 관계 다 모아놓은거
* attribute <- 속성

## <p.10>

entity: 구분가능한 objects

entity set: 같은 유형을 모아놓은거

속성의 set으로 나타냄

primar key는 attribute set의 subset

## <p.12>

Diagram은 직사각형으로, 안에는 속성

직사각형 하나가 entity set

## <p.13>

### Relationship Sets

adviosr <- relationship

entity의 pair로 나타낸다.

## <p.15>

마름모는 relationsihp

## <p.16>

속성 추가도 가능 (여러개 가능)

advisor 시작한 날짜 추가 <p.17>

## <p.18>

### Role

entity set이 distinct할 필요는 없다. 롤 여러개 가능

## <p.19>

관계가 entity 여러개 - non-binary

교수-학생-프로젝트

## <p.21>

속성의 타입 세분화?

* simple: 
* composite: 여러개의 세부속성으로 분리 가능, 분리한걸 또 세부속성으로 분리가능 (제한 X)

* sigle-valued
* multi-valued: 핸드폰이 두개면 번호 두개니깐
* derived: 계산돼서 값이 나오는 속성

Domain: 속성의 허용된 값들의 집합

관계형이랑 조금 달라서 composite, multi 허용, atomic 깨져도 OK! -> 이러면 파악용이

## <p.23>

<u>ID</u>: primary

name: composite

address: composite

{phone_number}: multi-valued 

age(): derived

## <p.24>

관계의 cardinality

binary 관계를 4개로 구분 가능

* One to one: entity끼리 하나씩 <- 교수당 학생 1명씩 지도
* One to many: <- 한 교수가 여러명 지도 가능, but 학생은 1명의 교수한테만 지도 받는거 가능
* Many to one: <- 학생 한 명에 교수 여려명, 교수는 한 학생만
* Many to many: <- 대충 알아서 ㅇㅇ

## <p.27>

-> : one

ㅡ: many

## <p.31>

= : total participation





2024/03/20

## <p.32>

l~h 사이의 값

instructor: 0~*명의 학생담당

student: 무조건 1명의 교수랑만

instructor <ㅡ advisor = student (one to many)

## <p.33>

Ternary Relationship: 세개의 엔터티간의 관계

대부분 한개의 화살표가 cardinality constraints를 나타내도록 함

예를들면 "proj_guide -> instructor" : 학생이 대부분 guide 하나씩은 받겠다

화살표가 한개보다 많으면 (B, C가 화살표라고 가)

1. A가 B와 C에 unique하게 연관
2. (A, B)가 C와 (A,C)가 B와 unique하게 연관

즉 화살표가 두개 이상이면 혼란을 야기하기에 잘 안

## <p.34>

primary key: unique하게 entity & relations 식별하는 방법 제시

## <p.35>

primary 속성이 다르면 다른 entity

entity끼리 attribute가 정확히 일치하면 안됨

## <p.36>

relation 의 속성: entity의 primary key + relation의 속성

entity의 primary key의 set은 R의 superkey

어떤거를 속성을 제거해야 unique? -> instrucstor 없어도 학생id unique함 -> instructor 속성은 extra, 

따라서 relationship의 primary key는 mapping cardinarity에 종속적이다.

## <p.37>

many to many: unique할라면 양쪽의 primary를 둘 다 써야한다.

one to many & many to one: many side에 있는 primary만 필요.

one to one: 둘 중 무엇이든지 하나만

## <p.38>

weak entity sets

[section] ㅡ <sec_course> ㅡ [course]

<u>course_id</u>                                  <u>course_id</u>

<u>section_id</u>

<u>year</u>

<u>semester</u>

sec_course에서 양쪽 course_id 중복 -> 

## <p.39>

section - course_id 삭제 -> course_id 필요

section은  course에 dependent

sec_course의 속성은 course_id + section의 primary 세개

section은 course_id 없이는 unique하지 않으므로 존재 자체가 course에 dependent 하다.

## <p.40>

section=weak entity set <-> course=strong entity set

weak entity set이 껴있는 relationship은 **identifying relation**이라고 함

## <p.41>

weak connect은 더블 다이아

section이 total이여야 한데(두줄) <- 종속적이라서 그런듯

## <p.42>

student - ID(primary)

department - dept_name(primary)

중복되니깐 student의 dept_name 삭제

## <p.43>

many side = primary

many to many는 테이블

entity set  도 테이블로 만들기

이제는 이거를 어떻게 관계형 모델로 바꾸나





2024/03/25

## <p.43>

relationship set - 테이블이 되는게 있고 안되는게 있음

many to many는 테이블로 바꾸자

뭐가 안되는 거더라

## <p.45>

읽어보자

## <p.46>

relation schema(course): <u>course_id</u>, title, credits

relation schema(section): <u>course_id</u>, <u>sec_id</u> ,<u>sem</u>, <u>year</u> <- course_id 추가함(weak하기 때문) <-만약에 course의 primary가 두개였음 둘다 가져오래

왠진모르지만 별도의 sec_cousre schema(관계의 스키마) 안만듦?

## <p.47>

first_name, street(세부속성)은 unique(모호성이 없을때)하므로 prefix 생략이 가능하다

multi, derive는 schema 묶음으로 안만듦, 속성화 안함

## <p.48>

multi는 새로운 schema를 만들어야 한다. -> EM (E: 이름, M: 속성)

instructor primary가 ID 였으므로 inst_phone에 추가

빨간글씨 읽어보기

multi가 time slot에 있음 -> schema 만들어보자 -> time_slot(<u>time_slot_id</u>) <- 나머지는 multi니깐 속성화 안함

-> time_slot_@(<u>time_slot_id</u>, <u>day</u>, <u>start_time</u>, end_time) <-따로 만들어주고 primary인 id 가져오기

## <p.49>

many to many는 걍 schema로 만들자

즉 advisor schema를 별도로 만들자.

또한 id 중복이니까 s_id, I_id로 구분하기

## <p.50>

학생 교수 모두 소속학과가 필요하므로 total임

근데 뭐 advisor는 필수는 아님 ㅇㅇ 그래서 굳이 total X

many side가 total임 그러면 one side의 primary key를 속성에 추가

ex) instructor(<u>ID</u>, name, salary, **dept_name**)

그리고 굳이 inst_dept - many to one(many가 total인 경우) table 안만듦 -> 이미 dept_name 들어가서 대충 설명 됨

advisor는 many to one이나 total은 아니다 -> 대충 학생만 보고도 구분가능(한 학생이 여러 교수 불가능하므로) 즉 primary key는 s_id만으로 충분 -> advisor(<u>s_id</u>, i_id)

만약에 advisor의 many가 total 이였다면 -> student(<u>ID</u>, name, total_credit, **i_id**) <- primary key 추가해줌 

-> 만약에 total이 아니라면 i_id가 NULL이 될 수 있음을 고려

-> i_id는 foreign key임 -> i_id가 NULL이라면 foreign key 규칙 위배 아님

**시험에서는 total아니면 별도의 table 만들어라**

## <p.51>

one to one: 한쪽을 many로 보고 추가 속성 넣기 -> total이 아니기에 넣은것이 NULL이 될 수 있다.

NULL을 피하고 싶다면 관계의 table을 만들면 된다.

## <p.54>

세분화

상위->하위

하위 속성-> 상위에 적용 X

상위의 개념 속성 상속받음

## <p.55>

* overlapping: 중복 가능(employee & student)
* disjoint: 중복 안됨(instructor, secretary)

## <p.56>

중복 저장X

join 해놔야 여러가지 정보를 끌어온다.

Instructor(ID, rank) -> salary알고 싶으면 join 하셈

## <p.57>

상속받는 모든 것을 다 써놓음 - 중복 O -> 따라서 join안해도 걍 알 수 있음

## <p.58>

내려가면 specialization, 올라가면 generalization -> 대충 비슷한거임 그래서

## <p.59>

* total: 무조건 아래에서 찾아볼 수 있음
* partial: 그건 아님







2024/03/27

## <p.60>

partial이 default, total은 화살표 필요

읽어보자

## <p.61>

학생의 평가 관련 entity - eval_for: 4개 참여

proj_guide : 3개 참여

정보 중복 -> project에 참여해야 평가도 내림

## <p.62>

관계와 관계간의 관계 -> ER모델에서는 표시할 수 없음 -> 그래서 entity 싹다 갖다붙임

어차피 중복인거 proj_guide 지우면 안됨? -> ㄴㄴ 모든 proj_guide관계가 eval_for에 포함 된다고 보장 X(평가를 안내리는 프로젝트 같은 경우)

중복해결 -> Aggregation!

관계(proj_guide)를 추상적인 entity로 만들기

## <p.63>

Aggregation - 네모박스 치기

proj_guide에 evaluation 속성을 추가하는 건 어떰? -> 뭐 평가안하면 NULL 생길수도 있긴한데 primary 아니라 노상관 -> 중간, 기말보면 multi 써서 2개 넣으면 됨

-> 그럼 eval_for 왜 씀? -> evaluation이 다른 entity와 관계를 맺을라면 관계의 속성이 아니라 entity여야함

eval_for의 primary key: aggregation의 primary key와 evaluation의 primary key

->4개 각각의 id(primary key) 

->eval_for(s_ID, project_id, i_ID, evaluation_id)

->foreign key: s_ID, project_id, i_ID

최종 schema: 6개 -> aggregation schema까진 만들 필요X

## <p.64>

읽어보자

## <p.66>

one의 primary를 many에 붙여 넣기(dept_name) -> 이거 foreign key인데 뭐 규칙 위배(없는거 있다고 우기는거)는 아니라함

erroneous가 뭐임?

stud_section는 many to many인 관계로 table 만들자. -> primary는 두 entity의 primary key + 두개의 relation 속성

## <p.67>

->근데 assignment 하나밖에 안됨 이러면 -> multi value 속성으로 변경(p.67)

entitiy로 해놓으면 relation 가능

## <p.68>

Instructor 하나로만 -> phone_number 하나만

relation -> phone_number 여러개, 같은 번호 공유 가능 -> 이게 더 많은 정보 수용 -> 근데 instructor 번호 알고싶을 때마다 join해야함

## <p.69>

Entities vs Realtionship set

action? - relationship set으로

​                          data(relationship 속성임)

​                             ㅣ

Instructor <- advisor - student

-> one to many에서 total이 아니기에 table(schema) 만들어줘야함

data를 student 속성으로 편입 가능 - many to many면 어디도 못들감

## <p.70>

binary로 쪼갤 순 있지만 의미가 희석 될수도

binary가 좋을때: ex) 부모자식 관계를 엄마아빠 묶어서 부모로 하면 -> 고아, 편부모 같은 경우에 부모ID가 비어버림 -> binary가 정보 저장이 쉽다.

## <p.71>

relationship set 끼워넣어서 binary로 바꿀 수 있음

## <p.72>

쪼개면

* transalte constraints: 
* 없던 것이 생겨날 수 있다. - one to one으로 하면 된다는 듯?
* 3번째꺼는 삭제

## <p.73>

* attribute & entity 잘표현해라
* action -> relationship set
* ternary vs binary
* strong or weak
* specialization vs generalization
* aggregation

## <p.74~>

뒤에 써머리 읽어보자

## <p.78~>

### UML 

-> 읽어보자
