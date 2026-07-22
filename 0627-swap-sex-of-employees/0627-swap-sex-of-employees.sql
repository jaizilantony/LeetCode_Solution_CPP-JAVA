-- select id ,name,
-- case
-- when sex = m then f
-- when sex = f then m
-- end , salary
--  from salary

-- SELECT
--     id,
--     name,
--     CASE
--         WHEN sex = 'm' THEN 'f'
--         WHEN sex = 'f' THEN 'm'
--     END AS sex,
--     salary
-- FROM salary;


UPDATE salary
SET sex = CASE
            WHEN sex = 'm' THEN 'f'
            WHEN sex = 'f' THEN 'm'
          END;