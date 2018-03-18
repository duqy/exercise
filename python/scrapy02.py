# -*- coding: utf-8 -*-

import urllib.parse
import urllib.request

# header
# F12，打开网络监听，登录知乎，分好多次请求，先加载HTML，再加载JS,CSS等
# User-Agent : 有些服务器或 Proxy 会通过该值来判断是否是浏览器发出的请求
# Content-Type : 在使用 REST 接口时，服务器会检查该值，用来确定 HTTP Body 中的内容该怎样解析。
# application/xml ： 在 XML RPC，如 RESTful/SOAP 调用时使用
# application/json ： 在 JSON RPC 调用时使用
# application/x-www-form-urlencoded ： 浏览器提交 Web 表单时使用
# 在使用服务器提供的 RESTful 或 SOAP 服务时， Content-Type 设置错误会导致服务器拒绝服务

# url = "https://passport.csdn.net/account/login?from=http://my.csdn.net/my/mycsdn"
# values = {"username": "du392110851", "password": "daejanggeum0958"}
# data = urllib.parse.urlencode(values).encode('utf-8')
# headers = { 'User-Agent' : 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'  ,
#                         'Referer':'http://www.zhihu.com/articles' } 
# request = urllib.request.Request(url, data, headers)
# response = urllib.request.urlopen(request, timeout=10)
# page = response.read()

# Proxy
# enable_proxy = True
# proxy_handler = urllib.request.ProxyHandler({"http": 'http://some-proxy.com:8080'})
# null_proxy_handler = urllib.request.ProxyHandler({})
# if enable_proxy:
#     opener = urllib.request.build_opener(proxy_handler)
# else:
#     opener = urllib.request.build_opener(null_proxy_handler)
#   
# urllib.request.install_opener(opener)

# http协议有六种请求方法，get,head,put,delete,post,options
# PUT：HTML表单不支持这个。本质上来讲， PUT和POST极为相似，都是向服务器发送数据，但它们之间有一个重要区别，PUT通常指定了资源的存放位置，而POST则没有，POST的数据存放位置由服务器自己决定。
# DELETE：删除某一个资源。基本上这个也很少见，不过还是有一些地方比如amazon的S3云服务里面就用的这个方法来删除资源。
# 如果要使用 HTTP PUT 和 DELETE ，只能使用比较低层的 httplib 库。通过下面的方式，使 urllib2 能够发出 PUT 或DELETE 的请求
# request = urllib.request.Request(url, data)
# request.get_method = lambda: 'PUT'  # or DELETE
# response = urllib.request.urlopen(request)

# DebugLog
httpHandler = urllib.request.HTTPHandler(debuglevel=1)
httpsHandler = urllib.request.HTTPSHandler(debuglevel=1)
opener = urllib.request.build_opener(httpHandler, httpsHandler)
urllib.request.install_opener(opener)
response = urllib.request.urlopen('http://www.baidu.com')



