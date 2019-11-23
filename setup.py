from setuptools import setup, Extension
from platform import platform

macros = []

if "Windows" in platform():
    macros.append(("WIN32", "1"))

SOURCE_DIR = "cryptohash/source/"

ext_modules = [ 
    Extension('cryptohashpy', 
              [ SOURCE_DIR + 'main_cryptohash.c', SOURCE_DIR +  "md5/md5.c",  SOURCE_DIR +  "md5/md5_py.c"],  
                include_dirs = [ 'cryptohash/include' ],
                define_macros = macros) 
]

setup(name='cryptohashpy', version='1.0', ext_modules = ext_modules)
