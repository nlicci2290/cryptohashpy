# cryptohashpy
Commonly used hash functions

## Installation
Use the setup.py script to install this C extension.

```bash
python setup.py install
```

## Usage

```python
import cryptohashpy

cryptohashpy.md5(b'word') # returns 'C47D187067C6CF953245F128B5FDE62A'
```

## Supported environments
This C extension module is supported in both python 2 and 3 on Linux and Windows. 
Module was tested on Windows 10 and CentOS 7.

## License
[MIT](https://choosealicense.com/licenses/mit/)
