DROP DATABASE mydb2;
create database mydb2;
use mydb2;

create table S
	(SNO	char(4) NOT NULL,
	SNAME	varchar(8),
	AGE	smallint,
    SEX CHAR(1),
    primary key (SNO));

CREATE TABLE C
(CNO	CHAR(20) NOT NULL,
CNAME	CHAR(20),
TEACHER_NAME	CHAR(20));


CREATE TABLE SC
	(SNO	CHAR(4) NOT NULL,
    CNO	CHAR(20) NOT NULL,
    GRADE smallint);
    
INSERT INTO S(SNO, SEX)
		VALUES('S1', 'M'),
			('S2', 'M'),
            ('S3', 'F'),
            ('S4', 'F');
            
INSERT INTO C(CNO, CNAME,TEACHER_NAME)
	VALUES('C1', 'SHUJUKUGAILUN', 'WANGWEI'),
		('C2', NULL, NULL),
        ('C3', NULL, NULL),
        ('C4', 'DASHUJUKEXUE', 'WANGXIAOYANG');
        
INSERT into SC(SNO, CNO, GRADE)
	VALUES('S1', 'C1', NULL),
		('S3', 'C1', NULL),
        ('S2', 'C4', 49);
        

