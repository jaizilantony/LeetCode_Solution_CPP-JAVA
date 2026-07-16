
-- select Department.name as Department, Employee.name as Employee , Employee.salary as Salary from employee 

-- join

-- department

-- on employee.departmentid = department.id

-- where employee.salary >= max_val (select max(employee.salary) as max_val,department.name from employee join department

-- on employee.departmentid = department.id

-- group by employee.departmentid;)



SELECT
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM Employee e
JOIN Department d
    ON e.departmentId = d.id
JOIN (
    SELECT
        departmentId,
        MAX(salary) AS max_salary
    FROM Employee
    GROUP BY departmentId
) m
    ON e.departmentId = m.departmentId
   AND e.salary = m.max_salary;