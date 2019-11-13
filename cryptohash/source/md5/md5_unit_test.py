import pytest
import cryptohashpy

def test_emptyhash():
    expectedOutput = "d41d8cd98f00b204e9800998ecf8427e"
    testInput = b""

    assert (expectedOutput == cryptohashpy.md5(testInput).lower())

def test_knownGoodHash():
    expectedOutput = "6f8db599de986fab7a21625b7916589c"
    testInput = b"test string"

    assert (expectedOutput == cryptohashpy.md5(testInput).lower())
