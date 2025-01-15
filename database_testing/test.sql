
/* Dropping and Adding Databases */
drop database if exists test;
create database test;

/* Select Database */
use test

/* Creating Tables */
create table Person (
			 fname VARCHAR(100),
			 lname VARCHAR(100),
			 fingers INT default 11
) engine=innodb;


insert Person (fname, lname, fingers) values ('John', 'Doe', 10), ('Tom', 'Smith', NULL);

/* Adding Rows to Tables 
insert Person set fname='John', lname='Doe', fingers=10;

insert into Person set fname='John', lname='Doe', fingers=10;

insert Person (fname, lname, fingers)
values ('John', 'Doe', 13);

/* Adding Multiple Rows 
insert Person (fname, lname, fingers)
values ('John', 'Doe'),
('Tom', 'Smith', 9);


/* Deleting Rows 
delete from Person whewre fname = 'Tom';

/* Updating Rows 
update Person set fname='George' wehre fname='John'; */

