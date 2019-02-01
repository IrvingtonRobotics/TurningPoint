# VEX Turning Point Code
**Team 44730A Bluescreens**


## Control Mapping

### Primary Joystick
| Joystick Channel | Position | Description |
|-----------|------|-----------|
| `Ch3` | Vertical of left joystick | Left drive control |
| `Ch2` | Vertical of right joystick | Right drive control |
| `Btn6U` | Upper button on back right | Raise conveyor |
| `Btn6D` | Bottom button on back down | Lower conveyor |

### Secondary Joystick
| Joystick Channel | Position | Description |
|-----------|------|------------|
| `Btn7UXmtr2` | Upper button on front left | Switch to flywheel high flag mode |
| `Btn7DXmtr2` | Lower button on front left | Switch to flywheel middle flag mode |
| `Btn8UXmtr2` | Upper button on front right | **Hold** to spin up flywheel to distance 1 |
| `Btn8LXmtr2` | Left button on front right | **Hold** to spin up flywheel to distance 2 |
| `Btn8DXmtr2` | Down button on front right | **Hold** to spin up flywheel to distance 3 |
| `Btn8RXmtr2` | Right button on front right | **Hold** to spin up flywheel to distance 4 |

## Wiring

### Sensors
| Sensor Port | Name | Type of Sensor | Function |
|-------------|------|----------------|----------|
| digital1 | `leftEncoder` | Shaft Encoder | Encoder for left drive side |
| digital3 | `rightEncoder` | Shaft Encoder | Encoder for right drive side |

### Motors 
| Motor Port | Motor Name | Function |
|-------------|------|----------|
| 1 | `flywheelLeft` | Left flywheel motor |
| 4 | `driveLeftFront` | Left front drive motor |
| 5 | `driveLeftBack` | Left back drive motor |
| 6 | `driveRightFront` | Right front drive motor |
| 7 | `driveRightBack` | Right back drive motor |
| 9 | `conveyor` | Conveyor motor |
| 10 | `flywheelRight` | Right flywheel motor |
