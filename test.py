from pprint import pprint
import json
import catdict
from catdict import _

d = catdict.CatDict()


def tmp():
    print(catdict.ext)


def func_version():
    catdict.version()


def _catdict_str_set():
    print('Test of CatDict.str')
    d.str['key'] = 'string 1.'

    try:
        d.str['a'] = 1
    except TypeError as e:
        print('-->', e)

    d.str[2] = 'string 2'
    print('--> OK')


def _catdict_str_get():
    print('Test of CatDict.str')

    d.str['k'] = 'This is some long string!'
    assert isinstance(d.str['k'], str)
    assert d.str['k'] == 'This is some long string!'

    d.str['k']
    d.str['k']
    d.str['k']
    print('--> OK')


def _catdict_bool_set():
    print('Test of CatDict.bool')
    d.bool['key'] = True

    try:
        d.bool['a'] = 'something'
    except TypeError as e:
        print('-->', e)

    d.bool[2] = 2
    print('--> OK')


def _catdict_bool_get():
    print('Test of CatDict.bool')

    d.bool['k'] = 1
    assert isinstance(d.bool['k'], bool)
    assert d.bool['k'] == 1

    print('--> OK')


def _catdict_int_set():
    print('Test of CatDict.int')
    d.int['a'] = 1

    try:
        d.int['key'] = 'string'
    except TypeError as e:
        print('-->', e)

    d.int[1] = 1
    print('--> OK')


def _catdict_int_get():
    print('Test of CatDict.int')

    d.int['k'] = 1
    assert isinstance(d.int['k'], int)
    assert d.int['k'] == 1

    print('--> OK')


def _catdict_float_set():
    print('Test of CatDict.float')
    d.float['a'] = 1

    try:
        d.float['key'] = 'string'
    except TypeError as e:
        print('-->', e)

    d.float['pi'] = 3.14
    print('--> OK')


def _catdict_float_get():
    print('Test of CatDict.float')

    d.float['k'] = 1
    assert isinstance(d.float['k'], float)
    assert d.float['k'] == 1

    print('--> OK')


def _catdict_list_set():
    print('Test of CatDict.list')
    d.list['k'] = []

    try:
        d.list['a'] = 1
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_list_get():
    print('Test of CatDict.list')

    d.list['k'] = []
    assert isinstance(d.list['k'], list)

    d.list['k'].append(1)
    assert d.list['k'][0] == 1

    print('--> OK')


def _catdict_tuple_set():
    print('Test of CatDict.tuple')
    d.tuple['key'] = (1,)

    try:
        d.tuple['a'] = 1
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_tuple_get():
    print('Test of CatDict.tuple')

    d.tuple['k'] = ('red prince',)
    assert isinstance(d.tuple['k'], tuple)

    d.tuple['k']
    assert d.tuple['k'][0] == 'red prince'

    print('--> OK')


def _catdict_dict_set():
    print('Test of CatDict.dict')
    d.dict['key'] = {"a": 1}

    try:
        d.dict['a'] = 1
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_dict_get():
    print('Test of CatDict.dict')

    d.dict['k'] = {"k": "v"}
    pprint(d.to_dict())
    # assert isinstance(d.dict['k'], dict)

    d.dict['k']
    assert d.dict['k']['k'] == 'v'

    print('--> OK')


def _catdict_set_set():
    print('Test of CatDict.set')
    d.set['key'] = set()

    try:
        d.set['a'] = []
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_set_get():
    print('Test of CatDict.set')

    d.set['k'] = set()
    assert isinstance(d.set['k'], set)

    d.set['k'].add(1)
    assert d.set['k'] == set([1])

    print('--> OK')


def _catdict_keys():
    print(d.str.keys())
    print(d.bool.keys())
    print(d.int.keys())
    print(d.float.keys())
    print(d.list.keys())
    print(d.tuple.keys())
    print(d.dict.keys())
    print(d.set.keys())


def _catdict_to_dict():
    print('Test of CatDict.to_dict()')
    dict_of_database = d.to_dict()
    dict_of_database = d.to_dict()
    dict_of_database = d.to_dict()
    print(dict_of_database.__class__)
    pprint(dict_of_database)


def _catdict_status():
    d.status()


def _catdict_delete():
    print('Test of del')
    del d.tuple['k']


"""
    TODO:
        1. d.dict['ordered'][-1]['dn']
"""


def run():
    tmp()
    func_version()
    _catdict_keys()
    _catdict_str_set()
    _catdict_str_get()
    _catdict_bool_set()
    _catdict_bool_get()
    _catdict_int_set()
    _catdict_int_get()
    _catdict_float_set()
    _catdict_float_get()
    _catdict_list_set()
    _catdict_list_get()
    _catdict_tuple_set()
    _catdict_tuple_get()
    _catdict_dict_set()
    _catdict_dict_get()
    _catdict_set_set()
    _catdict_set_get()
    _catdict_keys()
    _catdict_delete()
    _catdict_to_dict()
    _catdict_status()


if __name__ == '__main__':
    run()
