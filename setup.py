from setuptools import setup, Extension

ext_modules = [ Extension('cryptohashpy', ['cryptohash/cryptohash.c', 'cryptohash/md5.c']) ]

setup(name='cryptohashpy', version='1.0', ext_modules = ext_modules)
