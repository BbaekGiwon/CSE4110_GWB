# ch.3

2024/04/01

## p.3

메모리 비쌈 -> 비용 최소화 필요 -> 년도 4자리 안쓰고 2자리썼다는데

## p.4

DML: 데이터 조작 언어 - 정보검색 , 수정, 추가 등(INSERT, SELECT, UPDATE, DELETE)

DDL: 스키마 조작 언어 - 무결성 유지 확인?, view definition, (CREATE, ALTER, DROP, TRUNCATE)

integrity: 무결성 - 도메인무결성, 엔터티 무결성, 참조 무결성(foreign key)

primary key - 중복X, NULL X 

view 복습 필요할듯?

읽어보자

## p.5

## DDL

table tuple 정렬X -> 찾을때 index없으면 힘듦 -> index추가 (cost필요) ex) binary search tree (O(n)=logn)

## p.6

* char(n): 모든 글자가 n으로 고정
* varchar(n): n이하의 글자
* int
* smallint
* numeric: 고정 실수
* real, double, precision

## p.7

create table: 새로 table 만들기

attribute의 data type 정하기

## p.8

integrity constraints(primary key, foreign key, not null) 등을 고려해서 만들자

## p.11

insert: tuple을 집어넣을때

delete: tuple 삭제

drop table: 테이블 자체 삭제

alter: 속성 변경(column 추가, 삭제) -> 추가시 공란 NULL -> NULL 싫으니까 왠만하면 쓰지마라 -> 그래도 추가는 허용해줌 -> But, column삭제는 허용 안함 -> 삭제는 존나 위험(view 정의 망함)



embeded sql -> db 호출 -> insert 반복 -> 이러면 다수 튜플 삽입 용이

## p.12

select := relation algebra projection

## p.13

### Select

대소문자 구분 X

중복허용

## p.14

select distinct -> unique 한것만

select all -> 걍 

## p.15

select '437' 437가진 row 찾기

as는 이름 설정

from은 table

## p.16

operation 사용가능 - 사칙연산, 함수 등

## p.17

### Where

where: 조건

논리 연산자 사용가능 - and, or 등

관계연산자 - 크거나 작은거(<,>)

예시 확인

## p.18

### From

from: cartesian product과 같다.

```sql
select *
from instructor, teaches 
```

하면 둘의 곱한것과 같다.

-> 곱하면 오래 걸리니까 필요한것만 넣자

-> attribute 구분안되면 relation name을 앞에 넣어주자. ex) instructor.ID

## p.19

instructor, teaches에 있는 name, course_id에서 instructor.ID=teaches.ID인거

join : from, where 섞은거 -> 위에 join과 유사함

아래의 경우 and 뒤에꺼 덕분에 더 크기 작아짐

## p.20

### rename

rename: as와 같다.

as T, as S -> T,S 로도 접근 가능

끝나고나면 instructor만 남는데

## p.21

### Self join

self join: 자기자신과join -> 계층적 데이터 등에서 유리

s.supervisor = t.person -> supervisor의 supervisor를 구하려면 2개 self join 필요

-> @의 @의 @는 3개 ㅇㅇ

원래 지원잘 안함

## p.22

### like

%: any substring

_: any character _dar = adar, bdar, cdar ... 대충 뭐든 들어와도 오케이

\쓰면 character

|| 문자열 이어붙이

## p.23

읽어보자

## p.24

### order by

order by -> deafulat asc

order by desc -> 내림차순

order by dept_name, name -> 1순위 dept_name, 2순위 name

## p.25

### between

between : 대충 범위 설정가능 





2024/04/03

## p.26

### set

union, intersect, except -> 중복X

## p.27

all 사용하면 중복허용

## p.28

### Null

is null, is not null

null을 비교연산하면 null 나옴

null 관계연산하면 true와 false사이 어딘가쯤 있다고 생각하면 됨

## p.30

aggregate: 계산해서 single value return

## p.31

distinct -> 중복 제거

(*) -> 전체 선택

## p.32

### group by

세부 그룹으로 나누기(속성에 따라)

## p.33

select선택한거는 group by에 있어야 한다. -> 아니면 오류남

->chat gpt 함 돌려보자

## p.34

having -> 그룹이 형성된 후

where -> 그룹이 형성되기 전

ID가 select에도 있으면 평균값은 하난데 ID가 여러개 나와버린다 <- group by에 ID를 추가해주면 가능

## p.35

### Nested Subqueires

subquery도 selcet-from-where 형식

sub은 select, from, where 어디든 들어갈 수 있다.

결과로서 나오는 테이블은 시스템만 알지 우리는 이름 모름

Ai - sigle value로만 대체 가능

## p.37

sub: 2018년도의 course_id로 구성된 테이블 생성 ->결과적으로 2017, 2018 둘다

in, not in -> set과 같은 역할을 하기 위해서는 distinct가 필수이다.

## p.38

instructor id = 10101 -> 강의 한거 다 가져옴 -> 가져온거랑 일치하는 수업들은 학생수 세기

## p.40

### some

some: 한명보다라도 내가 월급을 많이 받으면 출력 -> set comparison

instructor product해줌 -> biology랑 모두 비교해서 높기만 하면 출력 -> 중복제거

some이 효율적임(하나만 찾으면 돼서 굳이 다 안 찾아봄) -> sql에서는 cartesian product 피해야함(일일이 다돌리기 때문)

## p.42

some: 하나라도 존재하면 참

in과 같다

!some != not in ->둘은 다르다

## p.43

### all

모두 만족시켜야 함

## p.45

exists: nonempty인지 확인

## p.46

correlation: sub과 연결된 outer table

course id당 T를 한번씩 다 훑는다

for() {

​	for() {

​		if() 과 유사함

## p.47

biology에 해당하는 course - takes에서 s_id=t_id

(biology 모든 과목) - (모든 학생이 수강한 과목정보 중에서 선택한 학생이 들은 과목)

-> 이걸 not exist하므로 모든 biology 과목을 다 들은 학생이면 true







2024/04/08

## p.48

unique: 중복제거

## p.50

from을 쓰면 having 대체 가능 -> 근데 having이 직관적임

## p.51

with: 임시 table 생성

## p.52

대충 두개의 table에서 정보 끌어오기

with 쓰면 중간단계의 table 가져와서 한줄에 쓸 수 있음

## p.53

select에 오는 subquery -> single value = scalar

조건 만족 instructor 숫자 세서 num_instructor에 저장

만약 select에 값 두개짜리가 오면 run time error

## p.55

### Delete

delete from -> 모두 삭제

delete from

where -> 조건만족 삭제

delete from

where	in(빌딩이름 watson인 학과)



drop 할때 굳이 delete 안해도 됨

## p.56

평균미만이 salary instructor 삭제

avg 값을 고정 후 삭제 -> 매번 계산한다면 삭제할때마다 avg 값 변함

## p.57

### Insertion

속성이름을 명시할 수도 있다.

Null 값 넣어도 됨

## p.58

음대 & 144 학점 이상 -> instructor table 삽입 (연봉 18000)

```sql
insert into table 1 select * from table1 #무한 루프 돌아버림
# select from where 하고 insert 하자
```

## p.59

### Update

값을 수정

update 뒤에 table 나옴

## p.60

where salary <= 가 위로가면 where salary >에도 해당하는 중복 케이스 발생할 수도

## p.61

### case

이거 사용하면 순서 상관 없음

## p.62

현재수강중이면 take.grade = Null

신입생은 tot_cred = 0

