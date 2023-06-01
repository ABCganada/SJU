create table branch(
  id int not null,
  name varchar(255),
  phone_no varchar(255),
  manager int default 1,

  primary key(id),
  foreign key(manager) references branch(id)
);
-------------------------
create table car(
  id int not null,
  capa_w int,
  capa_n int,
  bno int default 1,

  primary key (id),
  foreign key (bno) references branch(id) on delete set default
);
-------------------------
CREATE TABLE driver (
  id INT NOT NULL,
  name VARCHAR(255) NOT NULL,
  phone_no VARCHAR(255) NOT NULL,
  packs INT DEFAULT 0,
  total_packs INT DEFAULT 0,
  carno INT NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (carno) REFERENCES car (id) on delete cascade
);
-------------------------
CREATE TABLE customer (
  id INT IDENTITY(1,1) PRIMARY KEY,
  name VARCHAR(255),
  address VARCHAR(255),
  phone_no VARCHAR(20),
  email VARCHAR(255),
  dno INT,
  FOREIGN KEY (dno) REFERENCES driver(id)
);
--------------------------
create table package(
  customer_id int,
  pno int not null,
  weight int,
  status int default 0,
  charge int default 3500,

  primary key(customer_id, pno),
  foreign key(customer_id) references customer(id)
);
-------------------------
insert into branch values(1, 'master', '111-0001', null);
insert into branch values(2, 'second', '111-0002', 1);
insert into branch values(3, 'third', '111-0003', 1);
insert into branch values(22, 'twotwo', '112-0022', 2);
insert into branch values(31, 'baera', '113-0031', 3);
insert into branch values(41, 'four-one', '113-0041', 3);
insert into branch values(503, 'OhGongSam', '122-0503', 22);
insert into branch values(777, 'lucky', '122-0777', 22);
insert into branch values(8282, 'hurryUp', '503-8282', 503);
insert into branch values(666, 'sixixix', '141-0666', 41);
insert into branch values(1303, 'ill-3-0-3', '131-1303', 31);
--------------------------
insert into car values(1, 1200, 50, 1);
insert into car values(2, 1000, 50, 2);
insert into car values(3, 600, 30, 3);
insert into car values(4, 400, 20, 22);
insert into car values(5, 200, 10, 31);
insert into car values(6, 200, 10, 41);
insert into car values(7, 1000, 40, 777);
insert into car values(8, 500, 30, 777);
insert into car values(9, 200, 10, 777);
insert into car values(10, 100, 5, 8282);
insert into car values(11, 100, 5, 666);
insert into car values(12, 200, 10, 1303);
--------------------------
insert into driver values(111, 'Jung', '0001-0111', 0, 25, 1);
insert into driver values(112, 'Kang', '0002-0112', 0, 50, 2);
insert into driver values(113, 'Yoon', '0003-0113', 0, 30, 3);
insert into driver values(114, 'Jang', '0022-0114', 0, 40, 4);
insert into driver values(115, 'Jung', '0031-0115', 0, 0, 5);
insert into driver values(116, 'Kang', '0041-0116', 0, 2, 6);
insert into driver values(117, 'Kang', '0777-0117', 0, 5, 7);
insert into driver values(118, 'Han', '0777-0118', 0, 9, 8);
insert into driver values(119, 'Seo', '8282-0119', 0, 1, 10);
insert into driver values(120, 'An', '1303-0120', 0, 100, 12);
--------------------------
insert into customer(name, address, phone_no, email, dno) values('KIM', 'seoul', '010-1234-5678', 'kim123@gmail.com', 111);
insert into customer(name, address, phone_no, email, dno) values('LEE', 'seoul', '010-1111-2222', 'lee0107@email.com', 111);
insert into customer(name, address, phone_no, email, dno) values('PARK', 'busan', '010-2345-7890', 'phd33@gmail.com', 113);
insert into customer(name, address, phone_no, email, dno) values('CHOI', 'gwangju', '010-7272-8282', 'ch8802@email.com', 114);
insert into customer(name, address, phone_no, email, dno) values('SHIN', 'yongin', '010-3008-3613', 'smg9712@gmail.com', 112);
insert into customer(name, address, phone_no, email, dno) values('KIM', 'seoul', '010-1235-5321', 'kim123@naver.com', 111);
insert into customer(name, address, phone_no, email, dno) values('CHO', 'daejeon', '010-4567-8901', 'cho3mo4@naver.com', 116);
insert into customer(name, address, phone_no, email, dno) values('KIM', 'incheon', '010-3333-2211', 'kjs99@email.com', 119);
insert into customer(name, address, phone_no, email, dno) values('LEE', 'suwon', '010-4033-7692', 'ljh0827@naver.com', 112);
insert into customer(name, address, phone_no, email, dno) values('OH', 'jeju', '010-3577-7692', 'cjamm@email.com', 120);
--------------------------
insert into package values(1, 1111, 3, default, default);
insert into package values(1, 1112, 5, default, default);
insert into package values(3, 2001, 10, default, default);
insert into package values(4, 1013, 12, default, default);
insert into package values(5, 1111, 2, default, default);
insert into package values(5, 1234, 3, default, default);
insert into package values(5, 4321, 3, default, default);
insert into package values(6, 5555, 7, default, default);
insert into package values(7, 7777, 6, default, default);
insert into package values(8, 1003, 20, default, default);
insert into package values(9, 1103, 10, default, default);
insert into package values(10, 1111, 4, default, default);
insert into package values(10, 1234, 14, default, default);
-------------------------
update package
set charge = charge + 1000
where customer_id in (
	select id
	from customer
	where address = 'jeju'
);
-------------------------
update driver
set total_packs = total_packs + (select count(*) from customer, package where driver.id=customer.dno and customer.id=package.customer_id and package.status <> 1);
-------------------------
select id, (select count(*) from customer where customer.dno = driver.id) as total_customer
from driver;
-------------------------
update driver
set packs = (select count(*) from customer, package where driver.id=customer.dno and customer.id=package.customer_id and package.status <> 1);
-------------------------
select name, address, phone_no
from customer
where address = 'jeju'
-------------------------
select driver.name, car.bno
from driver, car
where driver.carno = car.id and car.bno = 777;
-------------------------
select *
from car
where car.id not in (select carno from driver)
-------------------------
select customer_id, pno, status
from package
-------------------------
update package
set status = 1
where customer_id = 10 and pno = 1111;
-------------------------
select lb.id, lb.name, hb.id, hb.name
from branch as lb, branch as hb
where lb.manager = hb.id;
-------------------------
select id, name,, phone_no, email
from customer
order by name asc;
-------------------------
SELECT id, name, CASE
  WHEN total_packs >= 5 THEN 2500000 + (15000 * total_packs)
  ELSE 2500000
  END AS Salary
FROM driver
order by name;
-------------------------
SELECT *
FROM car
WHERE id NOT IN (
  SELECT carno
  FROM driver
);
-------------------------
select customer.id, SUM(package.charge) as total_charge
from customer, package
where customer.id = package.customer_id
group by customer.id;