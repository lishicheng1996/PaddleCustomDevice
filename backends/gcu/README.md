# PaddlePaddle Custom Device Implementation for Enflame GCU

English | [简体中文](./README_cn.md)

Please refer to the following steps to compile, install and verify the hardware backend (GCU).

## Prepare environment and source code

```bash
# 1) Pull PaddlePaddle development docker image，and install Enflame GCU development kit.

# 2) Clone the source code.
git clone https://github.com/PaddlePaddle/PaddleCustomDevice
cd PaddleCustomDevice
```

## PaddleCustomDevice Installation and Verification

### Source code compilation and installation

```bash
# 1) Enter the hardware backend (Enflame GCU) directory.
cd backends/gcu

# 2) Before compiling, you need to ensure that the PaddlePaddle installation package is installed in the environment.
#    Just install the PaddlePaddle CPU version directly.
pip install paddlepaddle==0.0.0 -f https://www.paddlepaddle.org.cn/whl/linux/cpu-mkl/develop.html

# 3) Start compiling, and submodules will be downloaded on demand during compilation.
mkdir -p build && cd build
cmake .. -DWITH_TESTING=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make -j $(nproc)

# 4) The compiled product is in the build/dist path and installed using pip.
pip install --force-reinstall -U build/dist/paddle_custom_gcu*.whl
```

### Functional Verification

```bash
# 1) List available hardware backends.
python -c "import paddle; print(paddle.device.get_all_custom_device_type())"
# Expect the following output.
['gcu']

# 2) Check currently installed version.
python -c "import paddle_custom_device; paddle_custom_device.gcu.version()"
# Expect to get output like this.
version: 0.0.0.ffc0377-2.4.1
commit: ffc037739c55508532ee67b565517be2b4ae584d
plugin version: 0.0.1
```
