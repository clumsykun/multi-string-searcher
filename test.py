from pprint import pprint
import _catdict
import json

d = _catdict._CatDict()

def func_version():
    _catdict.version()


def _catdict_str_set():
    print('Test of CatDict.str.assign()')
    d.str.assign('key', 'string 1.')

    try:
        d.str.assign('a', 1)
    except TypeError as e:
        print('-->', e)

    d.str.assign(2, 'string 2')
    print('--> OK')


def _catdict_str_get():
    print('Test of CatDict.str.access()')

    d.str.assign('k', 'This is some long string!')
    assert isinstance(d.str.access('k'), str)
    assert d.str.access('k') == 'This is some long string!'

    d.str.access('k')
    d.str.access('k')
    d.str.access('k')
    print('--> OK')


def _catdict_bool_set():
    print('Test of CatDict.bool.assign()')
    d.bool.assign('key', True)

    try:
        d.bool.assign('a', 'something')
    except TypeError as e:
        print('-->', e)

    d.bool.assign(2, 2)
    print('--> OK')


def _catdict_bool_get():
    print('Test of CatDict.bool.access()')

    d.bool.assign('k', 1)
    assert isinstance(d.bool.access('k'), bool)
    assert d.bool.access('k') == 1

    print('--> OK')


def _catdict_int_set():
    print('Test of CatDict.int.assign()')
    d.int.assign('a', 1)

    try:
        d.int.assign('key', 'string')
    except TypeError as e:
        print('-->', e)

    d.int.assign(1, 1)
    print('--> OK')


def _catdict_int_get():
    print('Test of CatDict.int.access()')

    d.int.assign('k', 1)
    assert isinstance(d.int.access('k'), int)
    assert d.int.access('k') == 1

    print('--> OK')


def _catdict_float_set():
    print('Test of CatDict.float.assign()')
    d.float.assign('a', 1)

    try:
        d.float.assign('key', 'string')
    except TypeError as e:
        print('-->', e)

    d.float.assign(1, 3.14)
    print('--> OK')


def _catdict_float_get():
    print('Test of CatDict.float.access()')

    d.float.assign('k', 1)
    assert isinstance(d.float.access('k'), float)
    assert d.float.access('k') == 1

    print('--> OK')


def _catdict_list_set():
    print('Test of CatDict.list.assign()')
    d.list.assign('key', [])

    try:
        d.list.assign('a', 1)
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_list_get():
    print('Test of CatDict.list.access()')

    d.list.assign('k', [])
    assert isinstance(d.list.access('k'), list)

    d.list.access('k').append(1)
    assert d.list.access('k')[0] == 1

    print('--> OK')


def _catdict_tuple_set():
    print('Test of CatDict.tuple.assign()')
    d.tuple.assign('key', (1,))

    try:
        d.tuple.assign('a', 1)
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_tuple_get():
    print('Test of CatDict.tuple.access()')

    d.tuple.assign('k', ('red prince',))
    assert isinstance(d.tuple.access('k'), tuple)

    d.tuple.access('k')
    assert d.tuple.access('k')[0] == 'red prince'

    print('--> OK')


def _catdict_dict_set():
    print('Test of CatDict.dict.assign()')
    d.dict.assign('key', {"a": 1})

    try:
        d.dict.assign('a', 1)
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_dict_get():
    print('Test of CatDict.dict.access()')

    d.dict.assign('k', {"k": "v"})
    assert isinstance(d.dict.access('k'), dict)

    d.dict.access('k')
    assert d.dict.access('k')['k'] == 'v'

    print('--> OK')

def _catdict_set_set():
    print('Test of CatDict.set.assign()')
    d.set.assign('key', set())

    try:
        d.set.assign('a', [])
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def _catdict_set_get():
    print('Test of CatDict.set.access()')

    d.set.assign('k', set())
    assert isinstance(d.set.access('k'), set)

    d.set.access('k').add(1)
    assert d.set.access('k') == set([1])

    print('--> OK')


def _catdict_to_dict():
    print('Test of CatDict.to_dict()')
    dict_of_database = d.to_dict()
    dict_of_database = d.to_dict()
    dict_of_database = d.to_dict()
    print(dict_of_database.__class__)
    pprint(dict_of_database)


def _catdict_status():
    d.status()


def run():
    func_version()
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
    _catdict_to_dict()
    _catdict_status()


if __name__ == '__main__':
    run()
