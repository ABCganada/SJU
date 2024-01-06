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

1. Select, Insert, Delete, Update 쿼리 실행을 위한 시나리오 구현한다. 이때의 시나리오는 주제의 real world와 최대한 부합하도록 한다.

3. 2개의 테이블 join 시나리오 뿐만 아니라 3개의 join도 구현한다.

4. 5~6개의 엔티티로 데이터베이스 스키마를 구성한다.
    - customer(고객), package(택배), driver(택배 직원), car(운송 차량), branch(지점)

5. 적어도 1개의 엔티티는 순환 참조한다.
    - branch 엔티티는 하위 지점과 상위 지점 간 수직적 관계를 갖는다. 하위 지점은 상위 지점과 N:1의 관계를 가지며, 상위 지점은 다수의 하위 지점과 대응될 수 있다.
    - 하위 지점은 상위 지점의 pk를 fk로 취한다.

6. 전체 참여, 부분 참여 개념을 스키마에 적용한다.
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

## 비즈니스 시나리오 예시

### Select
ex1. Branch ID, 이름과 Manager branch ID, 이름을 확인한다.
<img width="603" alt="스크린샷 2024-01-06 오후 1 43 40" src="https://github.com/ABCganada/SJU/assets/96655921/6ac754e0-38e2-4daa-9d4b-ba059b43670f">

```sql
select lb.id, lb.name, hb.id, hb.name
from branch as lb, branch as hb
where lb.manager = hb.id;
```

ex2. Driver 리스트를 배달 개수의 내림차순으로 정렬하고, 총 패키지 개수와 Salary를 확인한다.
<img width="606" alt="스크린샷 2024-01-06 오후 1 44 55" src="https://github.com/ABCganada/SJU/assets/96655921/c6210e09-2c15-461f-801b-734bf8e9ed4c">

```sql
select id, name, total_packs, case 
                              when total_packs >= 3 then 2500000 + (2500 * total_packs)
                              else 2500000 end as salaray
from driver
order by total_packs desc;
```
<br>

### Insert
ex. Customer 정보를 삽입한다.
<img width="602" alt="스크린샷 2024-01-06 오후 1 47 21" src="https://github.com/ABCganada/SJU/assets/96655921/bff5f237-0a70-4db8-9c1f-4a12d9df0ff0">

```sql
insert into customer(name, address, phone_no, email, dno)
values('%s', '%s', '%s', '%s', null);
```
customer 튜플 삽입 시, 외래키 dno는 최초 null로 삽입된다.

<br>

### Delete
ex1. Driver 배정이 없는 car 데이터를 삭제한다.
<img width="608" alt="스크린샷 2024-01-06 오후 1 52 38" src="https://github.com/ABCganada/SJU/assets/96655921/52300ff2-d372-4933-b06a-703349c9c622">


```sql
---check btn query
select *
from car
where id not in (select carno from driver);

---delete query
delete from car
where car.id = '%s';
```

ex2. 담당하고 있는 Customer가 0인 Driver를 해고한다.
<img width="608" alt="스크린샷 2024-01-06 오후 1 50 02" src="https://github.com/ABCganada/SJU/assets/96655921/e771f3e7-4c11-4c4d-bdfc-52283e21683e">

```sql
---check btn query
select id, (select count(*)
            from customer
            where customer.dno = driver.id) as total_custmoer
from driver;

---delete query
delete from driver
where id = '%s';
```

<br>

### Update
ex1. 배송지가 jeju인 택배에 대한 추가 요금을 반영한다.
<img width="599" alt="스크린샷 2024-01-06 오후 1 54 29" src="https://github.com/ABCganada/SJU/assets/96655921/131e2529-557f-4a6a-8e97-6b3b95e99e5d">

```sql
---update query
update package
set charge = charge + 1000
where customer_id in (select id
                      from customer
                      where address = 'jeju');
```

ex2. 각 Driver가 현재 담당하고 있는 Package 개수와 총 택배 개수를 갱신한다.
<img width="605" alt="스크린샷 2024-01-06 오후 1 56 09" src="https://github.com/ABCganada/SJU/assets/96655921/d478a0cc-0dcc-4264-9013-d7cef1e4ffb6">

```sql
---check btn query
select id, name, packs, total_packs
from driver;

---update query 1
update driver
set packs = (select count(*)
             from customer as c, package as p
             where driver.id = c.dno and c.id = p.customer_id
             and p.status <> 1);

---update query 2
update driver
set total_packs = total_packs + packs;
```
update 쿼리 1은 driver가 현재 담당하고 있는 택배 개수를 업데이트한다. 쿼리에 중첩 질의를 사용하며, driver, customer, package 3개의 테이블을 join한다. 여기서 status가 1(배송이 완료된)인 택배 튜플에 대해서는 count하지 않는다.
