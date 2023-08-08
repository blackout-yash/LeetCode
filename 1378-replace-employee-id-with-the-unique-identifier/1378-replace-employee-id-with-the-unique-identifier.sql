# Write your MySQL query statement below

# select ei.unique_id, e.name from Employees as e left join EmployeeUNI as ei on e.id = ei.id;

# select ei.unique_id, e.name from Employees as e left join EmployeeUNI as ei using(id);

select ei.unique_id, e.name from EmployeeUNI ei right join Employees e using(id);
 