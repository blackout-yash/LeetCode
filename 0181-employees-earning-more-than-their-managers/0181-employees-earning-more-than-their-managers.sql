# Write your MySQL query statement below
SELECT e1.name AS Employee FROM Employee AS e1 CROSS JOIN Employee AS e2 ON e1.salary > e2.salary AND e1.managerId = e2.id;
