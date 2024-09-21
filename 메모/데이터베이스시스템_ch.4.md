# ch.4

2024/04/08

## p.3

### join 

cost가 크다

## p.4

### Natural join

a, b join할때 같은 속성만 join

## p.9

natural join을 두번하면 같이 있는 속성의 개수가 한개 보다 많아짐 -> student dept_name과 course dept_name이 같은 경우만 join하게 된다.

## p.10

using을 사용하면 속성을 제한 -> 문제해결

## p.12

### on

where과 유사

## p.13

### Outer join

뭐가 매치가 안됐는지 확인

left는 왼쪽에서 뭐가 안됐는지, right는 오른쪽

## p.15

left outer join -> 왼쪽 row 중 오른쪽에 없으면 join한 오른쪽 속성은 null 넣음

## p.20

공통된게 나오고 안나오고 하는데 차이가 무엇인지? / 열 5 vs 6 개







2024/04/15

## p.22

### View

다 보여줘서 좋을건 없다.

특정 데이터를 감춘 가상의 테이블 -> 접근 끝나면 사라짐

DB에는 expression만 저장

## p.24

view를 만들어 놓으면 select from 할때 만들어 놓은 view가 들어감

## p.25

ex) v1 -> v2 -> v3

depend directly: 바로 연결 ex) {v1, v2}

depend: 건너뛰어서 연결, view만들때 view불러와서 하는거 ex) {v1, v3}

## p.27

expansion

## p.28

view실행하는 것도 cost임, 여려개의 view가 동시에 실행되면 overload -> 그래서 그냥 table로 저장해버림 = materialized view

-> 추가 저장공간 필요

-> 업데이트할때마다 저장한것도 업데이트 필요

## p.30

view에다가 뭘 집어넣은다는 거는 원래 table에 넣는것 -> 근데 넣을라고 보니까 salary 값은 없네? -> 1) 이런거 다 불가능 2) 없는 것은 NULL로

## p.31

view에 새로운 tuple insert -> dept_name, salary, budget 모름 -> 근데 department table의 primary key인 dept_name이 없음 -> 이런거는 안됨 + not null 걸어놓아도 안됨

## p.32

고로 simple view(하나의 realtion)만 update 허용

aggregate, distinct 이런거 안됨 -> 관여하는 tuple 개수가 복수 -> update 문제 발생 가능성

대충 다 null 때릴수 있어야 update 가능

## p.33

select *한거에다가 insert -> 근데 where 조건에 안맞는 것을 넣네? -> 그래도 가능함 -> check option 사용하면 reject 가능

## p.34

검색, update 묶어서 transaction?

sequence 앞과 끝에 inplicit한거 넣는다는데

Commit work: transaction 100 %성공

Rollback work: 아에 복구 = 실행X

내 transaction 동안 동시에 실행되는 transaction과 무상관

## p.35

## p.38

unique 하면 null 가능 <-> primary key

## p.39

check(semester in ) : semester에 지정된 값만 가능

## p.40

-읽

참조 무결성

foreign key constraint는 referential integerity의 special case

referen

공통된 속성인데 이게 primary key면 딴 table의 foreign

## p.42

referentail integrity 위반 -> 

dept_name이 foreign key 역할 -> 없는 학과 이름 가진 tuple -> 삽입 ㄴㄴ

특정학과 삭제 -> dept table은 reference 되고 있다. -> foreign constraint 위배 ->

on delete cascade -> dept에서 학과 삭제할때 그 삭제한 학과가 들어있는 tuple 다 삭제

on update cascade -> dept에서 학과 이름 바꿈 -> 해당 업데이트 일괄 실행

대부분 foreign constraint만 확인, referentail 은 안함

set null, set default: 해당하는 것으로 바꿔주는거

## p.43

자기자신을 참조중

특정사람 삽입 -> 아빠 엄마에 해당하는 사람이 없는 경우 -> foreign key 위배 -> 1) 엄빠 선입력 2) 우선 NULL 3) 문제해결까지 연기

## p.44

-읽

## p.45

총 수강학점 = 계산해본거

-읽

## p.47

large object: 사진 동영상 등

blob: 해석이 안됨

clob: character 집합

이런거 return 할때는 주소값을 넘겨줌

## p.49

domain은 user-defined type과 다르게 check 와 같은 제약조건 붙일 수 있다.

## p.50

### Index

검색 - 특정 속성 가진 몇개만 

relation = 집합 -> 정렬 안되어있음 -> 검색할라면 다 찾아봐야함 -> tuple 많은 경우 오래 걸림 -> 효과적이지 않으므로 index라는 추가 속성 제공 = binary serach tree, O(log_2 n) -> 빠르다!

->근데 유지보수 해줘야함 (update)

-> 공간도 차지

## p.51

예시





2024/04/17

## p.52

권한을 줄 수 있다.

권한 줄때는 grant 사용

## p.55

grant all: 다 주기

## p.56

revoke: 권한 뺏기

revoke all: 다 뺏기

public이면 줄줄이 소세지로 뺏김, 따로 explicitly하게 받은 애는 제외

다른 애한데 두번 grant 받으면 revoke 해도 권한 남아있다.

dependt하면 세트로 revoke됨

## p.57

role: 유저의 그룹 

create role <역할>

grant <.role> to <.user>

user에게 역할 부여

## p.60

ferrence -> foreign key 할때

왜 default는 안되는가? -> 

삭제하고 싶어도 뭐 경해야 한다는데

-읽

with grant option: 남한데도 줄수 있다.

cascade: 얘가 남한데도 준거 있으면 그거까지 철회

retrict: 둘에게만 한정해서 뺏기



