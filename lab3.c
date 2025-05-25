CREATE TABLE Employee (
E_id INT PRIMARY KEY,
E_name VARCHAR(50),
Age INT,
Salary DECIMAL(10, 2)
);
SELECT COUNT(E_name) AS num_employees
FROM Employee;
SELECT MAX(Age) AS max_age
FROM Employee;
SELECT MIN(Age) AS min_age
FROM Employee;
SELECT E_name, Salary
FROM Employee
ORDER BY Salary ASC;
SELECT Salary, COUNT(*) AS num_employees
FROM Employee
GROUP BY Salary;
