p = (4, 5)
x, y = p
print('x=%d, y=%d', x, y)

data = ['ACME', 50, 90.1, (2018, 3, 16)]
name, shares, price, date = data
print('%s, %d, %d, %s' % name, shares, price, date)
name, shares, price, (year, mon, day) = data
