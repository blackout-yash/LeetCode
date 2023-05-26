# SELECT DISTINCT(email) as Email FROM Person GROUP BY email HAVING COUNT(email) > 1;

# SELECT email as Email FROM Person GROUP BY email HAVING COUNT(email) > 1;

SELECT email FROM (SELECT email, COUNT(email) as cnt FROM Person GROUP BY email) AS Temp where cnt > 1;