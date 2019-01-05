# VEX Turning Point Code
**Team 44730A Bluescreens**


## Control Mapping

### Primary Joystick
| Joystick Channel | Position | Description |
|-----------|------|-----------|
| `Ch3` | Vertical of left joystick | Left drive control |
| `Ch2` | Vertical of right joystick | Right drive control |
| `Btn7U` | Upper button on front left | Flip claw |
| `Btn6U` | Upper button on back right | Raise conveyor |
| `Btn6D` | Bottom button on back down | Lower conveyor |

### Secondary Joystick
| Joystick Channel | Position | Description |
|-----------|------|------------|
| `Ch2Xmtr2` | Vertical of right joystick | Lift control |
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
| analog1 | `clawPot` | Potentiometer | Potentiometer for claw |
| analog2 | `liftLeftPot` | Potentiometer | Potentiometer for left lift side |
| analog3 | `liftRightPot` | Potentiometer | Potentiometer for right lift side |
| digital1 | `leftEncoder` | Shaft Encoder | Encoder for left drive side |
| digital3 | `rightEncoder` | Shaft Encoder | Encoder for right drive side |

### Motors 
| Motor Port | Motor Name | Function |
|-------------|------|----------|
| 1 | `flywheelLeft` | Left flywheel motor |
| 2 | `clawFlip` | Claw flip motor |
| 3 | `driveLeftFront` | Left front drive motor |
| 4 | `driveLeftBack` | Left back drive motor |
| 5 | `liftBottom` | Lift bottom motor |
| 6 | `liftTop` | Lift top motor |
| 7 | `driveRightFront` | Right front drive motor |
| 8 | `driveRightBack` | Right back drive motor |
| 9 | `conveyor` | Conveyor motor |
| 10 | `flywheelRight` | Right flywheel motor |
