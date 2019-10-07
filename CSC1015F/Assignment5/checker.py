# checker.py

def check(a, b):
    errors=0
    if a<25:
        errors=errors+3
    if b<25:
        errors=errors+2
    return errors