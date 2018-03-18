# -*- coding: utf-8 -*-

import urllib.request
import urllib.parse

request = urllib.request.Request('http://blog.csdn.net/du3921101')
try:
    urllib.request.urlopen(request)
except urllib.request.HTTPError as e:
    print(e.code)
    if hasattr(e, "reason"):
        print(e.reason)
except urllib.request.URLError as e:
    print(e.reason)
else:
    print('ok')
    
