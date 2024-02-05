 
CREATE DATABASE BANK; 
use BANK;
CREATE TABLE `customer` (

 `ac_no` int NOT NULL AUTO_INCREMENT,

 `cname` varchar(45) DEFAULT NULL,

 `balance` varchar(45) DEFAULT NULL,
 
 `deposit` varchar(45) DEFAULT NULL,

 `pass_code` int DEFAULT NULL,

 PRIMARY KEY (`ac_no`),

 UNIQUE KEY `cname_UNIQUE` (`cname`)

) ;
CREATE TABLE transactions (
    transaction_id INT AUTO_INCREMENT PRIMARY KEY,
    sender_ac INT NOT NULL,
    receiver_ac INT NOT NULL,
    amount INT NOT NULL,
    transaction_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
INSERT INTO transactions (sender_ac, receiver_ac, amount, transaction_date)
VALUES (?, ?, ?, ?);


show databases;
CREATE TABLE `customer` (

 `ac_no` int NOT NULL AUTO_INCREMENT,

 `cname` varchar(45) DEFAULT NULL,

 `balance` varchar(45) DEFAULT NULL,
 
 `deposit` varchar(45) DEFAULT NULL,

 `pass_code` int DEFAULT NULL,

 PRIMARY KEY (`ac_no`),

 UNIQUE KEY `cname_UNIQUE` (`cname`)

);
CREATE TABLE `customer` (

 `ac_no` int NOT NULL AUTO_INCREMENT,

 `cname` varchar(45) DEFAULT NULL,

 `balance` varchar(45) DEFAULT NULL,
 
 `deposit` varchar(45) DEFAULT NULL,

 `pass_code` int DEFAULT NULL,

 PRIMARY KEY (`ac_no`),

 UNIQUE KEY `cname_UNIQUE` (`cname`)

);
use BANK;
