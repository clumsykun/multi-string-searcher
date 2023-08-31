from _catdict import _CatDict


class CatDict(_CatDict):

    def __init__(self):
        super().__init__()

    def status(self) -> None:
        super().status()

    def to_dict(self) -> dict:
        return super().to_dict()

    def assign(self, key: object, value: object) -> None:
        super().assign(key, value)

    def access(self, key: object) -> object:
        return super().access(key)

    @property
    def str(self):
        super().str
        return self

    @property
    def bool(self):
        super().bool
        return self

    @property
    def int(self):
        super().int
        return self

    @property
    def float(self):
        super().float
        return self

    @property
    def list(self):
        super().list
        return self

    @property
    def tuple(self):
        super().tuple
        return self

    @property
    def dict(self):
        super().dict
        return self

    @property
    def set(self):
        super().set
        return self
