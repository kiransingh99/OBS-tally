import enum
import obspython #pyright: ignore [reportMissingImports]
import serial

class _Events(enum.IntEnum):
    NONE = 0
    STREAMING = 1
    RECORDING = 2
    STREAMING_AND_RECORDING = 3

    def start_streaming(self):
        if self is self.NONE:
            new_state = self.STREAMING
        elif self is self.RECORDING:
            new_state = self.STREAMING_AND_RECORDING
        else:
            # Already in a streaming state.
            new_state = self
        return new_state

    def stop_streaming(self):
        if self is self.STREAMING:
            new_state = self.NONE
        elif self is self.STREAMING_AND_RECORDING:
            new_state = self.RECORDING
        else:
            # Already not in a streaming state.
            new_state = self
        return new_state

    def start_recording(self):
        if self is self.NONE:
            new_state = self.RECORDING
        elif self is self.STREAMING:
            new_state = self.STREAMING_AND_RECORDING
        else:
            # Already in a recording state.
            new_state = self
        return new_state

    def stop_recording(self):
        if self is self.RECORDING:
            new_state = self.NONE
        elif self is self.STREAMING_AND_RECORDING:
            new_state = self.STREAMING
        else:
            # Already not in a recording state.
            new_state = self
        return new_state

def frontend_event_handler(data):
    state = _Events.NONE

    if data == obspython.OBS_FRONTEND_EVENT_STREAMING_STARTING:
        print("streaming started")
        state = state.start_streaming()
    elif data == obspython.OBS_FRONTEND_EVENT_STREAMING_STOPPED:
        print("streaming stopped")
        state = state.stop_streaming()
    elif data == obspython.OBS_FRONTEND_EVENT_RECORDING_STARTING:
        print("recording started")
        state = state.start_recording()
    elif data == obspython.OBS_FRONTEND_EVENT_RECORDING_STOPPED:
        print("recording stopped")
        state = state.stop_recording()
    else:
        return

    _write_to_serial(state.value)

def script_update(settings):
    pass

def script_description():
	return "Turns on and off the tally light when streaming."

def _write_to_serial(msg):
    s.write(str(msg).encode("utf-8)"))

obspython.obs_frontend_add_event_callback(frontend_event_handler)
s = serial.Serial(port="COM5", baudrate=9600)
state = _Events.NONE