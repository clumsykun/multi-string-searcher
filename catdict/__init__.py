from .ext import _CatDict as _
from .ext import version


class CatDict(_):

    def __init__(self):
        super().__init__()

    def status(self) -> None:
        super().status()

    def to_dict(self) -> dict:
        return super().to_dict()
    
    def keys(self) -> list:
        return super().keys()

    def values(self) -> list:
        return super().values()

    @property
    def str(self):
        return super().str

    @property
    def bool(self):
        return super().bool

    @property
    def int(self):
        return super().int

    @property
    def float(self):
        return super().float

    @property
    def list(self):
        return super().list

    @property
    def tuple(self):
        return super().tuple

    @property
    def dict(self):
        return super().dict

    @property
    def set(self):
        return super().set
