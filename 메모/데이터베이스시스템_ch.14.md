# ch.14

2024/06/03

## p.3

책의 정보 찾기 -> 위치 파악 -> disk 주소? -

table에서 검색할때 -> disk block 주소를 알아야 한다.

index file: search key - pointer(주소)로 구성

ex) search key = ID, name, 등등 

index file은 실제 file 보다 크기가 작다 -> 이것도 overhead라는데

index

* ordered indices -> search key가 정렬되어 있는 경우

* Hash indices-> hash 활용

## p.4

index 평가 -> 아래의 것들을 잘 지원하는지?

* Access type: 속성에 특정 값 or 범위
* Access time: 시간복잡도 O(log n)이면 좋음
* Insertion time: 시간복잡도 O(log n)이면 좋음
* Deletion time: 시간복잡도 O(log n)이면 좋음
* Space overhead: index 유지용 저장 공간

## p.5

### Ordered Indices

search key 정렬

여기선 ID에 따라 정렬 -> search key = ID

Clustering index: 실제 저장 순서와 search key 순서가 같은 경우 -> 근데 꼭 search key가 primary일 필요는 없다(p.7)

Secondary Index: 물리적 순서X, 그냥 두번째 index임

Index-sequential file: 인덱스랑 파일순서랑 같은건가????

## p.6

### Dense Index Files

모든 search key value에 대응하는 index가 있다

search key 값이 중복이어도 dense index는 unqiue

## p.8

record 추가, 삭제시 Index도 계속 update 해줘야 함

범위로 가져올때 -> 6개 가져올때 3개가 1block, 그럼 두번만 I/O ->  

dept_name이 clustering, ID가 secondary일때, 위에 한것 처럼 ID 범위로 6개 가져오고 싶으면 -> 이게 흩어져있어서 I/O 많이 해야함

![image-20240603172615587](C:\Users\User\AppData\Roaming\Typora\typora-user-images\image-20240603172615587.png)

## p.9

### Sparse Index Files

몇개만 index로

뭐 찾을라하면 index 어느 범위안에 있는지 찾아야함 ㅇㅇ

Index 가 작아서 좋지만 search 비용이 크다

## p.10

### Secondary Indices

여러가지에 대해서 검색이 들어올 때, secondary를 유용하게 사용 가능

무조건 dense하게 해야함, sparse안됨(물리적으로 정렬되어 있지 않으므로)

## p.11

### Sparse Index Files

less space, less maintenance overhead

locating record는 느림

block 단위로 읽어오기 때문에 block안에 몇개를 읽어오든 I/O값은 같다

고로 각 block의 시작에 해당하는 애들의 search key만 index로(sparse) -> clustering index일때 가능

그럼 unclustering 이면? -> 정렬된 secondary index에 대한 sparse index 가능 (p.10에 salary 정렬되어 있는 secondary key 같은것에 대한 sparse index를 만든다는 거)

## p.12

### Multilevel Index

index에 대한 index

index가 큰 경우 -> 이것에 대한 I/O가 크다 -> 그럼 index를 sequential file로 보고 이것에 대한 sparse index를 또 만든다 -> 또 block으로 쪼개서 시작점만 sparse index로 만들기

## p.14

### Deletion

dense인 경우: file record 지우듯이 지우면 됨

sparse인 경우: 만약에 index인 거를 지울때, 다음에 있는거로 index를 대체함

다음거가 이미 index면 굳이 replace 안해도 됨







2024/06/05

## p.15

### Insertion

dense: 없으면 삽입

sparse: 새로운 블록이 만들어지지 않으면 냅둠

## p.16

indices on multiple keys

table access가 많으면 그래도 만들어줌, 아니면 이게 다 overhead이므로 안만듦

(John, 12121) < (John, 13514) and  (John, 13514) < (Peter, 11223)

(name, ID) -> name 1순위, ID 2순위

prefix여야 효과있다는데 -> prefix = string의 앞부터 차례대로 비교한다는 것인듯?

## p.17

### B+ Tree

관계형 DB에서 index 만든다고하면 이거임

indexed-sequentail: 주기적으로 파일 재구성 필요

B+ Tree: 재구성이 필요X, 대신 삽입, 삭제 비용이 좀 더 필요(근데 작아서 괜춘, log n 아닌가?), tree 구조인지라 space를 더 잡아먹음 -> 이러나 저러나 이게 더 좋더라

## p.18

search key = name

B+ tree(height balanced tree) =: binary search tree != height balanced tree(좌우가 길이 같은거)

leaf node에 있는게 데이터이다. 위에는 그냥 구분용임

고로 leaf node가 record에 대한 주소값을 가지고 있다.

모든 path가 같은 길이를 가지므로 find 시간이 같다

B+ tree는 무조건 ceiling(올림)만 사용한데 (floor 안씀)

하나의 tree node의 크기 == block의 크기

children을 [n/2]~n개 가져야 한다.

leaf node는 [(n-1)/2] ~ n-1개

(n이 포인터 개수임 고로 data 값은 n-1개 있는 것)

## p.20

search key ordered

key 사이사이에 pointer

## P.21

k_i-1<= p < k_i

포인터는 작같, 크 여야 함

## p.22

대충 leaf든 아니든 구조는 같음

## p.23

n=6 이므로 -> 3~5개 가능

root니까 2개만 있어도 가능

## p.24

block이 

파일에 저장할때는 block 끼리 꼭 인접해서 저장 될 필요는 없다. 어차피 block 단위로 불러옴, 옆동네 block일 필요는 없다. 붙어있든 안붙어있든 I/O 횟수는 같다

leaf node끼리는 linked list처럼 되어 있다.

non leaf: sparse index처럼 되어 있음

max tree depth = [log_(n/2) k] - ceiling -> 고로 삽입 삭제가 용이

## p.27

대충 max tree depth = [log_(n/2) k]이므로 binary search tree 보다 효율적이라는 뜻

## p.25

코드 살펴보기 -> 계속 내려가면서 찾는 것보다 큰것 중 젤 작은 거 -> 같으면 그놈이 그거, 없으면 없는거

range queries: 꼭 존재하는 key가 있을 필요X -> 사이에 있는 것만 꺼내기

 ## p.28

### Range query

linked list를 활용함 -> 맨끝의 link는 다음 노드, 마지막 노드꺼는 NULL -> 이거나오면 끝났는 갑다

## p.29

non unique key

위에는 중복 없다고 가정했었음 -> 근데 있다면? -> 추가적인 속성을 가져다 붙이자(composite하게) -> unique 완성 -> 정렬 가능(clustering일때)

-> clustering 하지 않다면 추가적인 I/O 발생

ex) salary로 bulid 했으면 ID랑 묶어서 pair로 ㄱㄱ (salary, ID)

## p.30

### Insertion

pr: pointer

v: serach key val

leaf node 자리가 없다면? -> split해서 하나 나눔

근데 parent도 꽉찼다면? -> 얘도 split

이렇게 올라가다가 root도 꽉차면? -> 얘도 split -> 위에 새로운 root 하나 만듦, depth 1 증가



[n/2]를 남기고 새로운거에 나머지 -> 새로운 node 중 가장 작은 값은 k를 parent에 추가

## p.32

Adam 넣고 싶음 -> 꽉참 -> 정렬 -> 새로운거 만듦 -> [n/2]남기고 나머지 새로운거로 이동 -> 새로운것 중 제일 작은 califieri parent에 삽입 -> 근데 parent도 꽉참 -> ......









2024/06/10

[] <-이거 다 ceiling

## p.33

### Insertion

non leaf node 쪼개기: -> leaf와는 다르게 pointer도 신경써줘야 함

p1, k1, p2, k2,,,, k[(n+1)/2 - 1], p[(n+1)/2] -> 여기가 기존

k[(n+1)/2] -> 이거는 parent로

p[(n+1)/2 + 1], k[(n+1)/2 + 1] ,,, ,, kn, pn+1 -> 새로운 거

-> parent도 꽉차면 recursive하게 ㄱㄱ



Lamport라는 애 넣음 -> 꽉 참 -> 정렬 -> 쪼개기 -> n=4이므로 3번째꺼를 계속 올림(kim, gold)

## p.35

### Deletion

leaf는 최소 [(n)/2]필요 -> 1개 삭제해서 1개 남는 경우 -> underflow -> 이 leaf도 삭제 -> **왼쪽** 애랑 합칠 수 있는지 확인

맨 왼쪽은 어떡함? -> 오른쪽에 있는 애를 끌어옴

읽어보자

## p.36

왼쪽애랑 합칠라고 봤는데 꽉차면 재분배 -> 이에 맞게 parent도 변경필요함 -> 이때 n=4가 되므로 3번째에 있던 kim이 parent쪽으로 올라가게 됨

## p.37

gold 없앨 때 -> leaf에 1개 남으므로 merge 필요 -> merge하고 보니 chlid가 1개 -> child는 [n/2]는 필요 -> underflow -> 고로 저 parent는 삭제해야함 -> 

leaf노드만 레코드 이므로 non leaf에는 비교용으로 삭제된거 가능

-> 수도코드 파악하라는데(교과서에 있단다)

## p.40

worst case O(log_[n/2] (K)) -> 성능이 일정하다

-> 왠만하면 저거보다 적게 든다

정렬해서 insert할때 보통 leaf에 절반만 차 있음

랜덤이면 2/3차있음

## p.41

중복되는건 unique하게 만들어준다

key를 위한 추가 공간 -> overhead 발생

key를 위한 pointer list를 만듦 -> 삭제할때마다 맞는지 확인해줘야함

각 key에 unique해지더록 추가정보(record-identifier) 삽입 -> 공간 잡아먹음

## p.42

### B+-Tree File Organization

범위로 가져오고 싶을때 -> (p.19) katz ~ singh (총 3개) -> 가져올라고 하는데 physical에서는 떨어져 있으므로 block I/O 3번 발생함

각 leaf node에 포인터가 아니라 record를 저장 -> 범위로 불러올때 효율적이다

record를 저장하게 되면 개수로는 몇개 저장못함 (record가 커서)

## p.45

record가 움직이면 secondary 포인터도 움직어야 한데

search key를 가지고 있으면 

secondar index로 search key 확보 -> search 할때 두번 찾아야 한다?

근데 update가 편하다는것 같은데









2024/06/12

## p.46

prefix compression: 접두사 압

## p.47

init할때 하나씩 insert하면 비효율적임(bulk loading)

대안 1) 정렬 -> 그 후 삽입 -> 그럼 들어오면서 쪼개지므로 공간 활용이 그닥이다.

대안 2) 정렬 -> n개씩 묶음 -> 묶은 것들의 parent를 recursive하게 만듦 -> 아래에서 위로 올라가기 -> 공간활용&depth 작음

## p.48

### B-Tree Index File

search key는 unique하다

leaf node 포인터 자리에 record & search key도 포인터 옆에 record -> 이러다보면 search 시 최대 tree depth 만큼 걸리지만 더 빠를 수도

node가 적다, 가끔씩 non-leaf에서도 찾을 수 있다, 

그러다보니 leaf가 오히려 오래 걸림, 삽입삭제 복잡, 공간 차지 더함

-> 결론적으로 구리다

## p.51~52

X

## p.54

### Static Hashing

bucket = block

hash 함수의 값에 해당하는 index에 넣기

## p.55

bucket overflow: linked list로 해서 이어 나가기 -> 고로 찾을 때 sequential하게 찾음 -> 고로 biased 된다면 시간복잡도 망함, 잘되면 O(1)로 치는 듯?

overflow를 막을 수는 없다

overflow chaining

## p.57

대충 읽어보면 될듯

bucket에는 실제 record가 들어가 있다.

## p.59

bucket 수가 너무 작다 -> overflow 많아짐 -> linked list 많아짐 -> I/O 많아짐 -> 구림

또 너무 크게 공간을 줘버리면 낭비임 or 삭제가 많이 일어난 경우

=> 주기적으로 재구성 해라

## p.61

### Dynamic Hashing

재구성하는 방법들

* Periodic rehashing: hash table수의 1.5배 되면 재구성
* Linear Hashing: ??
* Extendable Hashing: ??

## p.62

hash는 전체 재구성시 비용이 크다, update가 잦으면 B+tree가 좋다.(bucket overflow)

update가 적으면 hash 크기 정하기도 편함

worst case 보장

특정 값으로 찾는 경우 -> hash가 유리, tree는 위에서 내려와야함

범위로 찾는 경우 -> hash가 정렬 되어 있지 않으므로 비효율적이다

## p.63

index가 있는 조건의 record 부터 뽑아낸다

둘 다 있으면 둘 다 뽑아내서 교집합

## p.65

두 속성으로 search key를 만들었을 경우

둘 다 들어오면 빠름, 범위여도 빠름(먼저 =으로 찾는다면)

근데 처음부터 범위로 찾으면 개수가 많아진다

## p.66

covering indices: index에 추가속성 넣기 -> 가져오기 전에 그 속성을 활용

## p.67

create index, drop index

primary는 대부분 DB가 이미 생성함, foreign도 하기도 -> join할 때 빠르다

---

여기까지 시험 범위

