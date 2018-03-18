# -*- coding: utf-8 -*-

# urllib
import urllib.parse
import urllib.request

# 方式一
#response = urllib.request.urlopen("http://www.ftchinese.com/channel/ce.html")
#print(response.read())
# response  <http.client.HTTPResponse object at 0x7f4d205c76a0> 

# 方式二，推荐
# 构造Request
#request = urllib.request.Request("http://www.ftchinese.com/channel/ce.html")
#response = urllib.request.urlopen(request)
#print(response.read())

# 模拟登录CSDN
# POST方式
values = {"username": "du392110851", "password": "daejanggeum0958"}
data = urllib.parse.urlencode(values).encode('utf-8')
url = "https://passport.csdn.net/account/login?from=http://my.csdn.net/my/mycsdn"
request = urllib.request.Request(url, data)
response = urllib.request.urlopen(request)
print(response.read())

# GET方式
values = {}
values['username'] = ""
values['password'] = ""
data = urllib.urlencode(values).encode("utf-8")
url = ""
geturl = url + "?" + data
request = urllib.request.Request(geturl)
response = urllib.request.urlopen(request)
print(response.read())
