# cryptohashpy
A python C extension module containing commonly used hash functions.

## Installation
Use the setup.py script to install this C extension.

```bash
python setup.py install
```

## Running the tests
The unit tests are run with pytest.

Navigate to the cryptohash folder and run the md5_unit_test.py file
```bash
pytest md5_unit_test.py
```

## Usage

```python
import cryptohashpy

cryptohashpy.md5(b'word') # returns 'C47D187067C6CF953245F128B5FDE62A'
```

## Built With
* Tools installed with Visual Studio 2019
* gcc 4.8


## Supported environments
This C extension module is supported in both python 2 and 3 on Linux and Windows. 
Module was tested on Windows 10 and CentOS 7.

## License
[MIT](https://choosealicense.com/licenses/mit/)
