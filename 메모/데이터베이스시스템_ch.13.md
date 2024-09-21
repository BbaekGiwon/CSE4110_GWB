# ch.13

2024/05/27

## p.2

physical level은 다 file로 저장되어 있다.

1 tuple = 1 record

모든 tuple의 크기는 같다

하나의 type

다른 파일->다른 relation

disk I/O가 퍼포먼스 결정, 적으면 좋다! = disk block이 적다

## p.3

### Fixed-Length Records

block안에 record 저장 => 고로 block > record

record = 53byte, block = 120byte -> 이러면 두개씩 저장 -> 14byte 남는거는 버림, 다음 block에 저장

모든 record의 크기가 같으므로 c언어에서 배열 주소 찾아가듯이 하면 될듯? -> 딱코일때만 가능할지도?

## p.4

삭제하기

밑에것들 위로 땡기기

맨 밑에꺼 그위치에 넣기

삭제X, free list로 관리







2024/05/29

## p.7

변수는 offset, length로 표현

ID - 21, 5 -> 21위치부터 5개

## p.8

page = block

header에 위치,길이(offset, length)

record 삭제 -> free -> 쟤를 가르키고 있던애 header에서 size를 -1로 변경 -> 후에 한쪽으로 밀어넣음

block hear의 entry를 기준으로 주소 잡음 -> 레코드 절대?주소 아님

## p.9

record < page여야 함

아니면 대체 방법 읽

## p.10

### Organization

* Heap
* Sequential: by serach key
* Multitable clustering: 여러 table 하나의 file, 
* B+-tree, Hashing: ch.14에서

## p.11

### Free-space map

free-space map: 배열, 하나의 배열 칸은 하나의 block

사용할 수 있는 block의 비율?

대충 칸의 숫자가 사용가능한 공간의 크기 -> @/8

if block size =512byte -> 4라고 써져 있으면 512 * (4/8) = 256남음



second-level free-space map: free-space map의 4개씩 묶어서 최대값을 저장

## p.12

### Sequential

linked list처럼 작동하는 것 같은데

insert: free space있으면 그냥 삽입, 아니면 포인터로 연결

## p.14

### Multitable Clustering

cluster key: dept_name

대충 dept_name을 기준으로 table 두개 합친거

저렇게 해놓으면 DISK I/O 한번에 끝낼 수 있어서 좋다

크기에 따라 multitable이 유리하다

department talbe의 record는 서로 pointer 연결 -> 별도로 끄집어 내기 가능

## p.16

### Partitioning

유저는 physical level의 구조는 모름 -> heap인지 multi인지 모름

분할해서 저장하기

특정 년도만 많이 접근할때 -> 년도별로 나눠놓으면 효율적이다 -> 다른 저장공간, free management 이득?

## p.17

metadata: data에 대한 data - relation table에 대한 data = 실제 저장된 데이터가 아닌 DBMS를 유지하는데 필요한 정보(relation, attribute, view,,,)

-> 이것도 table로 저장되어 있음 -> 저장위치는 고정 -> 부팅할때 starting point가 된데

## p.18

realation, index, attribute, user, view 대충 읽어보자

## p.19

### Buffer

DISK I/O는 block 단위로

goal: block 최소화

buffer = cache라고 생각하면 될듯?

buffer manager: hash table로 관리

## p.20

block이 buffer에 있으면 buffer manager가 block 주소 반환

buffer에 없으면 가져옴

변경되었으면 disk에 써줌

## p.21

pined block : disk write back 안되는거 -> 사용중이기 때문 - mutex랑 유사한듯, pin = lock/unpin = unlock, pin count도 있음, pin count==0일때 write 가능

pin: 읽거나쓰기전에 걸어두고 후에 unpin

shared lock: 여러 프로그램이 동시에 읽을 수 있다 -> write는 안됨

exclusive lock: 나만 접근 가능, shared lock 과 양립 불가능







2024/06/03

## p.22

### LRU

buffer 용량 제한 -> 고로 누구를 없애고 가져올것인가?

LRU: least recently used -> 제일 나중에 사용했던애를 지움

두개를 join하는 경우 (nested for를 통해 macth가 되는 것을 찾음) -> 코드 교과서에 있을듯?

Instructor: b1,b2,b3 / Department: b4,b5라고 할때

buffer(최대 block 2개 수용): b1,b4 -> b4,b5 

근데 이렇게 하면 비효율적, 가장 최근에 사용한 b4가 교체되어야함 -> MRU

## p.23

### MRU

most recently used, 제일 최근에 사용한 것을 교체한다 -> j에 해당하는 것을 replace

outer for문에 있는 instructor의 final tupe처리가 끝나자마자 없앤다 -> **Toss-immediate**

for(int i,,,) 

​	for(int j,,,)

라고 할때 i 에 해당하는 table의 마지막 tuple에 접근 한 후



## p.24

뒤에는 읽어보란다.











