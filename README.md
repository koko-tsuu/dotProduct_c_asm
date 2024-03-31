The program is done under the requirement of LBYARCH’s MP2 with the following specs:

![sdot specs](http://url/to/img.png)

## The C Program

The C program allows the calling of both C and assembly kernels. The C program also tracks both the average time and number of execution of each kernel. The value for both vectors is: [put the calc for how given is calculated with the for loop]. It is simply a repetition of 0-100 repeatedly until the whole vector is filled out. The sanity check done to see the correctness of both the C and assembly program is if both programs have the same answer. The average time is calculated by executing each kernel 30 times.

## Kernel Comparison and Analysis

The assembly kernel is clearly faster than the C kernel where the speed difference ranges between 1-5%. But as the input size grows exponentially, the difference in average speed between the two kernels becomes insignificant. 

The tests where done with vector sizes 2^20, 2^24, and 2^26. Vector sizes beyond 2^26 are unfeasible due to the computer device lagging and crashing with it.

## Sample Results

### 2^20
![2^20 samples](http://url/to/img.png)
![2^20 stats](http://url/to/img.png)

### 2^24
![2^24 samples](http://url/to/img.png)
![2^24 stats](http://url/to/img.png)

### 2^20
![2^24 samples](http://url/to/img.png)
![2^24 stats](http://url/to/img.png)
