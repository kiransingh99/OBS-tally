import enum
import serial
import time

class Events(enum.IntEnum):
    NONE = 0
    STREAMING = 1
    RECORDING = 2
    STREAMING_AND_RECORDING = 3

    def start_streaming(self):
        if self is Events.NONE:
            new_state = Events.STREAMING
        elif self is Events.RECORDING:
            new_state = Events.STREAMING_AND_RECORDING
        else:
            # Already in a streaming state.
            new_state = self
        return new_state

    def stop_streaming(self):
        if self is Events.STREAMING:
            new_state = Events.NONE
        elif self is Events.STREAMING_AND_RECORDING:
            new_state = Events.RECORDING
        else:
            # Already not in a streaming state.
            new_state = self
        return new_state

    def start_recording(self):
        if self is Events.NONE:
            new_state = Events.RECORDING
        elif self is Events.STREAMING:
            new_state = Events.STREAMING_AND_RECORDING
        else:
            # Already in a recording state.
            new_state = self
        return new_state

    def stop_recording(self):
        if self is Events.RECORDING:
            new_state = Events.NONE
        elif self is Events.STREAMING_AND_RECORDING:
            new_state = Events.STREAMING
        else:
            # Already not in a recording state.
            new_state = self
        return new_state

s = serial.Serial(port="COM5", baudrate=9600)

while True: # stream record
    state = Events.NONE # 0 0
    for i in range(5):
        s.write(str(state.value).encode("utf-8)"))
        print(str(state.value).encode("utf-8)"), state)
        time.sleep(0.5)
    state = state.start_recording() # 0 1
    for i in range(5):
        s.write(str(state.value).encode("utf-8)"))
        print(str(state.value).encode("utf-8)"), state)
        time.sleep(0.5)
    state = state.start_streaming() # 1 1
    for i in range(5):
        s.write(str(state.value).encode("utf-8)"))
        print(str(state.value).encode("utf-8)"), state)
        time.sleep(0.5)
    state = state.stop_recording() # 1 0
    for i in range(5):
        s.write(str(state.value).encode("utf-8)"))
        print(str(state.value).encode("utf-8)"), state)
        time.sleep(0.5)
    state = state.stop_streaming() # 0 0
    for i in range(5):
        s.write(str(state.value).encode("utf-8)"))
        print(str(state.value).encode("utf-8)"), state)
        time.sleep(0.5)