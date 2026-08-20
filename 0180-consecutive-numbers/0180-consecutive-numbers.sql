-- WITH sample AS (
--     Select id,count(num) as num_count from Logs
--     group by (id)
-- )
-- SELECT *
-- FROM sample;

select distinct num as ConsecutiveNums from 
(SELECT
    num,
    LAG(num) OVER (ORDER BY id) AS before_value,
    LEAD(num) OVER (ORDER BY id) AS next_value
FROM Logs) as t

where num =  before_value and num =  next_value;