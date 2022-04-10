# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE FROM Person
WHERE Id NOT IN
    (
        SELECT MIN(Id)
        FROM (SELECT * FROM Person) as p 
        GROUP BY Email
    ); 