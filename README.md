# Preparing all the coding tests

## Contents Table

goto

- [Daily Log](#daily-logs)
- [LeetCode](#leetcode)
- [Interviews](#interviews)
- [Quick Setting up](#setting-environment-easily)

## Daily Logs

- *2023-01-15* | Solve 108
  - Start to think from the easiest way.
  - Recognize the difference between divide-and-conquer & build-BST-inline.
- *2023-01-08* | Solve 10035, 10036
  - **yaml-cpp for input is too much task for this.**
  - everyone want straightforward approach.
  - decide how to approach (ex: math or for-loop or if-elif-else ...?)
  - If you decided, stick to it and put into your implementation.

## LeetCode

Search pXXX in visual studio code \
*[Back to contents](#contents-table)*

### 0. Template

**Problem**:

The summary of the problem.

**Main Idea**:

What is the essential idea to solve this probelm?

**Extend** (*What if there are another constraints?*):

- Extra condition 1:
  - The method to overcome extra condition 1.

### 1. Two Sum

**Problem**:

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`. You may assume that each input would have **exactly one solution**, and you may not use the same element twice. You can return the answer in any order.

**Main Idea**:

The easiest way to solve this problem is the Brute-Force approach. But its time complexity is $O(N^2)$.

To optimze this, we can use unordered_map (= hash table). Access Time Complexity for hast table is $O(1)$ on average. So, we can check answer in constant time for each `num` since we can compute `residual` to get `target`. By storing pre-checked `num` (in `nums`) the matched number to complete `target` is known. It spends $O(N)$ for building hash table, and $O(N)$ for iterating `nums`, Total $2 * O(N)$ Time Complexity.

### 2. Add Two Numbers

**Problem**:

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Main Idea**:

Note that reversing order to represent a single digist is not a strange thing in a List. Converting a list to an integer type can lead to overflow for large numbers. Therefore, we have to calculate the sum of two digits using two lists without any preprocessing, traversing the nodes while considering carries from sums that equal to or greater than 10. Utilizing a recursive function for its implementation proved to be the most time-efficient approach (but not dramatic).

### 70. Climbing Stairs

**Problem**:

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Main Idea**:

When you got `n`, it can be divided by `n-1` / 1 and `n-2` / 2. And 2 cases are not redundant!

So, this is very good problem to get feeling about dynamic programming and recursion.

**Extend** (*What if there are another constraints?*):

- Extra condition 1:
  - The method to overcome extra condition 1.

### 108. Convert Sorted Array to Binary Search Tree

**Problem**:

Given an integer array nums **where the elements are sorted in ascending order**, convert it to a height-balanced binary search tree.

**Main Idea & Feedback**:

- At first, I failed to notice that the given integer vector was already sorted. That made me think the problem was more complicated than it needed to be.
- Nevertheless, it's a positive indication that I didn't immediately pursue the perfect solution. Instead, I chose to start with a easiest way.
- As it is sorted, this problem can be solved with divide and conquer approach.

**Extend** (*What if there are another constraints?*):

- Extra condition 1:
  - The method to overcome extra condition 1.

### 812. Largest Triangle Area

**Main Idea**:

How to compute the area of a triangle [back to contents](#contents-table) \
We can compute the area of a trianlge using cross product of two vectors. [YouTube](https://www.youtube.com/watch?v=VqBYFsLtrDo)

**Extend**:

- Small improvement:
  - Consider differenct approaches by minimizing the multiplication operation.
- Find boundary points first (Find Convex Hull)
  - $O(NlogN)$: Sort points in list according to x & y position
  - $O(4N)$: Select Upper hull($O(2N)$) + Lower hull($O(2N)$)
  - Selected M points => $O(M^3)$
  - **Total: $O(M^3) + O(NlogN)$ | Worst Case $O(N^3)$**

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

### 3028. Ant on the Boundary (Easy)

**Problem**:

An ant is on a 1-D space's boundary (means `0`-position). You are given an array of non-zero integers nums. The ant starts reading nums from the first element of it to its end.

At each step, it moves according to the value of the current element:

- If `nums[i]` < 0, it moves left by `-nums[i]` units.
- If `nums[i]` > 0, it moves right by `nums[i]` units.

Return the number of times the ant returns to the boundary(`0`).

**Notes**:

There is an infinite space on both sides of the boundary.
We check whether the ant is on the boundary only after it has moved |nums[i]| units. In other words, if the ant crosses the boundary during its movement, it does not count.

**Main Idea**:

Will be easily soved using dynamic programming.

## Interviews

### Journey to a FAANG Company - Amazon (@Kishan Kumar Patel) [Link](https://leetcode.com/discuss/interview-experience/3171859/Journey-to-a-FAANG-Company-Amazon-or-SDE2-(L5)-or-Bangalore-or-Oct-2022-Accepted)

*Summary* :

 every day check the mail in the morning and second to keep on applying for open positions on daily basis.
He was confident on wrting code, but not on the algorithms, so he just watched videos only.
=> Unfortunately He was not able to write any code in first two coding rounds.

*Things to remember for DSA round* :

1. Discuss the problem before deep diving into it.
2. Start with a brute force solution without thinking much on optimisation.
3. Be vocal while writing code and verifying your code - keep telling whatever you are thinking.
4. Must dry run your code and effort spent on thinking about corner cases.
5. If asked with behavioural questions, then keep it short and direct - to save more time for coding.

*Things to do for DSA preparation* :

1. Complete all the topic wise sections in the study plan section of the leet code.
2. Practice questions in a time constrained manner, no point of spending hours in a single question.
3. Easy and medium level questions are sufficient enough to crack DSA rounds.
4. Once you complete the study plan you can refer to the tutorial by Fraz on a set of 250 questions.
   One thing I would like to suggest is to remove the topic header in the excel sheet, so that
   when you attempt a question from the sheet you should not be aware of which topic it is from and
   that you should identify yourself. Also keep nothing down things you learnt from each of the
   questions - this will help you to revise concepts later. Repeat good questions/ questions that
   you find difficult to solve and keep repeating until you are convinced.
5. Few of the tutorials that I followed : \
  DP, Binary Search & Stack: [Link](https://www.youtube.com/@TheAdityaVerma) \
  Graph, Tree, Trie: [Link](https://m.youtube.com/@takeUforward) \
  C++ Tutorial: [Link](https://m.youtube.com/playlist?list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-) \
  Basic DSA Concepts : Jennys’ Classes & Abdul Baris’s Tutorial \
  Two of the good coding books were added to the github link given below.

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
