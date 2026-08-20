-- WITH joined_table AS (
--     SELECT
--         department.name AS Department,
--         employee.name AS Employee,
--         employee.salary AS Salary
--     FROM employee
--     JOIN department
--         ON employee.departmentId = department.id
-- )
-- -- SELECT *
-- -- FROM joined_table;

-- Select Department, employee, salary , dense_rank() over (partition by Department order by salary desc) as salary_rank from joined_table
-- where salary_rank <=3; 

WITH joined_table AS (
    SELECT
        department.name AS Department,
        employee.name AS Employee,
        employee.salary AS Salary
    FROM employee
    JOIN department
        ON employee.departmentId = department.id
),
ranked_table AS (
    SELECT
        Department,
        Employee,
        Salary,
        DENSE_RANK() OVER (
            PARTITION BY Department
            ORDER BY Salary DESC
        ) AS salary_rank
    FROM joined_table
)
SELECT
    Department,
    Employee,
    Salary
FROM ranked_table
WHERE salary_rank <= 3;