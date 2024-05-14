# mirte-master-simulator
> A package to simulate the Mirte Master Robot.

This packaged is structered as the [mirte-gazebo](https://github.com/ArendJan/mirte-gazebo/tree/rsp) Repository.

## Install
```
git clone git@github.com:diebolo/mirte-master-simulator.git
cd mirte-master-simulator
git submodule update --init --recursive
rosdep install --from-paths src --ignore-src -r -y
```

## Setup notes
 - Use the patched version of [RidgeBack control](https://github.com/ArendJan/ridgeback/tree/melodic-devel)