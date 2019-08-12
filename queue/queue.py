class Queue:

    def __init__(self):
        self._queue = []

    @property
    def length(self):
        return len(self._queue)

    def get(self):
        ret = None
        if len(self._queue) != 0:
            ret = self._queue.pop(0)
        return ret

    def put(self, value):
        self._queue.append(value)
