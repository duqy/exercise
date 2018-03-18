# -*- coding: utf-8 -*-

# RE

import re

# pattern = re.compile(r'hello')
# 参数flag是匹配模式，取值可以使用按位或运算符’|’表示同时生效，比如re.I | re.M
# 如果在pattern生成时已经指明了flags，那么在下面的方法中就不需要传入这个参数了
# re.I(全拼：IGNORECASE): 忽略大小写（括号内是完整写法，下同）
# re.M(全拼：MULTILINE): 多行模式，改变'^'和'$'的行为
# re.S(全拼：DOTALL): 点任意匹配模式，改变'.'的行为
# re.L(全拼：LOCALE): 使预定字符类 \w \W \b \B \s \S 取决于当前区域设定
# re.U(全拼：UNICODE): 使预定字符类 \w \W \b \B \s \S \d \D 取决于unicode定义的字符属性
# re.X(全拼：VERBOSE): 详细模式。这个模式下正则表达式可以是多行，忽略空白字符，并可以加入注释。

# re.match(pattern, string[, flags])
# re.search(pattern, string[, flags])
# re.split(pattern, string[, maxsplit])
# re.findall(pattern, string[, flags])
# re.finditer(pattern, string[, flags])
# re.sub(pattern, repl, string[, count])
# re.subn(pattern, repl, string[, count])


# 将正则表达式编译成Pattern对象，r表示原生字符串
# pattern = re.compile(r'hello')
# 
# result1 = re.match(pattern, 'hello')
# result2 = re.match(pattern, 'helloo CQC!')
# result3 = re.match(pattern, 'helo CQC!')
# result4 = re.match(pattern, 'hello CQC!')
# 
# if result1:
#     print(result1.group())
# else:
#     print('1匹配失败')
# 
# if result2:
#     print(result2.group())
# else:
#     print('2匹配失败')
# 
# 
# if result3:
#     print(result3.group())
# else:
#     print('3匹配失败')
# 
# 
# if result4:
#     print(result4.group())
# else:
#     print('4匹配失败')

########################
#hello
#hello
#3匹配失败
#hello
########################

# Match对象
# 属性：
# 1.string: 匹配时使用的文本。
# 2.re: 匹配时使用的Pattern对象。
# 3.pos: 文本中正则表达式开始搜索的索引。值与Pattern.match()和Pattern.seach()方法的同名参数相同。
# 4.endpos: 文本中正则表达式结束搜索的索引。值与Pattern.match()和Pattern.seach()方法的同名参数相同。
# 5.lastindex: 最后一个被捕获的分组在文本中的索引。如果没有被捕获的分组，将为None。
# 6.lastgroup: 最后一个被捕获的分组的别名。如果这个分组没有别名或者没有被捕获的分组，将为None。
# 
# 方法：
# 1.group([group1, …]):
# 获得一个或多个分组截获的字符串；指定多个参数时将以元组形式返回。group1可以使用编号也可以使用别名；编号0代表整个匹配的子串；不填写参数时，返回group(0)；没有截获字符串的组返回None；截获了多次的组返回最后一次截获的子串。
# 2.groups([default]):
# 以元组形式返回全部分组截获的字符串。相当于调用group(1,2,…last)。default表示没有截获字符串的组以这个值替代，默认为None。
# 3.groupdict([default]):
# 返回以有别名的组的别名为键、以该组截获的子串为值的字典，没有别名的组不包含在内。default含义同上。
# 4.start([group]):
# 返回指定的组截获的子串在string中的起始索引（子串第一个字符的索引）。group默认值为0。
# 5.end([group]):
# 返回指定的组截获的子串在string中的结束索引（子串最后一个字符的索引+1）。group默认值为0。
# 6.span([group]):
# 返回(start(group), end(group))。
# 7.expand(template):
# 将匹配到的分组代入template中然后返回。template中可以使用\id或\g、\g引用分组，但不能使用编号0。\id与\g是等价的；但\10将被认为是第10个分组，如果你想表达\1之后是字符’0’，只能使用\g0。


# Match实例
# 匹配 单词+空格+单词+任意字符
# m = re.match(r'(\w+) (\w+)(?P<sign>.*)', 'hello world')

# print('m.string:', m.string)
# print('m.re:', m.re)
# print('m.pos:', m.pos)
# print('m.endpos:', m.endpos)
# print("m.lastindex:", m.lastindex)
# print("m.lastgroup:", m.lastgroup)
# print("m.group():", m.group())
# print("m.group(1,2):", m.group(1, 2))
# print("m.groups():", m.groups())
# print("m.groupdict():", m.groupdict())
# print("m.start(2):", m.start(2))
# print("m.end(2):", m.end(2))
# print("m.span(2):", m.span(2))
# print(r"m.expand(r'\g \g\g'):", m.expand(r'\2 \1\3'))

######## output ########
# m.string: hello world
# m.re: re.compile('(\\w+) (\\w+)(?P<sign>.*)')
# m.pos: 0
# m.endpos: 11
# m.lastindex: 3
# m.lastgroup: sign
# m.group(): hello world
# m.group(1,2): ('hello', 'world')
# m.groups(): ('hello', 'world', '')
# m.groupdict(): {'sign': ''}
# m.start(2): 6
# m.end(2): 11
# m.span(2): (6, 11)
# m.expand(r'\2 \1\3'): world hello



# re.search(pattern, string[, flags])
# match()只检测re是不是在string的开始位置匹配,match()只有在0位置匹配成功的话才有返回,如果不是开始位置匹配成功的话，match()就返回None
# search()会扫描整个string查找匹配
# pattern = re.compile(r'world')
# match = re.search(pattern, 'hello world!')
# if match:
#     print(match.group())

######## output ########
#world



# re.split(pattern, string[, maxsplit])
# 按照能够匹配的子串将string分割后返回列表。
# maxsplit用于指定最大分割次数，不指定将全部分割
#pattern = re.compile(r'\d+')
#print(re.split(pattern, 'one1two2three3four4'))

######## output ########
#['one', 'two', 'three', 'four', '']



# re.findall(pattern, string[, flags])
# 搜索string，以列表形式返回全部能匹配的子串
#pattern = re.compile(r'\d+')
#print(re.findall(pattern, 'one1two2three3four4'))

######## output ########
#['1', '2', '3', '4']



# re.finditer(pattern, string[, flags])
# 搜索string，返回一个顺序访问每一个匹配结果(Match对象)的迭代器
#pattern = re.compile(r'\d+')
#for m in re.finditer(pattern, 'one1two2three3four4'):
#    print(m.group())

######## output ########
# 1
# 2
# 3
# 4



# re.sub(pattern, repl, string[, count])
# 使用repl替换string中每一个匹配的子串后返回替换后的字符串。
# 当repl是一个字符串时，可以使用\id或\g、\g引用分组，但不能使用编号0。
# 当repl是一个方法时，这个方法应当只接受一个参数（Match对象），并返回一个字符串用于替换（返回的字符串中不能再引用分组）。
# count用于指定最多替换次数，不指定时全部替换

# pattern = re.compile(r'(\w+) (\w+)')
# s = 'i say, hello world!'
# 
# print(re.sub(pattern, r'\2 \1', s))
# 
# def func(m):
#     return m.group(1).title() + ' ' + m.group(2).title()
# 
# print(re.sub(pattern, func, s))

######## output ########
# say i, world hello!
# I Say, Hello World!


# re.subn(pattern, repl, string[, count])
# 返回 (sub(repl, string[, count]), 替换次数)

pattern = re.compile(r'(\w+) (\w+)')
s = 'i say, hello world!'

print(re.subn(pattern, r'\2 \1', s))

def func(n):
    return n.group(1).title() + ' ' + n.group(2).title()

print(re.subn(pattern, func, s))

######## output ########
#('say i, world hello!', 2)
#('I Say, Hello World!', 2)



# Python Re模块的另一种使用方式
# 通过pattern.match，pattern.search调用，这样调用便不用将pattern作为第一个参数传入了
# match(string[, pos[, endpos]]) | re.match(pattern, string[, flags])
# search(string[, pos[, endpos]]) | re.search(pattern, string[, flags])
# split(string[, maxsplit]) | re.split(pattern, string[, maxsplit])
# findall(string[, pos[, endpos]]) | re.findall(pattern, string[, flags])
# finditer(string[, pos[, endpos]]) | re.finditer(pattern, string[, flags])
# sub(repl, string[, count]) | re.sub(pattern, repl, string[, count])
# subn(repl, string[, count]) |re.sub(pattern, repl, string[, count])


