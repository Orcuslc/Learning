
#create database mydb;

use mydb;

create table students
 (
     s char(11) not null,
     sname char(4) not null,
     sex char(1),
     birth char(8),
     register char(10),
     enrollment char(8),
     primary key (s)
 );

create table course
 (
     c char(20) not null,
     cname char(10) not null,
     t char(3) not null,
     primary key (c)
 );

create table sc
 (
     s char(11) not null,
     c char(20) not null,
     sctime date,
     primary key (s,c),
     foreign key (s) references students(s),
     foreign key (c) references course(c)
 );

insert into students values ('13300000001','ncea','M','19950710','shanghai','2013');
 insert into students values ('13300180062','wh','M','19950913','zhejiang','2013');
 insert into students values ('13300921321','whh','F','19940124','fujian','2013');

insert into course values('1','shuxue','zha');
 insert into course values('2','yuwen','qia');
 insert into course values('3','waiyu','sun');

insert into sc values('13307130001','1','2015-10-08');
 insert into sc values('13307130001','2','2015-10-08');
 insert into sc values('13307130001','3','2015-10-08');

update students set sname='jwz' where s='13307130001';

select sname
 from students
 where sname='wh';

delete from sc where s='13307130001';
 
