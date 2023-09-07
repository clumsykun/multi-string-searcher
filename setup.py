from setuptools import setup, Extension, find_packages

_catdict = Extension(
    'catdict.ext',
    sources = [
        'catdict/src/dtypes.c',
        'catdict/src/cd_unicode.c',
        'catdict/src/cd_bool.c',
        'catdict/src/cd_long.c',
        'catdict/src/cd_float.c',
        'catdict/src/cd_list.c',
        'catdict/src/cd_tuple.c',
        'catdict/src/cd_dict.c',
        'catdict/src/cd_set.c',
        'catdict/src/catdict.c',
        'catdict/src/catdict_ext.c',
    ],
    include_dirs = ['catdict/include'],
)

setup(
    name         = 'catdict',
    version      = '0.4.3',
    packages     = find_packages(),
    ext_modules  = [_catdict],
    description  = 'Python package providing categorical dict class.',
    author       = 'Zhao Kunwang',
    author_email = 'clumsykundev@gmail.com',
    url          = 'https://github.com/clumsykun/catdict',
    include_package_data = True,
)
