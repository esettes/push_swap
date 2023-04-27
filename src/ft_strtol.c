#include <errno.h>
#include "push_swap.h"

t_stol	set_cut_strol(int is_neg, int base);
void	loop_str(const char *p, const char **endp, t_stol *sl, char **endptr);
long	return_strtol_val(t_stol sl);

long ft_strtol(const char *nptr, char **endptr, int base)
{
	const char	*p;
	const char	*endp;
	t_stol		sl;

	p = nptr;
	endp = nptr;
	sl.n = 0;
	sl.is_neg = 0;
	sl.overflow = 0;
	while (ft_isspace(*p))
		p++;
	if (*p == '+')
		p++;
	else if (*p == '-')
	{
		sl.is_neg = 1;
		p++;
	}
	sl = set_cut_strol(sl.is_neg, base);
	loop_str(p, &endp, &sl, endptr);
	if (endptr)
		*endptr = (char *)endp;
	return (return_strtol_val(sl));
}

long	return_strtol_val(t_stol sl)
{
	if (sl.overflow)
	{
		if (sl.is_neg)
			return (LONG_MIN);
		return (LONG_MAX);
	}
	if (sl.is_neg)
		return (-sl.n);
	return (sl.n);
}

void	loop_str(const char *p, const char **endp, t_stol *sl, char **endptr)
{
	while (1)
	{
		printf("*p: %s \n", *p);
		if (*p <= '9')
		{
			sl->c = *p - '0';
			printf("sl->c: %i \n", sl->c);
		}
		else
			break;
		if (sl->c < 0 || sl->c >= 10)
			break;
		*endp = ++p;
		if (sl->overflow)
		{
			if (endptr)
				continue;
			break;
		}
		if (sl->n > sl->cutoff || (sl->n == sl->cutoff && sl->c > sl->cutlim))
		{
			sl->overflow = 1;
			continue;
		}
		sl->n = sl->n * 10 + sl->c;
	}
}

t_stol	set_cut_strol(int is_neg, int base)
{
	t_stol	sl;

	if (is_neg)
	{
		sl.cutoff = -(LONG_MIN / base);
		sl.cutlim = -(LONG_MIN % base);
	}
	else
	{
		sl.cutoff = LONG_MIN / base;
		sl.cutlim = LONG_MIN % base;
	}
	return (sl);
}