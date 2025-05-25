CREATE TABLE customers (
 ID INT AUTO_INCREMENT PRIMARY KEY,
 NAME VARCHAR(100),
 AGE INT,
 ADDRESS VARCHAR(255),
 SALARY DECIMAL(10, 2)
 );
INSERT INTO customers (NAME, AGE, ADDRESS, SALARY) VALUES
('John Doe', 30, '123 Main St, Anytown, USA', 50000.00),
('Jane Smith', 25, '456 Elm St, Othertown, USA', 60000.00),
('Alice Johnson', 35, '789 Oak St, Anycity, USA', 70000.00),
('Bob Brown', 40, '321 Pine St, Anothercity, USA', 55000.00),
('Emily Davis', 28, '654 Maple St, Somewhere, USA', 65000.00),
('Michael Wilson', 45, '987 Cedar St, Nowhere, USA', 75000.00),
('Sarah Miller', 32, '159 Birch St, Anyplace, USA', 62000.00),
('David Jones', 38, '852 Walnut St, Elsewhere, USA', 68000.00),
('Jennifer Taylor', 27, '753 Cherry St, Elsewhere, USA', 59000.00),
('William Anderson', 33, '369 Oak St, Somewhere, USA', 71000.00);
select *from customers;
DELIMITER //
 CREATE TRIGGER display_salary_changes_insert
BEFORE INSERT ON customers
FOR EACH ROW
BEGIN
INSERT INTO salary_changes_log (customer_id, old_salary, new_salary, change_time)
VALUES (NEW.ID, NULL, NEW.salary, NOW());
END//
CREATE TRIGGER display_salary_changes_update
 BEFORE UPDATE ON customers
FOR EACH ROW
BEGIN
INSERT INTO salary_changes_log (customer_id, old_salary, new_salary, change_time)
VALUES (NEW.ID, OLD.salary, NEW.salary, NOW());
END//
CREATE TRIGGER display_salary_changes_delete
BEFORE DELETE ON customers
FOR EACH ROW
BEGIN
INSERT INTO salary_changes_log (customer_id, old_salary, new_salary, change_time)
VALUES (OLD.ID, OLD.salary, NULL, NOW());
END//
DELIMITER ;
SHOW TRIGGERS;
