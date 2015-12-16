drop database mydb;
create database mydb;
use mydb;
create table student
	(s	char(4) NOT NULL,
	sname	varchar(8) NOT NULL,
	birth	char(8),
    household	varchar(8),
    admissionyear	int(4),
    primary key (s));
    
create table class
	(c	char(4) not null,
    cname	varchar(8) not null,
    tname	varchar(4),
    primary key(c));
    
create table selectclass
	(s	char(4),
    c	char(4),
    selecttime char(4),
    primary key(s,c),
    foreign key(s)references student(s),
    foreign key(c)references class(c));
    

    
