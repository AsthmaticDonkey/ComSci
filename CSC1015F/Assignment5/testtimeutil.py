#testtimeutil.py
#Myrin Naidoo
#NDXMYR001
"""
>>> import timeutil

>>> timeutil.validate("1111 am")
False
>>> timeutil.validate("111:00 am")
False
>>> timeutil.validate(":00 am")
False
>>> timeutil.validate("AA:00 am")
False
>>> timeutil.validate("11:11 AA")
False
>>> timeutil.validate("11:11am")
False
>>> timeutil.validate("11:111 am")
False
>>> timeutil.validate("11:AA am")
False
>>> timeutil.validate("11:-1 am")
False
>>> timeutil.validate("13:11 am")
False
>>> timeutil.validate("11:61 am")
False
>>> timeutil.validate("11:11 am")
True
>>> timeutil.validate("11:11 pm")
True

"""
import doctest
doctest.testmod(verbose=True)