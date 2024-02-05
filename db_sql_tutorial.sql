-- CREATE A NEW DATABASE db_sql_tutorial
DROP DATABASE IF EXISTS db_sql_tutorial;
CREATE DATABASE db_sql_tutorial;
USE db_sql_tutorial;
-- create table customers
DROP TABLE IF EXISTS db_sql_tutorial.customers;
CREATE TABLE db_sql_tutorial.customers(
customer_id INT(10) NOT NULL,
first_name VARCHAR(50) NULL,
last_name VARCHAR(50) NULL,
country VARCHAR(50) NULL,
score INT(32) NULL,
PRIMARY KEY (customer_id));
-- Insert customers data
INSERT INTO db_sql_tutorial.customers VALUES (1,'Maria','Cramer','Germany',350);
INSERT INTO db_sql_tutorial.customers VALUES (2,' John ','Steel','USA',900);
INSERT INTO db_sql_tutorial.customers VALUES (3,'Georg ','Pipps','UK',750);
INSERT INTO db_sql_tutorial.customers VALUES (4,'Martin','Muller','Germany',500);
INSERT INTO db_sql_tutorial.customers VALUES (5,' Peter','Franken','USA',NULL);
-- insert table orders
DROP TABLE IF EXISTS db_sql_tutorial.orders;
CREATE TABLE db_sql_tutorial.orders (
order_id INT(10) NOT NULL,
customer_id INT(10) NULL,
order_date DATE NULL,
quantity INT(32) NULL,
PRIMARY KEY (order_id));
-- insert orders data
INSERT INTO db_sql_tutorial.orders VALUES (1001,1,'2021-01-11',250);
INSERT INTO db_sql_tutorial.orders VALUES (1002,2,'2021-04-05',1150);
INSERT INTO db_sql_tutorial.orders VALUES (1003,3,'2021-06-18',500);
INSERT INTO db_sql_tutorial.orders VALUES (1004,6,'2021-07-31',710);
-- create table employees
DROP TABLE IF EXISTS db_sql_tutorial.employees;
CREATE TABLE db_sql_tutorial.employees (
emp_id   INT(10) NOT NULL,
first_name  VARCHAR(50) NULL,
last_name VARCHAR(50) NULL,
emp_country VARCHAR(50) NULL,
salary  INT(12) NULL,
PRIMARY KEY (emp_id));
-- insert employes data
INSERT INTO db_sql_tutorial.employees VALUES (1,'john','steel','usa',55000);
INSERT INTO db_sql_tutorial.employees VALUES (2,'ann','labrune','france',75000);
INSERT INTO db_sql_tutorial.employees VALUES (3,'marie','bertrand','brazil',75000);
INSERT INTO db_sql_tutorial.employees VALUES (4,'georg','afonsoemployees','uk',75000);
INSERT INTO db_sql_tutorial.employees VALUES (5,'marie','steel','uk',75000);