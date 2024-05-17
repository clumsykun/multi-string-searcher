from typing import Iterable

class Searcher:
    pass

    @property
    def num_targets(self) -> None:
        ...

    def add_target(self, target: str) -> None:
        ...

    def extend_targets(self, iterable: Iterable[str]) -> None:
        ...
