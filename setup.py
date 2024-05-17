from setuptools import setup, Extension, find_packages

_catdict = Extension(
    'catdict.mss',
    sources = [
        'catdict/src/module.c',
        'catdict/src/searcher.c',
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
