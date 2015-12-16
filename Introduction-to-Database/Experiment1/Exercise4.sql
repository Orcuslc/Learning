use mydb;

select class.cname
	from class
	where class.c in (select selectclass.c
				from selectclass
                where s in (select student.s
							from student
                            where student.sname = 'daerf'));
						
select *
from student
where student.s in (select selectclass.s
					from selectclass, class
                    where selectclass.c = class.c and class.cname = 'dasf')
order by student.s;

