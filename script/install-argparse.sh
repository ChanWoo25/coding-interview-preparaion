#! /bin/bash

# Arguments check
if [ $# -lt 2 ]; then
  echo "Example: install-argparse.sh <mode> <version>"
  echo " - mode: [local, docker]"
  echo " - version: [v1.0:v3.0:0.1](default: v3.0) | Link: https://github.com/p-ranav/argparse"
  exit 1
fi

DEFAULT_TARGET_VERSION="v3.0"
ALLOWED_MODES=("local" "docker")
mode="$1"
pre_sudo=""

if [[ ! "${ALLOWED_MODES[*]}" =~ "${mode}" ]]; then
  echo "Invalid argument: ${mode} is not in the allowed mode"
  exit 1
else
  if [ "${mode}" = "local" ]; then
    pre_sudo="sudo"
  fi
fi


if [ -z "$2" ]; then
  version="${DEFAULT_TARGET_VERSION}"
else
  version="$2"
fi
git_link="https://github.com/p-ranav/argparse"

echo "Install argparse ..."
echo " - mode(${mode}), version(${version})"

cd ~
git clone --single-branch -b ${version} ${git_link} tmp
cd tmp

# Build the tests
mkdir build && cd build
cmake ..
## When you want to build tests
# cmake -DARGPARSE_BUILD_SAMPLES=on -DARGPARSE_BUILD_TESTS=on ..
make

# Run tests
./test/tests

# Install the library
${pre_sudo} make install

cd ~ && rm -rf tmp
