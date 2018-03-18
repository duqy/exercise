# -*- coding: utf-8 -*-

import urllib.request
import urllib.parse
import re

# 1.抓取糗事百科热门段子
# 2.过滤带有图片的段子
# 3.实现每按一次回车显示一个段子的发布时间，发布人，段子内容，点赞数

page = 1
url = 'https://www.qiushibaike.com/8hr/page/' + str(page)
user_agent = 'Mozilla/5.0 (X11; Linux x86_64…) Gecko/20100101 Firefox/58.0'
headers = {'User-Agent' : user_agent }

try:
    request = urllib.request.Request(url, headers = headers)
    response = urllib.request.urlopen(request)
    content = response.read().decode('utf-8')
    pattern = re.compile('<div.*?clearfix">.*?<h2>(.*?)</h2>.*?<span>(.*?)</span>.*?number">(.*?)</i>', re.S)
    items = re.findall(pattern, content)

    for item in items:
        haveImg = re.search("img", item[3])
        if not haveImg:
            print(item[0], item[1], item[2], item[4])
except urllib.request.URLError as e:
    if hasattr(e, "code"):
        print(e.code)
    if hasattr(e, "reason"):
        print(e.reason)

# UnicodeEncodeError: 'latin-1' codec can't encode character '\u2026'

# 1）.*? 是一个固定的搭配，.和*代表可以匹配任意无限多个字符，加上？表示使用非贪婪模式进行匹配，也就是我们会尽可能短地做匹配，以后我们还会大量用到 .*? 的搭配。
# 
# 2）(.*?)代表一个分组，在这个正则表达式中我们匹配了五个分组，在后面的遍历item中，item[0]就代表第一个(.*?)所指代的内容，item[1]就代表第二个(.*?)所指代的内容，以此类推。
# 
# 3）re.S 标志代表在匹配时为点任意匹配模式，点 . 也可以代表换行符
