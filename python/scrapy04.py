# -*- coding: utf-8 -*-

import urllib.request
import urllib.parse
import http.cookiejar

# Cookie
# cookielib模块的主要作用是提供可存储cookie的对象
# 该模块主要的对象有CookieJar、FileCookieJar、MozillaCookieJar、LWPCookieJar
# CookieJar —-派生—->FileCookieJar  —-派生—–>MozillaCookieJar和LWPCookieJar

# cookie = http.cookiejar.CookieJar()
# handler = urllib.request.HTTPCookieProcessor(cookie)
# opener = urllib.request.build_opener(handler)
# response = opener.open('http://www.baidu.com')
# for item in cookie:
#     print('Name = '+ item.name)
#     print('Value = '+ item.value)

# 保存到文件
# filename = 'cookie.txt'
# cookie = http.cookiejar.MozillaCookieJar(filename)
# handler = urllib.request.HTTPCookieProcessor(cookie)
# opener = urllib.request.build_opener(handler)
# response = opener.open('http://www.baidu.com')
# cookie.save(ignore_discard=True, ignore_expires=True)

# ignore_discard: save even cookies set to be discarded. 
# ignore_expires: save even cookies that have expired, The file is overwritten if it already exists


# 从文件中获取Cookie
# cookie = http.cookiejar.MozillaCookieJar()
# cookie.load('cookie.txt', ignore_discard=True, ignore_expires=True)
# req = urllib.request.Request('http://www.baidu.com')
# opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie))
# response = opener.open(req)
# print(response.read())

# 利用Cookie模拟网站登录
filename = 'cookie.txt'
cookie = http.cookiejar.MozillaCookieJar(filename)
opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie))
postdata = urllib.parse.urlencode({
    'stuid':'201200131012',
    'pwd':'23342321'
}).encode('utf-8')

loginUrl = 'http://jwxt.sdu.edu.cn:7890/pls/wwwbks/bks_login2.login'
result = opener.open(loginUrl, postdata)
cookie.save(ignore_discard=True, ignore_expires=True)
gradeUrl = 'http://jwxt.sdu.edu.cn:7890/pls/wwwbks/bkscjcx.curscopre'
result = opener.open(gradeUrl)
print(result.read())
