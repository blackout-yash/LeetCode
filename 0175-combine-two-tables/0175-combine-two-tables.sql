# Write your MySQL query statement below
SELECT firstName, lastName, a.city, a.state  FROM Person as p LEFT JOIN Address as a ON p.personId = a.personId; 