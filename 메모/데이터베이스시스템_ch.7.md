# ch.7

2024/04/17

## p.4

in_dep -> instructor + department -> 두개 합쳐놔서 중복 생김 -> dept_name과 관련된 building, budget이 계속 중복 -> 둘이 따로였으면 한번만 나옴

합쳐놓은게 용량 더 큼 -> 낭비

building, budget을 수정하는 경우 -> 일일이 다 바꿔줘야함

정보 미리 넣기 불가능(신설학과 - instructor 아직 안뽑 - primary라 못 비어놓음)

## p.5

Decompositio: 두개로 쪼개기 -> 정보손실 없이 잘 쪼개야 한다.

## p.7

R1, R2 join 할때는 name을 기준으로 join -> 엄한거 존나 생김 -> 정보 왜곡

## p.8

정보 손실 없고 싶음 -> 둘이 join 한게 기존과 같다 R = R1 U R2

## p.10

Normalization Theory: 잘 만들어졌는지 판별 -> 아니면 쪼개야 함

## p.11

Functional Dependencies: key에 대해 일반화 된거 -> primary이 역할

ID에 의해 구분 가능

이름 하나

학과 하나

예산 하나

primary key -> 구분가능 -> 다른 정보 결정 남

## p.13

Functional dependency: a -> R

두개의 튜플에서 a가 같았으면 b도 같아야함 -> 정의역을 a라고 생각하면 함수 조건이랑 비슷한듯

a는 primary에 해당 -> a가 primary면 두개 존재 X

(1 4) (1 5) -> a가 같은데 b가 다르므로 이건 dependency X







2024/05/08

## p.14

(A->B & B->C) => A -> C

## p.15

superkey가 아니여도 dependency가 있을 수 있다.

A -> BCDE = A -> B, A->C, A->D, A->E

## p.16

F holds on R: 읽어보기

name -> ID : 동명 이인이 있으면 불가능, 특수한 예시로부터 dependency를 만들지 말자

## p.17

trivial 항상 만족

A -> B trivial, if B(=A

## p.18

나눈거 나눴다가 다시 join했을 때 똑같으면 Lossless Decomposition

밑에꺼 필요충분은 아님

## p.19

F^+ = {A->B, B->C, A->C}

ex1) R1, R2에서 A->B, B->C확인 가능하므로 굳이 join해서 확인할 필요 X(dependency preserving O)

B->R1(A,B) => B->A

B->R2(B,C) => B->C -> 이놈이 하나 만족하므로 Lossless?

둘다 만족할 필요는 없다

ex2) R2에서 B->C 확인이 안되므로 dependency preserving X

## p.20

### Dependency preserving

i_ID -> dept_name

s_ID, dept_name -> i_ID

학과 이름 중복 발생 -> 쪼갬

R1 = {s_ID, i_ID}, R2 = {i_ID, dept_name} -> Lossless O, preservable 은 아님, s_ID, dept_name -> i_ID 확인 불가능

## p.23

### BCNF

a->b trivial or a is superkey for R

## p.24

dept_name -> superkey 아님, -> 이것도 trivial 아님 -> BCNF 아님

## p.25

읽어보자

## p.26

R = (A, B, C)

A가 primary

A->B: trivial X, 그래도 A는 superkey

B->C: trivial X, B는 superkey X

BCNF X

1) R1=(A,B), R2=(B,C)
   1) Lossless O
   2) preserving O
   3) BCNF O
2) R1=(A,B), R2=(A,C)
   1) Lossless O
   2) preserving X
   3) BCNF O

## p.27

읽어보자

대충 BCNF라고 preserving은 아니라는 말인듯

## p.28

### Third Normal Form

BCNF | Each attribute A in b – a is contained in a candidate key for R

preserving 보장



1NF )= 3NF )= BCNF

## p.29

읽어보자

DB설계할때 세개의 규칙중 하나를 골라서 모두 만족하도록 해야한다. (주로 BCNF)

## p.30

3NF: 정보의 중복 발생 가능, null 사용해야함







2024/05/13

## p.32

good form: BCNF, 3NF (정규화) 만족하는지 -> 만족안하면 쪼개야지 뭐

## p.33

정보의 중복O -> 그래도 BCNF O

Insertion anomalies(여러개 삽입) 

## p.35

근데 쪼개면 정보 중복도 없고 좋다! -> 4NF

## p.36

functional dependency

## p.38

3개룰 존재(Armstrong's Axioms): 뭐 읽어보자

* reflexive
* augmentation
* transitivity

sound: 있는 것만 가능

complete 모든 functional dependcy 끌어낼 수 있다.

## p.40

모든 functional dependcy를 대충 룰 3개로 끄집어 낼 수 있다.

CG -> I => CG -> CGI (Augmnetation)

## p.41

* union rule: a->b & a->r => a -> br
* decomposition: a -> b =>  r a->b & a->r 
* Pseudotransitivity: a->b & rb->g => ar->g

대충 위의 3개로 유도 가능함 ㅇㅇ

## p.42

F functional dependencies 다뽑아낼라고 무한반복 -> 근데 가능한 개수는 2^2n (a->b 일때 각 원소의 부분집합의 경우의수 2^n, 고로 둘이 곱함)

## p.43

속성의 집합의 closure -> a -> a^+

b가 drive하는 r포함

## p.44

(AG)^+ -> AG로 부터 끄집어 낼수 있는 모든 속성

(AG)^+ = AGBC (A->B, A->C) -> AGBCHI (CG->H, CG->I)

AG -> AGBCHI 가능

모든 속성이 포함되어 있으므로 AG는 superkey이다. -> primary도 가능? -> A^+, G^+를 구해서 불필요한 거 있는지 확인해보자 -> A^+ = {ABCH}, G^+ = {G} 둘다 전체는 못만드므로 AG가 primary이다.

## p.45

closure 만들면 a->b(dependency) 파악 용이

마지막거 읽어보자

## p.46

### Canonical Cover

"필요없는거 다 줄인거"

업데이트 후 functional dependency 위배시 roll back함

canonical cover: functional dependecy 대충 최소화 -> 업데이트 용이

-> 얘 구할려면 extraneous attributes(불필요한 속성) 제거 -> 그래도 F+값이 똑같으면 없애도 되는거 ㅇㅇ

## p.47

a->b 양쪽에서 불필요한거 나올 수 있다.

ex) AB->C => A->C,    B=extraneous

ex) F={AB->C, A->D, D->C}   A->C가 나오므로 B는 불필요, 심지어 AB->C 자체가 불필요

ex) AB->CD vs AB->C,   AB->CD가 더 쎄다

ex) F={AB->CD, A->C} => F={AB->D, A->C}  //(AB)^+ = ABCD

AB->C 보다 B->C가 쎄다

A->B 보다 A->BC가 쎄다







2024/05/20

## p.49

대충 빼도 같으면 삭제 쌉가능

그래서 A를 뺀것과 F랑 서로 imply 하므로 서로 동치이다 -> A 빼도 된다

## p.50

A를 뺀거의 closure를 구했는데 A가 나오면 -> A=extraneous

A를 빼도 F가 다 나오면 -> A=extraneous

## p.51

F = {AB->CD, A->E, E->C}

AB->CD에서 C=extraneous 가정

F' = {AB->D, A->E, E->C}

AB의 closure 구하기 AB^+-> ABCDE

->C가 여전히 있음 -> C 삭제 가능



B 무쓸모 가정 - A의 closure AEC, D 없으므로 빼면 안됨



왼쪽은 하나만 있으면 못지우지만 오른쪽은 체크해봐야함

## p.52

F_c = F, 서로 closure가 같다

F_c 에서는 왼쪽파트가 같은게 존재하면 안된다. ex)A->B, A->C 불가능 => A->BC (O)

## p.53

대충 더 안바뀔때까지 F_c 바꿔라

## p.54

합치기

AB->C에서 A제거, B^+=BC=AB^+, 즉 A=extraneous

결론은 F_c = {A->B, B->C}

F_c는 unique 하지 않을 수도 있다.

## p.55

F = {A ->BC, B->C, A->B, AB->C, AC->D }

A ->BC, A->B => A ->BC

A ->BC => C를 삭제해도  A^+ = ABC => A->B

AB->C => C삭제해도 노상관

AC->D => C 삭제해도 A^+=ABCD => A->D

F_c = {A->B, B->C, A->D} => F_c = {A->BD, B->C}

## p.56

R -> R_1, R_2... 분할

F_i = R_1 ∩ F^+

## p.58

t = (result ∩ R_i)^+ ∩ R_i 일때 result = result ∪ t

대충 바뀌는거 없을 때까지다 검사하면 끝

## p.59

모든 dependency에 대해서 trivial 한가 & a가 superkey 거나

lossless(O): R1 R2 간의 dependency 존재

preserving(O): 

A->C preserve 된다는데







2024/05/22

## p.61

A^+=AB -> A는 superkey가 아님 -> R_1={A,B}, R_2={A,C,D,E} -> R_2는 BCNF가 아님, (AC)^+=ABCD != ABCDE -> R_3={A,C,D}, R_4={A,C,E}



A->B = AC->BC => AC->D

## p.62

대충 AC->R_2 - AC 하면 빈거 나와야하는데 뭐(D) 나와서 BCNF아니라는 듯?

## p.63

대충 위에서한거 만족할때까지 쪼개라는 듯

## p.64

읽어보자

## p.66

### 3NF

dependency preserving 지키고 싶다면, but 정보의 중복 가능

## p.67

s_ID, dept_name -> i_ID => (s_ID , dept_name) is a superkey

i_ID -> dept_name  => dept_name is contained in a candidate key -> 3NF 만족

## p.68

후보키 경우의 수: 2^n -> testing하는게 어려움

분할은 poly time

## p.69

if 관련한거 다시 읽어보기

-> 대충 3NF 조건 확인하란 소리같음 ㅇㅇ

## p.71

(c_id, e_id)^+=c_id, e_id, b_name, type이므로 customer_id, employee_id -> branch_name, type 에서 b_name 제거

대충 뭐 두번째 for는 안돌아도 되고, 세번째 for 포함관계 확인

## p.73

3NF: lossless, preserved

BCNF: lossless

-> 이유도 알자

## p.7478

읽어보기







2024/05/27

## p. 77

### Multivalued Dependencies

  대충 a,b 모든 조합 넣기

## p.78

ID->->child_name이 존재하면, ID->->phone_number도 존재해야함

MVD는 반드시 functional dependency가 존재하지는 않는다

## p.81

R(A,B,C)

A->->B = 모든 조합이 다들어 있어야 함 = A->->C

## p.83

a->b => a->->b, fucntional => multi

## p.84

4NF: function & multival

4NF < BCNF

## p.86

쪼개는 조건 확인해보기

## p.89

5NF도 있덴다

## p.92

non-normalized 하고 싶을때

denormalized relation 

join해 놓은것을 materialized view(실제 테이블로도 저장해놓은 view) 

## p.93

earning_200@: BCNF이긴한데 매년 새로운 table 필

company_year: BCNF, 매년 shcema 변경 -> 문제 생김

관계형 DB에서 별로임

## p.94

시간관념X -> 있는 놈은 temporal data -> 근데 안한데



