from pprint import pprint
import catdict

d = catdict.CatDict()


def func_version():
    catdict.version()


def catdict_iSet():
    print('Test of CatDict.iSet()')
    d.iSet('a', 1)

    try:
        d.iSet('key', 'string')
    except TypeError as e:
        print('-->', e)

    d.iSet(1, 1)
    print('--> OK')


def catdict_iGet():
    print('Test of CatDict.iGet()')

    d.iSet('k', 1)
    assert isinstance(d.iGet('k'), int)
    assert d.iGet('k') == 1

    print('--> OK')


def catdict_fSet():
    print('Test of CatDict.fSet()')
    d.fSet('a', 1)

    try:
        d.fSet('key', 'string')
    except TypeError as e:
        print('-->', e)

    d.fSet(1, 3.14)
    print('--> OK')


def catdict_fGet():
    print('Test of CatDict.fGet()')

    d.fSet('k', 1)
    assert isinstance(d.fGet('k'), float)
    assert d.fGet('k') == 1

    print('--> OK')


def catdict_uSet():
    print('Test of CatDict.uSet()')
    d.uSet('key', 'string 1.')

    try:
        d.uSet('a', 1)
    except TypeError as e:
        print('-->', e)

    d.uSet(2, 'string 2')
    print('--> OK')


def catdict_uGet():
    print('Test of CatDict.uGet()')

    d.uSet('k', 'This is some long string!')
    assert isinstance(d.uGet('k'), str)
    assert d.uGet('k') == 'This is some long string!'

    d.uGet('k')
    d.uGet('k')
    d.uGet('k')
    print('--> OK')


def catdict_lSet():
    print('Test of CatDict.lSet()')
    d.lSet('key', [])

    try:
        d.lSet('a', 1)
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def catdict_lGet():
    print('Test of CatDict.lGet()')

    d.lSet('k', [])
    assert isinstance(d.lGet('k'), list)

    d.lGet('k').append(1)
    assert d.lGet('k')[0] == 1

    print('--> OK')


def catdict_sSet():
    print('Test of CatDict.sSet()')
    d.sSet('key', set())

    try:
        d.sSet('a', [])
    except TypeError as e:
        print('-->', e)

    print('--> OK')


def catdict_sGet():
    print('Test of CatDict.sGet()')

    d.sSet('k', set())
    assert isinstance(d.sGet('k'), set)

    d.sGet('k').add(1)
    assert d.sGet('k') == set([1])

    print('--> OK')


def catdict_as_dict():
    print('Test of CatDict.as_dict()')
    dict_of_database = d.as_dict()
    print(dict_of_database.__class__)
    pprint(dict_of_database)


def catdict_display():
    d.display()


def run():
    func_version()
    catdict_iSet()
    catdict_iGet()
    catdict_fSet()
    catdict_fGet()
    catdict_uSet()
    catdict_uGet()
    catdict_lSet()
    catdict_lGet()
    catdict_sSet()
    catdict_sGet()
    catdict_as_dict()
    catdict_display()


if __name__ == '__main__':
    run()
