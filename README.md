# VEX Turning Point Code
**Team 44730A Bluescreens**


## Control Mapping

### Primary Joystick
| Joystick Channel | Position | Description |
|-----------|------|-----------|
| `Ch3` | Vertical axis of left joystick | Left drive control |
| `Ch2` | Vertical axis of right joystick | Right drive control |
| `Btn5U` | Upper button on back left | Start to spin roller for flip |
| `Btn5D` | Lower button on back left | Start to spin roller for suck |

### Secondary Joystick
| Joystick Channel | Position | Description |
|-----------|------|------------|
| `Btn5UXmtr2` | Upper button on back right | Raise conveyor |
| `Btn5DXmtr2` | Bottom button on back down | Lower conveyor |
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
| 1 | `flipper` | Flipper motor |
| 2 | `flywheelLeft` | Left flywheel motor |
| 3 | `driveLeftFront` | Left front drive motor |
| 4 | `driveLeftMiddle` | Left middle drive motor |
| 5 | `driveLeftBack` | Left back drive motor |
| 6 | `driveRightFront` | Right front drive motor |
| 7 | `driveRightMiddle` | Right middle drive motor |
| 8 | `driveRightBack` | Right back drive motor |
| 9 | `flywheelRight` | Right flywheel motor |
| 10 | `conveyor` | Conveyor motor |
