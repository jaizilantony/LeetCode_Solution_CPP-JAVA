-- SELECT class
-- FROM (
--     SELECT class, COUNT(class) AS freq
--     FROM courses
--     GROUP BY class
-- ) AS t
-- limit 1;
-- ;

SELECT class
FROM (
    SELECT class, COUNT(class) AS freq
    FROM courses
    GROUP BY class
    having count(class) >= 5
) AS t
;

