# Database final project [23.05 ~ 23.06]

택배 운송 업체 데이터베이스 설계 프로젝트
<br>

## summary

- 주제: 택배 운송 업체의 비즈니스 시나리오 구현
- 주요 목적: 고객에게 물품 전달
- 제한: 교환 및 환불 시나리오 제외 구현
  <br>

## 기술 스택

- C++
- MFC
- MSSQL

<br>

## Requirement & Analysis

- Select, Insert, Delete, Update 쿼리 실행을 위한 시나리오 구현한다.
- 2개의 테이블 join 시나리오 뿐만 아니라 3개의 join도 구현한다.
- 5~6개의 엔티티로 데이터베이스 스키마를 구성한다.
  - customer(고객), package(택배), driver(택배 직원), car(운송 차량), branch(지점)
- 적어도 1개의 엔티티는 순환 참조한다.
  - branch 엔티티는 하위 지점과 상위 지점 간 수직적 관계를 갖는다. 하위 지점은 상위 지점과 N:1의 관계를 가지며, 상위 지점은 다수의 하위 지점과 대응될 수 있다.
  - 하위 지점은 상위 지점의 pk를 fk로 취한다.
- 전체 참여, 부분 참여 개념을 스키마에 적용한다.
  - Car와 Driver는 1:1 관계를 갖는다.
  - Driver는 Car 엔티티와의 relation에서 전체 참여다. Driver는 항상 운행 차량이 배정되어야 한다.
  - Car는 Driver 엔티티와의 relation에서 부분 참여다. Car 엔티티의 어느 튜플은 배정된 Driver가 존재하지 않을 수 있다.

<br>

## Conceptual Design

<br>

## Logical Design

<br>

## 정규화

<br>
