# coding: UTF-8
from urllib.request import urlopen
from json import loads
from os import listdir


res = urlopen('https://leetcode-cn.com/api/problems/all/')
result = res.read().decode('utf-8')

problems = loads(result)['stat_status_pairs']

# {
#     'stat': {
#         'question_id': 1, 'question__title': 'Two Sum', 'question__title_slug': 'two-sum', 'question__hide': False,
#           'total_acs': 2013259, 'total_submitted': 3944650, 'total_column_articles': 12147, 'frontend_question_id': '1',
#           'is_new_question': False
#     },
#     'status': None,
#     'difficulty': {'level': 1},
#     'paid_only': False,
#     'is_favor': False,
#     'frequency': 0,
#     'progress': 0
#  }

# 去除问题的难度信息
problems_without_level_list = [it['stat'] for it in problems]
# 按问题id排序
problems_without_level_list.sort(key=lambda i: i['question_id'])

print(problems_without_level_list)

# 读取答案文件
codes = listdir('./codes/')
# 将答案文件转为 {文件名: 文件后缀}
codes_dict = {}
for code in codes:
    codes_dict[code.split('.')[0]] = code.split('.')[1]

# 生成md
base_url = 'https://leetcode-cn.com/problems/'

readme = open('./README.md', 'w', encoding="utf-8")
readme.write('# LeetCode\n\n')

for problems_without_level in problems_without_level_list:
    if codes_dict.__contains__(problems_without_level['frontend_question_id']):
        readme.write('{0}. [{1} - {2}]({3}) : [code](./codes/{4})\n'.format(problems_without_level['question_id'],
                                                           problems_without_level['frontend_question_id'],
                                                           problems_without_level['question__title'],
                                                           base_url + problems_without_level['question__title_slug'],
                                                           problems_without_level['frontend_question_id'] + '.' + codes_dict[problems_without_level['frontend_question_id']]))
    if codes_dict.__contains__(problems_without_level['question__title_slug']):
        readme.write('{0}. [{1} - {2}]({3}) : [code](./codes/{4})\n'.format(problems_without_level['question_id'],
                                                           problems_without_level['frontend_question_id'],
                                                           problems_without_level['question__title'],
                                                           base_url + problems_without_level['question__title_slug'],
                                                           problems_without_level['question__title_slug'] + '.' + codes_dict[problems_without_level['question__title_slug']]))
