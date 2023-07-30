# Write your MySQL query statement below

# SELECT name as Customers FROM Customers WHERE id NOT IN (
#     SELECT c.id FROM Customers AS c INNER JOIN Orders as o ON c.id = o.customerId);

SELECT name as Customers FROM Customers WHERE id NOT IN (
    SELECT customerId FROM Orders);