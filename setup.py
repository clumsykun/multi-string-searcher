from setuptools import setup, Extension, find_packages

catdict = Extension(
    'catdict',
    sources = [
        'catdict/src/catdict_module.c',
        'catdict/src/catdict.c',
        'catdict/src/cd_long.c',
        'catdict/src/cd_unicode.c',
        'catdict/src/cd_list.c',
        'catdict/src/cd_set.c',
        'catdict/src/cd_float.c',
    ],
    include_dirs = ['catdict/include'],
)

setup(
    name         = 'catdict',
    version      = '0.4',
    packages     = find_packages(),
    ext_modules  = [catdict],
    description  = 'Python package providing categorical Dict class.',
    author       = 'Zhao Kunwang',
    author_email = 'clumsykundev@gmail.com',
    url          = 'https://github.com/clumsykun/catdict',
    include_package_data = True,
)
