
> **NOTICE**
> If you are upgrading you need to run the following commands:
> ```
> git clone
> git submodule upgrade --init
> cd ../.. # Be in '**_ws/' root of workspace
> rosdep install --from-paths src --ignore-src -r -y
> ```

# Version 1.2.0 (`mirte_master_description`)
The package has been split into `mirte_master_description` and `mirte_master_gazebo`.
`mirte_master_description` now only contains the robot description and only has depencies required for that (No RVIZ or gazebo) making it suitable for use on the Mirte Master itself. (You need to copy over a package form `gazebo_sensor_collection` as well, which has also been split)

The package `mirte_master_gazebo` contains all the depencies for Gazebo and RVIZ, with the launch files previously found in `mirte_master_description`.

Besure to follow the upgrade instructions above.

# Version 1.1.0
In short the driving has been greatly improved.
There are however some breaking changes listed below.


## Renamed frames
 - `base_link` -> `frame_link`
 - `base_footprint` -> `base_link`

## Gazebo internals
Replaced the locomotion controller with the `ridgeback_gazebo_plugins`, which is the Gazebo plugin corresponding to the controller the Mirte Master actually uses.

For this reason, the `mirte_master_velocity_limiter` package has been deprecated.
Likewise the use of `gazebo_mecanum_plugins` and the `kinematics_only` parameter.

## Robot description
The frames has been renamed as mentioned in the **Renamed Frames** section.
Furthermore the wheel frames, joints, transmissions and actuators have been renamed.

| Old name | New name |
|:--------:|:--------:|
| wheel_fl | wheel_left_front |
| wheel_fb | wheel_left_rear  |
| wheel_fr | wheel_right_front |
| wheel_rb | wheel_right_front |

Actuators are now called `**WHEELNAME**_actuator` instead of `wheel_acc_**LOC**`, same applies to the joints and transmissions (but with `joint` and `transmission` postfix respectively)
