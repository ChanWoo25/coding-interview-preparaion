# Preparing all the coding tests

## Contents Table

goto

- [LeetCode Reviews](#leetcode)
- [Quick Setting up](#setting-environment-easily)

## Daily Logs

- *2023-01-08* | Solve 10035, 10036
  - **yaml-cpp for input is too much task for this.**
  - everyone want straightforward approach.
  - decide how to approach (ex: math or for-loop or if-elif-else ...?)
  - If you decided, stick to it and put into your implementation.

## LeetCode

back to [contents](#contents-table)

### 10035. Maximum Area of Longest Diagonal Rectangle

back to [contents](#contents-table)

### 10036. Minimum Moves to Capture The Queen

**Problem** _ *[back to contents](#contents-table)*\
Compute minimum moves to capture black queen using one rook and one bishop on a 8X8 Chessboard

1. There is no need to move more than 2 times. Just 1 or 2.
2. bishop은 rook 2번을 대체할 수도있지만, 절반밖에 커버하지 못한다.
3. rook으로 바로 잡을 수 있는 경우. => 1
4. rook과 직선상, 사이에 비숍이 있는 경우, => 2
5. Otherwise, bishop과의 직선거리 상에 rook이 있지 않은 이상, 모든 경우에 rook이 2번 안에 잡을 수 있음.

> Feedback \
> 조건문이 많은 것은 둘째치고, 일관성이 부족하다. 1번 혹은 2번만이 답이 될 수 있음을 사전에 알고 있다면, 반복문 따위보다는 조건문으로 푸는 것이 좋다. 또한 경우의 수가 적은 1번 Case를 앞으로 빼고, 2번은 Else 문으로 넘기려고 목표를 정해놓고 구현했으면 좀 더 Clear했을 것이다.

## Setting Environment Easily

### Create docker container

```bash
export IMAGE_NAME="leechanwoo25/cudagl_ros:13.1.1-u2004-noetic"
export CONTAINER_NAME="coding" &&
export MOUNT_DIR=~/shared-${CONTAINER_NAME} &&
mkdir -p ${MOUNT_DIR} &&
docker run --runtime=nvidia --gpus all -it \
--volume ${MOUNT_DIR}:/root/shared \
--workdir=/root/shared \
--name ${CONTAINER_NAME} \
${IMAGE_NAME}
# Do the following
ssh-keygen
cat ~/.ssh/id_rsa.pub
# => GitHub register SSH keys
git config --global user.email "leechanwoo25@gmail.com" &&
git config --global user.name "Chanwoo Lee"
# For running compdb
pip3 install -U pip
pip3 install -U wheel setuptools
pip3 install compdb
```

```bash
## Already installed in Image
apt install -y ninja-build
# For Ubuntu 20.04
wget https://apt.llvm.org/llvm.sh &&
chmod +x llvm.sh &&
./llvm.sh 10 &&
apt-get install -y clang clangd
rm llvm.sh
```
