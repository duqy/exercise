# -*- coding: utf-8 -*-

def lookup(word):
    url = DICT_API.format(word=word, key=KEY)
    resp = urllib.urlopen(url)
    json_result = json.loads(resp.read())
    try:
        meanings = json_result['symbols'][0]['parts']
        sound = json_result['symbols'][0]['ph_am']
    except KeyError as e:
        print('\nWord not found, check your spelling?\n')
        return
    print(u'\n\033[1m\033[4m{word}\033[0m  /{sound}/\n'.format(word=word, sound=sound))
    for meaning in meanings:
        print(meaning['part'])
        for mean in meaning['means']:
            print('\t' + mean)
    print('\n')


'''
iciba 词典的API http://open.iciba.com/?c=api
申请 key 之后在文档页可以看到简短的介绍
通过访问http://dict-co.iciba.com/api/dictionary.php?w=go&key=********&type=json可以获取 json 格式的单词go的解释
Python标准库中的json模块可以用来解析json数据
urllib2模块可以用来发送HTTP网络请求
'''
