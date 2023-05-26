# SELECT DISTINCT(email) as Email FROM Person GROUP BY email HAVING COUNT(email) > 1;

SELECT email as Email FROM Person GROUP BY email HAVING COUNT(email) > 1;