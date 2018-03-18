# -*- coding: utf-8 -*-

import string

# https://pymotw.com/3/

s = 'The quick brown fox jumped over the lazy dog.'
#print(s)
#print(string.capwords(s))
# The quick brown fox jumped over the lazy dog.
# The Quick Brown Fox Jumped Over The Lazy Dog.


# string_template
values = {'var': 'foo'}
t = string.Template("""
Variable        : $var
Escape          : $$
Variable in text: ${var}iable
""")
print('TEMPLATE:', t.substitute(values))

tp = """
Variable        : %(var)s
Escape          : %%
Variable in text: %(var)siable
"""
print('NTERPOLATION:', tp % values)

tp = """
Variable        : {var}
Escape          : {{}}
Variable in text: {var}iable
"""
print('FORMAT:', tp.format(**values))

# TEMPLATE: 
# Variable        : foo
# Escape          : $
# Variable in text: fooiable
# 
# NTERPOLATION: 
# Variable        : foo
# Escape          : %
# Variable in text: fooiable
# 
# FORMAT: 
# Variable        : foo
# Escape          : {}
# Variable in text: fooiable

tpsafe = string.Template("$var is here but $missing is not provided")
try:
    print('substitute()    :', tpsafe.substitute(values))
except KeyError as err:
    print('ERROR:', str(err))

print('safe_substitute():', tpsafe.safe_substitute(values))
# ERROR: 'missing'
# safe_substitute(): foo is here but $missing is not provided


# string_template_advanced
class MyTemplate(string.Template):
    delimiter = '%'
    idpattern = '[a-z]+_[a-z]+'

template_text = '''
  Delimiter : %%
  Replaced  : %with_underscore
  Ignored   : %notunderscored
'''

d = {
    'with_underscore': 'replaced',
    'notunderscored': 'not replaced',
}

t = MyTemplate(template_text)
print('Modified ID pattern:')
print(t.safe_substitute(d))

# Modified ID pattern:
# 
#   Delimiter : %
#   Replaced  : replaced
#   Ignored   : %notunderscored
