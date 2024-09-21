# ch.1

2024/03/06

## <p.6>

### DB 목적 <-> File

- 여러개 파일 X
- 새로운 파일 접속 -> 새로운 프로그램X
- 포멧 통일
- 조건달때 쉬움
- 되거나 안되거나 둘중 하나만 -> 나름 보장해줌
- 동시접속 -> 순서 정하기
- 대충 보안 ㅇ



## <p.12>

관계형 DB - logical level

view level: 사람에 따라 볼 수 있는 값들이 다르다.

physical level: table의 저장 구조

-> 스키마도 대충 비슷



## <p.16>

physical data independence: physical 바꿔도 logical 안바뀜, 즉 독립적임



## <p.17>

* char(n) : 무조건 n개
* varchar(n) : 1~n 개
* number(n, m) : n개, 소수점 m까지

data dictionary: 스키마, 조건, 권한 - 메타데이타



## <p.18>

procedural DML: 무엇을, 어떻게

declarative DML: 무엇을 만 - relative DB



## <p.22>

### database engine

* storage manager: 쿼리, 어플리케이션(정렬, 등)과 정보 연결 

* query processr: 대충 질문 넣으면 답나오는거
* transaction managemnet: 오류나도 되든지 안되든지 보장, 동시간 접속시 순차 실행,





2024/03/11

## <p.28>

### Database Architcture

* Centralized database - 이번학기
* Client-server
* Parallel database
* Distributed database: ex) 은행 - 지점마다 분산

## <p.29>

사진 짤린듯? -> p.32

query - manager - storage

메모리 가져올때 버퍼에다가

data dictionary : schema

대충 manager 거쳐서 db에서 읽어옴

## <p.30>

* Two-tier: 
* Three-tier: 중간에 application server를 추가로 거침

## <p.33>

Database Administrator - 읽어보자

## <p.34>

### History of DB systems

* 1950~60: tape - sequential
* 1960~70: hard disk - direct - 빨라짐 / 관계형 DB 등장 / 
* 1980: 관계형 DB - SQL
* 1990: 용량 커짐
* 2000: 비정형, NoSQL sys
* 2010: 다시 SQL / main-memory DB - 디스크 없이 메모리에 저장

