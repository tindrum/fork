Assignment 1:

Nikita Sadinidhi Vijayan  sv.nikita91@csu.fullerton.edu
Daniel Henderson          tindrum@csu.fullerton.edu
Joshua Edmonds            jedmonds91011@csu.fullerton.edu

Programming language: C++

How to execute:
Compile the .cpp files to executables using g++:
```g++ parallel.cpp -o par.run```
```g++ serial.cpp -o ser.run```
When executing the files, we also want the timing information.
Each executable requires an input text file, as well.
```time ./par.run large_urls.txt```
```time ./ser.run large_urls.txt```
or use tiny_files.txt to download the small files.
This works if your current directory contains the source and executable files.
If not, change directory (cd) to where the source files are.

Bonus: We have not chosen to implement the extra credit part of the excercise.

Questions:
1. In the output of time, what is the difference between real, user, and sys times?

     _real_ time is "wall clock time", the total time taken for the processes to run.
     This is the time the user will experience. This time includes all the time 
     the system is working on other processes and "blocked time", where the system is 
     simply switching between our and other tasks.
     _user_ time is time the processor spends in the user mode in this program.
     It may be much smaller than Real time, because the system may have multiple users,
     multiple programs running, and other factors.
     _sys_ time is the time the system has spent on system calls for our processes. 

2. Which is longer: user time or sys time? Use your knoweldge to explain why.

     The user time is small, because the process is not running interactively.
     The system time is small, since only a few system calls are being used.
     If the program was interactive, i.e. the user enters urls for each file he/she wants to
     download, the user time would be much greater than the system time.
     The wget command, or any command spun off from an execlp, does not seem to count 
     towards _sys_ or _user_ time. The spun-off task is not increasing the clock time
     for the process that initiated it.

3. When downloading the files above, which downloader finishes faster? 
   Why do you think that is?

     The parallel version runs faster with small file sizes. 
     When running in serial, the incoming bandwidth is not a factor, nor is task switching.
     The parallel version will saturate any incoming bandwidth.
     More importantly, task switching between download tasks will become overhead,
     and slow the overall process.

4. Repeat the experiment for 10 files (any reasonably large-sized files, e.g., 100 MB, will do).
   Is the downloader in the previous question still faster? If not so, why do you think that is?

     The download for larger files is still somewhat faster, but not by as much.
     It may be that context-switching between the different forks is taking a larger
     percentage of time, thereby reducing the amount of time spent actually downloading
     files.
     

We used a list of urls that get pdfs of various sizes, from a few megs up to 17.4 mb.
These urls are in large_urls.txt.
Big Files:
SERIAL version:
real	13m48.262s
user	0m1.196s
sys	0m3.988s

Parallel version:
real	12m21.350s
user	0m1.840s
sys	0m5.968s

To test for small file sizes, we used images and other small downloadable items.
These are in tiny_files.txt.
Tiny Files:
Serial version:
real	0m13.056s
user	0m0.032s
sys	0m0.036s

parallel version:
real	0m3.088s
user	0m0.008s
sys	0m0.056s
