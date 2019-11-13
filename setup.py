from setuptools import setup, Extension

source_dir = "cryptohash/source/"

ext_modules = [ 
    Extension('cryptohashpy', 
              [ source_dir + 'main_cryptohash.c', source_dir +  "md5/md5.c",  source_dir +  "md5/md5_py.c"],  
              include_dirs = [ 'cryptohash/include' ]) 
]

setup(name='cryptohashpy', version='1.0', ext_modules = ext_modules)
