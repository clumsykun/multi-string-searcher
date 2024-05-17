from setuptools import setup, Extension, find_packages

_catdict = Extension(
    'mss.mss',
    sources = [
        'mss/src/module.c',
        'mss/src/searcher.c',
    ],
    include_dirs = ['mss/include'],
)

setup(
    name         = 'mss',
    version      = '0.0.1',
    packages     = find_packages(),
    ext_modules  = [_catdict],
    description  = 'Multi-string searcher.',
    author       = 'Zhao Kunwang',
    author_email = 'clumsykun@qq.com',
    url          = 'https://github.com/clumsykun/multi-string-searcher',
    include_package_data = True,
)
