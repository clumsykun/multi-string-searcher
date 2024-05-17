from setuptools import setup, Extension, find_packages

_mss = Extension(
    'mss._mss',
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
    ext_modules  = [_mss],
    description  = 'Multi-string searcher.',
    author       = 'Zhao Kunwang',
    author_email = 'clumsykun@qq.com',
    url          = 'https://github.com/clumsykun/multi-string-searcher',
    include_package_data = True,
)
