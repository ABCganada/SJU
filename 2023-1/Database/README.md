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

1. Select, Insert, Delete, Update 쿼리 실행을 위한 시나리오 구현한다.

2. 2개의 테이블 join 시나리오 뿐만 아니라 3개의 join도 구현한다.

3. 5~6개의 엔티티로 데이터베이스 스키마를 구성한다.
    - customer(고객), package(택배), driver(택배 직원), car(운송 차량), branch(지점)

4. 적어도 1개의 엔티티는 순환 참조한다.
    - branch 엔티티는 하위 지점과 상위 지점 간 수직적 관계를 갖는다. 하위 지점은 상위 지점과 N:1의 관계를 가지며, 상위 지점은 다수의 하위 지점과 대응될 수 있다.
    - 하위 지점은 상위 지점의 pk를 fk로 취한다.

5. 전체 참여, 부분 참여 개념을 스키마에 적용한다.
    - Car와 Driver는 1:1 관계를 갖고 Driver는 해당 relation에서 전체 참여다.
      - Driver는 Car 엔티티와의 relation에서 전체 참여다. Driver는 항상 운행 차량이 배정되어야 한다.
      - Car는 Driver 엔티티와의 relation에서 부분 참여다. Car 엔티티의 어느 튜플은 배정된 Driver가 존재하지 않을 수 있다.
    - Customer와 Package는 1:N 관계를 갖고 Package는 해당 relation에서 전체 참여다.
      - Customer는 해당 relation에서 부분 참여다. 한 Customer에 대응되는 Package는 0~N의 범위를 갖는다.
      - Package는 해당 relation에서 전체 참여다. 한 Package는 무조건 한 Customer에 대응되어야 하며 대응되는 Customer는 1~1의 범위를 갖는다.

<br>

## Conceptual Design
<img width="699" alt="스크린샷 2024-01-06 오전 1 25 44" src="https://github.com/ABCganada/SJU/assets/96655921/3bde523e-7905-418c-9fd3-7a470d8c2b5c">

빨간 타원은 각 엔티티의 attribute를, 초록 직사각형은 엔티티를, 보라색 마름모는 엔티티 간 relation을 나타낸다.


<br>

## Logical Design
<img width="357" alt="image" src="https://github.com/ABCganada/SJU/assets/96655921/859352b4-c9e8-4269-b77c-2fb1f269fb72">

Weak entity Package
- Package는 무조건 Customer 엔티티의 한 튜플과 대응되어야 한다.
- Cusomer의 pk와 package의 번호를 복합키로 하여 식별자를 구성했다.

순환 관계
- Branch table의 'manager' 컬럼은 상위 지점의 pk가 된다.

cascade
- 고객의 정보가 삭제되면 대응되는 package도 삭제된다.
  - foreign key(customer_id) references customer(id) on delete cascade
  
on delete set default
- 지점 정보 삭제시 대응되는 car 튜플들의 소속 지점은 본사로 이동시키므로써 데이터 무결성을 지키도록 한다.
  - foreign key(branch_no) references branch(id) on delete set default

<br>

## 정규화 고민

제 2정규화: 완전 함수 종속성 만족
- driver의 기본급은 2,500,000원이며 매달 자신이 배달한 택배의 개수 * 2500원을 더해 최종 salary를 산출한다.
  - 최초 total_packs(배달한 택배 개수), salary(급여) 2개의 attribute를 디자인했으나 driver 엔티티의 pk가 아닌 total_packs 컬럼이 salary 컬럼을 결정하는 부분 함수 종속성이 존재했다.
  - 또한, total_packs가 변동되면 salary 마찬가지로 수정해주지 않는 이상 데이터 무결성이 깨져버리는 갱신 이상이 발생하기 때문에 salary를 driver 엔티티의 컬럼에서 제외시켰다.





<br>
