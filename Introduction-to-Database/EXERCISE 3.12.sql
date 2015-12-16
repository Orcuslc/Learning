#EXERCISE 3.12

1. INSERT INTO C(C#, CNAME, T#)
	VALUES ('C8','VC++', 'T6')

2. INSERT INTO FACULTY(TNAME)
	SELECT T.TNAME
	FROM T
	WHERE T.# IN (SELECT T#
					FROM C
					WHERE C.C# IN (SELECT C#
									FROM SC
									GROUP BY C#
									HAVING AVG(SCORE) > 80))

3. DELETE FROM SC
	WHERE SC.SCORE IS NULL

4. DELETE FROM SC 
	WHERE SC.C# = C.C# AND C.T# = T.T# AND T.TNAME = 'LIU' AND SC.S# = S.S# AMD S.SEX = 'FEMALE'

5. UPDATE SC 
	SET SCORE = '60'
	WHERE SC.SCORE < '60' AND SC.C# = C.C# AND C.CNAME = 'MATH'

6. UPDATE SC
	SET SCORE = SCORE *1.05
	WHERE SC.S# = S.S# AND S.SEX = 'FEMALE' AND SC.S# IN (SELECT S#
															FROM SC
															WHERE SC.SCORE < (SELECT AVG(SCORE)
																				FROM SC))

7. UPDATE SC
	SET SCORE = SCORE * 1.05
	WHERE SC.C# = C.C# AND C.CNAME = 'C4' AND SC.SCORE < '70'

	UPDATE SC
	SET SCORE = SCORE * 1.04
	WHERE SC.C# = C.C# AND C.CNAME = 'C4' AND SC.SCORE > 70

	UPDATE SC
	CASE SC.SCORE
	WHEN SC.SCORE > 70 THEN SET SC.SCORE = SC.SCORE * 1.04
	WHEN SC.SCORE < 70 THEN SET SC.SCORE = SC.SCORE * 1.05

8. UPDATE SC
	SET SC.SCORE = SC.SCORE * 1.05
	WHEN SC.SCORE < (SELECT AVG(SCORE)
						FROM SC)

